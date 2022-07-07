CC = g++
FLAGS = -m32 -std=c++11 -Os

LL = -lws2_32

all: xy home status move.inc move.abs speed.set speed.get acceleration.set

home status move.inc move.abs speed.set speed.get acceleration.set:
	$(CC) $(FLAGS) -DID=1 $@.cpp -o z.$@.exe $(LL)
	$(CC) $(FLAGS) -DID=2 $@.cpp -o phi.$@.exe $(LL)

xy:
	$(MAKE) -C serial

clean:
	del /Q /S *.o *.exe