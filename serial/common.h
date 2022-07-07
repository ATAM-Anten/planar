#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <Windows.h>
#include <iostream>
using namespace std;

int ex_atoi(char *param);

unsigned int getPortIni(
#ifndef axis
char *axis
#endif
);

#endif