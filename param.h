#ifndef PARAM_H
#define PARAM_H

#include <string>
#include <iostream>

using namespace std;

void params(int argc, char *argv[], const string &help){
	if(argc >= 2){
		if(argv[1][0]=='-'){
			if(string(argv[1])=="--help" || string(argv[1])=="-h"){
				cout << help << endl;
				exit(0);
			}
		}
	}
}

#endif