#include <ctime>
#include <queue>
#include <deque>
#include <memory>
#include </home/vatsuak/Desktop/catkin_ws/src/Lidartags/include/griz_tag.h>
#include </usr/include/pcl-1.7/pcl/common/common.h>
#include <chrono>
#include <time.h>

// #include "types.h"
// #include "ros/time.h"
using namespace BipedLab;

typedef struct TemporalSeq{
    /*
    two queues
        1 for the pointcloud temploadQ not a pointer??
        2 for the time       timeQ
    */
   std::queue<PointXYZRI> temploadQ;  // should I make this a pointer?
   std::queue<float> timeQ;

} TemporalSeq_t;

bool feeder(TemporalSeq_t &temp, const pcl::PointCloud<LiDARPoints_t*> &t_payload, const int timestamps, const int cutoff){
    /*
    takes in a refernce to 
            pointcloud
            Temporal_Seq
    returns true when it temp represents a valid input to the network
    */
   if (temp.temploadQ.size() < timestamps) {
        temp.temploadQ.push(t_payload.points);
	// XXX: change to sensor time
        temp.timeQ.push_back(ros::Time::now());
        if (temp.temploadQ.size() == timestamps) { 
            // after adding the last payload, I have a full temporal sequence
            // check for timeout
            if (temp.temploadQ.size() == timestamps){
                if ((temp.timeQ.back() - temp.timeQ.front()) < cutoff){
                    return true;
                }
            }
        }
   }
   if (temp.temploadQ.size() == timestamps) {
        //now I have a full complement of payloads
        // pop and push as usual
        //if the timestamp is within limits them pass it out as an input 
        temp.temploadQ.pop();
        temp.temploadQ.push(t_payload);
        temp.timeQ.pop_front();
        temp.timeQ.push_back(ros::Time::now());
        if ((temp.timeQ.back() - temp.timeQ.front()) < cutoff){
            return true;
        }   

   }
   return false;
}
int main(){


}
