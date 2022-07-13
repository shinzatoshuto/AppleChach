#include "DxLib.h"
#include "hensuu.h"
#include "pad.h"
#include "string.h"

void PAD::DrawInput(void) {

	int x = cursorX * 32;
	int y = cursorY * 32;
	OffSetX = 120;
	OffSetY = 250;

	DrawBox(x + OffSetX, y + OffSetY, x + 32 + OffSetX, y + 32 + OffSetY, 0x0000FF, 1);

	const char keybord[5][14] = { "ABCDEFGHIJKLM" ,"NOPQRSTUVWXYZ" ,"abcdefghijklm" ,"nopqrstuvwxyz" ,"0123456789   " };

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 13; j++) {
			SetFontSize(32);
			DrawFormatString(j * 32 + OffSetX, i * 32 + OffSetY, 0xffff00, "%c", keybord[i][j]);
		}
	}

	if (hen.g_KeyFlg & PAD_INPUT_RIGHT) {
		if (++cursorX > 12)cursorX = 0;
		PlaySoundMem(hen.MoveSE, DX_PLAYTYPE_BACK);
	}
	if (hen.g_KeyFlg & PAD_INPUT_LEFT) {
		if (--cursorX < 0)cursorX = 12;
		PlaySoundMem(hen.MoveSE, DX_PLAYTYPE_BACK);
	}
	if (hen.g_KeyFlg & PAD_INPUT_DOWN) {
		if (++cursorY > 4)cursorY = 0;
		PlaySoundMem(hen.MoveSE, DX_PLAYTYPE_BACK);
	}
	if (hen.g_KeyFlg & PAD_INPUT_UP) {
		if (--cursorY < 0)cursorY = 4;
		PlaySoundMem(hen.MoveSE, DX_PLAYTYPE_BACK);
	}

	if (hen.g_KeyFlg & PAD_INPUT_1 && inputnum < 10) {
		inputchar[inputnum++] = keybord[cursorY][cursorX];
		PlaySoundMem(hen.ClickSE, DX_PLAYTYPE_BACK);
	}
	if (hen.g_KeyFlg & PAD_INPUT_2 && inputnum > 0) {
		//inputchar[inputnum--] = ' ';
		strncpy_s(inputchar, inputchar, --inputnum);
		PlaySoundMem(hen.CancelSE, DX_PLAYTYPE_BACK);
	}
	DrawString(120, 205, inputchar, 0xffffff);
	DrawBox(120 + inputnum * 18, 201, 120 + inputnum * 18 + 16, 205 + 34, 0xff0000, 1);
	
}
