Inlining : Inlining.c
	-gcc -o $@ $^ -O2 -g
same_file : same_file.c
	-gcc -o $@ $^ -O2 -g
different_file : different_file.c different_file_mul.c
	-gcc -o $@ $^ -O2 -g

locality : locality.c
	-gcc -o $@ $^-O2 -g

inlined_manually : inlined_manually.c
	-gcc -o $@ $^ -O2 -g
