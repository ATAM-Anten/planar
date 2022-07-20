#include <iostream>
#include <string>
#include <Windows.h>
#include "common.h"
#include "../param.h"

using namespace std;

int main(int argc, char **argv){
	string help = "This program will return the current port of the requested axis.";
	params(argc, argv, help);
    if(argc <2){
        cerr << "At least 1 arguments are required!";
        return 0;
    }
    cout << "Port: COM" << getPortIni(argv[1]) << endl;
    return 0;
}