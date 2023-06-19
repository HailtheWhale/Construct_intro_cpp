// Exercises completed utilizing OOP with pointers (for practice) instead of POP using variable
// reassignment.
#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>

class Unit1Exercises {
    public:
    // Inherit rosbot class
    RosbotClass rosbot;

    // Call solutions to various exercises.
    void exercise_1_1();
    void exercise_1_2();
    void exercise_1_3(int reps);
    void exercise_1_4(int reps);
};

void Unit1Exercises::exercise_1_1() {
  // Pointer
  float* x_pointer;
  // Move forward
  rosbot.move();
  // Give x odom position and stream.
  float coordinate = rosbot.get_position(1);
  x_pointer = &coordinate;
  ROS_INFO_STREAM(*x_pointer<<" Meters.");
};

void Unit1Exercises::exercise_1_2() {
  // Pointers 
  float* x_pointer;
  float* y_pointer;
  // Give x odom position and stream.
  float x = rosbot.get_position(1);
  float y = rosbot.get_position(2);
  // Put these into pointers and stream.
  x_pointer = &x;
  y_pointer = &y;
  ROS_INFO_STREAM("X position is: "<< *x_pointer <<" | Y position is: " <<*y_pointer << " Meters.");

  // Move forward
  rosbot.move();
  // Give x odom position and stream.
  *x_pointer = rosbot.get_position(1);
  *y_pointer = rosbot.get_position(2);
  ROS_INFO_STREAM("NEW X position is: "<< *x_pointer <<" | Y position is: " <<*y_pointer << " Meters.");

}

void Unit1Exercises::exercise_1_3(int reps=1){
  // Make dictionary
  map<double,float> pos_dict;

  // Give x odom position and stream.
  float x = rosbot.get_position(1);
  double t = rosbot.get_time();
  // Put these into dictionary 
  pos_dict.insert({t,x});

  // Loop until number of movements is complete. 
  for (int i=0; i<reps; i++){
    // Move forward
    rosbot.move();
    // Give x odom position and stream.
    x = rosbot.get_position(1);
    t = rosbot.get_time();
    // Put these into dictionary 
    pos_dict.insert({t,x});
  }

  // Print contents 
  for (auto element: pos_dict){
    ROS_INFO_STREAM("At " <<  element.first << " Seconds | traveled " << element.second << " meters");
  }
};

void Unit1Exercises::exercise_1_4(int reps=1) {
  // Make pointers 
  float* x1p;
  float* x2p;
  double* t1p;
  double* t2p;
  float* vp;

  // Give x odom position and stream.
  float x1 = rosbot.get_position(1);
  double t1 = rosbot.get_time();
  // Save to pointer. 
  x1p = &x1;
  t1p = &t1;

  // Move forward
  rosbot.move();

  // Give x odom position and stream.
  float x2 = rosbot.get_position(1);
  double t2 = rosbot.get_time();
  // Save to pointer. 
  x2p = &x2;
  t2p = &t2;

  // Get velocity 
  float v = (*x2p-*x1p)/(*t2p-*t1p);
  // Save to pointer 
  vp = &v;

  ROS_INFO_STREAM("Velocity is: " << *vp << " At memory location: " << vp);

  for (int i = 1; i<reps; i++){
    // Save x odom position and stream to pointer
    *x1p = rosbot.get_position(1);
    *t1p = rosbot.get_time();

    // Move forward
    rosbot.move();

    // Give x odom position and stream.
    *x2p = rosbot.get_position(1);
    *t2p = rosbot.get_time();

    // Get velocity 
    *vp = (*x2p-*x1p)/(*t2p-*t1p);

    ROS_INFO_STREAM("Velocity is: " << *vp << " At memory location: " << vp);
    if (*vp < 1.0){
        ROS_INFO_STREAM("Velocity is less than 1m/s");
    } else{
        ROS_INFO_STREAM("Velocity is NOT less than 1m/s");
    }
  }
  
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_node");
  // Instanciate
  Unit1Exercises robot;
  robot.exercise_1_4(3);

  return 0;
}