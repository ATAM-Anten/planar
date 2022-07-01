#ifndef ID
#error No ID given for modbus slave!
#else
	
#include <iostream>
#include "modbus.h"

using namespace std;

int main(int argc, char **argv){
	if(argc!=2){
		cout << "This program works with 1 parameter" << endl;
		return 0;
	}
	
	int pos = atoi(argv[1]);
    // create a modbus object
    modbus mb = modbus("192.168.1.221", 502);

    // set slave id
    mb.modbus_set_slave_id(ID);

    // connect with the server
    mb.modbus_connect();
	
    mb.modbus_write_register(125, 0);
    mb.modbus_write_register(125, 128);
	
	if (pos<0){
		mb.modbus_write_register(1024,(1<<16)-1);
		mb.modbus_write_register(1025,(1<<16)+pos);
	}
	else{
		mb.modbus_write_register(1024,0);
		mb.modbus_write_register(1025,pos);
	}
	
	mb.modbus_write_register(1281, 2);

	mb.modbus_write_register(125,0);
	mb.modbus_write_register(125,8);

    // close connection and free the memory
    mb.modbus_close();
    return 0;
}
#endif
