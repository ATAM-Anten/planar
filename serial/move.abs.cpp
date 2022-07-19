#include <iostream>
#include <string>
#include <Windows.h>
#include "portController.h"
#include "common.h"

using namespace std;

int main(int argc, char **argv){
    // First parameter is position, second parameter is speed, third parameter is acceleration
    if(argc<4){
        cerr << "This program works with at least 3 arguments!" << endl;
        return 0;
    }
    ex_atoi(argv[1]);
    ex_atoi(argv[2]);
    ex_atoi(argv[3]);
    try{
        PortController ser("\\\\.\\COM"+to_string(getPortIni()));
        ser.writeData("ORDER 201 " + string(argv[1]) + " " + string(argv[2]) + " 8192 " + string(argv[3])+" " + string(argv[3]) +" 0 0 0 0\r\nMOVE 201\r\n");
    } catch (PortControllerException err){
        cerr << err.getMessage();
    }
    return 0;
}
