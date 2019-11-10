WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

#TESTFALGS = -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE

SRCS = main.c shuffle.c
OBJS = $(SRCS:%.c=%.o)

hw11: $(OBJS)
	$(GCC) $(OBJS) -o hw11

.c.o:
	$(GCC) -c $*.c

testmemory4: hw11
	$(VAL) ./hw11 4 3 | sort | uniq > output4

testmemory5: hw11
	$(VAL) ./hw11 5 2 | sort | uniq > output5

testmemory6: hw11
	$(VAL) ./hw11 6 2 | sort | uniq > output6

testmemory11: hw11
	$(VAL) ./hw11 11 2 | sort | uniq > output11


testall: test4 test5 test6 test11


test4: hw11
	./hw11 4 3 | sort | uniq > output4 
	diff -w output4 expected/expected_4_3

test5: hw11
	./hw11 5 2 | sort | uniq > output5 
	diff -w output5 expected/expected_5_2

test6: hw11
	./hw11 6 2 | sort | uniq > output6 
	diff -w output6 expected/expected_6_2

test11: hw11
	./hw11 11 2 | sort | uniq > output11 
	diff -w output11 expected/expected_11_2 

clean: 
	rm -f hw11 *.o output*

