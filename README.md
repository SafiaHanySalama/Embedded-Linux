
## Commands for Dynamic Library

Create Directory
```http
  mkdir DynamicLibrary_Lab
```
inside the directory create Lib and Include directories and your main.c file
```http
  cd DynamicLibrary_Lab/
  mkdir Lib Include
  touch main.c
```
inside Include directory create your files.h then open it to add functions prototype

```http
  cd Include 
  touch add.h sub.h mul.h mod.h div.h
  gedit add.h sub.h mul.h mod.h div.h
```
inside Lib directory create your files.c then open it to add functions definition

```http
  cd Lib
  touch add.c sub.c mul.c mod.c div.c
  gedit add.c sub.c mul.c mod.c div.c
```
Create object files for each file.c 
```http
  gcc -c -g -Wall -fPIC add.c
  gcc -c -g -Wall -fPIC sub.c
  gcc -c -g -Wall -fPIC mul.c
  gcc -c -g -Wall -fPIC mod.c
  gcc -c -g -Wall -fPIC div.c
```
### Note:
 The -fPIC flag ensures that the code is position-independent. This means it wouldn’t matter where the computer loads the code into memory. The -c options just ensure that each .o object file isn’t linked yet.

Create a Dynamic Library from this object code
```http
  gcc -shared -o libdynamic.so add.o sub.o mul.o mod.o div.o
```
Link our Dynamic Library to our main executable file
```http
  cd ..
  gcc main.c -L./Lib -ldynamic -o calc -I./Include
```
Set the Dynamic Library path (Use your own path)
```http
 export LD_LIBRARY_PATH=:/home/safia/embedded_linux/DynamicLibrary_Lab/Lib
```
Excute the program
```http
 ./calc
```
Use these commands to ensure that your library is dynamically linked
```http
 file calc
 ldd calc
```
Create Objdump file to see the symbol table (It must have UND for function calls) 
```http
  objdump -T calc > dynamic.objdump
```

## Commands for Static Library

Creat Directories and files as previous in Dynamic

Create object files for each file.c 
```http
  gcc -c add.c sub.c mul.c mod.c div.c
```
Create a Static Library from this object codes
```http
  ar -rcs libstatic.a add.o sub.o mul.o mod.o div.o
```
### Note:

r -> replace or insert file to archive

c ->create new archive

s -> add symbol table to archive

Link the static library with main in calc excutable file
```http
  gcc main.c -lstatic -o calc.exe -I ./Include -L ./Lib
```
Use same commands as previous to check the symbol table
