#include "DxLib.h"
#include "variable.h"
#include "pad.h"
#include "string.h"
#include "Load.h"

const char keyboard[5][14] = { "ABCDEFGHIJKLM" ,"NOPQRSTUVWXYZ" ,"abcdefghijklm" ,"nopqrstuvwxyz" ,"0123456789   " };

void PAD::DrawInput(void) {

	int x = cursorX * 32;
	int y = cursorY * 32;

	DrawBox(x + OffSetX, y + OffSetY, x + 32 + OffSetX, y + 32 + OffSetY, 0x0000FF, 1);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 13; j++) {
			SetFontSize(32);
			DrawFormatString(j * 32 + OffSetX, i * 32 + OffSetY, 0xffff00, "%c", keyboard[i][j]);
		}
	}

	if (pad.g_KeyFlg & PAD_INPUT_RIGHT) {
		if (++cursorX > 12)cursorX = 0;
		PlaySoundMem(load.MoveSE, DX_PLAYTYPE_BACK);
	}
	if (pad.g_KeyFlg & PAD_INPUT_LEFT) {
		if (--cursorX < 0)cursorX = 12;
		PlaySoundMem(load.MoveSE, DX_PLAYTYPE_BACK);
	}
	if (pad.g_KeyFlg & PAD_INPUT_DOWN) {
		if (++cursorY > 4)cursorY = 0;
		PlaySoundMem(load.MoveSE, DX_PLAYTYPE_BACK);
	}
	if (pad.g_KeyFlg & PAD_INPUT_UP) {
		if (--cursorY < 0)cursorY = 4;
		PlaySoundMem(load.MoveSE, DX_PLAYTYPE_BACK);
	}

	if (pad.g_KeyFlg & PAD_INPUT_1 && inputnum < 10) {
		inputchar[inputnum++] = keyboard[cursorY][cursorX];
		PlaySoundMem(load.ClickSE, DX_PLAYTYPE_BACK);
	}
	if (pad.g_KeyFlg & PAD_INPUT_2 && inputnum > 0) {
		strncpy_s(inputchar, inputchar, --inputnum);
		PlaySoundMem(load.CancelSE, DX_PLAYTYPE_BACK);
	}
	DrawString(120, 205, inputchar, 0xffffff);
	DrawBox(120 + inputnum * 18, 201, 120 + inputnum * 18 + 16, 205 + 34, 0xff0000, 1);
	
}
