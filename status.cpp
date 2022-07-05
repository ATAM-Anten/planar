#include <iostream>
#include "common_modbus.h"

using namespace std;

int main(int argc, char **argv){
    common_modbus mb;
	
    uint16_t h_alarm[1], l_alarm[1];
    union int_arr position;
    mb.read_holding_register_loop(204, 2, position.uint16);
    mb.modbus_read_holding_registers(129, 1, l_alarm);
    mb.modbus_read_holding_registers(128, 1, h_alarm);
	
	cout << "Position: "<< position.int32 << endl;
	cout << "Low Alarm: "<< l_alarm[0] << endl;
	cout << "High Alarm: "<< h_alarm[0] << endl;

    return 0;
}
