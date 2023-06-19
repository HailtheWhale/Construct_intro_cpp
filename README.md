# Based on theContruct's C++ for Robotics Course
- Completed by Donovan Gegg 

## Dependencies 
Base repository with rosbot control class here: https://bitbucket.org/theconstructcore/cpp_course_repo.git. Replace src folder with this one to get working. 

## What's This Repo About?
To demonstrate course contents, with an added twist to demonstrate material understanding. 

## What Makes This Repo Special?
- All exercises are done using C++ classes and pointers. This was mostly to practice these.
- Many exercises were modified to include loops to make the use of pointers actually useful. 
- Short videos demonstrating the more interesting exercises and the cafe escape using `rosbot_control`'s methods that give sensor data.

## Repo Structure 
1. Notes on what the exercise asked for, and what was changed (if anything).
2. Video demonstrations. 

## Exercise Requirements and Modifications 
- Exercise 1.1
    - Requirements: Instanciate an object using the `RosbotClass`. Make it move with `move` method and get its x position with the `get_position` method. 
    - Changes: Created class `Unit1Exercises`. Made exercise a method call. Made a pointer to the resultant position and dereferenced it. 
- Exercise 1.2
    - Requirements: Get the x, y coordinates from the robot. Make it move. Get the coordinates again. 
    - Changes: Made pointers to x, y variables. Made exercise a method call. Used pointers for all variables
- Exercise 1.3
    - Requirements: Get the x position and time stamp using the `get_time` method. Make the robot move. Get the x position and time stamp again. Save both values to a dictionary and print it. 
    - Changes: Made exercise a method call. Made the number of times it repeats this operation an input to the method. 
- Exercise 1.4
    - Requirements: Get the average velocity of the robot after it moves, and print true to the terminal if it is less than 1 m/s.
    - Changes: Made exercise a method call. Used pointers for all variables. Made the number of times it repeats this operation an input to the method. 
- Exercise 2.1
    - Requirements: Move the robot a specified number of seconds. Limit how far it can go in the x direction. Stop it if it went beyond the limit. Mave it move backwards if it did not. 
    - Changes: Created class `Unit2Exercises`. Made exercise a method call. Used pointers for all variables. Robot moves forward or backwards until it reaches the specified x position within a specified tolerance. 
- Exercise 2.2
    - Requirements: Repeat Exercise 2.1, but with a while loop. 
    - Changes: Literally copy pasted Exercise 2.1 for organization because my version already used a while loop. 
- Exercise 2.3
    - Requirements: Make the robot move a specified number of seconds. Use the method `get_position_full` to get a list of the robot's coordinates. Use a For loop to print the list contents. 
    - Changes: Made exercise a method call.
- Exercise 3.1
    - Requirements: Make a function. Make the robot move forward for a specific number of seconds. Report the new x, y position 
    - Changes: Created class `Unit3Exercises`. Made exercise a method call.
- Exercise 3.2
    - Requirements: Make the robot move to the door using method calls to the `Rosbot` class. 
    - Changes: Made exercise a method call.
- Exercise 4.1
    - Requirements: Move the robot forward. Retrieve 2 laser index readings using `get_laser(n)` from the left and right sides. Print to terminal. 
    - Changes: Created class `Unit4Exercises`. Made exercise a method call. Used pointers for all variables. Added a while loop which runs until the robot moves a specified number of seconds. 
- Exercise 4.2
    - Requirements: Initialize an array. Call a function passing in the array. In a for loop, square the value of each array using pointer calls. 
    - Changes: Made exercise a method call. Made length of input array modifiable. 
- Exercise 4.3
    - Requirements: Print an array of 720 floats using the returned pointer from the `get_laser_full` function. 
    - Changes: Made exercise a method call. Determined the length instead of assuming it was 720. 
- Exercise 5.1
    - Requirements: Make the robot move around the wall to the left or right. Make it do this based on retrieved sensor readings. 
    - Changes: None. 
- Exercise 6.1
    - Requirements: Use everything that was learned to make the robot move towards the door based on some sensory input. 
    - Changes: Used pointers for all variables.

## Video Demonstrations
WIP.
[INSERT VIDEO 1]
[INSERT VIDEO 2]
[INSERT VIDEO 3]
