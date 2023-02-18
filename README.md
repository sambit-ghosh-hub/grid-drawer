# C++ based OpenGL renderer

## Intution

This is a 2D renderer which renders custom sized pixels on a canvas surface. The program uses the Simple Directmedia Layer(SDL) library to implement the OpenGL APIs. The renderer has the ability to let the user draw pixel arts in 4 colours (with the ability to blend them for more colours) and allows them to save the creation in a .bmp file named 'Screenshot.bmp' when clearing the screen. It can also generate pixels in random colours in random co-ordinates. 

### Features included so far(More to be added in near future)

- Generate pixels in random colours
- Pixel draw in four colours (provision to add more to palette)
- Save canvas to a .bmp file
- One click erase and draw pixel
- Customized pixel size (change in griddrw.cpp, need to re-build project)
- Blend primary colours to get compound colors (Alpha can be adjusted in griddraw.cpp, need to re-build project)

## Files' description

1. custom.h - Custom header file to define extern functions and variables.
2. window.cpp - The main file to handle SDL events APIs and canvas window.
3. griddraw.cpp - The file to calculate and draw custom pixels based on cluster co-ordinates.
4. build.sh - Shell script of one click compilation.
5. SDL2.dll - The Dynamic-link Library file of SDL2 lib. 

## Compile Instruction

1. Compile the griddraw.cpp to make it's object file

 `g++ -g -c griddraw.cpp -I<include directory path> -L<lib directory path> -Wall -lmingw32 -lSDL2main -lSDL2`

2.Compile the main window.cpp file to create the output file

 `g++ window.cpp griddraw.o -I<include directory path> -L<lib directory path> -Wall -lmingw32 -lSDL2main -lSDL2 -o ../output`
