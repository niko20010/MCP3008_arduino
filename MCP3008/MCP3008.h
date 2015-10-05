 
#ifndef MCP3008_h
#define MCP3008_h


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#error "Arduino IDE below v1.0 is not supported!"
#endif

  

class ND_MCP3008
{
    public:
        ND_MCP3008(int CS);
        uint16_t read_single_channel(uint8_t channelnum);
    private:
        const byte channels[8]={0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F};
        int _SLAVESELECT;
};

#endif