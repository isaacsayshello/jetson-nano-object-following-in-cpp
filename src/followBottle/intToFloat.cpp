//THIS FUNCTION TRANSLATES INTS TO FLOATS

#include <iostream>
#include "followBottle.h"

float FollowBottle::intToFloat(int value, int leftMin, int leftMax, 
	float rightMin, float rightMax)
{

    // Figure out how 'wide' each range is
    int leftSpan = leftMax - leftMin;
    float rightSpan = rightMax - rightMin;

    // Convert the left range into a 0-1 range (float)
    //float valueScaled = (value - leftMin) / leftSpan;
    float valueScaled = (static_cast<float>(value - leftMin)) 
	    / static_cast<float>(leftSpan);



    // Convert the 0-1 range into a value in the right range.
    return rightMin + (valueScaled * rightSpan);


}	
	
