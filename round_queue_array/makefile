CC = gcc
CXXFLAGS = -Wall -W -O2
TARGET = Runfile

OBJ = main.o

# create out file (target name)
# before make obj
all: $(OBJ)
		$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJ)

# create obj file (func name = obj name)
main.o: main.c
		$(CC) -c main.c

clean:
	rm -r *.o 
	rm -r $(TARGET)
