/*
Write a program, called different_file, that

contains the definition of mul_cpx in a file different from the file containing
 the main function, call for instance different_file_mul.c. You may not include
  this file; provide it as an extra argument to the compiler instead.
write the declaration of mul_cpx into the same file as the main function.
generates vectors as_re, as_im, bs_re, bs_im, cs_im, and cs_im of doubles, each
 of length 30,000,
generates entries for bs_re, bs_im, cs_re, and cs_im (any kind of entries will do),
 and then
multiplies the entries of bs and cs using mul_cpx, saving results to as.
print one random entry of as to the terminal.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
mul_cpx(
	double *a_re,
	double *a_im,
	double *b_re,
	double *b_im,
	double *c_re,
	double *c_im
	);


int main()
	{
	double *a_re = (double *)malloc(30000 * sizeof(double));
	double *a_im = (double *)malloc(30000 * sizeof(double));
	double *b_re = (double *)malloc(30000 * sizeof(double));
	double *b_im = (double *)malloc(30000 * sizeof(double));
	double *c_re = (double *)malloc(30000 * sizeof(double));
	double *c_im = (double *)malloc(30000 * sizeof(double));
	size_t loop = 200000;
	clock_t start,end;
	double time;

		for ( int i = 0; i < 30000; ++i)
			{
			b_re[i] = (double) (rand() % 100);
			b_im[i] = (double) (rand() % 100);
			c_re[i] = (double) (rand() % 100);
			c_im[i] = (double) (rand() % 100);
			}
	start = (double) clock();
	for (int l = 0;l<loop; ++l)
	{
		mul_cpx(a_re,a_im,b_re,b_im,c_re,c_im); //Call the func from the other file
	}
	end = (double) clock();
	time = ((double)(end-start))/(CLOCKS_PER_SEC *loop);
	int n = (rand() % 30000);
	printf("Random selected product: %f +I * %f and time: %f\n",a_re[n],a_im[n],time);

	free(a_re);
	free(a_im);
	free(b_re);
	free(b_im);
	free(c_re);
	free(c_im);

return 0;
            }
