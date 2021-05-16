#!/bin/bash
echo "starting and my-recognition"
echo " NOT VirtualGL"

#if you want to try a different network or change perimiters then i would recommend that you 
#make copys of the command below and then just uncommit the one that you want to use.

#using the bottle network
#./my-recognition --input-flip=rotate-180 --network=coco-bottle --input-width=1280 --input-height=720 csi://0
#using the person recognition
./my-recognition --input-flip=rotate-180 --input-width=1280 --input-height=720 csi://0

