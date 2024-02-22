CC=gcc
OBJECTS_MAIN=StrList.o Main.o
CFLAGS=-Wall -g

all: StrList

StrList: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o StrList $(OBJECTS_MAIN) 

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c StrList.c

Main.o: Main.c StrList.h
	$(CC) $(CFLAGS) -c Main.c

clean:
	rm -f *.o StrList
