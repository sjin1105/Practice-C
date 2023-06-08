CC = gcc
CXXFLAGS = -Wall -W -O2
TARGET = Runfile

OBJ = stack.o

# create out file (target name)
# before make obj
all: $(OBJ)
		$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJ)

# create obj file (func name = obj name)
stack.o: stack.c
		$(CC) -c stack.c

clean:
	rm -r *.o 
	rm -r $(TARGET)
