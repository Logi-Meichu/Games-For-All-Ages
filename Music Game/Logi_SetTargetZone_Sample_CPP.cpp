// Logi_SetTargetZone_Sample_CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LogitechLEDLib.h"
#include <iostream>
#include <fstream>
#include <conio.h>

#include <unordered_map>
#include <queue>

#include <string.h>
#include <time.h>
#pragma comment(lib, "Winmm.lib")

// music
#include <windows.h>
#include <mmsystem.h>

std::unordered_map<char, LogiLed::KeyName> keymap;
double rank = 0.0, hit = 0.0, total = 0.0;

void init_keymap() {
    keymap.clear();

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

}

bool is_word(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

void Play_Music(std::string Music) {
    std::wstring stemp = std::wstring(Music.begin(), Music.end());
    LPCWSTR em = stemp.c_str();
    PlaySound(em, NULL, SND_ASYNC | SND_FILENAME);
}

void Count_Down(int t) {
    for (int i = 1; i <= t; i++) {
        printf("%d\n", i);
        Sleep(1000);
    }
    printf("Go\n");
}


void Create_Beats(std::string Music) {
    std::string MusicBeat = "./src/" + Music + ".txt";
    std::string MusicAudio = "./src/" + Music + ".wav";
    const char* out = MusicBeat.c_str();
    std::ofstream cout(out);
    float delta = 0.0;
    char input, pre = ' ';
    bool ok = false;
    Count_Down(3);
    
    clock_t begin_time = clock();
    Play_Music(MusicAudio);

    while (input = _getch()) {
        if (is_word(input)) {
            delta = float(clock() - begin_time) / CLOCKS_PER_SEC;
            if (!ok) {
                cout << delta << '\n';
                ok = true;
            }
            else cout << char(tolower(pre)) << " " << delta << '\n';
            pre = input;
            //printf("input: %c\n", input);
            begin_time = clock();
        }
    }
    cout << pre << " 1.0\n";
}

void Show_LED(char c, double ms) {
    int init_r = 0, init_g = 0, init_b = 0, end_r = 0, end_g = 100, end_b = 0;
    double delay_time = ms;
    LogiLedPulseSingleKey(keymap[c], init_r, init_g, init_b, end_r, end_g, end_b, delay_time, 0);
    //Sleep(delay_time);
}

void Show_Rank(double percent) {
    Sleep(500);
    int percent_int = percent * 12;
    double show_delay = 1.1 - percent;
    LogiLed::KeyName score_board[12] = { LogiLed::KeyName::F1, LogiLed::KeyName::F2, LogiLed::KeyName::F3, LogiLed::KeyName::F4, LogiLed::KeyName::F5, LogiLed::KeyName::F6, LogiLed::KeyName::F7, LogiLed::KeyName::F8, LogiLed::KeyName::F9, LogiLed::KeyName::F10, LogiLed::KeyName::F11, LogiLed::KeyName::F12 };

    for (int i = 0; i < percent_int; i++) {
        LogiLedSetLightingForKeyWithKeyName(score_board[i], 0, 100, 0);
        Sleep(show_delay * 1000); // sleep 1 sec
        show_delay += (percent / 7.0);
    }
}

void Over_Lighting_Effect(double rank, int r = 0, int g = 100, int b = 0, int time = 2500, int delay = 300) {
    if (rank < 0.6) std::swap(r, g);
    Sleep(300);
    LogiLedFlashLighting(r, g, b, time, delay);
}

void Beats_Lighting(std::string Music) {
    std::string MusicBeat = "./src/" + Music + ".txt";
    std::string MusicAudio = "./src/" + Music + ".wav";
    const char* in = MusicBeat.c_str();
    std::ifstream cin(in);
    
    bool initdelay = false;
    char c, player_hit;
    float t;
    int in_hit;
    Play_Music(MusicAudio);
    if (!initdelay) {
        initdelay = true;
        cin >> t;
        Sleep(t * 950);
    }
    while (cin >> c >> t) {
        Show_LED(c, double(t)*1000);
        bool ok = false;
        total += 1.0;

        clock_t get_input = clock();
        clock_t start = clock();
        double dt = (float(clock() - start) / CLOCKS_PER_SEC);
        while(dt <= t){
            if (_kbhit()) {
                player_hit = _getch();
                if (player_hit == c) {
                    hit += 1;
                    get_input = clock();
                    printf("hit %c\n", c);
                    ok = true;
                    break;
                }
                else printf("Wrong hit: %c, expected: %c\n", player_hit, c);
            }
            dt = (float(clock() - start) / CLOCKS_PER_SEC);
        }
        if (ok) {
            float ddt = t - (float(clock() - start) / CLOCKS_PER_SEC);
            Sleep(ddt * 900);
        }
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    // Initialize the LED SDK
    bool LedInitialized = LogiLedInitWithName("SetTargetZone Sample C++");

    if (!LedInitialized)
    {
        std::cout << "Starting failed." << std::endl;
        
        return 0;
    }
    init_keymap();

    std::cout << "Start" << std::endl;
    
    int game_over_led_time_ms = 3000, game_over_led_flash_delay = 300;


    LogiLedSetTargetDevice(LOGI_DEVICETYPE_ALL);

    // Set all devices to Black
    LogiLedSetLighting(0, 0, 0);


    //Create_Beats("cytus");
    Beats_Lighting("cytus");
    rank = hit / total;
    printf("hit: %lf%%\n", rank*100);
    Show_Rank(rank);
    Over_Lighting_Effect(rank, 255, 0, 0, game_over_led_time_ms, game_over_led_flash_delay);
    
    std::cout << "Press \"ENTER\" to continue...";
    std::cin.ignore();

    std::cout << "LED SDK Shutting down" << std::endl;

    LogiLedShutdown();
    
    return 0;
}

