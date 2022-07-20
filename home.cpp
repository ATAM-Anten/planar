#include <iostream>
#include "common_modbus.h"
#include "param.h"

using namespace std;

int main(int argc, char **argv){
	string help = "This program will move the motor to the relative home point, 0.";
	params(argc, argv, help);
    // create a modbus object
    common_modbus mb;
   
	mb.modbus_write_register(125,0);
	mb.modbus_write_register(125,128);

	mb.modbus_write_register(125,0);
	mb.modbus_write_register(125,16);

    return 0;
}
