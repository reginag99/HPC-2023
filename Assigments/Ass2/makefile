
all: newton

newton : function_test.c
	gcc -o newton function_test.c -O3 -g -lpthread -lm

run: newton
	./newton -t1 -l1000 1
	./newton -t1 -l1000 2
	./newton -t1 -l1000 5
	./newton -t1 -l1000 7

	./newton -t1 -l1000 5
	./newton -t2 -l1000 5
	./newton -t3 -l1000 5
	./newton -t4 -l1000 5

	./newton -t10 -l1000 7
	./newton -t10 -l2000 7
	./newton -t10 -l3000 7

	make clean

clean:
	rm -f newton

.PHONY: run clean













read_in : read_in.c
	gcc -o $@ $< -O1 -g
ellens : ellens.c
	gcc -o $@ $< -O1 -g

Lisas : Lisas.c
	gcc -o $@ $< -O1 -g

min : min.c
	gcc -o $@ $< -O1 -g

Ass2Open_hemma : Ass2Open_hemma.c
	gcc -o $@ $< -O1 -g -lm

OpenMP_hemma : OpenMP_hemma.c
	gcc -o $@ $< -O1 -g -lm

Lisa2 : Lisa2.c
	gcc -o $@ $< -O1 -g -lm

martin_comments : martin_comments.c
	gcc -o $@ $< -O1 -g -lm -fopenmp


cell_distances: cell_distances.c
	gcc -o $@ $< -O2 -g -fopenmp -lm
