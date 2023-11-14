/*In this task you get familiar with the impact of indirect addressing. It is frequently used for sparse matrix and vector operators.

Write a program that add to a vector y the multiple of a vector x by a. Both vectors have length 1,000,000 and are allocated on the heap. The vectors must be addressed indirectly, through an index vector p, and you will use two different initializations for this index vector.

Concretely, implement a program base on the following code:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main()
{
	size_t size = 10000;
	int a = 5;
	size_t loop = 100;
	clock_t start_1, end_1, start_2,end_2,start_1_im,end_1_im,start_2_im,end_2_im;
	double time1,time2,time1_im,time2_im;
	int n1 = (rand() % size);
	int n2 = (rand() % size/1000);
printf("n = %d", n2);

{
int *p = (int*)malloc(sizeof(int)*size);
int *x = (int*)malloc(sizeof(int)*size);
int *y = (int*)malloc(sizeof(int)*size);


for(size_t xx = 0; xx<size; ++xx)
	{
	x[xx] = (rand() % 100);
	}


//The two initializations of the index vector p are as follows. First, we use a linear initialization:
start_1 = (double) clock();
for (size_t l = 0; l<loop; ++l)
	{
	for ( size_t ix = 0; ix < size; ++ix  )
		{
		p[ix] = ix;
	
		for ( size_t kx = 0; kx < size; ++kx ) 
			{
	  		size_t jx = p[kx];
	 	 	y[jx] += a * x[jx];
	 		}
		}
	}
end_1 = (double) clock();
time1 = ((double) (end_1-start_1))/(CLOCKS_PER_SEC*loop);

printf("First method: %d and n: %d and time: %f\n",y[n1],n1,time1);

free(p);
free(x);
free(y);
}



//Second, we use an initialization that jumps in steps of 1000.
{
int *p = (int*)malloc(sizeof(int)*size);
int *x = (int*)malloc(sizeof(int)*size);
int *y = (int*)malloc(sizeof(int)*size);

start_2 = (double) clock();
size_t size_jump = 1000;
for (size_t l = 0; l<loop; ++l)
	{
	for ( size_t jx = 0, kx = 0; jx < size_jump; ++jx)
        	for ( size_t ix = jx; ix < size; ix += size_jump, ++kx)
  		{
		p[ix] = kx;
	
		for ( size_t kx = 0; kx < size; ++kx ) {
	  	size_t jx = p[kx];
	  	y[jx] += a * x[jx];
	  	}
		}
	end_2 = (double) clock();
	time2 = ((double) (end_2-start_2))/(CLOCKS_PER_SEC*loop);
	}

printf("Second method: %d and n: %d and time: %f\n",y[n2], n2,time2);

free(p);
free(x);
free(y);
}


//Add an implementation alternative implementation that accesses x and y in linear order directly, avoiding indirect addressing, and benchmark as before.

{
int *p = (int*)malloc(sizeof(int)*size);
int *x = (int*)malloc(sizeof(int)*size);
int *y = (int*)malloc(sizeof(int)*size);

start_1_im = (double) clock();
for (size_t l = 0; l<loop; ++l)
	{
	for ( size_t ix = 0; ix < size; ++ix  )
		{
	 	 y[ix] += a * x[ix];
	 	}
	}
end_1_im = (double) clock();
time1_im = ((double) (end_1_im-start_1_im))/(CLOCKS_PER_SEC*loop);

printf("First method implementation: %d and n: %d and time: %f\n",y[n1],n1,time1_im);

free(p);
free(x);
free(y);
}

//Second, we use an initialization that jumps in steps of 1000.
{
int *p = (int*)malloc(sizeof(int)*size);
int *x = (int*)malloc(sizeof(int)*size);
int *y = (int*)malloc(sizeof(int)*size);

start_2_im = (double) clock();
size_t size_jump = 1000;
for (size_t l = 0; l<loop; ++l)
	{
	for ( size_t jx = 0, kx = 0; jx < size_jump; ++jx)
  	for ( size_t ix = jx; ix < size; ix += size_jump, ++kx)
  		{
		p[ix] = kx;
	
		for ( size_t kx = 0; kx < size; ++kx ) {
	  	size_t jx = p[kx];
	  	y[jx] += a * x[jx];
	  	}
		}
	end_2_im = (double) clock();
	time2_im = ((double) (end_2_im-start_2_im))/(CLOCKS_PER_SEC*loop);
	}

printf("Second method implementation: %d and n and time: %f\n",y[n2],n2,time2_im);
free(p);
free(x);
free(y);
}
}
/*
Compile your program with optimization level 0, with optimization level 2, and with optimization level 2 including native architecture. Benchmark all variants and compare timings. Do not forget to print a random element of sums to avoid over-simplification by the compiler. In the example implementation 1000 benchmark iterations suffices to see the relevant effect.



For loop = 100 and size = 10000; 
First method:
O0 : 0.282308
O2 : 0.058941
O2 native : 0.059040

Second method:
O0 : 0.301776
O2 : 0.083434
O2 native : 0.083160

*/
