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
		<< midpointLineOfObject;

	if ( midpointLineOfObject > constants::leftMiddleOfPicLine 
		&& midpointLineOfObject < constants::rightMiddleOfPicLine)
	{
		forward(1);
		std::cout << "The robot is going straight\n";
	}	
	else if ( midpointLineOfObject < constants::leftMiddleOfPicLine )
	{
		skidLeft(0.75);
		std::cout << "The robot stoped left wheel and is turning left.\n";
	}
	else if ( midpointLineOfObject > constants::rightMiddleOfPicLine )
	{
		skidRight(0.75);
		std::cout << "The robot stoped right wheel and is turning right.\n";
	}


}
