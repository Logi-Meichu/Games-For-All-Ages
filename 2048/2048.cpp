#include <iostream>
#include <string.h>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int p[4][4];
vector<pair<int,int> > s;

void init(){
    s.clear();
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            s.push_back(make_pair(i,j));
        }
    }
    memset(p,0,sizeof(p));
    random_shuffle(s.begin(),s.end());
    p[s[0].first][s[0].second]=2;
}

void reset(){
    memset(p,0,sizeof(p));
    random_shuffle(s.begin(),s.end());
    p[s[0].first][s[0].second]=2;
}

void print_now(){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}

void shift_right(){
    cout << "right" << endl;
    int i,j;
    vector<int> b;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(p[i][3-j]!=0) b.push_back(p[i][3-j]);
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
            p[i][3-j]=b[j];
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
            if(p[i][j]!=0) b.push_back(p[i][j]);
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
            p[i][j]=b[j];
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
            if(p[j][i]!=0) b.push_back(p[j][i]);
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
            p[j][i]=b[j];
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
            if(p[3-j][i]!=0) b.push_back(p[3-j][i]);
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
            p[3-j][i]=b[j];
        }
        b.clear();
    }
}

bool check_result(){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(p[i][j]==2048){
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
        if(p[s[i].first][s[i].second]==0){
            p[s[i].first][s[i].second]=2;
            return true;
        }
    }
    return false;
}

int main(int argc,char *argv[]){
    srand(time(0));
    init();
    int i,j;
    int a[4][4];
    char input;
    input='0';
    while(input!='\x1b'){
        print_now();
        input=getch();
        if(input==-32){
        	input=getch();
        	switch (input){
        		case 80: shift_down();break;
	            case 75: shift_left();break;
	            case 77: shift_right();break;
	            case 72: shift_up();break; 
			}
			if(!add_one()){
                cout << "you can't not move anymore" << endl;
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
        else if(check_result()){
            finish();
        }
        else if(input=='2'||input=='4'||input=='6'||input=='8'){
            if(!add_one()){
                cout << "you can't not move anymore" << endl;
                cout << "enter 0 to reset " << endl;
            }
        }
    }
    return 0;
}
