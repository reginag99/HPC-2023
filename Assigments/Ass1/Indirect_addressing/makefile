
.PHONY:all clean
all: indirect_O0 indirect_O2 indirect_O2_native

.PHONY: all1 clean
all1: indirect1_O0 indirect1_O2 indirect1_O2_native

.PHONY: all2 clean
all2: indirect2_O0 indirect2_O2 indirect2_O2_native

.PHONY: all3 clean
all3: indirect3_O0 indirect3_O2 indirect3_O2_native

indirect_O0 : indirect.c
	-gcc -o $@ $^ -O0 -g
indirect_O2 : indirect.c
	-gcc -o $@ $^ -O2 -g

indirect_O2_native : indirect.c
	-gcc -o $@ $^ -O2 -march=native -g



indirect1_O0 : indirect1.c
	-gcc -o $@ $^ -O0 -g
indirect1_O2 : indirect1.c
	-gcc -o $@ $^ -O2 -g

indirect1_O2_native : indirect1.c
	-gcc -o $@ $^ -O2 -march=native -g







indirect2_O0 : indirect2.c
	-gcc -o $@ $^ -O0 -g
indirect2_O2 : indirect2.c
	-gcc -o $@ $^ -O2 -g

indirect2_O2_native : indirect2.c
	-gcc -o $@ $^ -O2 -march=native -g


indirect3_O0 : indirect3.c
	-gcc -o $@ $^ -O0 -g
indirect3_O2 : indirect3.c
	-gcc -o $@ $^ -O2 -g

indirect3_O2_native : indirect3.c
	-gcc -o $@ $^ -O2 -march=native -g
