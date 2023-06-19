// Exercises completed utilizing OOP with pointers (for practice) instead of POP using variable
// reassignment.
#include "ros/console.h"
#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>
#include <string>
#include <list>
#include <array>

class Unit4Exercises {
    public:
    // Inherit rosbot class
    RosbotClass rosbot;

    // Call solutions to various exercises.
    void exercise_4_1(int max_secs);
    void exercise_4_2(int array[], int size);
    void exercise_4_3();
};

void Unit4Exercises::exercise_4_1(int max_secs){
    // Move forward get laser data. 
    rosbot.move_forward(1);
    float laser_left = rosbot.get_laser(9);
    float laser_right = rosbot.get_laser(710);
    // Get pointers to laser data. Print outputs. 
    float* laser_left_p;
    float* laser_right_p;
    laser_left_p = &laser_left;
    laser_right_p = &laser_right;
    ROS_INFO_STREAM("Left scan reads: " << *laser_left_p << " | Right scan reads: "<< *laser_right_p);

    // Now loop until reach max seconds. 
    int i = 1;
    while (i<=max_secs){
        rosbot.move_forward(1);
        *laser_left_p = rosbot.get_laser(9);
        *laser_right_p = rosbot.get_laser(710);
        ROS_INFO_STREAM("Left scan memory address: " << laser_left_p);
        ROS_INFO_STREAM("Right scan memory address: " << laser_right_p);
        ROS_INFO_STREAM("Left scan reads: " << *laser_left_p << " | Right scan reads: "<< *laser_right_p);
        i++;
    }
}

void Unit4Exercises::exercise_4_2(int array[], int size){
    // Make pointer direct it to the array
    int* array_p;
    array_p = array;
    // Loop until end of array
    ROS_INFO_STREAM("The new array is: ");
    for (int i=1;i<=size;i++){
        *array_p = (*array_p)*(*array_p);
        ROS_INFO_STREAM(*array_p);
        array_p++;
    }
}

void Unit4Exercises::exercise_4_3(){
    // For some reason, not moving causes a segmentation fault when printing.
    rosbot.move_forward(1);
    // Retrieve pointer. 
    float *laser_p;
    laser_p = rosbot.get_laser_full();

    // Print Contents 
    ROS_INFO_STREAM("Laser contents are: ");
    int i = 0;
    while (i != 1) {
        ROS_INFO_STREAM(*laser_p);
        laser_p++;
        // If value = 0, then outside of recorded values. 
        if (*laser_p == 0){
            break;
        }
    }
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_node");
  // Instanciate
  Unit4Exercises robot;

  // Exercise 4_2 needs size of input array. 
  //int array[] = {1,2,3,4,5,6,7,8,9};
  //int size = sizeof(array)/sizeof(int);
  robot.exercise_4_3();

  return 0;
}