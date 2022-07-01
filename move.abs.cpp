#include <iostream>
#include "common.h"

using namespace std;

int main(int argc, char **argv){
	if(argc!=2){
		cout << "This program works with 1 parameter" << endl;
		return 0;
	}
	
	int pos = atoi(argv[1]);
	
    // create a modbus object
    common_modbus mb;
	
    mb.modbus_write_register(125, 0);
    mb.modbus_write_register(125, 128);
	
	mb.modbus_write_register(1024,0);
	mb.modbus_write_register(1025,pos);
	
	mb.modbus_write_register(1281, 1);

	mb.modbus_write_register(125,0);
	mb.modbus_write_register(125,8);

    return 0;
}
