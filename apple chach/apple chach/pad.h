#pragma once

class PAD {
public:
	int ALAN[14], ALOZ[12], alan[13], aloz[12], suuji[10];
int cursorX = 0;
int cursorY = 0;
char inputchar[10];
int inputnum = 0;
int OffSetX, OffSetY;

	void DrawInput(void);
};

extern PAD pad;