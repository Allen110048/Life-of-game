//
// Created by baiyu on 2021/5/6.
//
#include "unity.h"
#include "unity_internals.h"
#include "model.h"

void test_load_array_length()
{
    printf("Function: int load_array_length (char *filename)\n");
    printf("Please enter the filename: ");
    char *filename = (char*)malloc(sizeof(char));
    scanf("%s", filename);
    getchar();
    int judgement = load_array_length(filename);
    free(filename);
    TEST_ASSERT_FALSE_MESSAGE(judgement == -1, "File is not existed");
}

void test_get_neighbours()
{
    printf("Function: int get_neighbours( int x, int y, int row, int column, int cell[row][column])\n");
    printf("Please enter the cell file name: ");
    char *filename = (char*) malloc(sizeof(char));
    scanf("%s", filename);
    getchar();
    int row, column;
    row = load_array_length(filename);
    column = load_array_length(filename);
    int cell[row][column];
    init_cell(row, column, cell, filename);
    free(filename);
    printf("Please input the cell location(x y): ");
    int x, y;
    scanf("%d %d",&x, &y);
    getchar();
    int judgement = get_neighbours(x, y, row, column, cell);
    TEST_ASSERT_FALSE_MESSAGE(judgement == -1, "location out of range");
}

void test_load_file()
{
    printf("Function: int load_file(int row, int column, int cell[row][column], char *filename)\n");
    printf("Please enter the cell file name: ");
    char *filename = (char*)malloc(sizeof(char));
    scanf("%s", filename);
    getchar();
    int row, column;
    row = load_array_length(filename);
    column = load_array_length(filename);
    int cell[row][column];
    int judgement = load_file(row, column, cell, filename);
    free(filename);
    TEST_ASSERT_FALSE_MESSAGE(judgement == -1, "File is not exist");
}

void setUp(){

}
void tearDown(){

}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_load_array_length);
    RUN_TEST(test_get_neighbours);
    RUN_TEST(test_load_file);


    return UNITY_END();
}
