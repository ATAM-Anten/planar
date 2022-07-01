#ifndef COMMON_H
#define COMMON_H

#ifndef ID
#error No ID given for modbus slave!
#endif

#include "modbus.h"

union int_arr{
    uint16_t uint16[2];
    int int32;
};

class Connection_Failed{};

class common_modbus : public modbus{
    public:
    // create a modbus object
    common_modbus() : modbus("192.168.1.221", 502){
        // set slave id
        modbus::modbus_set_slave_id(ID);
        // connect with the server
        if (!modbus::modbus_connect()){
            throw Connection_Failed();
        }
    }

    ~common_modbus(){
        // close connection and free the memory
        modbus::modbus_close();
    }

    inline void read_holding_register_loop(uint16_t start_address, uint16_t amount, uint16_t *buffer){
        for(int i=0; i<amount; i++)
            modbus::modbus_read_holding_registers(start_address+i, 1, buffer+amount-1-i);
    }

    inline void write_register_loop(uint16_t start_address, uint16_t amount, uint16_t *buffer){
        for(int i=0; i<amount; i++)
		    modbus::modbus_write_register(start_address+i, *(buffer+amount-1-i));
    }
};

#endif