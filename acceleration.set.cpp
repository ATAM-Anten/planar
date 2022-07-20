#include <iostream>
#include "common_modbus.h"
#include "param.h"

using namespace std;

int main(int argc, char **argv){
	string help = "This program will set the desired acceleration rate given with the parameter.";
	params(argc, argv, help);
	if(argc!=2){
		cout << "This program works with 1 parameter" << endl;
		return 0;
	}
	union int_arr acc;
	acc.int32 = atoi(argv[1]);

    common_modbus mb;

	mb.write_register_loop(1536, 2, acc.uint16);
	mb.write_register_loop(1664, 2, acc.uint16);
    return 0;
}
