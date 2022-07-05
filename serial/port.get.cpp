#include <iostream>
#include <string>
#include <Windows.h>
#include "common.h"

using namespace std;

int main(int argc, char **argv){
    if(argc <2){
        cerr << "At least 1 arguments are required!";
    }
    cout << "Port: COM" << getPortIni(string(argv[1])) << endl;
    return 0;
}