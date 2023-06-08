CC = gcc
CXXFLAGS = -Wall -W -O2
TARGET = Runfile

OBJ = linked_list.o

# create out file (target name)
# before make obj
all: $(OBJ)
		$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJ)

# create obj file (func name = obj name)
linked_list.o: linked_list.c
		$(CC) -c linked_list.c

clean:
	rm -r *.o 
	rm -r $(TARGET)
