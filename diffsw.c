/*
 *
 *  Alternate Switch Detector  Version 0.1
 *  (C) 2014 Kazusa Okuda (a.k.a. klaNath)
 *
 *  This software is freely distributable under the terms of an MIT-style license.
 *  For details, see the https://github.com/klaNath/programable_switcher.git/LICENSE
 *
 */

#include "diffsw.h"




unsigned char diffsw(unsigned char inputSW){

  unsigned char prevSW, outputSW;

  outputSW = inputSW ^ prevSW;

  prevSW = inputSW;

  return outputSW;

}
