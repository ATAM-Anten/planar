#include <iostream>
#include <Windows.h>
#include "common.h"
#include "../param.h"

using namespace std;

int main(int argc, char **argv){
	string help = "This program will set the port number of the given axis. First argument should be \
x or y and second argument should be the desired COM port number (write 1 if COM1 is meant.)";
	params(argc, argv, help);
    if(argc <3){
        cerr << "At least 2 arguments are required!";
        return 0;
    }
    int num = ex_atoi(argv[2]);
    if(num<1 || num>255){
        cerr << "Invalid Parameter entered" << endl;
        return 0;
    }

    for(char* c=argv[1]; (*c)=toupper(*c); c++);
    WritePrivateProfileString("Ports", argv[1], argv[2], ".\\settings.ini");
    return 0;
}