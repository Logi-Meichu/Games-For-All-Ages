
#include <vector>
#include <cstring>
#include <algorithm>
#include <time.h>
#include <cctype>

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



ColorGame::ColorGame() {}

void ColorGame::init() {
	memset(map_color, 0, sizeof(map_color));

	for (int i = key_range_lef; i <= key_range_rig; i++) {
		flashLightByN(i, 125, 255, 255);
	}
	char  c;
	c = _getch();

	for (int i = key_range_lef; i <= key_range_rig; i++) {
		flashStopByN(i);
	}
}

void ColorGame::generateColor() {
	int n = 0;
	n = 1; keyLightByN(n, 255, 0, 0);
	n = 2; keyLightByN(n, 0, 255, 0);
	n = 3; keyLightByN(n, 0, 0, 255);
	n = 0; keyLightByN(n, 255, 255, 255);
}

void ColorGame::createMap() {
	this -> generateColor();

	for (int i = 4; i <= key_range_rig; i++) {
		keyLightByN(i, 0, 0, 0);
	}
}

void ColorGame::startPlay() {
	this->init(); Sleep(1);
	this -> createMap();

	int now_r = 0, now_g = 0, now_b = 0;

	char c;
	while (c = _getch()) {
		if (c == '\x1b') {
			for (int i = key_range_lef; i <= key_range_rig; i++) {
				keyLightByN(i, 0, 0, 0);
			}
			return;
		}
		if (c == '`') { now_r = -25; now_g = -25; now_b = -25; }
		if (c == '0') { now_r = 25; now_g = 25; now_b = 25; }
		if (c == '1') { now_r = 25; now_g =  0; now_b =  0; }
		if (c == '2') { now_r =  0; now_g = 25; now_b =  0; }
		if (c == '3') { now_r =  0; now_g =  0; now_b = 25; }

		if (!isalpha(c)) continue;
		c = tolower(c);

		int t = c - 'a';
		map_color[t][0] = min(map_color[t][0] + now_r, 255);
		map_color[t][1] = min(map_color[t][1] + now_g, 255);
		map_color[t][2] = min(map_color[t][2] + now_b, 255);

		map_color[t][0] = max(map_color[t][0] + now_r, 0);
		map_color[t][1] = max(map_color[t][1] + now_g, 0);
		map_color[t][2] = max(map_color[t][2] + now_b, 0);

		keyLightByC(c, map_color[t][0], map_color[t][1], map_color[t][2]);
	}
}




