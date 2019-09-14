#####
#demo project to test a hard coded policy 
#####
import gym
env = gym.make('CartPole-v1')
# action space has 2 actions {0-left ,1-right }
# observation has an array of [cart_pos, cart_vel, pole_angle, pole_vel]
print 'Initial observation'
obs = env.reset()
print obs
for t in range(1000):
    env.render()
    # action = env.action_space.sample()
    if obs[2]<0:         # if pole angle is to the left, go left, else go right (hard coded policy) 
        action = 0
    else:
        action = 1
    print 'action',t,':',action 
    obs, reward, done, info = env.step(action)
    if done: break
    print('obs: {} ; reward: {} done: {} info: {}'.format(obs, reward, done, info))
