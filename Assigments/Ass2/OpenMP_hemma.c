#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <omp.h> // Make sure to include the header for OpenMP if you intend to use it

int compare(const void *a, const void *b);

int main(int argc, char *argv[]) {
    int numberRow = 10;
    int box_size = 1000;
    int numberBoxes = (numberRow + box_size - 1) / box_size; // Calculate the number of boxes
    int sizeDistanceMatrix = (numberRow * (numberRow - 1)) / 2;
    int *distanceMatrix = (int *)malloc(sizeof(int) * sizeDistanceMatrix);
    int numberCol = 3, numThreads;
    int argLength = strlen(argv[1]);

    if (argv[1][0] == '-' && argv[1][1] == 't' && argLength > 2) {
        numThreads = atoi(&argv[1][2]);
    } else {
        printf("wrong format for argument. use format -t[integer], where [integer] must be a valid whole number larger than 0.");
        exit(EXIT_FAILURE);
    }

    if (numThreads == 0) {
        printf("integer must be a valid whole number larger than 0.");
        exit(EXIT_FAILURE);
    }

    printf("number of threads: %d\n", numThreads);

    // allocate memory for matrix 1

    float *matrixentries1 = (float *)malloc(sizeof(float) * box_size * numberCol);
    float **matrix1 = (float **)malloc(sizeof(float *) * box_size);

    for (size_t ix = 0; ix < box_size; ++ix)
    	matrix1[ix] = matrixentries1 + ix * numberCol;

    // allocate memory for matrix 2
    float *matrixentries2 = (float *)malloc(sizeof(float) * box_size * numberCol);
    float **matrix2 = (float **)malloc(sizeof(float *) * box_size);

    for (size_t ix = 0; ix < box_size; ++ix)
    	matrix2[ix] = matrixentries2 + ix * numberCol;

    FILE *file = fopen("test_data/test_data", "rb"); // open the file in binary mode

    if (file == NULL) {
        printf("error opening file.\n");
        return -1;
    }

//int sizedistancematrix = (numberrow*(numberrow-1)/2);
//int * distancematrix =  (int*) malloc(sizeof(int) * sizedistancematrix);

    if (numberRow > 1000) {
 /*       for (size_t b = 0; b < numberBoxes; ++b) {
	    for (int ix = b*1000; ix < numberRow; ix++)
		if( b*1000<numberRow)
		     box_size = numberRow-b*1000;

     		for (int jx = 0; jx < numberCol; jx++)
    	 		{
			long start1 = sizeof(float)*numberCol*(1000-1)*b;
			fseek(file,start1,SEEK_SET);
			for (int i = 0; i < box_size; i++){
			//	for (int j = 0; i < numberCol; j++)
				
				char *row1 = (char *)malloc(sizeof(char) * numberCol);
				if (fread(row1, sizeof(float), numberCol, file) != numberCol) {
				    printf("Error when reading row");
				}		
				for (int j = 0; j < numberCol; j++) {
  				  char *token1 = strtok(row1, "+-");
				    if (token1 != NULL) {
			        	matrix1[i][j] = (float)atof(token1);
 			       // Move to the next token
			       free(row1);
 				   }
				
				}
			}
				
			double distance, x1, x2, y1, y2, z1, z2;
			int element = 0;

			for (int ix = 0 ; ix < (box_size - 1) ; ++ix)
			   {
 		  	        x1 = matrix1[ix][0];
			        y1 = matrix1[ix][1];
			        z1 = matrix1[ix][2];
			    for (int jx = ix + 1; jx < box_size; ++jx )
			        {
			        x2 = matrix1[jx][0];
			        y2 = matrix1[jx][1];
			        z2 = matrix1[jx][2];

			        distance = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
			        distanceMatrix[element] = (float)(distance*100+0.5)/100;
			        element += 1;
				for (size_t ix = 0; ix < box_size; ++ix) 
				    free(matrix1[ix]);
				free(matrix1);
				free(matrixentries1);
			        }
			   }
			long start2 = sizeof(float)*numberCol*(1000-1)*(b+1);
			fseek(file,start2,SEEK_SET);
			for (int i = 0; i < box_size; i++){
				char *row2 = (char *)malloc(sizeof(char) * numberCol);
				if (fread(row2, sizeof(float), numberCol, file) != numberCol) {
				    printf("Error when reading row");
				}		
				for (int j = 0; j < numberCol; j++) {
  				  char *token2 = strtok(row2, "+-");
				    if (token2 != NULL) {
			        	free(row2);
 				   }
				
				}

			  }


			for (int k = b+1; k < numberBoxes; ++k ){
			  if(k*1000<numberRow)
				box_size = numberRow-b*1000;
		 	  for (int ix1 = 0; ix1 < (box_size - 1) ; ++ix1)

			   {
 		  	        x1 = matrix1[ix1][0];
			        y1 = matrix1[ix1][1];
			        z1 = matrix1[ix1][2];
			    for (int ix2 = b*1000; ix2 < box_size; ++ix2 )
			        {
			        x2 = matrix2[ix2][0];
			        y2 = matrix2[ix2][1];
			        z2 = matrix2[ix2][2];

			        distance = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
				 distanceMatrix[element] = (int)(distance*100+0.5)/100;
			        element += 1;
				for (size_t ix = 0; ix < box_size; ++ix) 
				    free(matrix2[ix]);
				free(matrix2);
				free(matrixentries2);

		     		}
			   }

		 	  }
			
			


// Step 1: Free Memory for Matrix Elements (Rows)
//for (size_t ix = 0; ix < box_size; ++ix) {
//    free(matrix1[ix]);
 //   free(matrix2[ix])
}
// Step 2: Free Memory for the Array of Pointers
//free(matrix1);
//free(matrix2);

// Step 3: Free Memory for matrixentries
//free(matrixentries1);
//free(matrixentries2);
		}
	 }
*/
    } else {
	
        float * matrixentries = (float*) malloc(sizeof(float) * box_size*numberCol);
	float ** matrix = (float**) malloc(sizeof(float*) * box_size);
	for (size_t ix = 0; ix < box_size; ++ix)
    		matrix[ix] = matrixentries + ix * numberCol;
	for (int i = 0; i < numberRow; i++){

		char *row = (char *)malloc(sizeof(char) * numberCol);
		if (fread(row, sizeof(float), numberCol, file) != numberCol) {
		    printf("Error when reading row");
		}		
		for (int j = 0; j < numberCol; j++) {
  		  char *token = strtok(row, "+-");
		    if (token != NULL) {
		       	matrix[i][j] = (float)atof(token);
 		      // Move to the next token
		       free(row);
 		   }
		
		}
	}
	
	double distance, x1, x2, y1, y2, z1, z2;
	int element = 0;
	
	for (int ix = 0 ; ix < (numberRow - 1) ; ++ix)
	   {
        	x1 = matrix[ix][0];
        	y1 = matrix[ix][1];
        	z1 = matrix[ix][2];
    	for (int jx = ix + 1; jx < numberRow; ++jx )
        	{
        	x2 = matrix[jx][0];
        	y2 = matrix[jx][1];
        	z2 = matrix[jx][2];

        	distance = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
        	distanceMatrix[element] = (int)(distance*100+0.5)/100;
       		element += 1;
		for (size_t ix = 0; ix < box_size; ++ix)
		    free(matrix1[ix]);
		free(matrix1);
		free(matrixentries1);
		
        	}
   	}
// Step 1: Free Memory for Matrix Elements (Rows)
for (size_t ix = 0; ix < box_size; ++ix) {
    free(matrix[ix]);
}

// Step 2: Free Memory for the Array of Pointers
free(matrix);

// Step 3: Free Memory for matrixentries
free(matrixentries);

    }

fclose(file);
/*
float largestElement = distanceMatrix[sizeDistanceMatrix-1];

//printf("%f", largestElement);                                                                                                                                                          

int sizeFrequencyMatrix = largestElement * 100; //Antag att vi har två decimaler                                                                                                         

float * frequencyMatrixEntries = (float*) malloc(sizeof(float) * sizeFrequencyMatrix*2);
float ** frequencyMatrix = (float**) malloc(sizeof(float*) * 2);

for ( size_t ix = 0, jx = 0; ix < 2; ++ix, jx+= sizeFrequencyMatrix) //Vilken ordning är bäst??                                                                                          
   frequencyMatrix[ix] = frequencyMatrixEntries + jx;


//Initiera 0or i frequencymatrix                                                                                                                                                         
for (size_t  ix = 0; ix < 2; ++ix)
    for (size_t jx = 0; jx <= sizeFrequencyMatrix; ++jx)
       frequencyMatrix[ix][jx] = 0.;


for (size_t ix = 0; ix < sizeDistanceMatrix; ++ix)//Vilken ordning är bäst??                                                                                                             
   {
    int jx = (int)(distanceMatrix[ix]*100);
    frequencyMatrix[0][jx] = distanceMatrix[ix];
    frequencyMatrix[1][jx] =+ 1;
    printf("%d",distanceMatrix[ix]);
   }

free(distanceMatrix);

for (int ix = 0; ix < sizeFrequencyMatrix; ++ix)
{
   if (frequencyMatrix[0][ix] != 0.00)
   {
    printf("%.2f %.2f \n",frequencyMatrix[0][ix],frequencyMatrix[1][ix]);
   }
}
for(int ix = 0;ix <numberCol;++ix)
	free(frequencyMatrix[ix]);
free(frequencyMatrix);
free(frequencyMatrixEntries);

 return 0;
*/
}

