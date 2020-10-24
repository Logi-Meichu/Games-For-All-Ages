#ifndef COLORGAME_H_INCLUDED
#define COLORGAME_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <cstring>
#include "ColorGame.cpp"

class ColorGame {
private:

	const int key_range_lef = 0;
	const int key_range_rig = 68;
	
	int map_color[200][3];

	void init();
	void createMap();
	void generateColor();

public:

	ColorGame();
	void startPlay();

};

#endif