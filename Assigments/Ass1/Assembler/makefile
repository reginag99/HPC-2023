CC = gcc 
CFLAGS = -O2 -maech=native

include_const : \
	include_const.c
	$(CC) $(CFLAGS)  $@ 
.PHONY : all
all : naive_O0_gdb naive_O1_gdb naive_O2_gdb naive_O3_gdb naive_Og_gdb naive_Os_gdb

naive_O0_gdb : naive_bench.c
	gcc -o $@ $< -O1 -g

naive_O1_gdb : naive_bench.c
	gcc -o $@ $< -O1 -g

naive_O2_gdb : naive_bench.c
	gcc -o $@ $< -O2 -g

naive_O3_gdb : naive_bench.c
	gcc -o $@ $< -O3 -g

naive_Os_gdb : naive_bench.c
	gcc -o $@ $< -Os -g

naive_Og_gdb : naive_bench.c
	gcc -o $@ $< -Og -g

naive_gdb : naive_bench.c
	gcc -o $@ $< -g

