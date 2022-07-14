#include<DxLib.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include"apple.h"
#include"Player.h"
#include "hensuu.h"
#include "Font.h"
#include "Ranking.h"
#include "Help.h"
#include "End.h"
#include"pad.h"
#include "Font.h"

APPLE apple[APPLE_MAX];
HENSUU hen;
PAD pad;
FONT font;
END end;
PLAYER player;
RANKING ranking;
HELP help;

//�֐��̃v���g�^�C�v�錾
void GameInit(void);
void GameMain(void);

void DrawGameTitle(void);
void DrawGameOver(void);

int LoadImages();

int nextTime;
int g_AppleCount[4];

//�v���O�����J�n
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
	SetMainWindowText("Apple Catch");   //�^�C�g����ݒ�
	ChangeWindowMode(TRUE);
	SetWindowSize(640, 480);

	if (DxLib_Init() == -1) return -1;
	if (LoadImages() == -1) return -1;
	if (LoadSound() == -1) return -1;
	if (font.LoadFont() == -1) return -1;
	if (ranking.ReadRanking() == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);
	ChangeVolumeSoundMem(100, hen.GameBGM);
	ChangeVolumeSoundMem(150, hen.TitleBGM);
	ChangeVolumeSoundMem(255, hen.FallSE);


	//�Q�[�����[�v
	while (ProcessMessage() == 0 && hen.g_GameState != 99 && !(hen.g_KeyFlg & PAD_INPUT_7))
	{
		hen.g_OldKey = hen.g_NowKey;
		hen.g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		hen.g_KeyFlg = hen.g_NowKey & ~hen.g_OldKey;

		ClearDrawScreen();

		switch (hen.g_GameState) {
		case 0:DrawGameTitle();
			break;
		case 1:GameInit();
			break;
		case 2:ranking.DrawRanking();
			break;
		case 3:help.DrawHelp();
			break;
		case 4:end.DrawEnd();
			break;
		case 5:GameMain();
			break;
		case 6:DrawGameOver();
			break;
		case 7:ranking.InputRanking();
			break;
		}

		ScreenFlip();
	}
	DxLib_End();

	return 0;
}

//�Q�[���^�C�g���\��
void DrawGameTitle(void) {
	static int MenuNo = 0;
	if (CheckSoundMem(hen.TitleBGM) == 0)
	PlaySoundMem(hen.TitleBGM, DX_PLAYTYPE_BACK);
	//���j���[�J�[�\���ړ�����
	if (hen.g_KeyFlg & PAD_INPUT_DOWN) {
		if (++MenuNo > 3)MenuNo = 0;
		PlaySoundMem(hen.MoveSE, DX_PLAYTYPE_BACK);
	}
	if (hen.g_KeyFlg & PAD_INPUT_UP) {
		if (--MenuNo < 0)MenuNo = 3;
		PlaySoundMem(hen.MoveSE, DX_PLAYTYPE_BACK);
	}

	//Z�L�[�Ń��j���[�I��
	if (hen.g_KeyFlg & PAD_INPUT_A) {
		hen.g_GameState = MenuNo + 1;
		PlaySoundMem(hen.ClickSE, DX_PLAYTYPE_BACK);
	}

	//�^�C�g���摜�\��
	DrawGraph(0, 0, hen.g_TitleImage, FALSE);

	//���j���[
	//DrawGraph(120, 200, hen.g_Menu, TRUE);

	//���j���[�J�[�\��
	DrawRotaGraph(430, 300 + MenuNo * 42, 0.7f, 0, hen.applecursor, TRUE);
}

//�Q�[����������
void GameInit(void) {
	//�X�R�A�̏�����
	hen.Score = 0;

	//�v���C���[�̏����ݒ�
	player.InitPlayer();

	//��񂲂̏����ݒ�
	for (int i = 0; i < APPLE_MAX; i++) {
		apple[i].InitApple();
	}
	//�����S�̃J�E���g�̏�����
	for (int i = 0; i < 4; i++) {
		g_AppleCount[i] = 0;
	}

	hen.g_Time = 1800;


	pad.inputnum = 0;
	strcpy_s(pad.inputchar, 10, "         ");

	nextTime = hen.g_Time - GetRand(MAX_INTERVAL);

	StopSoundMem(hen.TitleBGM);
	PlaySoundMem(hen.GameBGM, DX_PLAYTYPE_BACK);
	//�Q�[�����C��������
	hen.g_GameState = 5;

	//�|�[�Y�t���O
	hen.g_PauseFlg = 0;
}
//
////�Q�[�������L���O�`��\��
//void DrawRanking(void) {
//	//�X�y�[�X�L�[�Ń��j���[�ɖ߂�
//	if (hen.g_KeyFlg & PAD_INPUT_2) {
//		hen.g_GameState = 0;
//		PlaySoundMem(hen.CancelSE, DX_PLAYTYPE_BACK);
//	}
//	//�����L���O�摜�\��
//	DrawGraph(0, 0, hen.g_RankingImage, FALSE);
//	//�����L���O�ꗗ��\��
//	//SetFontSize(18);
//	for (int i = 0; i < RANKING_DATA; i++) {
//		DrawFormatStringToHandle(140, 170 + i * 35, 0xffffff, fontking,"%2d %+10s %10d", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
//	}
//	SetFontSize(25);
//	DrawString(150, 430, "---- B�{�^���Ŗ߂� ----", 0xffffff, 0);
//}

////�Q�[���w���v�`�揈��
//void DrawHelp(void) {
//	//�X�y�[�X�L�[�Ń��j���[�ɖ߂�
//	if (hen.g_KeyFlg & PAD_INPUT_2) {
//		hen.g_GameState = 0;
//		PlaySoundMem(hen.CancelSE, DX_PLAYTYPE_BACK);
//	}
//	//z�Q�[���J�n
//	if (hen.g_KeyFlg & PAD_INPUT_1) {
//		hen.g_GameState = 1;
//		PlaySoundMem(hen.ClickSE, DX_PLAYTYPE_BACK);
//	}
//
//	//�^�C�g���摜�\��
//	DrawGraph(0, 0, hen.HelpImage, FALSE);
//	SetFontSize(16);
//
//	DrawString(20, 160, "����͗����Ă��郊���S���E���Q�[���ł��B", 0x000000, 0);
//	DrawString(20, 180, "���E�ɓ����ė����Ă���l�X�ȃ����S���E���܂��B", 0x000000, 0);
//	DrawString(20, 200, "���㉺�ړ��͂ł��܂���", 0x000000, 0);
//	DrawString(20, 220, "�������Ԃ�30�b�ł��B", 0x000000, 0);
//	DrawString(20, 250, "�����S�ꗗ", 0x000000, 0);
//	DrawGraph(20, 260, hen.AppleImages[0], TRUE);
//	DrawString(62, 275, "+150P", 0x0000ff, 0);
//	DrawGraph(120, 260, hen.AppleImages[1], TRUE);
//	DrawString(162, 275, "+300P", 0x0000ff, 0);
//	DrawGraph(220, 260, hen.AppleImages[2], TRUE);
//	DrawString(262, 275, "+500P", 0x0000ff, 0);
//	DrawString(20, 315, "�ԁA���A�ΐF�̃����S���Ƃ�ƃX�R�A���������B", 0x000000, 0);
//	DrawGraph(20, 335, hen.AppleImages[3], TRUE);
//	DrawString(60, 350, "-1000P", 0xff0000, 0);
//	DrawString(20, 385, "�Ń����S�ɐG���Ƃ������������B", 0x000000, 0);
//	DrawString(20, 425, "�v���C����START�{�^���������ƃ|�[�Y�Ɉڍs���܂��B", 0x000000, 0);
//	DrawString(20, 445, "(������x�����ƃv���C��ʂɖ߂�܂�)", 0x000000, 0);
//	DrawString(490, 450, "�Q�[����[A�{�^��]", 0x000000, 0);
//	DrawString(524, 430, "�߂�[B�{�^��]", 0x000000, 0);
//
//	DrawStringToHandle(20, 120, "�w���v���", 0xffffff, font00);
//}


//�Q�[���G���h�`�揈��
//void DrawEnd(void) {
//	
//
//	//�G���h�摜�\��
//	DrawGraph(0, 0, hen.EndImage, FALSE);
//
//	DrawStringToHandle(65, 30, "Thank you for Playing !!", 0xffff00, fonten);
//
//	if (++hen.g_WaitTime < 90)hen.PosY = 90 - hen.g_WaitTime / 2;
//	DrawStringToHandle(80, 70 + hen.PosY, "�^�C�g���@�@AppleChach", 0xffffff, fontensc);
//	DrawStringToHandle(80, 110 + hen.PosY, "����ҁ@���ۓd�q�r�W�l�X���w�Z", 0xffffff, fontensc);
//	DrawStringToHandle(80, 150 + hen.PosY, "�@�@�@�@�@����@��m", 0xffffff, fontensc);
//	DrawStringToHandle(80, 190 + hen.PosY, "�@�@�@�@�@�u�o���@���l", 0xffffff, fontensc);
//	DrawStringToHandle(80, 230 + hen.PosY, "�@�@�@�@�@��ԁ@����", 0xffffff, fontensc);
//	DrawStringToHandle(80, 270 + hen.PosY, "�@�@�@�@�@�V���@�A�l", 0xffffff, fontensc);
//	DrawStringToHandle(80, 310 + hen.PosY, "�f�ޗ��p", 0xffffff, fontensc);
//	DrawStringToHandle(80, 350 + hen.PosY, "BGM�@�@�@�@������", 0xffffff, fontensc);
//	DrawStringToHandle(80, 390 + hen.PosY, "SE�@�@�@�@   ������", 0xffffff, fontensc);
//
//	//�^�C���̉��Z����&�I��
//	if (++hen.g_WaitTime > 160) hen.g_GameState = 99;
//}

//�Q�[�����C��
void GameMain(void) {
	DrawGraph(0, 0, hen.GameImage, FALSE);
	player.PlayerControl();
	for (int i = 0; i < APPLE_MAX; i++) {
		apple[i].AppleControl();
	}
	if (hen.g_PauseFlg == 0) {
		if (--hen.g_Time < nextTime) {
			for (int i = 0; i < APPLE_MAX; i++) {
				if (apple[i].CreateApple()) {
					nextTime -= GetRand(MAX_INTERVAL);
					break;
				}
			}
		}
	}
}

//void PlayerControl() {
//	//�Q�[���I�[�o�[������
//	if (hen.g_Time <= 0) {
//		StopSoundMem(hen.GameBGM);
//		hen.g_GameState = 6;
//	}
//
//	//�㉺���E�ړ�
//	if (hen.g_PauseFlg == 0) {
//		if (g_player.flg == TRUE || true) {
//			if (hen.g_NowKey & PAD_INPUT_LEFT) g_player.x -= g_player.speed;
//			if (hen.g_NowKey & PAD_INPUT_RIGHT) g_player.x += g_player.speed;
//		}
//	}
//	//��ʂ��͂ݏo���Ȃ��悤�ɂ���
//	if (g_player.x < 16)  g_player.x = 16;
//	if (g_player.x > SCREEN_WIDTH - 146)  g_player.x = SCREEN_WIDTH - 146;
//	//if (g_player.y < 60)  g_player.y = 60;
//	//if (g_player.y > SCREEN_HEIGHT - 60)  g_player.y = SCREEN_HEIGHT - 60;
//
//	
//	//�v���C���[�̕\��
//	//if (g_player.flg == TRUE) {
//	if (g_player.flg == TRUE || (hen.g_PauseFlg == FALSE && g_player.flg == FALSE && --g_player.count % 20 == 0)) {
//		if (hen.g_NowKey & PAD_INPUT_LEFT) {
//			//po-zu
//			if (hen.g_PauseFlg == FALSE) {
//				//DrawGraph(g_player.x - 86, g_player.y - g_player.h / 2, hen.PlayerImages[0], TRUE);
//				DrawRotaGraph(g_player.x, g_player.y, 1, 0, hen.PlayerImages[0], TRUE);
//			}
//			else {
//				//DrawGraph(g_player.x - 86, g_player.y - 125, hen.PlayerImages[2], TRUE);
//				DrawRotaGraph(g_player.x, g_player.y, 1, 0, hen.PlayerImages[2], TRUE);
//			}
//		}
//		else if (hen.g_NowKey & PAD_INPUT_RIGHT) {
//			//po-zu
//			if (hen.g_PauseFlg == FALSE) {
//				//DrawGraph(g_player.x - 86, g_player.y - g_player.h / 2, hen.PlayerImages[1], TRUE);
//				DrawRotaGraph(g_player.x, g_player.y, 1, 0, hen.PlayerImages[1], TRUE);
//			}
//			else {
//				//DrawGraph(g_player.x - 86, g_player.y - 125, hen.PlayerImages[2], TRUE);
//				DrawRotaGraph(g_player.x, g_player.y, 1, 0, hen.PlayerImages[2], TRUE);
//			}
//		}
//		else {
//			//DrawGraph(g_player.x - 86, g_player.y - 125, hen.PlayerImages[2], TRUE);
//			DrawRotaGraph(g_player.x, g_player.y, 1, 0, hen.PlayerImages[2], TRUE);
//		}
//	}
//	if (hen.g_PauseFlg == TRUE) {
//		//DrawGraph(g_player.x - 86, g_player.y - 125, hen.PlayerImages[2], TRUE);
//		DrawRotaGraph(g_player.x, g_player.y, 1, 0, hen.PlayerImages[2], TRUE);
//	}
//		if (g_player.count <= 0) g_player.flg = TRUE;
//
//	//�|�[�Y�t���O
//	if (hen.g_NowKey & PAD_INPUT_B && hen.g_PauseFlg == FALSE) {
//		hen.g_PauseFlg = TRUE;
//		StopSoundMem(hen.GameBGM);
//	}
//	if (hen.g_NowKey & PAD_INPUT_X && hen.g_PauseFlg == TRUE) {
//		hen.g_PauseFlg = FALSE;
//		PlaySoundMem(hen.GameBGM, DX_PLAYTYPE_BACK, FALSE);
//		
//	}
//	if (hen.g_PauseFlg == TRUE) {
//		DrawStringToHandle(120, 180, "�ہ[�����イ", 0x000000, fontpose);
//	}
//	
//	//UI�̘g�\��
//	DrawBox(SCREEN_WIDTH - 130, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x00ffff, TRUE);
//
//	//�������Ԃ̕\��
//	SetFontSize(25);
//	DrawFormatString(520, 20, 0x000000, "��������");
//	DrawFormatString(560, 60, 0x000000, "%d", hen.g_Time / 60);
//
//	//��񂲂����������\��
//	SetFontSize(16);
//	for (int i = 0; i < 4; i++) {
//		DrawRotaGraph(528 + i * 30, 120, 0.5f, 0, hen.AppleImages[i], TRUE, FALSE);
//		DrawFormatString(520 + i * 30, 140, 0x000000, "%02d", g_AppleCount[i]);
//	}
//
//	SetFontSize(30);
//	DrawFormatString(530, 180, 0x000000, "�X�R�A");
//	SetFontSize(20);
//	DrawFormatString(543, 220, 0x000000, "%06d", hen.Score);
//}

//�Q�[���I�[�o�[�摜�`�揈��
void DrawGameOver(void) {
	//B�{�^���Ń��j���[�ɖ߂�
	if (hen.g_KeyFlg & PAD_INPUT_2) {
		PlaySoundMem(hen.CancelSE, DX_PLAYTYPE_BACK);
		if (ranking.g_Ranking[RANKING_DATA - 1].score >= hen.Score) {
			hen.g_GameState = 0;
		}
		else {
			hen.g_GameState = 7;
		}
	}

	DrawBox(150, 150, 490, 330, 0x009900, TRUE);
	DrawBox(150, 150, 490, 330, 0x000000, FALSE);

	SetFontSize(20);
	DrawString(220, 170, "�Q�[���I�[�o�[", 0xcc0000);
	SetFontSize(18);

	DrawRotaGraph(215, 220, 0.5f, 0, hen.AppleImages[0], TRUE, FALSE);
	DrawRotaGraph(215, 240, 0.5f, 0, hen.AppleImages[1], TRUE, FALSE);
	DrawRotaGraph(215, 260, 0.5f, 0, hen.AppleImages[2], TRUE, FALSE);
	DrawRotaGraph(215, 280, 0.5f, 0, hen.AppleImages[3], TRUE, FALSE); 

	DrawFormatString(210, 212, 0xFFFFFF, "%6d x   150 = %6d", g_AppleCount[0], g_AppleCount[0] * 150);
	DrawFormatString(210, 233, 0xFFFFFF, "%6d x   300 = %6d", g_AppleCount[1], g_AppleCount[1] * 300);
	DrawFormatString(210, 254, 0xFFFFFF, "%6d x   500 = %6d", g_AppleCount[2], g_AppleCount[2] * 500);
	DrawFormatString(210, 275, 0xFFFFFF, "%6d x -1000 = %6d", g_AppleCount[3], g_AppleCount[3] * -1000);

	DrawString(310, 310, "�X�R�A", 0x000000);
	DrawFormatString(260, 310, 0xFFFFFF, "             = %6d", hen.Score);
	SetFontSize(25);
	DrawString(150, 450, "---- B�{�^���Ŗ߂� ----", 0xffffff, 0);
}

//�����L���O���͏���
//void InputRanking(void) {
//	//�����L���O�摜�\��
//	DrawGraph(0, 0, hen.g_RankingImage, FALSE);
//	SetFontSize(20);
//
//	//���O���͎w��������̕`��
//	DrawStringToHandle(110, 120, "�����L���O�ɓo�^���܂�", 0xffffff, fontrans);
//	DrawStringToHandle(110, 150, "���O���p���œ��͂��Ă�������", 0xffffff, fontrans);
//
//	//���O�̓���
//	DrawString(110, 210, ">", 0xffffff);
//	DrawBox(120, 200, 317, 240, 0x000055, TRUE);
//
//	pad.DrawInput();
//	//try {
//		if (hen.g_KeyFlg & PAD_INPUT_8 && pad.inputnum > 0) {
//			//g_Ranking[4].name = pad.inputchar;
//			PlaySoundMem(hen.ClickSE, DX_PLAYTYPE_BACK);
//			strcpy_s(g_Ranking[4].name, 11, pad.inputchar);
//			g_Ranking[4].score = hen.Score;
//			SortRanking();
//			SaveRanking();
//			hen.g_GameState = 2;
//		}
//	//}
//	//catch (int& err) {
//	//	printf("�G���[�R�[�h%d\n", err);
//	//}
//
//	//if (KeyInputSingleCharString(130, 210, 10, g_Ranking[4].name, FALSE) == 1) {
//	//	g_Ranking[4].score = hen.Score;
//	//	SortRanking();
//	//	SaveRanking();
//	//	hen.g_GameState = 2;
//	//}
//}
//
////�����L���O���ёւ�
//void SortRanking(void) {
//	int i, j;
//	RankingData work;
//
//	//�I���\�[�g
//	for (i = 0; i < 4; i++) {
//		for (j = i + 1; j < 5; j++) {
//			if (g_Ranking[i].score <= g_Ranking[j].score) {
//				work = g_Ranking[i];
//				g_Ranking[i] = g_Ranking[j];
//				g_Ranking[j] = work;
//			}
//		}
//	}
//
//	//���ʕt��
//	for (i = 0; i < 5; i++) {
//		g_Ranking[i].no = 1;
//	}
//	//���_�������������ꍇ�́A�������ʂƂ���
//	//�����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
//	for (i = 0; i < 4; i++) {
//		for (j = i + 1; j < 5; j++) {
//			if (g_Ranking[i].score > g_Ranking[j].score) {
//				g_Ranking[j].no++;
//			}
//		}
//	}
//}
//
////�����L���O�f�[�^�̕ۑ�
//int SaveRanking(void) {
//	FILE* fp;
//#pragma warning(disable:4996)
//
//	//�t�@�C���I�[�v��
//	if ((fp = fopen("rankingdata.txt", "w")) == NULL) {
//		//�G���[����
//		printf("Ranking Data Error\n");
//		return-1;
//	}
//
//	//�����L���O�f�[�^���z��f�[�^����������
//	for (int i = 0; i < 5; i++) {
//		fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
//	}
//
//	//�t�@�C���N���[�Y
//	fclose(fp);
//
//	return 0;
//}
//
////�����L���O�f�[�^�ǂݍ���
//int ReadRanking(void) {
//	FILE* fp;
//#pragma warning(disable:4996)
//	if ((fp = fopen("rankingdata.txt", "r")) == NULL) {
//		printf("Ranking Data Error\n");
//		return-1;
//	}
//
//	for (int i = 0; i < 5; i++) {
//		fscanf(fp, "%2d %10s %10d\n", &g_Ranking[i].no, g_Ranking[i].name, &g_Ranking[i].score);
//	}
//
//	fclose(fp);
//
//	
//	return 0;
//}