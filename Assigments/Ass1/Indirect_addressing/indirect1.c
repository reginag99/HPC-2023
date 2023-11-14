#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main()
{
	size_t size = 1000000;
	int a = 5;
	size_t loop = 1000;
	clock_t start_1, end_1;
	double time1;
	int n1 = (rand() % size);

int *p = (int*)malloc(sizeof(int)*size);
int *x = (int*)malloc(sizeof(int)*size);
int *y = (int*)malloc(sizeof(int)*size);


for(size_t xx = 0; xx<size; ++xx)
	{
	x[xx] = (rand() % 100);
	}


//The two initializations of the index vector p are as follows. First, we use a linear initialization:

for ( size_t ix = 0; ix < size; ++ix  )
	{
	p[ix] = ix;}

start_1 = (double) clock();
for (size_t l = 0; l<loop; ++l)
	{
	for ( size_t kx = 0; kx < size; ++kx ) 
		{
	  	size_t jx = p[kx];
	 	y[jx] += a * x[jx];
	 	}
	}
end_1 = (double) clock();
time1 = ((double) (end_1-start_1))/(CLOCKS_PER_SEC*loop);

printf("First method: %d and n: %d and time: %f\n",y[n1],n1,time1);

free(p);
free(x);
free(y);
}



