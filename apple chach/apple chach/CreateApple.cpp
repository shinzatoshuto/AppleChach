#include "DxLib.h"
#include "apple.h"
#include "hensuu.h"

int applespeed[] = {1,1,1,1};//‚µ‘‚«

int APPLE::CreateApple() {
	//for (int i = 0; i < APPLE_MAX; i++) {
		if (flg == FALSE) {
			point = 0;
			type = GetRand(4);
			img = hen.AppleImages[type];
			x = GetRand(7) * 40 + 38;
			y = -50;
			speed = applespeed[GetRand(4)];
			flg = TRUE;
			//¬Œ÷
			return TRUE;
		}
	//}
	return FALSE;
}