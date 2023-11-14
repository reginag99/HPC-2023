#include <omp.h>
#include <stdio.h>

static long num_steps = 100000;
double step;
#define NUM_THREADS 2

int main()
{
	double pi = 0.0;
	step = 1.0/ (double)num_steps;
	pi = 0.0;
	omp_set_num_threads(NUM_THREADS);	
	#pragma omp parallel
		{
		int i,id,nthrds; // local to each thread. varje thread behöver ha sina egna så de kan variera dem så dom det behövs
		double x,sum;
		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		if( id == 0)
			id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		for (i = id, sum = 0.0; i<num_steps; i = i+nthrds)//låter id hoppa lika många steg per varv i loopen som det är threads
			{
			x = (i +0.5)*step;
			sum += 4.0/(1.0 + x*x);
			}
		}
		#pragma omp critical
		pi += sum * step;//sum fick en array så att det fins en sum för varje thread. OBS att number of threads var def utanför parallel region

	
	printf("%f\n", pi);
}


