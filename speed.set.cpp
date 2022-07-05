#include <iostream>
#include "common_modbus.h"

using namespace std;

int main(int argc, char **argv){
	if(argc!=2){
		cout << "This program works with 1 parameter" << endl;
		return 0;
	}
	int speed = atoi(argv[1]);

    // create a modbus object
    common_modbus mb;
	mb.modbus_write_register(1153, speed);
    return 0;
}
