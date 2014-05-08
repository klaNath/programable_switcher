/*
 *
 *  Programable Switcher For PIC 16F1, PSW-1 Version 0.0.1
 *  (C) 2014 Kazusa Okuda (a.k.a. klaNath)
 *
 *  PSW-1 is freely distributable under the terms of an MIT-style license.
 *  For details, see the https://github.com/klaNath/programable_switcher.git/LICENSE
 *
 */

#ifndef _PSW_H
#define _PSW_H

extern char IfSettingPSW;
extern int SysTick;
extern int PrevSysTick;
extern unsigned char PushedSW;
extern unsigned char RanSetting;


void incSysTick();
void initSystem();
void initPSW();

void PSW(unsigned char);
void settingPSW(unsigned char);

void loadSetting();
void updateView();
void updateLoop();
void storeData();


#endif