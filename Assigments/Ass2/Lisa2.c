#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <ctype.h>
#include <math.h>


int main(int argc, char *argv[])
{
 int numberRow = 10;
 int numberCol = 3, numThreads;
 int argLenght = strlen(argv[1]);
 int blockSize = 2 * 21;
 int blockNumberOfRows = 2;

 int numberOfBlocks = numberRow/blockNumberOfRows;

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


 //float * matrixEntries = (float*) malloc(sizeof(float) * numberRow*numberCol);                                                                                                       
 //float * matrix = (float*) malloc(sizeof(float*) * numberRow);                                                                                                                     

 //for ( size_t ix = 0, jx = 0; ix < numberRow; ++ix, jx+=numberCol)                                                                                                                   
 //   matrix[ix] = matrixEntries + jx;                                                                                                                                                 

 FILE *file = fopen("test_data/test_data", "r");

 if (file == NULL)
    {
     printf("Error opening file.\n");
     return -1;
    }

 float distance, x1, x2, y1, y2, z1, z2, temp;
 int sizeDistanceMatrix = (numberRow*(numberRow-1)/2);

 float * distanceMatrix =  (float*) malloc(sizeof(float) * sizeDistanceMatrix);

 float * block1Entries =  (float*) malloc(sizeof(float) * blockSize * numberCol);
 float ** block1 = (float**) malloc(sizeof(float*) * blockSize);

  for ( size_t ix = 0, jx = 0; ix < blockSize; ++ix, jx+= numberCol)
 {
    block1[ix] = block1Entries + jx;
 }

 float * block2Entries =  (float*) malloc(sizeof(float) * blockSize * numberCol);
 float ** block2 = (float**) malloc(sizeof(float*) * blockSize);

 for ( size_t ix = 0, jx = 0; ix < blockSize; ++ix, jx+= numberCol)
 {
    block2[ix] = block2Entries + jx;
 }

 int element = 0;
 char * charBuffer = (char*)malloc(numberCol*sizeof(char));

 int offset = 0;
 int subOffset = 0;


 for(size_t mainIteration = 0; mainIteration < numberOfBlocks; ++mainIteration)
 {
        printf("Block 1 \n");                                                                                                                                                        
        for (size_t ix = 0; ix < blockNumberOfRows; ++ix)
          {
           fread(charBuffer, sizeof(char),numberCol*8, file);

           char *token = strtok(charBuffer, " ");

           int jx = 0;

           while (token != NULL)
               {
                block1[ix][jx] = atof(token);
                token = strtok(NULL, " ");
                printf("%f ", block1[ix][jx]);                                                                                                                                       

                jx = jx +1;
               }
            printf("\n");                                                                                                                                                            
          }

        printf("Block 2 \n");                                                                                                                                                        

        subOffset = offset;
	for(size_t subIteration = (mainIteration); subIteration < numberOfBlocks; ++subIteration)
        {  fseek(file,subOffset, SEEK_SET);
           for (size_t ix = 0; ix < blockNumberOfRows; ++ix)
             {
              fread(charBuffer, sizeof(char),3*8, file);

              char *token = strtok(charBuffer, " ");

              int jx = 0;
              while (token != NULL)
                {
                 block2[ix][jx] = atof(token);
                 token = strtok(NULL, " ");
                 printf("%f ", block2[ix][jx]);                                                                                                                                      

                 jx = jx + 1;
                }
               printf("\n");                                                                                                                                                         

             }
             printf("\n");                                                                                                                                                           

             for(int ix = 0; ix  < blockNumberOfRows; ++ix)
           {
            x1 = block1[ix][0];
            y1 = block1[ix][1];
            z1 = block1[ix][2];
            for(int jx = 0; jx  <  blockNumberOfRows; ++jx)
             {
              x2 = block2[jx][0];
              y2 = block2[jx][1];
              z2 = block2[jx][2];

              distance = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
              //printf("%f\n ",distance);
              distanceMatrix[element] = distance;
              element = element + 1;
             }

            subOffset = subOffset + 8*3;
            fseek(file,subOffset, SEEK_SET);
           }

        }

   offset = offset + 8*3;

   fseek(file,offset, SEEK_SET);
 }


 return 0;

}
