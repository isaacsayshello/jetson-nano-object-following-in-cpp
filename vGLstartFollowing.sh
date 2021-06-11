#!/bin/bash
echo "starting vglrun and my-recognition"


#if you want to try a different network or change perimiters then i would recommend that you 
#make copys of the command below and then just uncommit the one that you want to use.



#vglrun ./my-recognition --input-flip=rotate-180 --network=multiped --input-width=1280 --input-height=720 csi://0
#vglrun ./my-recognition --input-flip=rotate-180 --network=pednet --threshold=0.1 --input-width=1280 --input-height=720 csi://0
#vglrun ./my-recognition --input-flip=rotate-180 --network=facenet --threshold=0.1 --input-width=1280 --input-height=720 csi://0

#using the default person recontion
vglrun ./my-recognition --input-flip=rotate-180 --input-width=1280 --input-height=720 csi://0




