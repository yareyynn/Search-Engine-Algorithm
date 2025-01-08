#ifndef COMPLIN_H
#define COMPLIN_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void pagerank(int size, const double **AdjacencyMatrix, double *firststatevector, int iter);
void pagerankdumping(int size, const double **AdjacencyMatrix, double *firststatevector, int iter, double dampingFactor);

#endif
