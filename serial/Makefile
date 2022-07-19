CC = g++
FLAGS = -m32 -std=c++11 -Os

all: move.inc move.abs position port.get port.set home

move.inc move.abs position home: portController.o x.common.o y.common.o
	$(CC) $(FLAGS) -c -Daxis='"X"' $@.cpp -o x.$@.o
	$(CC) $(FLAGS) -c -Daxis='"Y"' $@.cpp -o y.$@.o
	$(CC) $(FLAGS) x.$@.o x.common.o portController.o -o ../x.$@.exe
	$(CC) $(FLAGS) y.$@.o y.common.o portController.o -o ../y.$@.exe

port.get port.set: common.o
	$(CC) $(FLAGS) -c $@.cpp -o $@.o
	$(CC) $(FLAGS) $@.o $^ -o ../$@.exe

portController.o:
	$(CC) $(FLAGS) -c portController.cpp -o portController.o

common.o:
	$(CC) $(FLAGS) -c common.cpp -o common.o
x.common.o:
	$(CC) $(FLAGS) -c -Daxis='"X"' common.cpp -o x.common.o
y.common.o:
	$(CC) $(FLAGS) -c -Daxis='"Y"' common.cpp -o y.common.o

clean:
	del /Q /S *.o *.exe