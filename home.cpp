#include <iostream>
#include "common_modbus.h"

using namespace std;

int main(int argc, char **argv){
    // create a modbus object
    common_modbus mb;
   
	mb.modbus_write_register(125,0);
	mb.modbus_write_register(125,128);

	mb.modbus_write_register(125,0);
	mb.modbus_write_register(125,16);

    return 0;
}
