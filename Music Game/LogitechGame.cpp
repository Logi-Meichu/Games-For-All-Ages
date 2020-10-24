#include "stdafx.h"
#include "LogitechLEDLib.h"

#include "LogitechGame.h"
#include <conio.h>
#include <map>
#include <string.h>
#include <iostream>
//using namespace std;

std::unordered_map<char, LogiLed::KeyName> keymap;
std::unordered_map<int, LogiLed::KeyName> keyCode;

void init_keymap() {

    keymap['a'] = LogiLed::KeyName::A;
    keymap['b'] = LogiLed::KeyName::B;
    keymap['c'] = LogiLed::KeyName::C;
    keymap['d'] = LogiLed::KeyName::D;
    keymap['e'] = LogiLed::KeyName::E;
    keymap['f'] = LogiLed::KeyName::F;
    keymap['g'] = LogiLed::KeyName::G;
    keymap['h'] = LogiLed::KeyName::H;
    keymap['i'] = LogiLed::KeyName::I;
    keymap['j'] = LogiLed::KeyName::J;
    keymap['k'] = LogiLed::KeyName::K;
    keymap['l'] = LogiLed::KeyName::L;
    keymap['m'] = LogiLed::KeyName::M;
    keymap['n'] = LogiLed::KeyName::N;
    keymap['o'] = LogiLed::KeyName::O;
    keymap['p'] = LogiLed::KeyName::P;
    keymap['q'] = LogiLed::KeyName::Q;
    keymap['r'] = LogiLed::KeyName::R;
    keymap['s'] = LogiLed::KeyName::S;
    keymap['t'] = LogiLed::KeyName::T;
    keymap['u'] = LogiLed::KeyName::U;
    keymap['v'] = LogiLed::KeyName::V;
    keymap['w'] = LogiLed::KeyName::W;
    keymap['x'] = LogiLed::KeyName::X;
    keymap['y'] = LogiLed::KeyName::Y;
    keymap['z'] = LogiLed::KeyName::Z;

    keymap['0'] = LogiLed::KeyName::ZERO;
    keymap['1'] = LogiLed::KeyName::ONE;
    keymap['2'] = LogiLed::KeyName::TWO;
    keymap['3'] = LogiLed::KeyName::THREE;
    keymap['4'] = LogiLed::KeyName::FOUR;
    keymap['5'] = LogiLed::KeyName::FIVE;
    keymap['6'] = LogiLed::KeyName::SIX;
    keymap['7'] = LogiLed::KeyName::SEVEN;
    keymap['8'] = LogiLed::KeyName::EIGHT;
    keymap['9'] = LogiLed::KeyName::NINE;

    keymap['-'] = LogiLed::KeyName::MINUS;
    keymap['='] = LogiLed::KeyName::EQUALS;
    keymap['{'] = LogiLed::KeyName::OPEN_BRACKET; 
    keymap['}'] = LogiLed::KeyName::CLOSE_BRACKET;

    keymap[';'] = LogiLed::KeyName::SEMICOLON; 
    keymap['\''] =LogiLed::KeyName::APOSTROPHE;

    keymap['.'] = LogiLed::KeyName::PERIOD;
    keymap[','] = LogiLed::KeyName::COMMA;    
    keymap['/'] = LogiLed::KeyName::BACKSLASH;
}

void init_keyCode() {

    keyCode[0] = LogiLed::KeyName::ZERO;
    keyCode[1] = LogiLed::KeyName::ONE;
    keyCode[2] = LogiLed::KeyName::TWO;
    keyCode[3] = LogiLed::KeyName::THREE;
    keyCode[4] = LogiLed::KeyName::FOUR;
    keyCode[5] = LogiLed::KeyName::FIVE;
    keyCode[6] = LogiLed::KeyName::SIX;
    keyCode[7] = LogiLed::KeyName::SEVEN;
    keyCode[8] = LogiLed::KeyName::EIGHT;
    keyCode[9] = LogiLed::KeyName::NINE;

    keyCode[10] = LogiLed::KeyName::NUM_ONE;
    keyCode[11] = LogiLed::KeyName::NUM_ONE;
    keyCode[12] = LogiLed::KeyName::NUM_TWO;
    keyCode[13] = LogiLed::KeyName::NUM_THREE;
    keyCode[14] = LogiLed::KeyName::NUM_FOUR;
    keyCode[15] = LogiLed::KeyName::NUM_FIVE;
    keyCode[16] = LogiLed::KeyName::NUM_SIX;
    keyCode[17] = LogiLed::KeyName::NUM_SEVEN;
    keyCode[18] = LogiLed::KeyName::NUM_EIGHT;
    keyCode[19] = LogiLed::KeyName::NUM_NINE;

    keyCode[20] = LogiLed::KeyName::A;
    keyCode[21] = LogiLed::KeyName::B;
    keyCode[22] = LogiLed::KeyName::C;
    keyCode[23] = LogiLed::KeyName::D;
    keyCode[24] = LogiLed::KeyName::E;
    keyCode[25] = LogiLed::KeyName::F;
    keyCode[26] = LogiLed::KeyName::G;
    keyCode[27] = LogiLed::KeyName::H;
    keyCode[28] = LogiLed::KeyName::I;
    keyCode[29] = LogiLed::KeyName::J;
    keyCode[30] = LogiLed::KeyName::K;
    keyCode[31] = LogiLed::KeyName::L;
    keyCode[32] = LogiLed::KeyName::M;
    keyCode[33] = LogiLed::KeyName::N;
    keyCode[34] = LogiLed::KeyName::O;
    keyCode[35] = LogiLed::KeyName::P;
    keyCode[36] = LogiLed::KeyName::Q;
    keyCode[37] = LogiLed::KeyName::R;
    keyCode[38] = LogiLed::KeyName::S;
    keyCode[39] = LogiLed::KeyName::T;
    keyCode[40] = LogiLed::KeyName::U;
    keyCode[41] = LogiLed::KeyName::V;
    keyCode[42] = LogiLed::KeyName::W;
    keyCode[43] = LogiLed::KeyName::X;
    keyCode[44] = LogiLed::KeyName::Y;
    keyCode[45] = LogiLed::KeyName::Z;

    keyCode[46] = LogiLed::KeyName::G_1;
    keyCode[47] = LogiLed::KeyName::G_2;
    keyCode[48] = LogiLed::KeyName::G_3;
    keyCode[49] = LogiLed::KeyName::G_4;
    keyCode[50] = LogiLed::KeyName::G_5;
    
    keyCode[51] = LogiLed::KeyName::MINUS;
    keyCode[52] = LogiLed::KeyName::EQUALS;
    keyCode[53] = LogiLed::KeyName::OPEN_BRACKET;
    keyCode[54] = LogiLed::KeyName::CLOSE_BRACKET;
    keyCode[55] = LogiLed::KeyName::SEMICOLON;
    keyCode[56] = LogiLed::KeyName::APOSTROPHE;
    keyCode[57] = LogiLed::KeyName::PERIOD;
    keyCode[58] = LogiLed::KeyName::COMMA;
    keyCode[59] = LogiLed::KeyName::BACKSLASH;

    keyCode[61] = LogiLed::KeyName::F1;
    keyCode[62] = LogiLed::KeyName::F2;
    keyCode[63] = LogiLed::KeyName::F3;
    keyCode[64] = LogiLed::KeyName::F4;
    keyCode[65] = LogiLed::KeyName::F5;
    keyCode[66] = LogiLed::KeyName::F6;
    keyCode[67] = LogiLed::KeyName::F7;
    keyCode[68] = LogiLed::KeyName::F8;
    keyCode[69] = LogiLed::KeyName::F9;
    keyCode[70] = LogiLed::KeyName::F10;
    keyCode[71] = LogiLed::KeyName::F11;
    keyCode[72] = LogiLed::KeyName::F12;
}

bool LogitechGame_init() {
    bool LedInitialized = LogiLedInitWithName("SetTargetZone Sample C++");
    
    if (!LedInitialized) {
        std::cout << "Starting failed." << '\n';
        return 1;
    }

    LogiLedSetTargetDevice(LOGI_DEVICETYPE_ALL);

    // Set all devices to Black
    LogiLedSetLighting(0, 0, 0);

    init_keymap();
    init_keyCode();

    return 0;
}

int keyLightByC(char& c, int r = 0, int g = 0, int b = 0) {
    if (keymap.find(c) == keymap.end()) return 1; // out of range

    r = r / 255;
    g = g / 255;
    b = b / 255;

    LogiLedSetLightingForKeyWithKeyName(keymap[c], r, g, b);

    return 0;
}

int keyLightByN(int& n, int r = 0, int g = 0, int b = 0) {
    if (keyCode.find(n) == keyCode.end()) return 1; // out of range

    r = r / 255;
    g = g / 255;
    b = b / 255;

    LogiLedSetLightingForKeyWithKeyName(keyCode[n], r, g, b);

    return 0;
}

int flashLightByC(char& c, int r = 0, int g = 0, int b = 0, int t = 200) {
    if (keymap.find(c) == keymap.end()) return 1;  // out of range

    r = r / 255;
    g = g / 255;
    b = b / 255;

    LogiLedFlashSingleKey(keymap[c], r, g, b, LOGI_LED_DURATION_INFINITE, t);

    return 0;
}

int flashLightByN(int& n, int r = 0, int g = 0, int b = 0, int t = 200) {
    if (keyCode.find(n) == keyCode.end()) return 1; // out of range

    r = r / 255;
    g = g / 255;
    b = b / 255;

    LogiLedFlashSingleKey(keyCode[n], r, g, b, LOGI_LED_DURATION_INFINITE, t);

    return 0;
}

// bool LogiLedStopEffectsOnKey(LogiLed::KeyName keyName);

int flashStopByC(char& c) {
    if (keymap.find(c) == keymap.end()) return 1;  // out of range

    LogiLedStopEffectsOnKey(keymap[c]);

    return 0;
}

int flashStopByN(int& n) {
    if (keyCode.find(n) == keyCode.end()) return 1; // out of range

    LogiLedStopEffectsOnKey(keyCode[n]);

    return 0;
}

bool LogitechGame_close() {
    LogiLedShutdown();

    return 0;
}
