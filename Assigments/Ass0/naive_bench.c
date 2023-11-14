/*
Implement a program that

    in a loop repeats,
        the naive computation of the sum of the first billion integers,
    writes the result to stdout,
    takes the time before and after the loop,
    computes the runtime of a single loop iteration from the 
    difference of start and stop time.

Compile and run the program with all possible optimization levels 
(add the flags -O0, -O1, -O2, -O3, -Os, and -Og to the compiler).

Discuss the timing results and speculate about the possible cause.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
double size = 1000000000;
double tot = 0;
//double time_spent = 0.0;
long start_t, end_t. tot_t;


start_t = (long) clock();
//time_t begin = time(NULL);
for (long n = 1; n<size+1; ++n){
	tot = tot + n;
	}
end_t = (long)clock();
//time_t end = time(NULL);
time_t = (end_t-start_t);
fprintf(stdout, "Sum: %f and time elapsed: %f\n", tot,time_spent);

}

/*
Ingen Time: 2.0000
-O0 Time: 3.0000 optimize for compile time and debug-ability. Most 
performance optimizations are disabled. This is the default for GCC
-O1 Time: 3.0000 pick the low hanging fruit in terms of performance, 
without impacting compilation time too much.
-O2 Time: 3.0000 optimize for performance more aggressively, but not 
at the cost of larger code size.
-O3 Time: 2.0000 optimize for performance at all cost, no matter the 
code size or compilation time impact.
-Os Time: 2.0000  optimize for code size. This uses O2 as the baseline,
 but disables some optimizations. For example, it will not inline3 
 code if that leads to a size increase.
-Og Time: 3.0000

This flags are options to reduse firmware codesize. All options are 
trade offs and as the best time with the frags is the same as without
 any flags this can mean both that the code is pretty fast as it is
  already, or that the trade off by adding the flag is equal to 0
