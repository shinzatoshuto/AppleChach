#include "DxLib.h"
#include "hensuu.h"
#include "pad.h"
#include "string.h"

void PAD::DrawInput(void) {
	//static int cursorX = 0;
	//static int cursorY = 0;
	//static char inputchar[10];
	//static int inputnum = 0;

	int x = cursorX * 32;
	int y = cursorY * 32;
	DrawBox(x, y, x + 32, y + 32, 0x0000FF, 1);

	const char keybord[5][14] = { "ABCDEFGHIJKLM" ,"NOPQRSTUVWXYZ" ,"abcdefghijklm" ,"nopqrstuvwxyz" ,"0123456789" };

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 13; j++) {
			SetFontSize(32);
			DrawFormatString(j * 32, i * 32, 0xffff00, "%c", keybord[i][j]);
		}
	}

	if (hen.g_KeyFlg & PAD_INPUT_RIGHT) {
		if (++cursorX > 12)cursorX = 0;
	}
	if (hen.g_KeyFlg & PAD_INPUT_LEFT) {
		if (--cursorX < 0)cursorX = 12;
	}
	if (hen.g_KeyFlg & PAD_INPUT_DOWN) {
		if (++cursorY > 4)cursorY = 0;
	}
	if (hen.g_KeyFlg & PAD_INPUT_UP) {
		if (--cursorY < 0)cursorY = 4;
	}

	if (hen.g_KeyFlg & PAD_INPUT_1 && inputnum < 10) {
		inputchar[inputnum++] = keybord[cursorY][cursorX];
	}
	if (hen.g_KeyFlg & PAD_INPUT_2 && inputnum > 0) {
		//inputchar[inputnum--] = ' ';
		strncpy_s(inputchar, inputchar, --inputnum);
	}
	DrawString(320, 320, inputchar, 0xffffff);
	DrawFormatString(320, 400, 0xffffff,"%02d",inputnum);
	DrawBox(320 + inputnum * 18, 320, 320 + inputnum * 18 + 16, 320 + 34, 0xff0000, 1);
	
}
