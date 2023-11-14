//Implement two programs. One that

    //opens a file for writing,
    //writes a square matrix of size 10 with int entries (ix*jx in the
    // ix-th row and jx-th column) to that file,
    //closes the file.

#include <stdio.h>
#include <stdlib.h>

int main()
{

int size = 10;
#define ROWS size //ändra till int och rows
#define COLUMNS size
int matrix[ROWS][COLUMNS];
	{
		
	for ( int ix = 0; ix<size; ++ix)
		for ( int jx = 0; jx<size; ++jx)
	    		matrix[ix][jx] = ix * jx;

	// File pointer.
	FILE *new_file_pointer;
	new_file_pointer = fopen("new_file.bin", "w");
	
	//Creates a new file named new_file.txt if it does not exist

	if ( new_file_pointer == NULL ) 
		{
		printf("Error opening or creating file\n");
		return -1;
		}


	for (int ix = 0; ix<size; ++ix)
		{
		for (int jx = 0; jx<size; ++jx)
			{
	    		fprintf(new_file_pointer, "%d ", matrix[ix][jx]);
	  		}
		fprintf(new_file_pointer, "\n");
		}

	fclose(new_file_pointer);
	//closes the file using the pointer to the file


	}


//The other one
 
    //reopens the file for reading,
    //reads the matrix from the file,
    //checks that the entry in the ix-th row and jx-th column equals 
    //ix*jx.

	{
	
	FILE * new_file_pointer;
	new_file_pointer = fopen("new_file.bin", "r");


	//fread(&matrix, sizeof(int), size,new_file_pointer); 
	//printf("%d\n", matrix[3][3]);
	


	if ( new_file_pointer == NULL ){
		printf("Error opening file\n");
		return -1;
		}
	if (fseek(new_file_pointer, 0, SEEK_SET) != 0)
		{
		printf("Error seeking the beginning of the file \n");
		return -1;
		}

	int row = 0; //keep track on the row
	while (!feof(new_file_pointer)) //feof will return tru untill the end of the file
		{
		if (ferror(new_file_pointer))
			{	
			printf("Error, reading file\n");
			return -1;
			}
		for (int ix = 0; ix<COLUMNS; ix++)
			{
			fscanf(new_file_pointer,"%d", &matrix[row][ix]);//fscanf skippar blanspaces automatiskt
			}
		row++;
		if (row == ROWS)
			break;

		}
	fclose(new_file_pointer);
	
	for (int ix = 0; ix < ROWS; ix++)
		{
		for (int jx = 0; jx < COLUMNS; jx++)
			{
			printf("%d ", matrix[ix][jx]);
			if (matrix[ix][jx] != ix*jx)
				{
				printf("Error, nonexpected element\n");
				return -1;
				}
			}
		printf("\n");
		}
	}

}







//How does your choice of memory allocation (contiguous vs. 
//noncontiguous) impact the possibilties to write the matrix in text 
//and binary format? 

/*
If cont. its easier to both store and then print out the elements 
in the matrix, as you can handle it as an array. This is also how 
 things are stored in the memory, even if we see it as a matrix. 
 When using cont. its preferd to have binary format as it is easy 
 to get extraxt each element. If its text/string it can be more 
 important to store the content as it is read, so there is no 
 missunderstandings.

*/

