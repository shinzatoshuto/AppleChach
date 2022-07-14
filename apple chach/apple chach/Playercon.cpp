#include "DxLib.h"
#include "Player.h"
#include"hensuu.h"
#include "Font.h"

void PLAYER::InitPlayer() {
	flg = TRUE;
	x = PLAYER_POS_X;
	y = PLAYER_POS_Y;
	w = PLAYER_WIDTH;
	h = PLAYER_HEIGHT;
	count = 0;
	speed = PLAYER_SPEED;
}

void PLAYER::PlayerControl() {
	//�Q�[���I�[�o�[������
	if (hen.g_Time <= 0) {
		StopSoundMem(hen.GameBGM);
		hen.g_GameState = 6;
	}

	//�㉺���E�ړ�
	if (hen.g_PauseFlg == 0) {
		if (flg == TRUE || true) {
			if (hen.g_NowKey & PAD_INPUT_LEFT) x -= speed;
			if (hen.g_NowKey & PAD_INPUT_RIGHT) x += speed;
		}
	}
	//��ʂ��͂ݏo���Ȃ��悤�ɂ���
	if (x < 16)  x = 16;
	if (x > SCREEN_WIDTH - 146)  x = SCREEN_WIDTH - 146;
	//if (y < 60)  y = 60;
	//if (y > SCREEN_HEIGHT - 60)  y = SCREEN_HEIGHT - 60;


	//�v���C���[�̕\��
	//if (flg == TRUE) {
	if (flg == TRUE || (hen.g_PauseFlg == FALSE && flg == FALSE && --count % 20 == 0)) {
		if (hen.g_NowKey & PAD_INPUT_LEFT) {
			//po-zu
			if (hen.g_PauseFlg == FALSE) {
				//DrawGraph(x - 86, y - h / 2, hen.PlayerImages[0], TRUE);
				DrawRotaGraph(x, y, 1, 0, hen.PlayerImages[0], TRUE);
			}
			else {
				//DrawGraph(x - 86, y - 125, hen.PlayerImages[2], TRUE);
				DrawRotaGraph(x, y, 1, 0, hen.PlayerImages[2], TRUE);
			}
		}
		else if (hen.g_NowKey & PAD_INPUT_RIGHT) {
			//po-zu
			if (hen.g_PauseFlg == FALSE) {
				//DrawGraph(x - 86, y - h / 2, hen.PlayerImages[1], TRUE);
				DrawRotaGraph(x, y, 1, 0, hen.PlayerImages[1], TRUE);
			}
			else {
				//DrawGraph(x - 86, y - 125, hen.PlayerImages[2], TRUE);
				DrawRotaGraph(x, y, 1, 0, hen.PlayerImages[2], TRUE);
			}
		}
		else {
			//DrawGraph(x - 86, y - 125, hen.PlayerImages[2], TRUE);
			DrawRotaGraph(x, y, 1, 0, hen.PlayerImages[2], TRUE);
		}
	}
	if (hen.g_PauseFlg == TRUE) {
		//DrawGraph(x - 86, y - 125, hen.PlayerImages[2], TRUE);
		DrawRotaGraph(x, y, 1, 0, hen.PlayerImages[2], TRUE);
	}
	if (count <= 0) flg = TRUE;

	//�|�[�Y�t���O
	if (hen.g_NowKey & PAD_INPUT_B && hen.g_PauseFlg == FALSE) {
		hen.g_PauseFlg = TRUE;
		StopSoundMem(hen.GameBGM);
	}
	if (hen.g_NowKey & PAD_INPUT_X && hen.g_PauseFlg == TRUE) {
		hen.g_PauseFlg = FALSE;
		PlaySoundMem(hen.GameBGM, DX_PLAYTYPE_BACK, FALSE);

	}
	if (hen.g_PauseFlg == TRUE) {
		DrawStringToHandle(120, 180, "�ہ[�����イ", 0x000000, font.fontpose);
	}

	//UI�̘g�\��
	DrawBox(SCREEN_WIDTH - 130, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x00ffff, TRUE);

	//�������Ԃ̕\��
	SetFontSize(25);
	DrawFormatString(520, 20, 0x000000, "��������");
	DrawFormatString(560, 60, 0x000000, "%d", hen.g_Time / 60);

	//��񂲂����������\��
	SetFontSize(16);
	for (int i = 0; i < 4; i++) {
		DrawRotaGraph(528 + i * 30, 120, 0.5f, 0, hen.AppleImages[i], TRUE, FALSE);
		DrawFormatString(520 + i * 30, 140, 0x000000, "%02d", g_AppleCount[i]);
	}

	SetFontSize(30);
	DrawFormatString(530, 180, 0x000000, "�X�R�A");
	SetFontSize(20);
	DrawFormatString(543, 220, 0x000000, "%06d", hen.Score);
}
