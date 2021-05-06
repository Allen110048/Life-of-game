#include "model.h"
#include "view.h"
#include "interface.h"

void interface() 
{
    while (1) {
        printf("Please input the file name: ");
        char *filename = (char *) malloc(sizeof(char));
        scanf("%s", filename);
        getchar();

        int row, column;
        row = load_array_length(filename);
        column = load_array_length(filename);
        if (row == -1 || column == -1) {
            printf("Please input again\n\n");
            free(filename);
            continue;
        }
        int cell[row][column];
        init_cell(row, column, cell, filename);

        free(filename);


        int Height = row * CSIZE;
        int Width = column * CSIZE;


        initSDLWindow(Width, Height);

        drawGrid(Width, Height, row, column, cell);


        int done = 1;
        int run = 1;
        while (done) {

            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT: {
                        done = 0;
                        break;
                    }
                    case SDL_KEYDOWN: {
                        if (event.key.keysym.sym == SDLK_SPACE)
                            run = !run;
                        break;
                    }
                }
            }
            if(run) {

                int temp_cell[row][column];
                update_cells(row, column, cell, temp_cell);


                drawGrid(Width, Height, row, column, cell);
                SDL_Delay(1000);

            }
        }
        quitAll();
        store_file(row, column, cell);
        return;
    }
}