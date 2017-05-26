CC := gcc
CFLAGS :=  -std=c99 -Wall -Werror -o0 -fprofile-arcs -ftest-coverage
CFLAGS2 := -std=c99 -Wall -Werror
rk2.exe : rk2.o read_array.o merge.o sdvig.o
	$(CC) $(CFLAGS) $^ -o $@ 
%.o: %.c *.h
	$(CC) $(CFLAGS2) -c $<
gcov: rk2.c read_array.c merge.c
	gcov rk2.c read_array.c merge.c
clean:
	rm *.o *.exe *.gcno *.gcda *.gch *.gcov