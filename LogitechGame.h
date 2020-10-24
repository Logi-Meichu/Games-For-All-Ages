#ifndef LogitechGame_H_INCLUDED
#define LogitechGame_H_INCLUDED

#include "LogitechGame.cpp"
#include "stdafx.h"
#include "LogitechLEDLib.h"

#define 

// init
bool LogitechGame_init();
void init_keymap();
void init_keyCode();

// Light control
int keyLightByC(char& c, int r = 0, int g = 0, int b = 0);
int keyLightByN( int& n, int r = 0, int g = 0, int b = 0);
 
// flash control
int flashLightByC(char& c, int r = 0, int g = 0, int b = 0, int t = 200);
int flashLightByN( int& n, int r = 0, int g = 0, int b = 0, int t = 200);

int flashStopByN(int& n);
int flashStopByC(char& c);

// end function
bool LogitechGame_close();