#include <iostream>
#include "common.h"

using namespace std;

int main(int argc, char **argv){
	if(argc!=2){
		cout << "This program works with 1 parameter" << endl;
		return 0;
	}
	union int_arr pos;
	pos.int32 = atoi(argv[1]);

    common_modbus mb;
	
    mb.modbus_write_register(125, 0);
    mb.modbus_write_register(125, 128);

	mb.write_register_loop(1024, 2, pos.uint16);
	
	mb.modbus_write_register(1281, 2);

	mb.modbus_write_register(125,0);
	mb.modbus_write_register(125,8);
    return 0;
}
