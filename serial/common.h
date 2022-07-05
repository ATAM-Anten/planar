#ifndef COMMON_H
#define COMMON_H

#include <string>

class NoIniSettingFound{};
class InvalidParameter{};

int ex_atoi(){
    int num = 0;
    for(char *ch = argv[2]; (*ch)!='\0'; ch++){
        if((*ch)<'0' || (*ch)>'9')
            throw InvalidParameter();
        num = (num*10) + (*ch) - '0';
    }
    return num;
}

string getPortIni(
#ifndef axis
const string &axis
#endif
){
	unsigned int port = GetPrivateProfileInt("Ports", axis, 0, ".\\settings.ini");
	if (port==0){
		throw NoIniSettingFound();
	}
	return to_string(port);
}

#endif
