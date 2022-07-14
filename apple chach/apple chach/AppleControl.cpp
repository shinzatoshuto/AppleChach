#define _USE_MATH_DEFINES
#include "apple.h"
#include "Player.h"
#include "hensuu.h"
#include "DxLib.h"

void APPLE::AppleControl() {
	if (flg == TRUE) {
		//リンゴの表示

		DrawGraph(x, y, img, TRUE);

		//ポーズ―中じゃない間動かす
		if (hen.g_PauseFlg == 0) {
			y += speed;
		}

		//画面をはみ出したら消去
		if (y > SCREEN_HEIGHT + h) flg = FALSE;

		//当たり判定
		if (HitBoxPlayer(&player) == TRUE) {
			g_AppleCount[type]++;
			hen.Score += point;
			flg = FALSE;
			if (type == 3) {
				PlaySoundMem(hen.PoisonSE, DX_PLAYTYPE_BACK);
				player.flg = FALSE;
				player.count = 120;
			}
			else {
				PlaySoundMem(hen.GetAppleSE, DX_PLAYTYPE_BACK);
			}
		}
	}
}