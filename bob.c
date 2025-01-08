#include "complin.h"

void pagerankdumping(int size, const double **AdjacencyMatrix, double *firststatevector, int iter, double dampingFactor)
{
    int i = 0;
    int j = 0;
    double sum;
    double **ProbabilityTransitionMatrix = (double **)calloc(size, sizeof(double *));
    for (i = 0; i < size; i++)
    {
        ProbabilityTransitionMatrix[i] = (double *)calloc(size, sizeof(double));
    }
    double *laststatevector = (double *)calloc(size, sizeof(double));           

    // Webgraph'in yakınlık matrisine göre olasılık geçiş matrisi oluşturalım.
    for (j = 0; j < size; j++)
    {
        sum = 0;
        for (i = 0; i < size; i++)
        {
            sum = sum + AdjacencyMatrix[i][j];
        }
        for (i = 0; i < size; i++)
        {
            if (sum != 0)
                ProbabilityTransitionMatrix[i][j] = (AdjacencyMatrix[i][j] / sum) * dampingFactor + (1 - dampingFactor) / size;
            else
                ProbabilityTransitionMatrix[i][j] = 1.0 / size; // Boş sütun (dead-end) durumunda her düğüme eşit olasılık dağıtılır.
        }
    }

    // Olasılık geçiş matrisini bastıralım.
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%f ", ProbabilityTransitionMatrix[i][j]);
        }
        printf("\n");
    }

    // Özvektörü bulmak için iteratif bir işlem yapalım.
    for (int k = 0; k < iter; k++)
    {
        for (i = 0; i < size; i++)
        {
            laststatevector[i] = 0;
            for (j = 0; j < size; j++)
            {
                laststatevector[i] += ProbabilityTransitionMatrix[i][j] * firststatevector[j];
            }
        }
        for (i = 0; i < size; i++)
        {
            firststatevector[i] = laststatevector[i];
        }
    }

    // Son durum matrisini bastıralım.
    for (i = 0; i < size; i++)
    {
        printf("%f\n", firststatevector[i]);
    }

    for (int i = 0; i < size; i++) 
        free(ProbabilityTransitionMatrix[i]);
    free(ProbabilityTransitionMatrix);
    free(firststatevector);
    free(laststatevector);
}
