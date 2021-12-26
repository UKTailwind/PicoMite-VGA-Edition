# PicoMite-VGA-Edition

PicoMiteVGA V5.07.03b3

This repository contains the files needed to build the PicoMite VGA Edition

Use all the files from the PicoMite repository with the exception of 
gui.c, 
gui.h, 
touch.c, 
touch.h, 
and CMakeLists.txt

Then build with the two additional files here and the VGA version of the CMakeLists.txt build file

Special thanks to Miroslav Nemecek for the code used as the basis of the 320x240 16colour and 640x480 monochrome VGA drivers. This runs exclusively on the second processor and has little of no impact on MMbasic performance.

