#include "DxLib.h"
#include "apple.h"
#include "hensuu.h"
 
int APPLE::CreateApple() {
	//for (int i = 0; i < APPLE_MAX; i++) {
		if (flg == FALSE) {
			point = 0;
			type = GetRand(3);
			img = hen.AppleImages[type];
			x = GetRand(6) * 60 + 40;
			y = -50;
			speed = applespeed[GetRand(3)];
			flg = TRUE;
			w = 40;
			h = 40;
			//¬Œ÷
			return TRUE;
		}
	//}
	return FALSE;
}