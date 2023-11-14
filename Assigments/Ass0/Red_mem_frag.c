//Reducing memory fragmentation


//When allocating memory on the heap, there is no guarantee about 
//where it is positioned. A common strategy to avoid this is to 
//allocate memory in large blocks (contiguous memory). 
//Implement a program based on the next two code snippets. 
//Explain the meaning of all variables, and exhibit the possible 
//layout of allocated memory in both cases.

//Using contiguous memory and thus avoiding memory fragmentation:

#include <stdio.h>
#include <stdlib.h>

int
main( )
{

{
	int size = 10;

	int * asentries = (int*) malloc(sizeof(int) * size*size);
	 //asentries is pointers asignes with memory of int times size square.
	 //In C matrices in not stored as a matrix but as a long line.
	 
	int ** as = (int**) malloc(sizeof(int*) * size);
	// Creates an array of pointers for the pointers in 
	//asentries. It is of size size = 10.
	//

	
	for ( size_t ix = 0, jx = 0; ix < size; ++ix, jx+=size )
 	    as[ix] = asentries + jx;
 	//For-loop that goes from ix = 0 until size and jx=0 that is
 	// increasing by size for each loop. If comparing to how this 
 	//would look as a matrix, ix is the row and jx is the column. The reason jx is increasing by 10 is so it gets to the next 
 	//column. What this for-loop does is that it assignes the 
 	//array of pointers as with the adress of the first position
 	//in the rows. 


	
	for ( size_t ix = 0; ix < size; ++ix )
  	for ( size_t jx = 0; jx < size; ++jx )
  	//loops over the matrix, one kollumn at the time, and 
  	//changes the value in each position to 0.
	    as[ix][jx] = 0;

	printf("%d\n", as[0][0]);// Prints out the value in point 0,0

free(as); 
free(asentries);
}

{
	int size = 10;

	int ** as = (int**) malloc(sizeof(int*) * size); 
	//Declares pointer to a pointer, of size size = 10, thats 
	//points to an int.
	for ( size_t ix = 0; ix < size; ++ix )
	  as[ix] = (int*) malloc(sizeof(int) * size);
	//It loops over as and for each int it declares another 
	//array of pointer of size size = 10 for each element in as.

	for ( size_t ix = 0; ix < size; ++ix )
	  for ( size_t jx = 0; jx < size; ++jx )
	    as[ix][jx] = 0;
	    //loops over the matrix and assignes every position 
	    //with 0

	printf("%d\n", as[0][0]);

	for ( size_t ix = 0; ix < size; ++ix )
	    free(as[ix]);
	free(as);
}

return 0;
}
