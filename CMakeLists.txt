# require CMake 2.8 or greater
cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 17)

# declare my-recognition project
project(my-recognition)

# import jetson-inference and jetson-utils packages.
# note that if you didn't do "sudo make install"
# while building jetson-inference, this will error.
find_package(jetson-utils)
find_package(jetson-inference)

# CUDA is required
find_package(CUDA)


# compile the my-recognition program
cuda_add_executable(my-recognition 
	./src/detectnet.cpp
	./src/everyThingIDontWantToDealWith.h
	./src/constants.h

	./src/followBottle/followBottle.h
	./src/followBottle/findClosest.cpp
	./src/followBottle/driveRobot.cpp
	./src/followBottle/initI2C.cpp
	./src/followBottle/motorDrive.cpp
	./src/followBottle/floatToInt.cpp
	./src/followBottle/intToInt.cpp
	./src/followBottle/intToFloat.cpp


	)

target_compile_options(my-recognition PUBLIC -I/usr/include/glib-2.0 -I/usr/lib/aarch64-linux-gnu/glib-2.0/include -lglib-2.0)




# link my-recognition to jetson-inference library
target_link_libraries(my-recognition jetson-inference)
