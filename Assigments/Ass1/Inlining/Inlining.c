/*
In this task you will see the effect of automatic inlining. You have to compile
 programs with optimization level 2 (i.e. compiler flag -O2) in order to produce
  the effect.

Implement a function with signature:(see below)

that computes the product of two complex numbers b and c, and stores it in a.
 The suffices re and im stand for the real and imaginary part of a,b,c
  respectively. This function may only multiply two complex numbers as opposed
   to several pairs.
*/

#include <stdio.h>
#include <stdlib.h>

//Here i sort of declare the function mul_cpx and what it involvs
void
mul_cpx(
    double *a_re,
    double *a_im,
    double *b_re,
    double *b_im,
    double *c_re,
    double *c_im
    );


int
main()
{
//Here i declare all parameter values and put them in the function. Clear memory for these
double a_re = 3;
double a_im = 4;
double b_re = 5;
double b_im = 6;
double c_re,c_im;


//calls on function using the values set above, or the adresses to the values set above
mul_cpx(&a_re,&a_im,&b_re,&b_im,&c_re,&c_im);
printf("The product is: %f + I* %f", c_re, c_im);
}


void
mul_cpx(
    double *a_re,
    double *a_im,
    double *b_re,
    double *b_im,
    double *c_re,
    double *c_im
    )
{
    *c_re = (* a_re) * ( *b_re);
    *c_im = (* a_im) * ( *b_im);

}
/*We have to use the pointers when multiplying as the names a_re etc is just the
 names of the variables but what we want to reach and use us the acctual values
  of the variables, To find these we use pointers. 

*/
