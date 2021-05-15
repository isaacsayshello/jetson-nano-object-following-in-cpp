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

void FollowBottle::initI2C()
{	
    std::cout << "just entered initI2C\n";

    //int file;
    char filename[40];
    const gchar *buffer;

    int addr = 0x40;        // The I2C address of the ADC

    sprintf(filename,"/dev/i2c-0");
    if ((m_file = open(filename,O_RDWR)) < 0) {
        printf("Failed to open the bus.");
        /* ERROR HANDLING; you can check errno to see what went wrong */
    }


    if (ioctl(m_file,I2C_SLAVE,addr) < 0) {
        printf("Failed to acquire bus access and/or talk to slave.\n");
        /* ERROR HANDLING; you can check errno to see what went wrong */
    }
 
    std::cout << "Just left initI2C\n";
}	
