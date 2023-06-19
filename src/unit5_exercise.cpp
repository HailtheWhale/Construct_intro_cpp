// Exercises completed utilizing OOP with pointers (for practice) instead of POP using variable
// reassignment..
#include "ros/console.h"
#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>
#include <string>

class Unit5Exercises {
    public:
    // Inherit rosbot class
    RosbotClass rosbot;

    Unit5Exercises(string a){dir = a;};
    string dir;

    // Call solutions to various exercises.
    void exercise_5_1();
};

void Unit5Exercises::exercise_5_1(){
    // For some reason, not moving causes a segmentation fault when printing.
    rosbot.move_forward(1);

    // Get initial distance 
    float* front_d_p;
    float front_scan = rosbot.get_laser(0);
    front_d_p = &front_scan;

    // Wait until close 
    while(*front_d_p > 2.0){
        rosbot.move_forward(1);
        *front_d_p = rosbot.get_laser(0);
        ROS_INFO_STREAM("Front is " << *front_d_p << " away.");
    }

    // Turn left or right based on input.
    if (dir == "left"){
        rosbot.turn("counterclockwise",3);
    } else {
        rosbot.turn("clockwise",3);
    }
    // Move forward 
    rosbot.move_forward(3);

    // Turn opposite direction 
    if (dir == "right"){
        rosbot.turn("counterclockwise",3);
    } else {
        rosbot.turn("clockwise",3);
    }
    // Move forward 
    rosbot.move_forward(3);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_node");
  // Instanciate
  Unit5Exercises robot("left");
  robot.exercise_5_1();

  return 0;
}