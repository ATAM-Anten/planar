CC = g++
FLAGS = -m32 -std=c++11

LL = -lws2_32

all: home status move.inc move.abs speed.set speed.get acceleration.set

home:
	$(CC) $(FLAGS) -DID=1 $@.cpp -o z.$@.exe $(LL)
	$(CC) $(FLAGS) -DID=2 $@.cpp -o phi.$@.exe $(LL)

status:
	$(CC) $(FLAGS) -DID=1 $@.cpp -o z.$@.exe $(LL)
	$(CC) $(FLAGS) -DID=2 $@.cpp -o phi.$@.exe $(LL)

move.inc:
	$(CC) $(FLAGS) -DID=1 $@.cpp -o z.$@.exe $(LL)
	$(CC) $(FLAGS) -DID=2 $@.cpp -o phi.$@.exe $(LL)

move.abs:
	$(CC) $(FLAGS) -DID=1 $@.cpp -o z.$@.exe $(LL)
	$(CC) $(FLAGS) -DID=2 $@.cpp -o phi.$@.exe $(LL)

speed.set:
	$(CC) $(FLAGS) -DID=1 $@.cpp -o z.$@.exe $(LL)
	$(CC) $(FLAGS) -DID=2 $@.cpp -o phi.$@.exe $(LL)

speed.get:
	$(CC) $(FLAGS) -DID=1 $@.cpp -o z.$@.exe $(LL)
	$(CC) $(FLAGS) -DID=2 $@.cpp -o phi.$@.exe $(LL)

acceleration.set:
	$(CC) $(FLAGS) -DID=1 $@.cpp -o z.$@.exe $(LL)
	$(CC) $(FLAGS) -DID=2 $@.cpp -o phi.$@.exe $(LL)

clean:
	del /Q /S *.o *.exe