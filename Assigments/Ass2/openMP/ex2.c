#include <omp.h>
#include <stdio.h>

static long num_steps = 100000;
#define PAD 8 //assumed 664 byte L1 cache line size
double step;
#define NUM_THREADS 2

int main()
{
	int i,nthreads;
	double pi,sum[NUM_THREADS][PAD];
	step = 1.0/ (double)num_steps;
	pi = 0.0;
	omp_set_num_threads(NUM_THREADS);	
	#pragma omp parallel
		{
		int i,id,nthrds; // local to each thread. varje thread behöver ha sina egna så de kan variera dem så dom det behövs
		double x;
		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		if( id == 0)
			nthreads = nthrds;

		for (i = id, sum[id] = 0.0; i<num_steps; i = i+nthrds)//låter id hoppa lika många steg per varv i loopen som det är threads
			{
			x = (i +0.5)*step;
			sum[id][0] += 4.0/(1.0 + x*x);
			}
		}
	for (i = 0;i<nthreads;i++)
		pi += sum[i][0] * step;//sum fick en array så att det fins en sum för varje thread. OBS att number of threads var def utanför parallel region

	printf("%f\n", pi);
}

/*fFalse sharing = if idenpendent data elements happen to sit on the same cache line, each update will cause the cache lines to slosh back an forths between reads
 *
 * by adding PAD it is more efficient but it is an ugly solution
 *
