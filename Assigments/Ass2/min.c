#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <ctype.h>
#include <math.h>

void dist(float *distance, float x_1, float x_2, float y_1, float y_2, float z_1, float z_2)
{
    *distance = sqrt((x_2 - x_1) * (x_2 - x_1) + (y_2 - y_1) * (y_2 - y_1) + (z_2 - z_1) * (z_2 - z_1));
    printf("%f\n",*distance);
}

int main(int argc, char *argv[])
{
    int numberRow = 10;
    int numberCol = 3, numThreads;

    if (argc < 2)
    {
        printf("Usage: %s -t[INTEGER]\n", argv[0]);
        return EXIT_FAILURE;
    }

    int argLength = strlen(argv[1]);

    if (argv[1][0] == '-' && argv[1][1] == 't' && argLength > 2)
    {
        numThreads = atoi(&argv[1][2]);
        if (numThreads <= 0)
        {
            printf("Invalid thread count. Please provide a positive integer.\n");
            return EXIT_FAILURE;
        }
    }
    else
    {
        printf("Wrong format for argument. Use format -t[INTEGER], where [INTEGER] must be a valid whole number larger than 0.\n");
        return EXIT_FAILURE;
    }

    printf("Number of threads: %d\n", numThreads);

    // Allocate memory for matrix
    float *matrixEntries = (float *)malloc(sizeof(float) * numberRow * numberCol);
    float **matrix = (float **)malloc(sizeof(float *) * numberRow);

    for (int ix = 0, jx = 0; ix < numberRow; ++ix, jx += numberCol)
        matrix[ix] = matrixEntries + jx;

    FILE *file = fopen("test_data/test_data", "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return EXIT_FAILURE;
    }

    for (int ix = 0; ix < numberRow; ix++)
    {
        for (int jx = 0; jx < numberCol; jx++)
        {
            fscanf(file, "%f", &matrix[ix][jx]);
        }
    }

    fclose(file);

    // Calculate distances
    int n = numberRow * (numberRow - 1) / 2;
    float *distance = (float *)malloc(sizeof(float) * n);

    int distance_index = 0;
    for (int ix = 0; ix < numberRow; ix++)
    {
        for (int k = ix + 1; k < numberRow; k++)
        {
            dist(&distance[distance_index], matrix[ix][0], matrix[k][0], matrix[ix][1], matrix[k][1], matrix[ix][2], matrix[k][2]);
            distance_index++;
        }
    }


for( int ix = 0; ix < n; ++ix)
    {
        for(int jx = ix + 1; jx < n; ++jx)
        { if(distanceMatrix[ix]> distanceMatrix[jx])
            {
                temp = distanceMatrix[ix];
                distanceMatrix[ix] = distanceMatrix[jx];
                distanceMatrix[jx] = temp;
            }
        }
    }

for (int ix = 0 ; ix < n; ++ix)
    printf("%f\n",distanceMatrix[ix]);




    /*
float ** matrixCountEntris = (float*)malloc(sizeof(float) * 2);
float **matrixCount = (float **)malloc(sizeof(float *));
for (size_t ix = 0, jx = 0; ix)

int *controll;

for (i = 0; i<n; i++){
	for (c = 0;c<stril(count); c++)
		{
		if 
		}
	}
*/

    // Free allocated memory
    free(matrix);
    free(matrixEntries);
    free(distance);

    return 0;
}
