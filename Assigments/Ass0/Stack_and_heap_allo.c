//Allocation describes the reserving of memory for a program. 
//Stack allocation is the fastest variant. 
//While the C standard makes no assumption on what memory is allocated on the stack, it is reasonable to assume
//that arrays of static size are allocated on the stack.

//Make sure that you place the declaration of the array in the main
// function (as opposed to global scope).

//Compile and run the program. Then increase the size of the array, 
//recompile and run, until the program fails with a segmentation fault. 
//Explain this behavior assuming that that allocation was performed 
//on the stack.

#include <stdlib.h>
#include <stdio.h>

int main(void) {

/**
{	int size = 5000000;
	int as[size];
	for ( size_t ix = 0; ix < size; ++ix )
		as[ix] = 0;
		printf("%d\n", as[0]);
		printf("%d\n", size);
}

/**/

//Answer: 
//The space on the stack is smal and limited to fit only a limited 
//number of integers. When giving the input, the compiler is preperad 
//on what sort of data it is. The different types have different 
//limitations and is more or less optimal to use depending on the 
//input.  Therefore, then size became to big, the program in which 
//we were using int failed. 



//Heap allocation is the alternative to stack allocation. It is 
//generally slower, but more flexible. In particular, it has less 
//restrictions on the size of allocated memory.

//Write a program with the following allocation pattern


{
	int size = 50000000000000000000000;;

	int * as = (int*) malloc(sizeof(int) * size);
	for ( size_t ix = 0; ix < size; ++ix )
  		as[ix] = 0;

		printf("%d\n", as[0]);

	free(as);
	}
return 0;
}
//Compile and run as above, and verify that the program does not fail 
//for sizes that triggered a segmentation fault before.

//Answer: 
// When using this the program did not fail as in the earliar case. 
//To test the program the size was increased even more and it did 
//then become very clear that it took longer time to the program 
//to finiche than it had before. 
