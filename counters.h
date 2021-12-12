#include <stdio.h>
#include <stdlib.h>

int count_infect_total_cell(int rc, char a[rc][rc], int *r, int *c);
int count_infect_vector_cell(int rc  ,char a[rc][rc], int *r, int *c);
int count_infect_neighbor_cell(int rc  ,char a[rc][rc], int *r, int *c);
int count_dead_total_cell(int rc  ,char a[rc][rc], int *r, int *c);
int count_cells(int rc, int *r, int *c);
