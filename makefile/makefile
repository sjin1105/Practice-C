CC = gcc

# flags
# -Wall (모호한 코딩에 대한 경고 옵션)
# -W (합법적이지만 모호한 코딩에 대해서 경고)
# -O2 (최적화 레벨을 2로 설정)
CXXFLAGS = -Wall -W -O2
TARGET = Runfile

OBJ = main.o

# create out file (target name)
# before make obj
all: $(OBJ)
		$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJ)

# create obj file (func name = obj name)
main.o: main.c
		mkdir hello
		$(CC) -c main.c

clean:
	rmdir hello
	rm -r *.o 
	@if [ -e $(TARGET) ] ; then \
		rm -r $(TARGET); \
		echo "del $(TARGET)"; \
	fi
