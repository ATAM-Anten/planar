#include "portController.h"

using namespace std;

PortControllerException::PortControllerException(const string& where) {
	msg = "Failure at " + where + ": " + to_string(GetLastError()) + "\n";
}
PortControllerException::~PortControllerException() {}

string PortControllerException::getMessage() const {return(msg);}

PortController::PortController(const string& port){
	rs232 = CreateFileA (&port[0], GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
	if (rs232 == INVALID_HANDLE_VALUE){
		throw PortControllerException("CreateFile");
	}

	// Get & Set CommState
	DCB port_configuration;
	int err = GetCommState (rs232, &port_configuration);
	if (err <= 0){
		throw PortControllerException("GetCommState");
	}
	port_configuration.BaudRate = 38400;
	port_configuration.ByteSize = 8;
	port_configuration.Parity = 0;
	port_configuration.StopBits = 0;
	port_configuration.DCBlength = sizeof (port_configuration);
	err = SetCommState (rs232, &port_configuration);
	if (err <= 0){
		throw PortControllerException("SetCommState");
	}

	// SetCommTimeouts
	COMMTIMEOUTS timeout_configuration;
	timeout_configuration.ReadIntervalTimeout = 1;// MAXDWORD;
	timeout_configuration.ReadTotalTimeoutMultiplier = 1;// 0;
	timeout_configuration.ReadTotalTimeoutConstant = 1;// 0;
	timeout_configuration.WriteTotalTimeoutMultiplier = 1;// 0;
	timeout_configuration.WriteTotalTimeoutConstant = 1;// 0;
	err = SetCommTimeouts (rs232, &timeout_configuration);
	if (err <= 0){
		throw PortControllerException("SetCommTimeouts");
	}
}

PortController::~PortController(){
	CloseHandle (rs232);
}

void PortController::writeData(const string& data){
	DWORD buffer_size_w;
	// char buffer_w[128]="MH\r\n";
	int err = WriteFile (rs232, &data[0], data.size(), &buffer_size_w, 0);
	if (err <= 0){
		throw PortControllerException("WriteFile");
	}
}

string PortController::readData(){
	DWORD buffer_size_r;
	char buffer_r[128] = {0};
	int err = ReadFile (rs232, buffer_r, 128, &buffer_size_r, 0);
	if (err <= 0){
		throw PortControllerException("ReadFile");
	}
	return string(buffer_r);
}
