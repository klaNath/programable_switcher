/*
 *
 *  Programable Switcher For PIC 16F1, PSW-1 Version 0.0.1
 *  (C) 2014 Kazusa Okuda (a.k.a. klaNath)
 *
 *  PSW-1 is freely distributable under the terms of an MIT-style license.
 *  For details, see the https://github.com/klaNath/programable_switcher.git/LICENSE
 *
 */

/*
 *  This firmware is made for PIC16F1939.
 *  Include 6 Loop, 5 Preset and 16 SongSet.
 */



#include <xc.h>
#include "diffsw.h"
#include "psw.h"
#include "sc1602.h"

__CONFIG(CLKOUTEN_OFF & FOSC_INTOSC & FCMEN_OFF & IESO_OFF & BOREN_ON & PWRTE_ON
        & WDTE_OFF & MCLRE_OFF & CP_OFF & CPD_OFF) ;
__CONFIG(PLLEN_OFF & STVREN_ON & WRT_OFF & BORV_HI & LVP_OFF);




void interrupt IRQ()
{
    incSysTick();
}

void incSysTick()
{
    SysTick++;
}

void main()
{

    initSystem();
    initSC1602();
    initPSW();

    while(1)
    {
        if(10 =< SysTick - PrevSysTick)
        {
            PushedSW = diffsw(PORTB());
            if(PORTBbits.RB5 == 1)  IfSettingPSW = IfSettingPSW ^ 1;
            PrevSysTick = SysTick;
        }

        if(IfSettingPSW == 1)
        {
            settingPSW(PushedSW);
        }
        else
        {
            PSW(PushedSW);
        }
    }
}


void PSW(unsigned char SW)
{
    if(RanSetting == 1) loadSetting();
    if(SW !== 0){
        updateLoop();
        updateView();
        storeData();
    }
}
