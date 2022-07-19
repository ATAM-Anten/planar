#include <iostream>
#include <string>
#include <Windows.h>
#include "portController.h"
#include "common.h"

using namespace std;

int main(int argc, char **argv){
    try{
        PortController ser("\\\\.\\COM"+to_string(getPortIni()));
        ser.writeData("MH\r\n");
    } catch (PortControllerException err){
        cerr << err.getMessage();
    }
    return 0;
}