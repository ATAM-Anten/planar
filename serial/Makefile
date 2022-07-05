CC = g++
FLAGS = -m32 -std=c++11

LL = 

all: move.inc move.abs position port.get port.set

move.inc:
	$(CC) $(FLAGS) -Daxis='"X"' $@.cpp -o x.$@.exe $(LL)
	$(CC) $(FLAGS) -Daxis='"Y"' $@.cpp -o y.$@.exe $(LL)

move.abs:
	$(CC) $(FLAGS) -Daxis='"X"' $@.cpp -o x.$@.exe $(LL)
	$(CC) $(FLAGS) -Daxis='"Y"' $@.cpp -o y.$@.exe $(LL)

position:
	$(CC) $(FLAGS) -Daxis='"X"' $@.cpp -o x.$@.exe $(LL)
	$(CC) $(FLAGS) -Daxis='"Y"' $@.cpp -o y.$@.exe $(LL)

port.get:
	$(CC) $(FLAGS) $@.cpp -o $@.exe $(LL)
	
port.set:
	$(CC) $(FLAGS) $@.cpp -o $@.exe $(LL)

clean:
	del /Q /S *.o *.exe