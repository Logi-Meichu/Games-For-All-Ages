// Logi_SetTargetZone_Sample_CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "LogitechLEDLib.h"
#include <iostream>
#include <fstream>
#include <conio.h>

//#include <unordered_map>
#include <queue>
#include <tuple>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <string.h>
//#include <time.h>
#pragma comment(lib, "Winmm.lib")

// music
#include <windows.h>
#include <mmsystem.h>

#include "LogitechGame.cpp"
#include "ColorGame.cpp"
#include "ox_game.cpp"
#include "2048.cpp"
//#include "ColorGame.h"

double hit = 0.0, total = 0.0;
bool success_end = false, failed_end = false;

int n_color[9], difficulty;
int rr[10] = { 255, 0, 0, 255, 255, 0, 255, 125, 255, 125 };
int gg[10] = { 0, 255, 0, 255, 0, 255, 255, 125, 125, 255 };
int bb[10] = { 0, 0, 255, 0, 255, 255, 255, 255, 125, 125 };

std::vector<int> obstacle;
int dinosaur_jump = 0;

void din_init() {
    int i;
    for (i = 0; i < 8; i++) {
        obstacle.push_back(0);
    }
    obstacle.push_back(1);
    obstacle.push_back(0);
}

void next_frame() {
    obstacle.erase(obstacle.begin(), obstacle.begin() + 1);
    srand((unsigned)time(NULL));
    int random = rand() % 10;
    if (random <= 2 && obstacle.back()!=1)
        obstacle.push_back(1);
    else
        obstacle.push_back(0);
}

void draw(int leg) {
    int i;
    if (!dinosaur_jump) {
        std::cout << "0000000000" << std::endl;
        std::cout << "0020000000" << std::endl;
        keyLightByN(1, 0, 0, 255);
        keyLightByN(2, 0, 0, 255);
        keyLightByN(3, 0, 0, 255);
        keyLightByN(4, 0, 0, 255);
        keyLightByN(5, 0, 0, 255);
        keyLightByN(6, 0, 0, 255);
        keyLightByN(7, 0, 0, 255);
        keyLightByN(8, 0, 0, 255);
        keyLightByN(9, 0, 0, 255);
        keyLightByN(0, 0, 0, 255);
        keyLightByN(36, 0, 0, 255);
        keyLightByN(42, 0, 0, 255);
        leg ? keyLightByN(24, 255, 0, 0) : keyLightByN(24, 0, 0, 255);
        keyLightByN(37, 255, 0, 0);
        !leg ? keyLightByN(39, 255, 0, 0) : keyLightByN(39, 0, 0, 255);
        keyLightByN(44, 0, 0, 255);
        keyLightByN(40, 0, 0, 255);
        keyLightByN(28, 0, 0, 255);
        keyLightByN(34, 0, 0, 255);
        keyLightByN(35, 0, 0, 255);
        keyLightByN(20, 0, 0, 255);
        keyLightByN(38, 0, 0, 255);
        keyLightByN(23, 255, 0, 0);
        keyLightByN(25, 0, 0, 255);
        keyLightByN(26, 0, 0, 255);
        keyLightByN(27, 0, 0, 255);
        keyLightByN(29, 0, 0, 255);
        keyLightByN(30, 0, 0, 255);
        keyLightByN(31, 0, 0, 255);
        keyLightByN(55, 0, 0, 255);
        std::cout << obstacle[0] << obstacle[1] << "2";
        obstacle[0] ? keyLightByN(45, 0, 255, 0) : keyLightByN(45, 0, 0, 255);
        //obstacle[1] ? keyLightByN(43, 0, 255, 0) : keyLightByN(43, 0, 0, 255);
        !leg ? keyLightByN(43, 255, 0, 0) : obstacle[1] ? keyLightByN(43, 0, 255, 0) : keyLightByN(43, 0, 0, 255);
        leg ? keyLightByN(22, 255, 0, 0) : obstacle[2] ? keyLightByN(22, 0, 255 , 0) : keyLightByN(22, 0, 0, 255);
        obstacle[3] ? keyLightByN(41, 0, 255, 0) : keyLightByN(41, 0, 0, 255);
        obstacle[4] ? keyLightByN(21, 0, 255, 0) : keyLightByN(21, 0, 0, 255);
        obstacle[5] ? keyLightByN(33, 0, 255, 0) : keyLightByN(33, 0, 0, 255);
        obstacle[6] ? keyLightByN(32, 0, 255, 0) : keyLightByN(32, 0, 0, 255);
        obstacle[7] ? keyLightByN(57, 0, 255, 0) : keyLightByN(57, 0, 0, 255);
        obstacle[8] ? keyLightByN(58, 0, 255, 0) : keyLightByN(58, 0, 0, 255);
        obstacle[9] ? keyLightByN(59, 0, 255, 0) : keyLightByN(59, 0, 0, 255);
        for (i = 3; i < 10; i++)
            std::cout << obstacle[i];
        std::cout << std::endl;
    }
    else {
        std::cout << "0020000000" << std::endl;
        std::cout << "0020000000" << std::endl;
        keyLightByN(1, 0, 0, 255);
        keyLightByN(2, 0, 0, 255);
        keyLightByN(3, 255, 0, 0);
        keyLightByN(4, 255, 0, 0);
        keyLightByN(5, 0, 0, 255);
        keyLightByN(6, 0, 0, 255);
        keyLightByN(7, 0, 0, 255);
        keyLightByN(8, 0, 0, 255);
        keyLightByN(9, 0, 0, 255);
        keyLightByN(0, 0, 0, 255);
        keyLightByN(36, 0, 0, 255);
        keyLightByN(42, 0, 0, 255);
        keyLightByN(24, 255, 0, 0);
        keyLightByN(37, 0, 0, 255);
        keyLightByN(39, 0, 0, 255);
        keyLightByN(44, 0, 0, 255);
        keyLightByN(40, 0, 0, 255);
        keyLightByN(28, 0, 0, 255);
        keyLightByN(34, 0, 0, 255);
        keyLightByN(35, 0, 0, 255);
        keyLightByN(20, 0, 0, 255);
        keyLightByN(38, 0, 0, 255);
        keyLightByN(23, 255, 0, 0);
        keyLightByN(25, 0, 0, 255);
        keyLightByN(26, 0, 0, 255);
        keyLightByN(27, 0, 0, 255);
        keyLightByN(29, 0, 0, 255);
        keyLightByN(30, 0, 0, 255);
        keyLightByN(31, 0, 0, 255);
        keyLightByN(55, 0, 0, 255);
        obstacle[0] ? keyLightByN(45, 0, 255, 0) : keyLightByN(45, 0, 0, 255);
        obstacle[1] ? keyLightByN(43, 0, 255, 0) : keyLightByN(43, 0, 0, 255);
        obstacle[2] ? keyLightByN(22, 0, 255, 0) : keyLightByN(22, 0, 0, 255);
        obstacle[3] ? keyLightByN(41, 0, 255, 0) : keyLightByN(41, 0, 0, 255);
        obstacle[4] ? keyLightByN(21, 0, 255, 0) : keyLightByN(21, 0, 0, 255);
        obstacle[5] ? keyLightByN(33, 0, 255, 0) : keyLightByN(33, 0, 0, 255);
        obstacle[6] ? keyLightByN(32, 0, 255, 0) : keyLightByN(32, 0, 0, 255);
        obstacle[7] ? keyLightByN(57, 0, 255, 0) : keyLightByN(57, 0, 0, 255);
        obstacle[8] ? keyLightByN(58, 0, 255, 0) : keyLightByN(58, 0, 0, 255);
        obstacle[9] ? keyLightByN(59, 0, 255, 0) : keyLightByN(59, 0, 0, 255);
        for (i = 0; i < 10; i++)
            std::cout << obstacle[i];
        std::cout << std::endl;
    }

}

void GetKeyPress()
{
    while (1) {
        int k = _getch();
        if (k == 72) {
            //cout << "up" << endl;
            dinosaur_jump = 1;
        }
    }
}

int din_main() {
    start:
    LogitechGame_init();
    std::thread t(GetKeyPress);
    din_init();
    int i, die = 0, leg=0;
    while (!die) {
        draw(leg);
        if (dinosaur_jump == 0 && obstacle[2] == 1)
            die = 1;
        if (!leg) leg = 1;
        else leg = 0;
        dinosaur_jump = 0;
        std::cout << std::endl;
        next_frame();
        Sleep(500);
    }
    t.detach();
    for (i = 0; i < 60; i++) {
        keyLightByN(i, 255, 0, 0);
    }
    std::cout << "Game Over" << std::endl;
    char c;
    while (c = getchar()) {
        if (c == 'r')
            goto start;
        else return 0;
    };
}

void Over_Lighting_Effect(double rank, int r = 0, int g = 100, int b = 0, int time = 2500, int delay = 300) {
    if (rank < 0.6) std::swap(r, g);
    Sleep(300);
    LogiLedFlashLighting(r, g, b, time, delay);
}

void init() {
    for (int i = 0; i < 9; i++) {
        n_color[i] = i+1;
    }
}
void random_color(int lv) {
    srand(time(NULL));
    int r, g, b;
    int arr[26] = { 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 
                    30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
                    40, 41, 42, 43, 44, 45};
    int key[26][3];
    bool vis[26];
    std::random_shuffle(arr, arr+26);
    for (int i = 0; i < 26; i=i+2) {
        vis[i] = false;
        vis[i + 1] = false;
        int cc = rand() % (lv+1);
        r = rr[cc];
        g = gg[cc];
        b = bb[cc]; 
        keyLightByN(arr[i], r, g, b);
        key[arr[i] - 20][0] = r;
        key[arr[i] - 20][1] = g;
        key[arr[i]-20][2] = b;
        keyLightByN(arr[i + 1], r, g, b);
        key[arr[i + 1] - 20][0] = r;
        key[arr[i + 1] - 20][1] = g;
        key[arr[i + 1] - 20][2] = b;
    }
    Sleep(3000);
    LogiLedSetLighting(0, 0, 0);
    int err_cnt = 0;
    int cur_cnt = 0;
    while (err_cnt < 5 && cur_cnt<13) {
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

        if (key[ina][0] == key[inb][0] && key[ina][1] == key[inb][1] && key[ina][2] == key[inb][2] && !vis[ina] && !vis[inb]) {
            cur_cnt++;
            vis[ina] = true;
            vis[inb] = true;
            std::cout << "Same color !" << std::endl;
        }
        else if(key[ina][0] != key[inb][0] || key[ina][1] != key[inb][1] || key[ina][2] != key[inb][2]){
            Sleep(1000);
            keyLightByN(inaa, 0, 0, 0);
            keyLightByN(inbb, 0, 0, 0);
            err_cnt++;
            keyLightByN(err_cnt + 60, 255, 0, 0);
            std::cout << "Different color !" << std::endl;
        }
    }
    if (cur_cnt == 13) LogiLedFlashLighting(0, 100, 0, 2500, 300);
    else LogiLedFlashLighting(100, 0, 0, 2500, 300);
}


bool is_word(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

bool is_number(char c) {
    return (c >= '0' && c <= '9');
}

bool c_is_same(char a, char b) {
    return(a == b);
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


void Dinorsour_Game() {
    din_main();
}

void _2048_Game() {
    pow2_main();
    LogiLedSetLighting(0, 0, 0);
}

void OOXX_Game() {
    ox_main();
    Sleep(2000); 
    for (int i = 11; i <= 19; i++) {
        flashStopByN(i);
    }
    LogiLedSetLighting(0, 0, 0);
}

void Filp_Card_Game() {
    char inlv;
    int lv = 3;
    for (int i = 0; i < 10; i++) {
        keyLightByN(i, 0, 255, 0);
    }
    while (inlv = _getch()) {
        if (is_number(inlv)) {
            lv = (int)inlv - '0';
            for (int i = 0; i < 10; i++) {
                keyLightByN(i, 0, 0, 0);
            }
            break;
        }
    }
    random_color(lv);
}

void Music_Game() {
    int game_over_led_time_ms = 3000, game_over_led_flash_delay = 300;
    Beats_Lighting("cytus");
    int rank = hit / total;
    //printf("hit: %lf%%\n", rank*100);
    Show_Rank(rank);
    Over_Lighting_Effect(rank, 255, 0, 0, game_over_led_time_ms, game_over_led_flash_delay);
    success_end = true;
}

int _tmain(int argc, _TCHAR* argv[])
{
    // Initialize the LED SDK

    LogitechGame_init();

    LogiLedSetTargetDevice(LOGI_DEVICETYPE_ALL);

    // Set all devices to Black
    LogiLedSetLighting(0, 0, 0);


    //Create_Beats("cytus");
    
    std::cout << "Start" << std::endl;
    
    char layout_input;
    for (int i = 1; i <= 5; i++) {
        keyLightByN(i, 255, 255, 255);
    }
    while (layout_input = _getch()) {
        
        // ESC to leave
        if(layout_input == '\x1b') break;


        // OOXX
        if (layout_input == '1') {
            OOXX_Game();
        }
        
        // Card
        else if (layout_input == '2') {
            Filp_Card_Game();
            Sleep(3000);
            LogiLedSetLighting(0, 0, 0);
        }
        
        else if (layout_input == '3') {
            ColorGame cg;
            cg.startPlay();

        }


        // 2048
        else if (layout_input == '4') {
            LogiLedSetLighting(0, 0, 0);
            _2048_Game();
        }
        
        Sleep(200);
        for (int i = 1; i <= 5; i++) {
            keyLightByN(i, 255, 255, 255);
        }
        //LogiLedShutdown();
    }

    std::cout << "Press \"ENTER\" to continue...";
    std::cin.ignore();

    std::cout << "LED SDK Shutting down" << std::endl;

    LogiLedShutdown();
    
    return 0;
}

