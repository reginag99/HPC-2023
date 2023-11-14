

// Define the function
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
for ( int i = 0; i<30000; i++)
	{
	a_re[i] = b_re[i]*c_re[i];
	a_im[i] = b_im[i]*c_im[i];
	}
}


