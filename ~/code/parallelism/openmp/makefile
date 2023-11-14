BINS = what_is_openmp
CFLAGS = -O2 -fopenmp

.PHONY : all
all : $(BINS) 

what_is_openmp : what_is_openmp.c
	gcc $(CFLAGS) -o $@ $<

.PHONY : clean
clean :
	rm -rf $(BINS)
