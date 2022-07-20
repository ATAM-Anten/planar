#include <iostream>
#include "common_modbus.h"
#include "param.h"

using namespace std;

int main(int argc, char **argv){
	string help = "This program will set the desired speed rate given with the parameter.";
	params(argc, argv, help);
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
