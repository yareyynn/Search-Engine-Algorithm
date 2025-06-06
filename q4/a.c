#include "../complin.h"

int main()
{
	int size = 5;
	double **AdjacencyMatrix = (double **)calloc(size, sizeof(double *));
		for (int i = 0; i < size; i++)
		{
			AdjacencyMatrix[i] = (double *)calloc(size, sizeof(double));
		}
	double *firststatevector = (double *)calloc(size, sizeof(double));

	AdjacencyMatrix[0][0] = 0;
	AdjacencyMatrix[0][1] = 1;
	AdjacencyMatrix[0][2] = 1;
	AdjacencyMatrix[0][3] = 1;
	AdjacencyMatrix[0][4] = 1;
	AdjacencyMatrix[1][0] = 1;
	AdjacencyMatrix[1][1] = 0;
	AdjacencyMatrix[1][2] = 1;
	AdjacencyMatrix[1][3] = 0;
	AdjacencyMatrix[1][4] = 0;
	AdjacencyMatrix[2][0] = 0;
	AdjacencyMatrix[2][1] = 1;
	AdjacencyMatrix[2][2] = 0;
	AdjacencyMatrix[2][3] = 1;
	AdjacencyMatrix[2][4] = 0;
	AdjacencyMatrix[3][0] = 0;
	AdjacencyMatrix[3][1] = 0;
	AdjacencyMatrix[3][2] = 1;
	AdjacencyMatrix[3][3] = 0;
	AdjacencyMatrix[3][4] = 1;
	AdjacencyMatrix[4][0] = 0;
	AdjacencyMatrix[4][1] = 0;
	AdjacencyMatrix[4][2] = 0;
	AdjacencyMatrix[4][3] = 1;
	AdjacencyMatrix[4][4] = 0;
	

	firststatevector[0] = 1.0/5.0;
	firststatevector[1] = 1.0/5.0;
	firststatevector[2] = 1.0/5.0;
	firststatevector[3] = 1.0/5.0;
	firststatevector[4] = 1.0/5.0;

	pagerank(size, (const double **)AdjacencyMatrix, firststatevector, 15);

	return 0;
}
