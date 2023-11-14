/*

Write a C program, called locality, that

creates 1000 x 1000 doubles,
stores them in a matrix in row major order,
computes the row and the column sums.
Use the following naive implementations of row and column sums. You may 
inline them at will, they are here given as functions to make all types
 transparent.

Note that when calling a function that has an argument of type const
 double ** with a value of type double **, you can explicitly convert
  the argument to the correct type.

Compile your program with optimization level 0, with optimization level 2
, and with optimization level 2 including native architecture. Benchmark
 all variants and compare timings. Do not forget to print a random
  element of sums to avoid over-simplification by the compiler. In the
   example implementation 5000 benchmark iterations were more than
    sufficient to see the relevant effect. Interpret the results with an
   eye to memory access patterns.

Add a reimplementation of the slower summation in a more effective way
 and benchmark as before. The benchmarking results arising from this reimplement might be surprising at first sight and will be clarified in the next task.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
row_sums(
  double * sums,
  const double ** matrix,
  size_t nrs,
  size_t ncs
)
{
  for ( size_t ix = 0; ix < nrs; ++ix ) {
    double sum = 0.;
    for ( size_t jx = 0; jx < ncs; ++jx )
      sum += matrix[ix][jx];
    sums[ix] = sum;
  }
}

void
col_sums(
  double * sums,
  const double ** matrix,
  size_t nrs,
  size_t ncs
  )
{
  for ( size_t jx = 0; jx < ncs; ++jx ) {
    double sum = 0.;
    for ( size_t ix = 0; ix < nrs; ++ix )
      sum += matrix[ix][jx];
    sums[jx] = sum;
  }
}

void
col_sums2(
  double * sums,
  const double ** matrix,
  size_t nrs,
  size_t ncs
  )
{
  for ( size_t ix = 0;ix < nrs; ++ix ) {
    for ( size_t jx = 0; jx < ncs; ++jx )
      sums[jx] += matrix[ix][jx];
     }
}


int
main()

{
int size = 1000;
double * sums_row = (double *)malloc(size * sizeof(double));
double * sums_col = (double *)malloc(size * sizeof(double));
double * sums_col2 = (double *)malloc(size * sizeof(double));

double **matrix_in = (double **)malloc(size * sizeof(double*));
int loop = 5000;
clock_t start_row,end_row,start_col,end_col,start_col2,end_col2;;
double time_row,time_col, time_col2;

 
for (int i = 0; i<size; i++)
	{
	matrix_in[i] = (double *)malloc(size * sizeof(double));
	for (int j = 0; j<size; j++)
		matrix_in[i][j]=(double)(rand() %100);
	}
const double ** matrix = (const double **) matrix_in;

start_row = (double) clock();
for (int l = 0; l<loop; ++l)
	row_sums(sums_row,(const double **)matrix,size,size);
end_row =(double) clock();

time_row = ((double) (end_row-start_row))/(CLOCKS_PER_SEC*loop);


start_col = (double) clock();
for (int l = 0; l<loop; ++l)
	col_sums(sums_col,(const double **)matrix,size,size);
end_col = (double)clock();

time_col = ((double) (end_col-start_col))/(CLOCKS_PER_SEC*loop);

int n = (rand() % size);
printf("Sums of columns: %f and time: %f  and Sums of rows: %f and time: %f\n" ,sums_row[n],time_row, sums_col[n], time_col);


start_col2 = (double) clock();
for (int l = 0; l<loop; ++l)
	col_sums2(sums_col2,(const double **)matrix,size,size);
end_col2 = (double)clock();

time_col2 = ((double) (end_col2-start_col2))/(CLOCKS_PER_SEC*loop);
printf("Sums of columns, mod: %f and time: %f\n", sums_col2[n], time_col2);




for (int i = 0; i < size; i++)
        free((void *)matrix[i]);

//moving this to the loop for matrix in main to free for each loop
//for (int ix = 0; ix < size; ++ix)
//    free(matrix[ix]);
free(matrix);
free(sums_row);
free(sums_col);
}

/*-O0: 0.028583
 *-O2: 0.023115
 *-O2 native: 0.029936
 *
 * after adjustment above: 
 *-O0: 0.027309
 *-O2: 0.022249
 *-O2 native: 0.021916
 * */

