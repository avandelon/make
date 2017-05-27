CC := gcc
CFLAGS :=  -std=c99 -Wall -Werror -O0 -fprofile-arcs -ftest-coverage
rk2.exe : rk2.o read_array.o merge.o sdvig.o
	$(CC) $(CFLAGS) $^ -o $@ 
%.o: %.c
	$(CC) $(CFLAGS) -c $<
gcov: rk2.c read_array.c merge.c
	gcov rk2.c read_array.c merge.c
clean:
	rm *.o *.exe *.gcno *.gcda *.gch *.gcov