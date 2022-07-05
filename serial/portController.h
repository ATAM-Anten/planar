#ifndef PORTCONTROLLER_H
#define PORTCONTROLLER_H

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class PortControllerException {

public:
   	PortControllerException(const string& where);
  	~PortControllerException();
   	string getMessage() const;
private:
   	string msg;
};

class PortController{
private:
	HANDLE rs232;

public:
	PortController(const string& port);
	~PortController();
	void writeData(const string& data);
	string readData();
};

#endif
