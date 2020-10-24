#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include "LogitechGame.h"

using namespace std;

int player=1; 

int p[3][3];

void init(){
    memset(p,0,sizeof(p));
    p[2][0]=0;
    player=1;
}

void print_table(){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
    int co=10;
    for(i=2;i>=0;i++){
        for(j=0;j<3;j++){
            co++;
            if(p[i][j]==0){
                keyLightByN(co,255,255,255);    
            }
            else if(p[i][j]==1){
                keyLightByN(co,255,0,0);
            }
            else if(p[i][j]==2){
                keyLightByN(co,0,0,255);
            }
        }
    }
}

bool check_result(){
    int i,j;
    bool ch=true;
    bool ch1=false;
    if(p[0][0]==1&&p[0][1]==1&&p[0][2]==1) cout << "player1 win" << endl;
    else if(p[1][0]==1&&p[1][1]==1&&p[1][2]==1) cout << "player1 win" << endl;
    else if(p[2][0]==1&&p[2][1]==1&&p[2][2]==1) cout << "player1 win" << endl;
    else if(p[0][0]==1&&p[1][0]==1&&p[2][0]==1) cout << "player1 win" << endl;
    else if(p[0][1]==1&&p[1][1]==1&&p[2][1]==1) cout << "player1 win" << endl;
    else if(p[0][2]==1&&p[1][2]==1&&p[2][2]==1) cout << "player1 win" << endl;
    else if(p[0][0]==1&&p[1][1]==1&&p[2][2]==1) cout << "player1 win" << endl;
    else if(p[0][2]==1&&p[1][1]==1&&p[2][0]==1) cout << "player1 win" << endl;
    else if(p[0][0]==2&&p[0][1]==2&&p[0][2]==2) cout << "player2 win" << endl;
    else if(p[1][0]==2&&p[1][1]==2&&p[1][2]==2) cout << "player2 win" << endl;
    else if(p[2][0]==2&&p[2][1]==2&&p[2][2]==2) cout << "player2 win" << endl;
    else if(p[0][0]==2&&p[1][0]==2&&p[2][0]==2) cout << "player2 win" << endl;
    else if(p[0][1]==2&&p[1][1]==2&&p[2][1]==2) cout << "player2 win" << endl;
    else if(p[0][2]==2&&p[1][2]==2&&p[2][2]==2) cout << "player2 win" << endl;
    else if(p[0][0]==2&&p[1][1]==2&&p[2][2]==2) cout << "player2 win" << endl;
    else if(p[0][2]==2&&p[1][1]==2&&p[2][0]==2) cout << "player2 win" << endl;
    else ch=false;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(!p[i][j]){
                ch1=true;
            }
        }
        if(ch1) break;
    }
    if(ch){
        cout << "press 0 to reset" << endl;
    }
    if(ch1==false){
        cout << "Tie" << endl;
    }
    print_table();
    return ch;
}

int main(){
    init();
    LogitechGame_init();
    char input;
    bool has_result=false;
    check_result();
    while(player){
        input=getch();
        if(input=='\x1b'){
            break;
        }
        if(has_result&&input!='0'){
            check_result();
        }
        else if(input=='1'&&p[2][0]==0){
            p[2][0]=player;
            player=3-player;
            if(check_result()) has_result=true;
        }
        else if(input=='2'&&p[2][1]==0){
            p[2][1]=player;
            player=3-player;
            if(check_result()) has_result=true;
        }
        else if(input=='3'&&p[2][2]==0){
            p[2][2]=player;
            player=3-player;
            if(check_result()) has_result=true;
        }
        else if(input=='4'&&p[1][0]==0){
            p[1][0]=player;
            player=3-player;
            if(check_result()) has_result=true;
        }
        else if(input=='5'&&p[1][1]==0){
            p[1][1]=player;
            player=3-player;
            if(check_result()) has_result=true;
        }
        else if(input=='6'&&p[1][2]==0){
            p[1][2]=player;
            player=3-player;
            if(check_result()) has_result=true;
        }
        else if(input=='7'&&p[0][0]==0){
            p[0][0]=player;
            player=3-player;
            if(check_result()) has_result=true;
        }
        else if(input=='8'&&p[0][1]==0){
            p[0][1]=player;
            player=3-player;
            if(check_result()) has_result=true;
        }
        else if(input=='9'&&p[0][2]==0){
            p[0][2]=player;
            player=3-player;
            if(check_result()) has_result=true;
        }
        else if(input=='0'){
            init();
            has_result=false;
            check_result();
        }
        else{
            cout << "Invalid input" << endl; 
        }
        
        
    }
    LogitechGame_close();
    return 0;
}
