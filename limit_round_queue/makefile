CC = gcc
CXXFLAGS = -Wall -W -O2
TARGET = Runfile

OBJ = main.o dequeue.o is_empty.o enqueue.o initqueue.o print_queue.o is_full.o

# create out file (target name)
# before make obj
all: $(OBJ)
		$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJ)

# create obj file (func name = obj name)
main.o: main.c
		$(CC) -c main.c

dequeue.o: dequeue.c
		$(CC) -c dequeue.c

is_full.o: is_full.c
		$(CC) -c is_full.c

is_empty.o: is_empty.c
		$(CC) -c is_empty.c

enqueue.o: enqueue.c
		$(CC) -c enqueue.c

print_queue.o: print_queue.c
		$(CC) -c print_queue.c

initqueue.o: initqueue.c
		$(CC) -c initqueue.c

clean:
	rm -r *.o 
	rm -r $(TARGET)
