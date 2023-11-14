/* Write a C program, called data_dependency, that

creates 1000 x 1000 doubles,
stores them in a matrix in row major order,
computes the row sums.
Use the following implementations of row sums. You may inline them at will, they are here given as functions to make all types transparent.
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
row_sums_unrolled2(
  double * sums,
  const double ** matrix,
  size_t nrs,
  size_t ncs
)
{
  for ( size_t ix = 0; ix < nrs; ++ix ) {
    double sum0 = 0.;
    double sum1 = 0.;
    for ( size_t jx = 0; jx < ncs; jx += 2 ) {
      sum0 += matrix[ix][jx];
      sum1 += matrix[ix][jx+1];
    }
    sums[ix] = sum0 + sum1;
  }
}

void
row_sums_unrolled4(
  double * sums,
  const double ** matrix,
  size_t nrs,
  size_t ncs
)
{
  for ( size_t ix = 0; ix < nrs; ++ix ) {
    double sum0 = 0.;
    double sum1 = 0.;
    double sum2 = 0.;
    double sum3 = 0.;
    for ( size_t jx = 0; jx < ncs; jx += 4 ) {
      sum0 += matrix[ix][jx];
      sum1 += matrix[ix][jx+1];
      sum2 += matrix[ix][jx+2];
      sum3 += matrix[ix][jx+3];
    }
    sums[ix] = sum0 + sum1 + sum2 + sum3;
  }
}

void
row_sums_unrolled8(
  double * sums,
  const double ** matrix,
  size_t nrs,
  size_t ncs
)
{
  for ( size_t ix = 0; ix < nrs; ++ix ) {
    double sum0 = 0.;
    double sum1 = 0.;
    double sum2 = 0.;
    double sum3 = 0.;
    double sum4 = 0.;
    double sum5 = 0.;
    double sum6 = 0.;
    double sum7 = 0.;
    for ( size_t jx = 0; jx < ncs; jx += 8 ) {
      sum0 += matrix[ix][jx];
      sum1 += matrix[ix][jx+1];
      sum2 += matrix[ix][jx+2];
      sum3 += matrix[ix][jx+3];
      sum0 += matrix[ix][jx+4];
      sum1 += matrix[ix][jx+5];
      sum2 += matrix[ix][jx+6];
      sum3 += matrix[ix][jx+7];
    }
    sums[ix] = sum0 + sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7;
  }
}

void
row_sums_unrolled4_imp(
  double * sums,
  const double ** matrix,
  size_t nrs,
  size_t ncs
)
{
  for ( size_t ix = 0; ix < nrs; ++ix ) {
    double sum[4] = {0., 0.,0.,0.};
    for ( size_t jx = 0; jx < ncs; jx += 4 ) {
      sum[0] += matrix[ix][jx];
      sum[1] += matrix[ix][jx+1];
      sum[2] += matrix[ix][jx+2];
      sum[3] += matrix[ix][jx+3];
    }
    sums[ix] = sum[0] + sum[1] + sum[2] + sum[3];
  }
}

int
main()

{
int size = 1000;
double * sums_row = (double *)malloc(size * sizeof(double));
double * sums_row_unrolled2 = (double *)malloc(size * sizeof(double));
double * sums_row_unrolled4 = (double *)malloc(size * sizeof(double));
double * sums_row_unrolled8= (double *)malloc(size * sizeof(double));
double * sums_row_unrolled4_imp = (double *)malloc(size * sizeof(double));

double **matrix = (double **)malloc(size * sizeof(double *));
int loop = 5000;
clock_t start1,end1,start2,end2,start4,end4,start8,end8,start4_imp,end4_imp;
double time1,time2,time4,time8,time4_imp;

for (int ix = 0; ix < size; ++ix)
	matrix[ix] = (double *)malloc(size * sizeof(double));

for (int ix = 0; ix<size; ++ix)
	for (int jx = 0; jx<size; ++jx)
		matrix[ix][jx] = (double)(rand() %100);

start1 = (double) clock();
for (int l = 0; l<loop; ++l)
	row_sums(sums_row,(const double **)matrix,size,size);
end1 = (double)clock();
time1 = ((double) (end1-start1))/(CLOCKS_PER_SEC*loop);


start2 = (double) clock();
for (int l = 0; l<loop; ++l)
	row_sums_unrolled2(sums_row_unrolled2,(const double **)matrix,size,size);
end2 = (double) clock();
time2 = ((double) (end2-start2))/(CLOCKS_PER_SEC*loop);


start4 = (double) clock();
for (int l = 0; l<loop; ++l)
	row_sums_unrolled4(sums_row_unrolled4,(const double **)matrix,size,size);
end4 = (double) clock();
time4 = ((double) (end4-start4))/(CLOCKS_PER_SEC*loop);


start8 = (double) clock();
for (int l = 0; l<loop; ++l)
	row_sums_unrolled8(sums_row_unrolled8,(const double **)matrix,size,size);
end8 = (double) clock();
time8 = ((double) (end8-start8))/(CLOCKS_PER_SEC*loop);


start4_imp = (double) clock();
for (int l = 0; l<loop; ++l)
	row_sums_unrolled4_imp(sums_row_unrolled4_imp,(const double **)matrix,size,size);
end4_imp = (double) clock();
time4_imp = ((double) (end4_imp-start4_imp))/(CLOCKS_PER_SEC*loop);



int n = (rand() % size);
printf("Sums of rows: %f\n and Time elapser: %f\n" ,sums_row[n],time1) ;

printf("Sum of unrolled rows 2:%f and time:%f\n", sums_row_unrolled2[n], time2);

printf("Sum of unrolled rows 4:%f and time:%f\n", sums_row_unrolled4[n], time4);

printf("Sum of unrolled rows 8:%f and time:%f\n", sums_row_unrolled8[n], time8);
printf("Sum of unrolled rows 4 imp:%f and time:%f\n", sums_row_unrolled4_imp[n], time4_imp);



//moving this to the loop for matrix in main to free for each loop
//for (int ix = 0; ix < size; ++ix)
//    free(matrix[ix]);
for (int ix = 0; ix < size; ++ix)
        	free(matrix[ix]);
free(matrix);
free(sums_row);
free(sums_row_unrolled2);
free(sums_row_unrolled4);
free(sums_row_unrolled8);
free(sums_row_unrolled4_imp);

}


/*
 -O0 : 0.024379
 -O2 : 0.021348
 -O2 native : 0.021123
 Compile your program with optimization level 0, with optimization level 2, and with optimization level 2 including native architecture. Benchmark all variants and compare timings. Do not forget to print a random element of sums to avoid over-simplification by the compiler. In the example implementation 5000 benchmark iterations were more than sufficient to see the relevant effect. Interpret the results with an eye to data dependency.

Add reimplementations row_sums_unrolled4 and row_sums_unrolled8, imitating the provided pattern, and benchmark as before.


-O0: 0.025653
-O2: 0.021220
-O2 native: 0.020778



Finally, add an implementation row_sums_unrolled4 in which you use an array of four doubles

double sum[4] = {0.,0.,0.,0.};
instead of four separate variable to store the intermediate sums.

*/

