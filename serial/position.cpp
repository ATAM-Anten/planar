#include <iostream>
#include <string>
#include <Windows.h>
#include "portController.h"
#include "common.h"

using namespace std;

int main(int argc, char **argv){
    try{
        PortController ser("\\\\.\\COM"+getPortIni());
        ser.writeData("PFB\r\n");
        cout << "Position: " << ser.readData() << endl;
    } catch (PortControllerException err){
        cerr << err.getMessage();
    }
    return 0;
}