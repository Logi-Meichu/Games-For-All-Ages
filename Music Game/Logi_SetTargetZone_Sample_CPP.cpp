// Logi_SetTargetZone_Sample_CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LogitechLEDLib.h"
#include <iostream>
#include <fstream>
#include <conio.h>

#include <unordered_map>
#include <queue>
#include <tuple>
#include <algorithm>
#include "LogitechGame.h"

#include <string.h>
#include <time.h>
#pragma comment(lib, "Winmm.lib")

// music
#include <windows.h>
#include <mmsystem.h>



double rank = 0.0, hit = 0.0, total = 0.0;



int n_color[9], difficulty;
int rr[10] = { 255, 0, 0, 255, 255, 0, 255, 125, 255, 125 };
int gg[10] = { 0, 255, 0, 255, 0, 255, 255, 125, 125, 255 };
int bb[10] = { 0, 0, 255, 0, 255, 255, 255, 255, 125, 125 };

void init() {
    for (int i = 0; i < 9; i++) {
        n_color[i] = (i + 1) * 2;
    }
}
void random_color() {
    srand(time(NULL));
    int r, g, b;
    int arr[26] = { 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 
                    30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
                    40, 41, 42, 43, 44, 45};
    int key[26][3];
    std::random_shuffle(arr, arr+26);
    for (int i = 0; i < 26; i=i+2) {
        int cc = rand() % 10;
        r = rr[cc];
        g = gg[cc];
        b = bb[cc];
        std::cout << r << " " << g << " " << b  << " " << arr[i] << " & " << arr[i+1] << std::endl;
        keyLightByN(arr[i], r, g, b);
        key[arr[i] - 20][0] = r;
        key[arr[i] - 20][1] = g;
        key[arr[i+1]-20][2] = b;
        keyLightByN(arr[i + 1], r, g, b);
        key[arr[i + 1] - 20][0] = r;
        key[arr[i + 1] - 20][1] = g;
        key[arr[i + 1] - 20][2] = b;
        std::cout << key[arr[i] - 20][0] << " " << key[arr[i] - 20][1] << key[arr[i] - 20][2] << std::endl;
        std::cout << key[arr[i + 1] - 20][0] << " " << key[arr[i + 1] - 20][1] << key[arr[i + 1] - 20][2] << std::endl;
    }
    Sleep(3000);
    LogiLedSetLighting(0, 0, 0);
    char input1 = _getch();
    input1 = (tolower(input1));
    int ina = input1 - 'a';
    int inaa = ina + 20;
    keyLightByN(inaa, key[ina][0], key[ina][1], key[ina][2]);
    char input2 = _getch();
    input2 = (tolower(input2));
    int inb = input2 - 'a';
    int inbb = inb + 20;
    keyLightByN(inbb, key[inb][0], key[inb][1], key[inb][2]);
    std::cout << (int)ina << std::endl << (int)inb << std::endl;
    if (key[ina][0] == key[inb][0] && key[ina][1] == key[inb][1] && key[ina][2] == key[inb][2]) {
        std::cout << "it's same." << std::endl;
    }
    else {
        Sleep(1000);
        keyLightByN(inaa, 0, 0, 0);
        keyLightByN(inbb, 0, 0, 0);
        std::cout << "it's different." << std::endl;
    }
}


bool is_word(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

bool c_is_same(char a, char b) {
    return(a == b);
}
/*
void readinput() {
    char input, temp1 = ' ', temp2 = ' ';
    input = _getch();
    if (is_word(input)) {
        temp1 = input;
    }
    input = _getch();
    if (is_word(input)) {
        temp2 = input;
    }
    if (c_is_same(temp1, temp2)) {
        printf("it's same.\n");
    }
    else {
        printf("it's different.\n");
    }
}
*/

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

    LogitechGame_init();


    std::cout << "Start" << std::endl;
    
    int game_over_led_time_ms = 3000, game_over_led_flash_delay = 300;


    LogiLedSetTargetDevice(LOGI_DEVICETYPE_ALL);

    // Set all devices to Black
    LogiLedSetLighting(0, 0, 0);

    //readinput();
    random_color();

    //Create_Beats("cytus");
    //Beats_Lighting("cytus");
    //rank = hit / total;
    //printf("hit: %lf%%\n", rank*100);
    //Show_Rank(rank);
    //Over_Lighting_Effect(rank, 255, 0, 0, game_over_led_time_ms, game_over_led_flash_delay);
    
    std::cout << "Press \"ENTER\" to continue...";
    std::cin.ignore();

    std::cout << "LED SDK Shutting down" << std::endl;

    LogiLedShutdown();
    
    return 0;
}

