.PHONY:all clean
all: data_O0 data_O2 data_O2_native

data_O0 : data_dependency.c
	-gcc -o $@ $^ -O0 -g
data_O2 : data_dependency.c
	-gcc -o $@ $^ -O2 -g

data_O2_native : data_dependency.c
	-gcc -o $@ $^ -O2 -march=native -g


