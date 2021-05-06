#include "model.h"

int load_array_length (char *filename)
{
    FILE *file;
    file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("Error!\n");
        return -1;
    }
    int length;
    fscanf(file, "%d", &length);
    fclose(file);
    return length;
}
int init_cell(int row, int column, int cell[row][column], char *filename)
{

    for (int x=0 ; x<row ; x++)
    {
        for (int y=0 ; y<column ; y++ )
        {
            cell[x][y] = 0;
        }
    }
    load_file(row, column, cell, filename);
    return 0;
}
int load_file(int row, int column, int cell[row][column], char *filename)
{
    FILE *file;
    file = fopen(filename, "r");
    if(file == NULL)
    {
        return -1;
    }
    int x, y, temp;
    int row_temp, column_temp;
    fscanf(file, "%d %d", &row_temp, &column_temp);
    fscanf(file, "%d %d", &x, &y);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(i == x && j == y)
            {
                fscanf(file, "%d", &(cell[x][y]));
                temp = fscanf(file, "%d %d", &x, &y);
                if(temp == EOF)
                {
                    fclose(file);
                    return 1;
                }
            }
        }
    }
}
void store_file(int row, int column, int cell[row][column])
{
    FILE *file;
    printf("The file will be saved.\n");
    printf("Please input the file name: ");
    char *filename = (char*)malloc(sizeof(char));
    scanf("%s", filename);
    getchar();
    file = fopen(filename, "w");
    fprintf(file, "%d %d\n", row, column);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(cell[i][j] == 1)
                fprintf(file, "%d %d\n%d\n", i, j, cell[i][j]);
        }
    }
    fclose(file);
    free(filename);
}

int get_neighbours(int x, int y, int row, int column, int cell[row][column])
{
    if(x < 0 || x >= row || y < 0 || y >= column)
    {
        return -1;
    }
    int neighbors = 0 ;
    for(int i=x-1 ; i<=x+1 ; i++)
    {
        for(int j=y-1 ; j<=y+1 ; j++)
        {
            if( (i != x || j != y) && (i >= 0 && i < row && j >= 0 && j < column) &&(x >= 0 && x < row && y >= 0 && y < column))
            {
                if(cell[i][j]==1)
                {
                    neighbors++;
                }

            }

        }


    }
    return neighbors;
}

void update_cells(int row, int column, int cell[row][column], int temp_cell[row][column])
{
    copy_cell(row, column, cell, temp_cell);
    for(int x = 0; x < row; x++)
    {
        for(int y = 0; y < column; y++)
        {
            int neighbours = get_neighbours(x, y, row, column, cell);
            if(cell[x][y] == 1 && (neighbours < 2 || neighbours > 3))
            {
                temp_cell[x][y] = 0;
            }
            if(cell[x][y] == 0 && neighbours == 3)
            {
                temp_cell[x][y] = 1;
            }
        }
    }
    copy_cell(row, column, temp_cell, cell);
}

void copy_cell(int row, int column, int former[row][column], int latter[row][column])
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            latter[i][j] = former[i][j];
        }
    }
}
	
	





















