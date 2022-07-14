#pragma once

class PAD {
private:
	int cursorX = 0;
	int cursorY = 0;
	const int OffSetX = 120;
	const int OffSetY = 250;
public:
	char inputchar[10];
	int inputnum = 0;

	void DrawInput(void);
};

extern PAD pad;