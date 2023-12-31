#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <ctype.h>
#include <math.h>

//Plocka ut siffran i -t5 och                                                                                                                              
//Måste lösningen kunna ta hänsyn till mellanslag?                                                                                                         
//Om ja leta efter första siffran sedan atoi?                              

/*
void 
calculateDistance (matrix)
{
int sizeDistanceMatrix = (numberRow*(numberRow-1)/2);
double distance, x1, x2, y1, y2, z1, z2;
int element = 0;

int * distanceMatrix =  (int*) malloc(sizeof(int) * sizeDistanceMatrix);

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
        }
   }
free(matrix);
free(matrixEntries);
}

*/


int compare (const void * a, const void * b);

int main(int argc, char *argv[])
{
int numberRow = 10;
int box_size = 1000;
int numberBoxes = ceil(numberRow/box_size);
int sizeDistanceMatrix = (numberRow*(numberRow-1)/2);
int * distanceMatrix =  (int*) malloc(sizeof(int) * sizeDistanceMatrix);
int numberCol = 3, numThreads;
int argLenght = strlen(argv[1]);

if (argv[1][0] == '-' && argv[1][1] == 't' && argLenght > 2)
   {
    numThreads = atoi(&argv[1][2]);
   }
else
   {
    printf("Wrong format for argument use format -t[INTEGER], where [INTEGER] must be valid whole number larger than 0.");
    exit(EXIT_FAILURE);
   }

if (numThreads == 0)
   {
    printf("INTEGER must be valid whole number larger than 0.");
    exit(EXIT_FAILURE);
   }

printf("Number of threads %d\n", numThreads);


//Allokera minne för Matrix 1
float * matrixEntries1 = (float*) malloc(sizeof(float) * box_size*numberCol);
float ** matrix1 = (float**) malloc(sizeof(float*) * box_size);

for ( size_t ix = 0, jx = 0; ix < box_size; ++ix, jx+=numberCol)
   matrix1[ix] = matrixEntries1 + jx;


//Allokera minne för Matrix 2
float * matrixEntries2 = (float*) malloc(sizeof(float) * box_size*numberCol);
float ** matrix2 = (float**) malloc(sizeof(float*) * box_size);

for ( size_t ix = 0, jx = 0; ix < box_size; ++ix, jx+=numberCol)
   matrix2[ix] = matrixEntries2 + jx;


FILE *file = fopen("test_data/test_data", "r");

if (file == NULL)
   {
    printf("Error opening file.\n");
    return -1;
   }
if (numberRows > 1000)
	{
for (size_t b = 0; b<numberBoxes; ++b )
	{
	int sizeDistanceMatrix = (numberRow*(numberRow-1)/2);
	int * distanceMatrix =  (int*) malloc(sizeof(int) * sizeDistanceMatrix);
	for (int ix = 0; ix < numberRow; ix++)
     		for (int jx = 0; jx < numberCol; jx++)
    	 		{
			fread(matrix1[ix][jx],sizeof(int),box_size*numberCol);
			double distance, x1, x2, y1, y2, z1, z2;
			int element = 0;

			for (int ix = 0 ; ix < (box_sixe - 1) ; ++ix)
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
			        distanceMatrix[element] = (int)(distance*100+0.5)/100;
			        element += 1;
			        }
			   }
			fread(matrix2:[ix][jx],sizeof(int),box_size*numberCol);
			for (int k = b+1; k < numberBoxes; ++k ){
			  if(b*1000<numberRow){
				box_size = numberRow-b*1000;}
		 	  for (int ix1 = 0; ; ix1 < (box_sixe - 1) ; ++ix1)
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
		     		}

		 	  }
			}

	free(matrix1);
	free(matrixEntries1);
	free(matrix2);
	free(matrixEntries2);

}	
else{
	float * matrixEntries = (float*) malloc(sizeof(float) * box_size*numberCol);
float ** matrix = (float**) malloc(sizeof(float*) * box_size);

for ( size_t ix = 0, jx = 0; ix < box_size; ++ix, jx+=numberCol)
   matrix[ix] = matrixEntries + jx;

	
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
        	}
   	}
free(matrix);
free(matrixEntries);

}
fclose(file);

//Räkna distanserna mellan koordinaterna                                                                                                                                                 


/*
for( int ix = 0; ix < sizeDistanceMatrix; ++ix)
    {
        for(int jx = ix + 1; jx < sizeDistanceMatrix; ++jx)
        { if(distanceMatrix[ix]> distanceMatrix[jx])
            {
                temp = distanceMatrix[ix];
                distanceMatrix[ix] = distanceMatrix[jx];
                distanceMatrix[jx] = temp;
            }
        }
    }
*/

//for (int ix = 0 ; ix < sizeDistanceMatrix; ++ix)                                                                                                                                       
//    printf("%f\n",distanceMatrix[ix]);                                                                                                                                                 

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
   }

free(distanceMatrix);

for (int ix = 0; ix < sizeFrequencyMatrix; ++ix)
{
   if (frequencyMatrix[0][ix] != 0.00)
   {
    printf("%.2f %.2f \n",frequencyMatrix[0][ix],frequencyMatrix[1][ix]);
   }
}

free(frequencyMatrix);
free(frequencyMatrixEntries);

 return 0;

}
