GCC = gcc
FLAGS = -ansi -pedantic -Wall -std=c99 -pthread
PROGRAMAS = matricesApp

matricesApp:
	$(GCC) $(FLAGS) funcionmatrices.c -c
	$(GCC) $(FLAGS) ctime.c -c
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) -o $@ $@.o funcionmatrices.o ctime.o

clean:
	$(RM) $(PROGRAMAS) *.o
