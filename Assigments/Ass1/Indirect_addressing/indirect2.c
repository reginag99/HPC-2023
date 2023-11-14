#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main()
{
	size_t size = 1000000;
	int a = 5;
	size_t loop = 1000;
	clock_t start_2,end_2;
	double time2;
	int n2 = (rand() % size/1000);

int *p = (int*)malloc(sizeof(int)*size);
int *x = (int*)malloc(sizeof(int)*size);
int *y = (int*)malloc(sizeof(int)*size);


for(size_t xx = 0; xx<size; ++xx)
	{
	x[xx] = (rand() % 100);
	}




size_t size_jump = 1000;
for ( size_t jx = 0, kx = 0; jx < size_jump; ++jx)
        for ( size_t ix = jx; ix < size; ix += size_jump, ++kx)
  	{
	p[ix] = kx;}



start_2 = (double) clock();
for (size_t l = 0; l<loop; ++l)
	{
	for ( size_t kx = 0; kx < size; ++kx ) {
  		size_t jx = p[kx];
	  	y[jx] += a * x[jx];
  	}
}
end_2 = (double) clock();
time2 = ((double) (end_2-start_2))/(CLOCKS_PER_SEC*loop);

printf("Second method: %d and n: %d and time: %f\n",y[n2], n2,time2);

free(p);
free(x);
free(y);
}


