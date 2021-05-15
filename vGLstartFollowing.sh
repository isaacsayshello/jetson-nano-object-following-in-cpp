#!/bin/bash
echo "starting vglrun and my-recognition"
#vglrun ./my-recognition --input-flip=rotate-180 --network=coco-bottle --input-width=1280 --input-height=720 csi://0
#vglrun ./my-recognition --input-flip=rotate-180 --network=pednet --threshold=0.1 --input-width=1280 --input-height=720 csi://0
vglrun ./my-recognition --input-flip=rotate-180 --network=facenet --threshold=0.1 --input-width=1280 --input-height=720 csi://0


