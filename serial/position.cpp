#include <iostream>
#include <string>
#include <Windows.h>
#include "portController.h"

using namespace std;

int main(int argc, char **argv){
    PortController ser("\\\\.\\COM"+getPortIni());
    ser.writeData("PFB\r\n");
    cout << "Position: " << ser.readData() << endl;
    return 0;
}