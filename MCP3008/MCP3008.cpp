 
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#error "Arduino IDE below v1.0 is not supported!"
#endif

#include <SPI.h>
#include "MCP3008.h"



SPISettings MCP3008(8000000, MSBFIRST, SPI_MODE0);

ND_MCP3008::ND_MCP3008(int CS)
{
    _SLAVESELECT = CS;
    pinMode(_SLAVESELECT,OUTPUT);
    digitalWrite(_SLAVESELECT,LOW);
    digitalWrite(_SLAVESELECT,HIGH);
    
    SPI.begin();
}





uint16_t ND_MCP3008::read_single_channel(uint8_t channelnum){
    byte dataMSB =    0;
    byte dataLSB =    0;
    byte JUNK    = 0x00;
    
    SPI.beginTransaction (MCP3008);
    digitalWrite         (_SLAVESELECT, LOW);
    SPI.transfer         (0x01);                                 // Start Bit
    dataMSB =            SPI.transfer(channels[channelnum] << 4) & 0x03;  // Send readAddress and receive MSB data, masked to two bits
    dataLSB =            SPI.transfer(JUNK);                     // Push junk data and get LSB byte return
    digitalWrite         (_SLAVESELECT, HIGH);
    SPI.endTransaction   ();
    return ((dataMSB << 8 | dataLSB));
}