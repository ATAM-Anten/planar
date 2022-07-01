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
	
    uint16_t position[1], h_alarm[1], l_alarm[1];
    mb.modbus_read_holding_registers(205, 1, position);
    mb.modbus_read_holding_registers(129, 1, l_alarm);
    mb.modbus_read_holding_registers(128, 1, h_alarm);
	
	cout << "Position: "<< position[0] << endl;
	cout << "Low Alarm: "<< l_alarm[0] << endl;
	cout << "High Alarm: "<< h_alarm[0] << endl;

    // close connection and free the memory
    mb.modbus_close();
    return 0;
}
#endif
