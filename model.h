#ifndef MODEL_H_
#define MODEL_H_

#include <stdio.h>
#include <malloc.h>

//Initialize cell array
int init_cell(int row, int column, int cell[row][column], char *filename);

//Game of Life rule Function
void update_cells(int row, int column, int cell[row][column], int temp_cell[row][column]);

//Assign the array of the former to the latter
void copy_cell(int row, int column, int former[row][column], int latter[row][column]);

//Get the status of the surrounding eight cells
int get_neighbours(int x, int y, int row, int column, int cell[row][column]);

//Store the final state array in a file
void store_file(int row, int column, int cell[row][column]);

//Get the length of the array in the file
int load_array_length (char *filename);

//Get the status of living cells in the file
int load_file(int row, int column, int cell[row][column], char *filename);


#endif
