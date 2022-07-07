#include "DxLib.h"
#include "apple.h"
#include "hensuu.h"
 
int APPLE::CreateApple() {
	//for (int i = 0; i < APPLE_MAX; i++) {
		if (flg == FALSE) {
			point = 0;
			type = GetType();
			img = hen.AppleImages[type];
			x = GetRand(6) * 60 + 40;
			y = -50;
			speed = applespeed[type];
			flg = TRUE;
			w = 40;
			h = 40;
			PlaySoundMem(hen.FallSE, DX_PLAYTYPE_BACK);
			//¬Œ÷
			return TRUE;
		}
	//}
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