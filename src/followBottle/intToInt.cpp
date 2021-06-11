#include "followBottle.h"


int FollowBottle::intToInt(int value, 
	int leftMin, int leftMax, 
	int rightMin, int rightMax)
{

    // Figure out how 'wide' each range is
    int leftSpan = leftMax - leftMin;
    int rightSpan = rightMax - rightMin;

    // Convert the left range into a 0-1 range (float)
    float valueScaled = (static_cast<float>(value - leftMin)) / static_cast<float>(leftSpan);

    // Convert the 0-1 range into a value in the right range.
    return rightMin + (valueScaled * rightSpan);
	
}
