#!/bin/bash
echo "starting and my-recognition"
echo " NOT VirtualGL"
 ./my-recognition --input-flip=rotate-180 --network=coco-bottle --input-width=1280 --input-height=720 csi://0
