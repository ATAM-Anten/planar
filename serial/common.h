#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <Windows.h>
using namespace std;

class NoIniSettingFound{};
class InvalidParameter{};

int ex_atoi(char *param);

string getPortIni(
#ifndef axis
char *axis
#endif
);

#endif