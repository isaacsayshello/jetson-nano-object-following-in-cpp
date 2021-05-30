#ifndef FOLLOW_BOTTLE_H
#define FOLLOW_BOTTLE_H

#include <iostream>


#include "jetson-inference/detectNet.h"
#include "jetson-utils/videoSource.h"
#include "jetson-utils/videoOutput.h"


class FollowBottle
{
private:
	//contains the left cord of the closest object 
	int m_leftCord{}; 
	int m_rightCord{}; //same as above only on right.
	//this is a pointer to the network that was created before
	//the processing loop
	detectNet* m_net; 
	//file for the i2c
	int m_file{};

	
			
public:
	FollowBottle(detectNet* net)
		: m_net{ net }
	{
	}
	// finds the closest bottle so we arn't working with something in the distance
	void findClosest(detectNet::Detection* detections, 
	    const int numDetections);

	//translates ints to ints.
	int intToInt(int value, int leftMin, int leftMax, int rightMin, int rightMax);
	//translates a speed of say -1, to 1 to 0 to 255 
	//which is what arduino wants
	//can also translate any float to int range 
	int floatToInt(float value, float leftMin, 
		float leftMax, int rightMin, int rightMax);
	//this one translates ints into float values
	float intToFloat(int value, int leftMin, 
		int leftMax, float rightMin, float rightMax);
	


	//find out which wheel to stop
	void driveRobot();
	//find out if we have gotton close enough	
	
	//this establishes communication to arduino	
	void initI2C();
	
	//this is the functions that drive the robot
	//speed should be from -1 to 1; 0 being stop
	void forward(float speed);
	void backward(float speed);
	void left(float speed);
	void right(float speed);
	//skid ones only turn on one wheel and leave the other one off
	void skidLeft(float speed);
	void skidRight(float speed);
	void setSpeeds(float speed1, float speed2);
	
 

};


#endif
