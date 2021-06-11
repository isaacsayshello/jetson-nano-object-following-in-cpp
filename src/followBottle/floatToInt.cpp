//this file translates a float value range into an int range used to run the arduino.
//example: -1, 1 to 0, 255
#include <iostream>
#include "followBottle.h"


int FollowBottle::floatToInt(float value, 
	float leftMin, float leftMax, 
	int rightMin, int rightMax)
{
    // Figure out how 'wide' each range is
    float leftSpan = leftMax - leftMin;
    float rightSpan = rightMax - rightMin;

    // Convert the left range into a 0-1 range (float)
    float valueScaled = (value - leftMin) / leftSpan;

    // Convert the 0-1 range into a value in the right range.
    return rightMin + (valueScaled * rightSpan);


	
}

