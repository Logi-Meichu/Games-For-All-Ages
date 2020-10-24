#ifndef LogitechGame_H_INCLUDED
#define LogitechGame_H_INCLUDED

#include "LogitechGame.cpp"
#include "stdafx.h"
#include "LogitechLEDLib.h"


// init
bool LogitechGame_init();
void init_keymap();
void init_keyCode();

// Light control
int keyLightByC(char& c, int r, int g, int b);
int keyLightByN( int& n, int r, int g, int b);
 
// flash control
int flashLightByC(char& c, int r, int g, int b, int t);
int flashLightByN( int& n, int r, int g, int b, int t);

int flashStopByN(int& n);
int flashStopByC(char& c);

// end function
bool LogitechGame_close();
<<<<<<< HEAD:Music Game/LogitechGame.h

#endif
=======
>>>>>>> 85635b9734b58b4e9109f9c86e11336f77cded80:LogitechGame.h
