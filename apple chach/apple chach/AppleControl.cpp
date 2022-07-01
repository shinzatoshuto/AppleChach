#define _USE_MATH_DEFINES
#include "apple.h"
#include "hensuu.h"
#include "DxLib.h"

void APPLE::AppleControl() {
	//for (int i = 0; i < APPLE_MAX; i++) {
		if (flg == TRUE) {
			//敵の表示
			DrawGraph(x, y, img, TRUE);

			//if (g_player.flg == FALSE) continue;

			//まっすぐ下に移動
			//g_enemy[i].y += g_enemy[i].speed + g_player.speed - PLAYER_SPEED + 1;
			y += speed;

			//画面をはみ出したら消去
			if (y > SCREEN_HEIGHT + h) flg = FALSE;

			//敵機を追い越したらカウント
			/*if (g_enemy[i].y > g_player.y && g_enemy[i].point == 1) {
				g_enemy[i].point = 0;
				if (g_enemy[i].type == 0)g_EnemyCount1++;
				if (g_enemy[i].type == 1)g_EnemyCount2++;
				if (g_enemy[i].type == 2)g_EnemyCount3++;
				if (g_enemy[i].type == 3)g_EnemyCount4++;
			}*/

			/*if (++g_Time < 120) {
				if (g_enemy[i].type == 3)g_enemy[i].x += v[g_enemy[i].cnt] + g_enemy[i].speed - PLAYER_SPEED + 3;
			}
			else if (++g_Time < 240) {
				if (g_enemy[i].type == 3)g_enemy[i].x -= v[g_enemy[i].cnt] + g_enemy[i].speed - PLAYER_SPEED + 3;
			}
			else if (g_Time > 300) {
				g_Time = 0;
			}*/

			//当たり判定
			if (HitBoxPlayer(&g_player) == TRUE) {
				//g_player.flg = FALSE;
				//g_player.speed = PLAYER_SPEED;
				//g_player.count = 0;
				//g_player.hp -= 100;
				flg = FALSE;
				//if (g_player.hp <= 0)  g_GameState = 6;
			}
		}
	//}

	//走行距離ごとに敵出現パターンを制御する
	/*if (g_Mileage / 10 % 50 == 0) {
		CreateEnemy();
	}*/
}