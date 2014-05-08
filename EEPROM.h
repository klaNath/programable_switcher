/*
 *
 *  PIC16F1 EEPROM Library  Version 0.1
 *  (C) 2014 Kazusa Okuda (a.k.a. klaNath)
 *
 *  This software is freely distributable under the terms of an MIT-style license.
 *  For details, see the https://github.com/klaNath/programable_switcher.git/LICENSE
 *
 */


#ifndef _EEPROM_H
#define _EEPROM_H

char eepromRead(unsigned char);
void eepromWrite(unsigned char, char);

#endif