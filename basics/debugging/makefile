.PHONY : all
all : gdb_example gdb_example_noassertion valgrind_example

gdb_example : gdb_example.c
	gcc -o gdb_example gdb_example.c -g -Og 
	//g instructs the debugger to include info in the binary. 
	//very important. Og tryes to say that it should not try to optimize to much. It wtill need to run the code

gdb_example_noassertion : gdb_example.c
	gcc -o gdb_example_noassertion gdb_example.c -g -Og -D NDEBUG
	//D NDEBUG is a definition flag

valgrind_example : valgrind_example.c
	gcc -o valgrind_example valgrind_example.c -g
