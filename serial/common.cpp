#include "common.h"
using namespace std;

int ex_atoi(char *param){
    int num = 0;
    for(char *ch = param; (*ch)!='\0'; ch++){
        if((*ch)<'0' || (*ch)>'9')
            cerr << "Invalid parameter" << endl;
            exit(0);
        num = (num*10) + (*ch) - '0';
    }
    return num;
}

unsigned int getPortIni(
#ifndef axis
char *axis
#endif
){
	unsigned int port = GetPrivateProfileInt("Ports", axis, 0, ".\\settings.ini");
	if (port==0){
		cerr << ".ini setting not found" << endl;
        exit(0);
	}
	return port;
}
