// Exercises completed utilizing OOP with pointers (for practice) instead of POP using variable
// reassignment..
#include "ros/console.h"
#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>
#include <math.h>

class Unit6Exercises{
    public:
    // Inherit rosbot class
    RosbotClass rosbot;

    // Call solutions to various exercises.
    void exercise_6_1();
};

void Unit6Exercises::exercise_6_1(){
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
    // Begin first turn
    rosbot.turn("clockwise",3);
    // Move forward 
    rosbot.move_forward(2);
    // Turn opposite direction 
    rosbot.turn("counterclockwise",3);

    // Now calculate distance traveled. 
    // No longer using scanner. 
    // Get initial positions. Pointers used for things that are overwrited.
    float* x_p2;
    float* y_p2;
    float* dist_p;

    float x1 = rosbot.get_position(1);
    float y1 = rosbot.get_position(2);
    float x2 = x1;
    float y2 = y1;
    float dist = 0.0;

    x_p2 = &x2;
    y_p2 = &y2;
    dist_p = &dist;
    // Loop until distance traveled is sufficient. 
    while (*dist_p < 3.0){
        rosbot.move_forward(1);
        *x_p2 = rosbot.get_position(1);
        *y_p2 = rosbot.get_position(2);
        *dist_p = sqrt(pow(*x_p2-x1,2)-pow(*y_p2-y1,2));
        ROS_INFO_STREAM("Distance traveled is: "<<*dist_p);
    }

}

int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_node");
  // Instanciate
  Unit6Exercises robot;
  robot.exercise_6_1();

  return 0;
}