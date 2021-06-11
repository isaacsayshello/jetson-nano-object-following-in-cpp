#ifndef CONSTANTS_H
#define CONSTANTS_H
//were my constants things that i have to tune live
namespace constants
{
	//this is from the left side of the picture
	//starting at 0 and going to the right side at 1280
	//basically you have the middle of the picture and where the computer decides if the middle of the picture is too far left or right is to far right.
	//so if the middle of the picture is left of the leftMiddleOfPicLine then we know that we need to turn right to get going straight again.
	inline constexpr int leftMiddleOfPicLine{ 590 };
	//basically the farther away the middle line of our box is 
	//from the middle of the picture.
	//The faster the wheels move to get back going straight.
	//but the middle line will never accually get to 0 or 1280 
	//because most of the object needs to be seen for it to detect 
	//it and it won't detect the object if it is on the very far 
	//side.
	//so we have the leftLeftMiddleOfPicLine to define where the 
	//edge of the "picture" is so it can travel the entire range 
	//of wheel speeds.
	inline constexpr int leftLeftMiddleOfPicLine{ 300 };	
	inline constexpr int rightMiddleOfPicLine{ 690 };
	inline constexpr int rightRightMiddleOfPicLine{ 980 };



	//i wrote this code below awhile ago and i am not sure what this number is for exactly but
	//i think it is the width of the box
	//if the box width exeds this width then it will stop
	inline constexpr int tooCloseToObject{ 300 };

	//this is a value from -1 to 1
	inline constexpr float speedOfSkidRight{ 1 };	
	inline constexpr float speedOfSkidLeft{ 1 };	
	inline constexpr float speedOfForward{ 1 };	

	

}




#endif
