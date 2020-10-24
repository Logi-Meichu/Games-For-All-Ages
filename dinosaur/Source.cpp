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
        keyLightByC('Q', 0, 0, 255);
        keyLightByC('W', 0, 0, 255);
        keyLightByC('E', 0, 0, 255);
        keyLightByC('R', 0, 0, 255);
        keyLightByC('T', 0, 0, 255);
        keyLightByC('Y', 0, 0, 255);
        keyLightByC('U', 0, 0, 255);
        keyLightByC('I', 0, 0, 255);
        keyLightByC('O', 0, 0, 255);
        keyLightByC('P', 0, 0, 255);
        keyLightByC('A', 0, 0, 255);
        keyLightByC('S', 0, 0, 255);
        keyLightByC('D', 255, 0, 0);
        keyLightByC('F', 0, 0, 255);
        keyLightByC('G', 0, 0, 255);
        keyLightByC('H', 0, 0, 255);
        keyLightByC('J', 0, 0, 255);
        keyLightByC('K', 0, 0, 255);
        keyLightByC('L', 0, 0, 255);
        keyLightByC(';', 0, 0, 255);
        cout << obstacle[0] << obstacle[1] << "2";
        obstacle[0] ? keyLightByC('Z', 0, 255, 0) : keyLightByC('Z', 0, 0, 255);
        obstacle[1] ? keyLightByC('X', 0, 255, 0) : keyLightByC('X', 0, 0, 255);
        keyLightByC('C', 255, 0, 0);
        obstacle[3] ? keyLightByC('V', 0, 255, 0) : keyLightByC('X', 0, 0, 255);
        obstacle[4] ? keyLightByC('B', 0, 255, 0) : keyLightByC('X', 0, 0, 255);
        obstacle[5] ? keyLightByC('N', 0, 255, 0) : keyLightByC('X', 0, 0, 255);
        obstacle[6] ? keyLightByC('M', 0, 255, 0) : keyLightByC('X', 0, 0, 255);
        obstacle[7] ? keyLightByC(',', 0, 255, 0) : keyLightByC('X', 0, 0, 255);
        obstacle[8] ? keyLightByC('.', 0, 255, 0) : keyLightByC('X', 0, 0, 255);
        obstacle[9] ? keyLightByC('/', 0, 255, 0) : keyLightByC('X', 0, 0, 255);
        for(i=3;i<10;i++)
            cout << obstacle[i];
        cout << endl;
    }
    else{
        cout << "0020000000" << endl;
        cout << "0020000000" << endl;
        keyLightByC('Q', 0, 0, 255);
        keyLightByC('W', 0, 0, 255);
        keyLightByC('E', 255, 0, 0);
        keyLightByC('R', 0, 0, 255);
        keyLightByC('T', 0, 0, 255);
        keyLightByC('Y', 0, 0, 255);
        keyLightByC('U', 0, 0, 255);
        keyLightByC('I', 0, 0, 255);
        keyLightByC('O', 0, 0, 255);
        keyLightByC('P', 0, 0, 255);
        keyLightByC('A', 0, 0, 255);
        keyLightByC('S', 0, 0, 255);
        keyLightByC('D', 255, 0, 0);
        keyLightByC('F', 0, 0, 255);
        keyLightByC('G', 0, 0, 255);
        keyLightByC('H', 0, 0, 255);
        keyLightByC('J', 0, 0, 255);
        keyLightByC('K', 0, 0, 255);
        keyLightByC('L', 0, 0, 255);
        keyLightByC(';', 0, 0, 255);
        obstacle[0] ? keyLightByC('Z', 0, 255, 0) : keyLightByC('Z', 0, 0, 255);
        obstacle[1] ? keyLightByC('X', 0, 255, 0) : keyLightByC('Z', 0, 0, 255);
        obstacle[2] ? keyLightByC('C', 0, 255, 0) : keyLightByC('Z', 0, 0, 255);
        obstacle[3] ? keyLightByC('V', 0, 255, 0) : keyLightByC('Z', 0, 0, 255);
        obstacle[4] ? keyLightByC('B', 0, 255, 0) : keyLightByC('Z', 0, 0, 255);
        obstacle[5] ? keyLightByC('N', 0, 255, 0) : keyLightByC('Z', 0, 0, 255);
        obstacle[6] ? keyLightByC('M', 0, 255, 0) : keyLightByC('Z', 0, 0, 255);
        obstacle[7] ? keyLightByC(',', 0, 255, 0) : keyLightByC('Z', 0, 0, 255);
        obstacle[8] ? keyLightByC('.', 0, 255, 0) : keyLightByC('Z', 0, 0, 255);
        obstacle[9] ? keyLightByC('/', 0, 255, 0) : keyLightByC('Z', 0, 0, 255);
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

int main() {
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





