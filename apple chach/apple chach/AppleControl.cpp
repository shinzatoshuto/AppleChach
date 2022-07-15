#define _USE_MATH_DEFINES
#include "apple.h"
#include "Player.h"
#include "variable.h"
#include "DxLib.h"
#include"Load.h"

void APPLE::AppleControl() {
		if (flg == TRUE) {
			//“G‚Ì•\Ž¦
			DrawGraph(x, y, img, TRUE);

			if (player.g_PauseFlg == 0) {
				y += speed;
			}

			//‰æ–Ê‚ð‚Í‚Ýo‚µ‚½‚çÁ‹Ž
			if (y > SCREEN_HEIGHT + h) flg = FALSE;

			//“–‚½‚è”»’è
			if (HitBoxPlayer(&player) == TRUE) {
				g_AppleCount[type]++;
				var.Score += point;
				flg = FALSE;
				if (type == 3) {
					PlaySoundMem(load.PoisonSE, DX_PLAYTYPE_BACK);
					player.flg = FALSE;
					player.count = 120;
					if (var.Score < 0) {
						var.Score = 0;
					}
				}
				else {
					PlaySoundMem(load.CatchSE, DX_PLAYTYPE_BACK);
				}
			}
		}
}