#include "DxLib.h"
#include "apple.h"
#include "variable.h"

int applePoints[4] = { 150, 300, 500, -1000 };

void APPLE::InitApple() {
	flg = FALSE;
}

int APPLE::CreateApple() {
	if (flg == FALSE) {
		type = GetType();
		point = applePoints[type];
		img = hen.AppleImages[type];
		x = GetRand(6) * 60 + 40;
		y = -50;
		speed = applespeed[type];
		flg = TRUE;
		w = 40;
		h = 40;
		PlaySoundMem(hen.FallSE, DX_PLAYTYPE_BACK);
		//ê¨å˜
		return TRUE;
	}
	return FALSE;
}

int APPLE::GetType() {
	int rand = GetRand(9);
	if (rand < 6) {
		return 0;
	}
	else if (rand < 8) {
		return 1;
	}
	else if (rand < 9) {
		return 2;
	}
	else {
		return 3;
	}
}