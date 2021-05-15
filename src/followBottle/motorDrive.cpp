#include <iostream>
#include <glib.h>
#include <glib/gprintf.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>


#include "followBottle.h"


//THIS FILE HAS THE FUNCIONS THAT ACCUALLY MOVE THE WHEELS

//********************FOWARD********
void FollowBottle::forward(float speed)
{
        
    int temp{ floatToInt(speed, -1, 1, 0, 255) };

    char buf[2] = {0};
//buf[0] is left side
//buf[1] is right side
    buf[0] = temp;
    buf[1] = temp;

   //this writes to the arduino 
    if (write(m_file, buf, 2) != 2 ){
        //  ERROR HANDLING: i2c transaction failed  /
        printf("Failed to write to the i2c bus.\n");
       // buffer = g_strerror(errno);
//        printf(buffer);
        printf("\n\n");

    }
 

}
//*****************BACKWARD******************
void FollowBottle::backward(float speed)
{
	forward(-speed);
}

//**********************RIGHT***************

void FollowBottle::right(float speed)
{
        
    //floatToInt(speed, -1, 1, 0, 255);

    char buf[2] = {0};
//buf[0] is left side
//buf[1] is right side
    buf[0] = floatToInt(speed, -1, 1, 0, 255);
    buf[1] = floatToInt(speed, 1, -1, 0, 255);
   // buf[1] = 127;

   //this writes to the arduino 
    if (write(m_file, buf, 2) != 2 ){
        //  ERROR HANDLING: i2c transaction failed  /
        printf("Failed to write to the i2c bus.\n");
       // buffer = g_strerror(errno);
//        printf(buffer);
        printf("\n\n");

    }
 

}


//**********************LEFT***************

void FollowBottle::left(float speed)
{
        

    char buf[2] = {0};
//buf[0] is left side
//buf[1] is right side
    buf[0] = floatToInt(speed, 1, -1, 0, 255);
    //buf[0] = 127;
    buf[1] = floatToInt(speed, -1,  1, 0, 255);

   //this writes to the arduino 
    if (write(m_file, buf, 2) != 2 ){
        //  ERROR HANDLING: i2c transaction failed  /
        printf("Failed to write to the i2c bus.\n");
       // buffer = g_strerror(errno);
//        printf(buffer);
        printf("\n\n");

    }
 

}


//**********************SKID_LEFT***************

void FollowBottle::skidLeft(float speed)
{
        

    char buf[2] = {0};
//buf[0] is left side
//buf[1] is right side
   // buf[0] = floatToInt(speed, 1, -1, 0, 255);
    buf[0] = 127;
    buf[1] = floatToInt(speed, -1,  1, 0, 255);

   //this writes to the arduino 
    if (write(m_file, buf, 2) != 2 ){
        //  ERROR HANDLING: i2c transaction failed  /
        printf("Failed to write to the i2c bus.\n");
       // buffer = g_strerror(errno);
//        printf(buffer);
        printf("\n\n");

    }
 

}


//**********************SKID_RIGHT***************

void FollowBottle::skidRight(float speed)
{
        

    char buf[2] = {0};
//buf[0] is left side
//buf[1] is right side
    buf[0] = floatToInt(speed, 1, -1, 255, 0);
    buf[1] = 127;
   // buf[1] = floatToInt(speed, -1,  1, 0, 255);

   //this writes to the arduino 
    if (write(m_file, buf, 2) != 2 ){
        //  ERROR HANDLING: i2c transaction failed  /
        printf("Failed to write to the i2c bus.\n");
       // buffer = g_strerror(errno);
//        printf(buffer);
        printf("\n\n");

    }
 

}


