CC = gcc
CXXFLAGS = -Wall -W -O2
TARGET = Runfile

OBJ = main.o queue.o inout.o

# create out file (target name)
# before make obj
all: $(OBJ)
		$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJ) -lpthread

# create obj file (func name = obj name)
main.o: main.c
		$(CC) -c main.c

queue.o: queue.c
		$(CC) -c queue.c

inout.o: inout.c
		$(CC) -c inout.c

clean:
	rm -r *.o
	rm -r $(TARGET)
	rm -r *.txt