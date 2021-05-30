#ifndef CONSTANTS_H
#define CONSTANTS_H
//were my constants things that i have to tune live
namespace constants
{
	//this is from the left side of the picture
	//starting at 0 and going to the right side at 1280
	inline constexpr int leftMiddleOfPicLine{ 590 };
	inline constexpr int rightMiddleOfPicLine{ 690 };
	//i wrote this code below awhile ago and i am not sure what this number is for exactly but
	//i think it is the width of the box
	inline constexpr int tooCloseToObject{ 300 };

	//this is a value from -1 to 1
	inline constexpr float speedOfSkidRight{ 1 };	
	inline constexpr float speedOfSkidLeft{ 1 };	
	inline constexpr float speedOfForward{ 1 };	

}




#endif
