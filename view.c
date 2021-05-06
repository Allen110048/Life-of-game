#include "view.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int initSDLWindow(int Width, int Height)
{
	if (SDL_Init(SDL_INIT_VIDEO) == 0)
	{
		if (SDL_CreateWindowAndRenderer(Width+1, Height+1,
				0, &window, &renderer) == 0)
		{
			SDL_SetWindowTitle(window, "Game Of Life in Medeniyet");
		}

	}
}

int drawGrid(int Width, int Height, int row, int column, int cell[row][column])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			SDL_Rect rect = {CSIZE*j,CSIZE*(i),CSIZE*(j+1),CSIZE*(i+1)};
			if (cell[i][j] == 0)
			{
				/*change color to dead*/
				SDL_SetRenderDrawColor(renderer, 0,0,0, SDL_ALPHA_OPAQUE);
			}
			else
			{
				/*change color to alive*/
				SDL_SetRenderDrawColor(renderer, 255, 165,0, SDL_ALPHA_OPAQUE);

			}
			/*draw cell with the determined color*/
			SDL_RenderFillRect(renderer,&rect);
		}
	}

	/* draw lines for grid */
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	/*draw horizontal*/
	for (int x = 0; x <= Width; x = x+CSIZE){
		SDL_RenderDrawLine(renderer,0, x, Width, x);
	}
	/* draw vertical */
	for (int y = 0; y <= Height; y = y+CSIZE){
		SDL_RenderDrawLine(renderer,y,0, y, Height);
	}


	SDL_RenderPresent(renderer);
	return 0;
}

int quitAll(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

	return 0;
}

