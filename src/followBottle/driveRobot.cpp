//this FILE HAS THE CODE THAT FIGURE OUT WHICH WHEELS TO RUN

#include "followBottle.h"
#include "../constants.h"

void FollowBottle::driveRobot()
{	
	//this is the midpoit of the object box + the the left distance
	//resulting in a line in the middle of the picture that i 
	//can compare to the middle of the large full picture
	int midpointLineOfObject{
		((m_rightCord - m_leftCord) / 2) + m_leftCord
	};
	
	//you know you probably want to check if the object is closes
	//enough before you figure out how much you turn right.
	
	if ( (m_rightCord - m_leftCord) > constants::tooCloseToObject)
	{
		std::cout << "The robot has gotton too close to object"
			<< " and has stoped\n";
		forward(0);
	}


	std::cout << "The value of midpointLineOfObject = " 
		<< midpointLineOfObject << '\n';

	if ( midpointLineOfObject > constants::leftMiddleOfPicLine 
		&& midpointLineOfObject < constants::rightMiddleOfPicLine)
	{
		forward(constants::speedOfForward);
		std::cout << "The robot is going straight\n";
	}	
	else if ( midpointLineOfObject < constants::leftMiddleOfPicLine )
	{
		//heres where i need to modify

		setSpeeds(intToFloat(midpointLineOfObject, 0, constants::leftMiddleOfPicLine, 0, 1), 1);

	//	skidLeft(constants::speedOfSkidLeft);
		std::cout << "The robot stoped left wheel and is turning left.\n";
	}
	else if ( midpointLineOfObject > constants::rightMiddleOfPicLine )
	{
	//	skidRight(constants::speedOfSkidRight);
		setSpeeds(1, intToFloat(midpointLineOfObject, 1278, constants::rightMiddleOfPicLine, 0, 1));
		//std::cout << "The robot stoped right wheel and is turning right.\n";
	}
	


}
/*
 * this is what im going to do
 * so basically i am going to use a translate function to translate the width of say 0-600 with the
 * midpoint of the picture  being 500 to 0-255 which is the forward reverse of arduino 
 */
