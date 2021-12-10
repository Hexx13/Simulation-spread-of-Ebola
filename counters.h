#include <stdio.h>
#include <stdlib.h>
int row = 10;
int col = 10;

int count_infect_total_cell(char a[row][col], int r, int c);
int count_infect_vector_cell(char a[row][col], int r, int c);
int count_infect_neighbor_cell(char a[row][col], int r, int c);
int count_dead_total_cell(char a[row][col], int r, int c);
int count_cells(char a[row][col], int r, int c);