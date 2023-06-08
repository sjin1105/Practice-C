CC = gcc
CXXFLAGS = -Wall -W -O2
TARGET = Runfile

OBJ = pthread.o

# create out file (target name)
# before make obj
all: $(OBJ)
		$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJ) -lpthread

# create obj file (func name = obj name)
pthread.o: pthread.c
		$(CC) -c pthread.c

clean:
	rm -r *.o 
	rm -r $(TARGET)
