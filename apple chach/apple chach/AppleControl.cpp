#define _USE_MATH_DEFINES
#include "apple.h"
#include "DxLib.h"

void APPLE::AppleControl() {
	for (int i = 0; i < APPLE_MAX; i++) {
		if (flg == TRUE) {
			//�G�̕\��
			DrawRotaGraph(x, y, 1.0f, 0, img, TRUE, FALSE);

			//if (g_player.flg == FALSE) continue;

			//�܂��������Ɉړ�
			//g_enemy[i].y += g_enemy[i].speed + g_player.speed - PLAYER_SPEED + 1;
			y += speed;

			//��ʂ��͂ݏo���������
			//if (g_enemy[i].y > SCREEN_HEIGHT + g_enemy[i].h) g_enemy[i].flg = FALSE;

			//�G�@��ǂ��z������J�E���g
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

			//�����蔻��
			/*if (HitBoxPlayer(&g_player, &g_enemy[i]) == TRUE && g_player.baricnt <= 0) {
				g_player.flg = FALSE;
				g_player.speed = PLAYER_SPEED;
				g_player.count = 0;
				g_player.hp -= 100;
				g_enemy[i].flg = FALSE;
				if (g_player.hp <= 0)  g_GameState = 6;
			}*/
		}
	}

	//���s�������ƂɓG�o���p�^�[���𐧌䂷��
	/*if (g_Mileage / 10 % 50 == 0) {
		CreateEnemy();
	}*/
}