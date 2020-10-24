#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <Windows.h>
#include <conio.h>
#include "LogitechGame.h"
using namespace std;

vector<int> obstacle;
int dinosaur_jump = 0;

void init() {
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
    if (random <= 2)
        obstacle.push_back(1);
    else
        obstacle.push_back(0);
}

void print_map() {
    int i;
    for (i = 0; i < 10; i++) {
        cout << obstacle[i];
    }
}

void draw() {
    int i;
    if(!dinosaur_jump){
        cout << "0000000000" <<endl;
        cout << "0020000000" <<endl;
        
        keyLightByN(36, 0, 0, 255);
        keyLightByN(42, 0, 0, 255);
        keyLightByN(24, 0, 0, 255);
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
        keyLightByN(';', 0, 0, 255);
        cout << obstacle[0] << obstacle[1] << "2";
        obstacle[0] ? keyLightByN(45, 0, 255, 0) : keyLightByN(45, 0, 0, 255);
        obstacle[1] ? keyLightByN(43, 0, 255, 0) : keyLightByN(43, 0, 0, 255);
        keyLightByN(22, 255, 0, 0);
        obstacle[3] ? keyLightByN(41, 0, 255, 0) : keyLightByN(41, 0, 0, 255);
        obstacle[4] ? keyLightByN(21, 0, 255, 0) : keyLightByN(21, 0, 0, 255);
        obstacle[5] ? keyLightByN(33, 0, 255, 0) : keyLightByN(33, 0, 0, 255);
        obstacle[6] ? keyLightByN(32, 0, 255, 0) : keyLightByN(32, 0, 0, 255);
        obstacle[7] ? keyLightByN(57, 0, 255, 0) : keyLightByN(57, 0, 0, 255);
        obstacle[8] ? keyLightByN(58, 0, 255, 0) : keyLightByN(58, 0, 0, 255);
        obstacle[9] ? keyLightByN(59, 0, 255, 0) : keyLightByN(59, 0, 0, 255);
        for(i=3;i<10;i++)
            cout << obstacle[i];
        cout << endl;
    }
    else {
        cout << "0020000000" << endl;
        cout << "0020000000" << endl;
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
        keyLightByN(';', 0, 0, 255);
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
        for(i=0;i<10;i++)
            cout << obstacle[i];
        cout << endl;
    }

}

void GetKeyPress()
{
    while (1) {
        int k = _getch();
        if (k == 72) {
            //cout << "up" << endl;
            dinosaur_jump=1;
        }
    }
}

int din_main() {
    LogitechGame_init();
    thread t(GetKeyPress);
    init();
    int i, die=0;
    while (!die) {
        draw();
        if (dinosaur_jump == 0 && obstacle[2] == 1)
            die = 1;
        dinosaur_jump = 0;
        cout << endl;
        next_frame();
        Sleep(1000);
    }
    t.detach();
    cout << "Game Over" << endl;
    return 0;
}





