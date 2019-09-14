import tensorflow as tf
import gym
import numpy as np
import pdb
import sys

def helper_discount_rewards(rewards, discount_rate):
    '''
    Takes in a list of rewards and applies discount rate
    '''
    discounted_rewards = np.zeros(len(rewards))
    cumulative_rewards = 0
    for step in reversed(range(len(rewards))):
        cumulative_rewards = rewards[step] + cumulative_rewards * discount_rate
        discounted_rewards[step] = cumulative_rewards
    return discounted_rewards

def discount_and_normalize_rewards(all_rewards, discount_rate):
    '''
    Takes in all rewards, applies helper_discount function and then normalizes
    using mean and std.
    '''
    all_discounted_rewards = []
    for rewards in all_rewards:
        all_discounted_rewards.append(helper_discount_rewards(rewards,discount_rate))

    flat_rewards = np.concatenate(all_discounted_rewards)
    reward_mean = flat_rewards.mean()
    reward_std = flat_rewards.std()
    return [(discounted_rewards - reward_mean)/reward_std for discounted_rewards in all_discounted_rewards]


num_inps = 4
num_hidden = 4
num_out = 1

lr = 0.01
initializer = tf.contrib.layers.variance_scaling_initializer()
X = tf.placeholder(tf.float32,shape=[None,num_inps])

hidden_layer = tf.layers.dense(X,num_hidden,activation=tf.nn.elu,kernel_initializer=initializer)
logits = tf.layers.dense(hidden_layer,num_out)
outputs = tf.nn.sigmoid(logits)      # will be a prob for the go left cmd  

probs = tf.concat(axis=1,values=[outputs,1-outputs])      # [p(left),p(right)]
action = tf.multinomial(probs, num_samples=1)             # given the binomial dist above sample 1 action from {0,1}(2 possible since binomial)
y = 1.0 - tf.to_float(action)

cross_entropy = tf.nn.sigmoid_cross_entropy_with_logits(labels=y,logits=logits)
optimizer = tf.train.AdamOptimizer(lr)
grads_and_var = optimizer.compute_gradients(cross_entropy)

gradients = []
gradient_placeholders = []
grads_and_var_feed = []

for grad,var in grads_and_var:
    gradients.append(grad)
    gradient_placeholder = tf.placeholder(tf.float32,shape=grad.get_shape())
    gradient_placeholders.append(gradient_placeholder)
    grads_and_var_feed.append((gradient_placeholder,var))

training_op = optimizer.apply_gradients(grads_and_var_feed)
init = tf.global_variables_initializer()
saver = tf.train.Saver()

#start with the training
env = gym.make("CartPole-v0")

num_game_rounds = 10
max_game_steps = 250
num_iterations = 1000
discount_rate = 0.95

with tf.Session() as sess:
    sess.run(init)


    for iteration in range(num_iterations):
        print("Currently on Iteration: {} \n".format(iteration) )

        all_rewards = []
        all_gradients = []

        # Play n amount of game rounds
        for game in range(num_game_rounds):

            current_rewards = []
            current_gradients = []

            observations = env.reset()

            # Only allow n amount of steps in game
            for step in range(max_game_steps):

                # Get Actions and Gradients
                action_val, gradients_val = sess.run([action, gradients], feed_dict={X: observations.reshape(1, num_inps)})

                # Perform Action
                observations, reward, done, info = env.step(action_val[0][0])

                # Get Current Rewards and Gradients
                current_rewards.append(reward)
                current_gradients.append(gradients_val)

                if done:
                    # Game Ended
                    break

            # Append to list of all rewards
            all_rewards.append(current_rewards)
            all_gradients.append(current_gradients)

        all_rewards = discount_and_normalize_rewards(all_rewards,discount_rate)
        feed_dict = {}


        for var_index, gradient_placeholder in enumerate(gradient_placeholders):
            mean_gradients = np.mean([reward * all_gradients[game_index][step][var_index]
                                      for game_index, rewards in enumerate(all_rewards)
                                          for step, reward in enumerate(rewards)], axis=0)
            feed_dict[gradient_placeholder] = mean_gradients

        sess.run(training_op, feed_dict=feed_dict)

    print('SAVING GRAPH AND SESSION')
    # meta_graph_def = tf.train.export_meta_graph(filename='/models/my-650-step-model.meta')
    saver.save(sess, './models/my-650-step-model')



# inference

env = gym.make('CartPole-v0')
new_saver = tf.train.Saver()
observations = env.reset()
with tf.Session() as sess:
    # https://www.tensorflow.org/api_guides/python/meta_graph
    # new_saver = tf.train.import_meta_graph('/models/my-650-step-model.meta')
    new_saver.restore(sess,'./models/my-650-step-model')

    for x in range(500):
        env.render()
        action_val, gradients_val = sess.run([action, gradients], feed_dict={X: observations.reshape(1, num_inps)})
        observations, reward, done, info = env.step(action_val[0][0])





