/*
 *
 *  PIC16F1 EEPROM Library  Version 0.1
 *  (C) 2014 Kazusa Okuda (a.k.a. klaNath)
 *
 *  This software is freely distributable under the terms of an MIT-style license.
 *  For details, see the https://github.com/klaNath/programable_switcher.git/LICENSE
 *
 */

#include <xc.h>

char eepromRead(unsigned char adrs )
{
    char RData;

    EEADRL = adrs;
    EECON1bits.CFGS = 0;
    EECON1bits.EEPGD = 0;
    EECON1bits.RD = 1;
    RData = EEDATL ;

    return (RData);
}

void eepromWrite(unsigned char Adrs, char Data)
{

    EEADRL = Adrs;
    EEDATL = Data;
    EECON1bits.CFGS = 0;
    EECON1bits.EEPGD = 0;
    EECON1bits.WREN = 1;
    INTCONbits.GIE = 0;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;
    INTCONbits.GIE = 1;
    while(EECON1bits.WR = 1)
    {
        asm("nop");
    }

    return;
}