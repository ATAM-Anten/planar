#include <iostream>
#include <string>
#include <Windows.h>
#include "portController.h"
#include "common.h"
#include "../param.h"

using namespace std;

int main(int argc, char **argv){
	string help = "This program will get the position value.";
	params(argc, argv, help);
    try{
        PortController ser("\\\\.\\COM"+to_string(getPortIni()));
        ser.writeData("PFB\r\n");
        cout << "Position: " << ser.readData() << endl;
    } catch (PortControllerException err){
        cerr << err.getMessage();
    }
    return 0;
}