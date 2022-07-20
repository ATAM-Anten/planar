#include <iostream>
#include <string>
#include <Windows.h>
#include "portController.h"
#include "common.h"
#include "../param.h"

using namespace std;

int main(int argc, char **argv){
	string help = "This program will move the motor to the relative home point, 0.";
	params(argc, argv, help);
    try{
        PortController ser("\\\\.\\COM"+to_string(getPortIni()));
        ser.writeData("MH\r\n");
    } catch (PortControllerException err){
        cerr << err.getMessage();
    }
    return 0;
}