#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
//#include "LogitechGame.h"

using namespace std;

int p2048[4][4];
vector<pair<int,int> > s;

void pow2_init(){
    s.clear();
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            s.push_back(make_pair(i,j));
        }
    }
    memset(p2048,0,sizeof(p2048));
    random_shuffle(s.begin(),s.end());
    p2048[s[0].first][s[0].second]=2;
}

void reset(){
    memset(p2048,0,sizeof(p2048));
    random_shuffle(s.begin(),s.end());
    p2048[s[0].first][s[0].second]=2;
}

void print_now(){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            cout << p2048[i][j] << " ";
        }
        cout << endl;
    }
    int cha=0;
    int re=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            cha=i*4+j;
            switch(cha){
                case 0: re=4; break;
                case 1: re=5; break;
                case 2: re=6; break;
                case 3: re=7; break;
                case 4: re=37; break;
                case 5: re=39; break;
                case 6: re=44; break;
                case 7: re=40; break;
                case 8: re=25; break;
                case 9: re=26; break;
                case 10: re=27; break;
                case 11: re=29; break;
                case 12: re=41; break;
                case 13: re=21; break;
                case 14: re=33; break;
                case 15: re=32; break;
            }
            switch(p2048[i][j]){
            	case 0: keyLightByN(re,0,0,0); break;
                case 2: keyLightByN(re,255,255,255); break;
                case 4: keyLightByN(re,255,158,0); break;
                case 8: keyLightByN(re,255,255,0); break;
                case 16: keyLightByN(re,0,255,125); break;
                case 32: keyLightByN(re,0,255,0); break;
                case 64: keyLightByN(re,0,255,255); break;
                case 128: keyLightByN(re,0,0,125); break;
                case 256: keyLightByN(re,0,0,255); break;
                case 512: keyLightByN(re,255,0,0); break;
                case 1024: keyLightByN(re,255,0,125); break;
                case 2048: keyLightByN(re,255,0,255); break;
            }
        }
    }
}

void shift_right(){
    cout << "right" << endl;
    int i,j;
    vector<int> b;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(p2048[i][3-j]!=0) b.push_back(p2048[i][3-j]);
        }
        for(j=0;j<5;j++){
            b.push_back(0);
        }
        for(j=0;j<4;j++){
            if(b[j]==0){
                break;
            }
            if(b[j]==b[j+1]){
                b[j]*=2;
                b.erase(b.begin()+j+1);
            }
        }
        for(j=0;j<4;j++){
            b.push_back(0);
        }
        for(j=0;j<4;j++){
            p2048[i][3-j]=b[j];
        }
        b.clear();
    }
}

void shift_left(){
    cout << "left" << endl;
    int i,j;
    vector<int> b;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(p2048[i][j]!=0) b.push_back(p2048[i][j]);
        }
        for(j=0;j<5;j++){
            b.push_back(0);
        }
        for(j=0;j<4;j++){
            if(b[j]==0){
                break;
            }
            if(b[j]==b[j+1]){
                b[j]*=2;
                b.erase(b.begin()+j+1);
            }
        }
        for(j=0;j<4;j++){
            b.push_back(0);
        }
        for(j=0;j<4;j++){
            p2048[i][j]=b[j];
        }
        b.clear();
    }
}

void shift_up(){
    cout << "up" << endl;
    int i,j;
    vector<int> b;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(p2048[j][i]!=0) b.push_back(p2048[j][i]);
        }
        for(j=0;j<5;j++){
            b.push_back(0);
        }
        for(j=0;j<4;j++){
            if(b[j]==0){
                break;
            }
            if(b[j]==b[j+1]){
                b[j]*=2;
                b.erase(b.begin()+j+1);
            }
        }
        for(j=0;j<4;j++){
            b.push_back(0);
        }
        for(j=0;j<4;j++){
            p2048[j][i]=b[j];
        }
        b.clear();
    }
}

void shift_down(){
    cout << "down" << endl;
    int i,j;
    vector<int> b;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(p2048[3-j][i]!=0) b.push_back(p2048[3-j][i]);
        }
        for(j=0;j<5;j++){
            b.push_back(0);
        }
        for(j=0;j<4;j++){
            if(b[j]==0){
                break;
            }
            if(b[j]==b[j+1]){
                b[j]*=2;
                b.erase(b.begin()+j+1);
            }
        }
        for(j=0;j<4;j++){
            b.push_back(0);
        }
        for(j=0;j<4;j++){
            p2048[3-j][i]=b[j];
        }
        b.clear();
    }
}

bool check_res(){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(p2048[i][j]==2048){
                return true;
            }
        }
    }
    return false;
}

void finish(){
    cout << "win" << endl;
}

bool add_one(){
    random_shuffle(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(p2048[s[i].first][s[i].second]==0){
            p2048[s[i].first][s[i].second]=2;
            return true;
        }
    }
    return false;
}

int pow2_main(){
    std::srand(std::time(0));
    pow2_init();
    int i,j;
    int a[4][4];
    char input;
    input='0';
    while(input!='\x1b'){
        print_now();
        input=_getch();
        if(input==-32){
        	input=_getch();
        	switch (input){
        		case 80: shift_down();break;
	            case 75: shift_left();break;
	            case 77: shift_right();break;
	            case 72: shift_up();break; 
			}
			if(!add_one()){
                cout << "This movement can't move anything." << endl;
                cout << 1111111 << endl;
                cout << "enter 0 to reset " << endl;
            }
		}
		else{
			printf("%d\n",input);
	        switch (input){
	            case '0': reset();break;
	            case '2': shift_down();break;
	            case '4': shift_left();break;
	            case '6': shift_right();break;
	            case '8': shift_up();break;
	            case '\x1b': break;
	            default: cout << "Invalid input" << endl; input=1; break;
	        }
		}
        if(input=='\x1b'){
            break;
        }
        else if(check_res()){
            finish();
        }
        else if(input=='2'||input=='4'||input=='6'||input=='8'){
            if(!add_one()){
                cout << "This movement can't move anything." << endl;
                cout << "enter 0 to reset " << endl;
            }
        }
    }
    return 0;
}
