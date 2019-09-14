# basic feedfowards nn to determine the action, has no concept of learning 
import tensorflow as tf
import gym
import numpy as np
import sys

def fc_layer(inputs, num_inp, num_out, activate=None, scope=None):
    with tf.variable_scope(scope):
        weights = tf.get_variable('w',shape=[num_inp,num_out],dtype=tf.float32,initializer=tf.random_normal_initializer)
        biases = tf.get_variable('b',shape=[num_out],dtype=tf.float32,initializer=tf.constant_initializer(0.0))
        outputs = tf.nn.bias_add(tf.matmul(inputs,weights), biases)
        if activate:
            outputs = activate(outputs)
        return outputs

def net(inp,hid):
    x = fc_layer(inp,4,4,tf.nn.relu,'fc0')
    for i in range(hid):
        x = fc_layer(x,4,4,tf.nn.relu,'fc'+str(i+1))
    out = fc_layer(x,4,1,tf.nn.sigmoid,'out')
    return out

num_inps = 4 # for the 4 obs
num_hid = 4 # number of neurons in the hidden layer
num_outs = 1 # for the action

obs_pl = tf.placeholder(tf.float32,[None,4],'obseravtions')

# sample = tf.zeros(shape=[1,4],dtype=tf.float32)
# res = fc_layer(sample,4,4,tf.nn.relu,'fc1')
# print res
num_epi = 200
num_steps = 50
out = net(obs_pl,2)
action = tf.multinomial(out,num_samples=1)
init = tf.global_variables_initializer()
avg_steps = []
# print action 
# sys.exit()
env = gym.make('CartPole-v1')
with tf.Session() as sess:
    sess.run(init)
    for epi in range(num_epi):
        obs = env.reset()
        obs = np.reshape(obs, [1,4])
        # print obs.shape
        for step in range(num_steps):
            act = sess.run(action,feed_dict={obs_pl:obs})
            obs, r, done, info = env.step(act[0,0])
            obs = np.reshape(obs, [1,4])
            if done:
                avg_steps.append(step)
                print('Done after {} steps'.format(step))
                break
print('After {} episodes, avg steps per game {}'.format(epi, np.mean(avg_steps)))
env.close()  



            


