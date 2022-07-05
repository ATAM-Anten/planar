#include <iostream>
#include "common_modbus.h"

using namespace std;

int main(int argc, char **argv){
    common_modbus mb;
	
    uint16_t h_alarm[1], l_alarm[1];
    union int_arr position1, position2;
    mb.read_holding_register_loop(204, 2, position1.uint16);
	int bef_time = GetTickCount();
	Sleep(100);
    mb.read_holding_register_loop(204, 2, position2.uint16);
	int aft_time = GetTickCount();
	
	cout << "Speed: "<< (position2.int32-position1.int32)*1000/(aft_time-bef_time) << endl;

    return 0;
}
