#define _USE_MATH_DEFINES
#include "apple.h"
#include "Player.h"
#include "hensuu.h"
#include "DxLib.h"

void APPLE::AppleControl() {
	if (flg == TRUE) {
		//�����S�̕\��

		DrawGraph(x, y, img, TRUE);

		//�|�[�Y�\������Ȃ��ԓ�����
		if (hen.g_PauseFlg == 0) {
			y += speed;
		}

		//��ʂ��͂ݏo���������
		if (y > SCREEN_HEIGHT + h) flg = FALSE;

		//�����蔻��
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