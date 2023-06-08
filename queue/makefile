CC = gcc
CXXFLAGS = -Wall -W -O2
TARGET = Runfile

OBJ = queue.o

# create out file (target name)
# before make obj
all: $(OBJ)
		$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJ)

# create obj file (func name = obj name)
queue.o: queue.c
		$(CC) -c queue.c

clean:
	rm -r *.o 
	rm -r $(TARGET)
