// Exercises completed utilizing OOP with pointers (for practice) instead of POP using variable
// reassignment.
#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>

class Unit2Exercises {
    public:
    // Inherit rosbot class
    RosbotClass rosbot;

    // Call solutions to various exercises.
    void exercise_2_1(float tol, float x_lim);
    void exercise_2_2(float tol, float x_lim);
    void exercise_2_3(int secs);
};

void Unit2Exercises::exercise_2_1(float tol, float x_lim){
    // Move forward 
    rosbot.move_forward(1);

    // get position 
    float x = rosbot.get_position(1);

    //Save to pointer 
    float* xp;
    xp = &x;
    ROS_INFO_STREAM("Position is: " << *xp << ". Want near "<< x_lim);

    while (*xp <= x_lim - tol || *xp >= x_lim + tol){
        if (*xp < x_lim - tol){
            // Move forward 
            rosbot.move_forward(1);
        }
        else{
            // Move backwards 
            rosbot.move_backwards(1);
        }
        // Update position
        *xp = rosbot.get_position(1);
        ROS_INFO_STREAM("Position is: " << *xp << ". Want near "<< x_lim);
    }
    ROS_INFO_STREAM("Close enough to "<< x_lim);
}

void Unit2Exercises::exercise_2_2(float tol, float x_lim){
    // Move forward 
    rosbot.move_forward(1);

    // get position 
    float x = rosbot.get_position(1);

    //Save to pointer 
    float* xp;
    xp = &x;
    ROS_INFO_STREAM("Position is: " << *xp << ". Want near "<< x_lim);

    while (*xp <= x_lim - tol || *xp >= x_lim + tol){
        if (*xp < x_lim - tol){
            // Move forward 
            rosbot.move_forward(1);
        }
        else{
            // Move backwards 
            rosbot.move_backwards(1);
        }
        // Update position
        *xp = rosbot.get_position(1);
        ROS_INFO_STREAM("Position is: " << *xp << ". Want near "<< x_lim);
    }
    ROS_INFO_STREAM("Close enough to "<< x_lim);
}
void Unit2Exercises::exercise_2_3(int secs){
    // Move 
    rosbot.move_forward(secs);
    // Make list
    list<float> position;
    // Retrieve coordinate list
    position = rosbot.get_position_full();

    ROS_INFO_STREAM("X,Y,Z positions are: ");
    // Unpack using pointers 
    for (auto i=position.cbegin(); i!=position.cend();i++){
        ROS_INFO_STREAM(*i);
    }

}

int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_node");
  // Instanciate
  Unit2Exercises robot;
  robot.exercise_2_3(3);

  return 0;
}