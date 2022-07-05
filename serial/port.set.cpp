#include <iostream>
#include <Windows.h>
#include "common.h"

using namespace std;

int main(int argc, char **argv){
    if(argc <3){
        cerr << "At least 2 arguments are required!";
    }
    int num = ex_atoi(argv[2]);
    if(num<1 || num>255)
        throw InvalidParameter();
    for(char* c=argv[1]; (*c)=toupper(*c); c++);
    WritePrivateProfileString("Ports", argv[1], argv[2], ".\\settings.ini");
    return 0;
}