#CC = g++
CC = gcc
CXXFLAGS = -Wall -W -O2
TARGET = Runfile

OBJ = first.o second.o third.o

# create out file (target name)
# before make obj
all: $(OBJ)
		$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJ)

# create obj file (func name = obj name)
first.o: first.c
		$(CC) -c first.c

second.o: second.c
		$(CC) -c second.c

third.o: third.c
		$(CC) -c third.c

clean:
	rm -r *.o
#	rm -r $(TARGET)
	@if [ -e $(TARGET) ] ; then \
		rm -r $(TARGET); \
		echo "del $(TARGET)"; \
	fi