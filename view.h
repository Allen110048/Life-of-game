#ifndef VIEW_H_
#define VIEW_H_

#include "SDL2/SDL.h"



#define CSIZE 10


//Create SDL window
int initSDLWindow(int Width, int Height);

//Draw Width * Height board
int drawGrid(int Width, int Height, int row, int column, int cell[row][column]);

//Free up the memory of the SDL tool
int quitAll();
#endif 