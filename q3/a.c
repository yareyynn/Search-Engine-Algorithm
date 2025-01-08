#include "../complin.h"

int main()
{
	int size = 2;
	double **AdjacencyMatrix = (double **)calloc(size, sizeof(double *));
		for (int i = 0; i < size; i++)
		{
			AdjacencyMatrix[i] = (double *)calloc(size, sizeof(double));
		}
	double *firststatevector = (double *)calloc(size, sizeof(double));

	AdjacencyMatrix[0][0] = 0;
	AdjacencyMatrix[0][1] = 1;
	AdjacencyMatrix[1][0] = 1;
	AdjacencyMatrix[1][1] = 0;
	

	firststatevector[0] = 1;
	firststatevector[1] = 0;

	pagerank(size, (const double **)AdjacencyMatrix, firststatevector, 5);

	return 0;
}
