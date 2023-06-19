// Exercises completed utilizing OOP with pointers (for practice) instead of POP using variable
// reassignment.
#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>
#include <string>
#include <list>

class Unit3Exercises {
    public:
    // Inherit rosbot class
    RosbotClass rosbot;

    // Call solutions to various exercises.
    void exercise_3_1(int n_secs);
    void exercise_3_2();
};

void Unit3Exercises::exercise_3_1(int n_secs){
    rosbot.move_forward(n_secs);
    float x = rosbot.get_position(0);
    float y = rosbot.get_position(1);
    ROS_INFO_STREAM("X position: "<< x << " | Y position: "<< y);
}

void Unit3Exercises::exercise_3_2(){
  rosbot.turn("clockwise", 3);
  rosbot.move_forward(2);
  rosbot.turn("counterclockwise", 3);
  rosbot.move_forward(9);
  rosbot.turn("clockwise", 2);
  rosbot.move_forward(3);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_node");
  // Instanciate
  Unit3Exercises robot;
  robot.exercise_3_2();

  return 0;
}