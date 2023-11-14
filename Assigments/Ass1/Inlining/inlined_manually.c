/*
Write a program, called inlined_manually, that

generates vectors as_re, as_im, bs_re, bs_im, cs_im, and cs_im of doubles,
 each of length 30,000,
generates entries for bs_re, bs_im, cs_re, and cs_im (any kind of entries
 will do), and then
multiplies the entries of bs and cs saving results to as by inserting
 the implementation of mul_cpx into the main function by hand.
print one random entry of as to the terminal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int
main()
{
size_t loop = 200000;
clock_t start,end;
double time;


    double *a_re = (double *)malloc(30000 * sizeof(double));
    double *a_im = (double *)malloc(30000 * sizeof(double));
    double *b_re = (double *)malloc(30000 * sizeof(double));
    double *b_im = (double *)malloc(30000 * sizeof(double));
    double *c_re = (double *)malloc(30000 * sizeof(double));
    double *c_im = (double *)malloc(30000 * sizeof(double));


    	for ( int i = 0; i < 30000; ++i)
    		{
    		b_re[i] = (double) (rand() % 100);
		b_im[i] = (double) (rand() % 100);
		c_re[i] = (double) (rand() % 100);
		c_im[i] = (double) (rand() % 100);
		}
    start = (double) clock();
    for (int l = 0; l<loop; ++l)
	{
        for ( int i = 0; i <30000; ++i)
		{
		a_re[i] = b_re[i]*c_re[i];
		a_im[i] = b_im[i]*c_im[i];
		}
	}
    end = (double) clock();
time = ((double) (end-start))/(CLOCKS_PER_SEC*loop);

int n = (rand() % 30000);
printf("Random selected product; %f +I * %f and time: %f\n" , a_re[n],a_im[n], time);


    free(a_re);
    free(a_im);
    free(b_re);
    free(b_im);
    free(c_re);
    free(c_im);

//return 0;
}
