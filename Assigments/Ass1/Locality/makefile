.PHONY:all clean
all: locality_O0 locality_O2 locality_O2_native

locality_O0 : locality.c
	-gcc -o $@ $^ -O0 -g
locality_O2 : locality.c
	-gcc -o $@ $^ -O2 -g

locality_O2_native : locality.c
	-gcc -o $@ $^ -O2 -march=native -g

locality_O0 : locality.c
	-gcc -o $@ $^ -O0 -g
locality_O2 : locality.c
	-gcc -o $@ $^ -O2 -g

locality_O2_native : locality.c
	-gcc -o $@ $^ -O2 -march=native -g
