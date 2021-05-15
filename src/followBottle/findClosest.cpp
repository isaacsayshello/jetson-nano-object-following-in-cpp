#include "followBottle.h"



void FollowBottle::findClosest(detectNet::Detection* detections, const int numDetections) 
{
	int indexOfClosest{};
	std::cout << " HI FROM FOLLOW BOTTLE";
	//std::cout << " left: " << detections[0].Left << " Right: " << detections[0].Right << '\n'; 
	//getting all of the detections
	for (int xxx{}; xxx < numDetections; ++xxx)
	{
		int tempWidthOfPic{ static_cast<int>(detections[xxx].Right 
			- detections[xxx].Left) };

		if ( (detections[indexOfClosest].Right 
			- detections[indexOfClosest].Left) 
			< tempWidthOfPic)
		{
		//	m_closestBottleIndex == indexOfCurrentClosest;
			indexOfClosest = xxx;
		}
	}
	std::cout << "index of Closest: " << indexOfClosest << '\n';


	m_leftCord = detections[indexOfClosest].Left;	
	m_rightCord = detections[indexOfClosest].Right;
   	
}


/*
sorry just how it copyed not going to fix it.
std::cout << "\nindex of 0, size == " << detections[0].Right 
                  - detections[0].Left << '\n';   
   
            std::cout << "\nindex of 1, size == " << detections[1].Right 
                     - detections[1].Left << '\n';   
      
               std::cout << "\nindex of 2, size == " << detections[2].Right 
                        - detections[2].Left << '\n';   
         
	          std::cout << "\nindex of 3, size == " << detections[3].Right 
	                   - detections[3].Left << '\n';   
	            std::cout << "This is what the largest one is " 
	                     << detections[m_closestBottleIndex].Right 
	                      - detections[m_closestBottleIndex].Left << '\n';

 * --------------------------------------
 * so we need to find the closest one
 * start by finding width of pic one
 * put its index in the indexOfCurrentClosest 
 * if 1 is bigger than 2 
 * 	keep 1 as biggest 
 * if 1 is smaller than 2
 * 	put 2 as biggest
 * keep repeating until end 
 * what is in the m_closestBottleIndex is the biggest in the end.
 * */ 
