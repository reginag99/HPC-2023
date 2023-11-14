#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 17
#define COLS 3


int main(int argc, char *argv[])

{

    FILE *file = fopen("test_data/cells_17", "r");
    
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    double matrix[ROWS][COLS];

    // read data from the file and store it in the matrix
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fscanf(file, "%lf", &matrix[i][j]);
            }
        }

    fclose(file);

      // Print the matrix
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");}


    return 0;
    }
