#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main()
{
size_t size = 1000000;
int a = 5;
size_t loop = 1000;
clock_t start, end;
double time;
int n = (rand() % size);
int *x = (int*)malloc(sizeof(int)*size);
int *y = (int*)malloc(sizeof(int)*size);


for(size_t xx = 0; xx<size; ++xx)
	{
	x[xx] = (rand() % 100);
	}
start = (double) clock();
for (size_t l = 0; l<loop; ++l )
	{
	for ( size_t jx = 0; jx < size; ++jx ) {
		y[jx] += a * x[jx];
		}
	}
end = (double) clock();

time = ((double)(end-start))/(CLOCKS_PER_SEC*loop);

printf("Direct: %d and time: %f\n", y[n],time);

free(x);
free(y);
}


