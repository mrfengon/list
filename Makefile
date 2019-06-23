CC = gcc

CCFLAGS = -g

OBJ = list.o main.o

.SUFFIXES: .c .o

main: $(OBJ)
	@$(CC) $(CCFLAGS) $(OBJ) -o main

main.o: list.o
	$(CC) -c $(CCFLAGS) main.c

list.o: list.h list.c
	$(CC) -c $(CCFLAGS) list.h list.c

clean:
	@rm -f *.o *.gch main