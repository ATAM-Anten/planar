#ifndef ID
#error No ID given for modbus slave!
#else

#include <iostream>
#include "modbus.h"

using namespace std;

int main(int argc, char **argv){
    // create a modbus object
    modbus mb = modbus("192.168.1.221", 502);

    // set slave id
    mb.modbus_set_slave_id(ID);

    // connect with the server
    mb.modbus_connect();
   
	mb.modbus_write_register(125,0);
	mb.modbus_write_register(125,128);

	mb.modbus_write_register(125,0);
	mb.modbus_write_register(125,16);

    // close connection and free the memory
    mb.modbus_close();
    return 0;
}
#endif
