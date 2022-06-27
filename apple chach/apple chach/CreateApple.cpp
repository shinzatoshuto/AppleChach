#include "DxLib.h"
#include "apple.h"

int applespeed[] = {1,5,7,10};

int APPLE::CreateApple() {
	//for (int i = 0; i < APPLE_MAX; i++) {
		if (flg == FALSE) {
			point = 0;
			type = GetRand(4);
			img = appleimgs[type];
			x = GetRand(7) * 40 + 38;
			speed = type * applespeed[GetRand(4)];
			flg = TRUE;
			//¬Œ÷
			return TRUE;
		}
	//}
	return FALSE;
}