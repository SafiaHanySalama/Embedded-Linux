#!bin/bash
mkdir DynamicLibrary_Lab
cd DynamicLibrary_Lab/
mkdir Lib Include
touch main.c
cd Include 
touch add.h sub.h mul.h mod.h div.h
#gedit add.h sub.h mul.h mod.h div.h
cd ..
cd Lib
touch add.c sub.c mul.c mod.c div.c
#gedit add.c sub.c mul.c mod.c div.c
gcc -c -g -Wall -fPIC add.c
gcc -c -g -Wall -fPIC sub.c
gcc -c -g -Wall -fPIC mul.c
gcc -c -g -Wall -fPIC mod.c
gcc -c -g -Wall -fPIC div.c
gcc -shared -o libdynamic.so add.o sub.o mul.o mod.o div.o
cd ..
gcc main.c -L./Lib -ldynamic -o calc -I./Include
export LD_LIBRARY_PATH=:/home/safia/embedded_linux/DynamicLibrary_Lab/Lib
./calc

