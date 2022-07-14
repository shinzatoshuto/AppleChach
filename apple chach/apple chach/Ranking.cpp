#include "Ranking.h"
#include "hensuu.h"
#include "font.h"
#include "pad.h"
#include "DxLib.h"

//�Q�[�������L���O�`��\��
void RANKING::DrawRanking(void) {
	//�X�y�[�X�L�[�Ń��j���[�ɖ߂�
	if (hen.g_KeyFlg & PAD_INPUT_2) {
		hen.g_GameState = 0;
		PlaySoundMem(hen.CancelSE, DX_PLAYTYPE_BACK);
	}
	//�����L���O�摜�\��
	DrawGraph(0, 0, hen.g_RankingImage, FALSE);
	//�����L���O�ꗗ��\��
	//SetFontSize(18);
	for (int i = 0; i < RANKING_DATA; i++) {
		DrawFormatStringToHandle(140, 170 + i * 35, 0xffffff, font.fontking, "%2d %+10s %10d", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
	}
	SetFontSize(25);
	DrawString(150, 430, "---- B�{�^���Ŗ߂� ----", 0xffffff, 0);
}

void RANKING::InputRanking(void) {
	//�����L���O�摜�\��
	DrawGraph(0, 0, hen.g_RankingImage, FALSE);
	SetFontSize(20);

	//���O���͎w��������̕`��
	DrawStringToHandle(110, 120, "�����L���O�ɓo�^���܂�", 0xffffff, font.fontrans);
	DrawStringToHandle(110, 150, "���O���p���œ��͂��Ă�������", 0xffffff, font.fontrans);

	//���O�̓���
	DrawString(110, 210, ">", 0xffffff);
	DrawBox(120, 200, 317, 240, 0x000055, TRUE);

	pad.DrawInput();
	//try {
	if (hen.g_KeyFlg & PAD_INPUT_8 && pad.inputnum > 0) {
		//g_Ranking[4].name = pad.inputchar;
		PlaySoundMem(hen.ClickSE, DX_PLAYTYPE_BACK);
		strcpy_s(g_Ranking[4].name, 11, pad.inputchar);
		g_Ranking[4].score = hen.Score;
		SortRanking();
		SaveRanking();
		hen.g_GameState = 2;
	}
	//}
	//catch (int& err) {
	//	printf("�G���[�R�[�h%d\n", err);
	//}

	//if (KeyInputSingleCharString(130, 210, 10, g_Ranking[4].name, FALSE) == 1) {
	//	g_Ranking[4].score = hen.Score;
	//	SortRanking();
	//	SaveRanking();
	//	hen.g_GameState = 2;
	//}
}

//�����L���O���ёւ�
void RANKING::SortRanking(void) {
	int i, j;
	RankingData work;

	//�I���\�[�g
	for (i = 0; i < 4; i++) {
		for (j = i + 1; j < 5; j++) {
			if (g_Ranking[i].score <= g_Ranking[j].score) {
				work = g_Ranking[i];
				g_Ranking[i] = g_Ranking[j];
				g_Ranking[j] = work;
			}
		}
	}

	//���ʕt��
	for (i = 0; i < 5; i++) {
		g_Ranking[i].no = 1;
	}
	//���_�������������ꍇ�́A�������ʂƂ���
	//�����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
	for (i = 0; i < 4; i++) {
		for (j = i + 1; j < 5; j++) {
			if (g_Ranking[i].score > g_Ranking[j].score) {
				g_Ranking[j].no++;
			}
		}
	}
}

//�����L���O�f�[�^�̕ۑ�
int RANKING::SaveRanking(void) {
	FILE* fp;
#pragma warning(disable:4996)

	//�t�@�C���I�[�v��
	if ((fp = fopen("rankingdata.txt", "w")) == NULL) {
		//�G���[����
		printf("Ranking Data Error\n");
		return-1;
	}

	//�����L���O�f�[�^���z��f�[�^����������
	for (int i = 0; i < 5; i++) {
		fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	return 0;
}

//�����L���O�f�[�^�ǂݍ���
int RANKING::ReadRanking(void) {
	FILE* fp;
#pragma warning(disable:4996)
	if ((fp = fopen("rankingdata.txt", "r")) == NULL) {
		printf("Ranking Data Error\n");
		return-1;
	}

	for (int i = 0; i < 5; i++) {
		fscanf(fp, "%2d %10s %10d\n", &g_Ranking[i].no, g_Ranking[i].name, &g_Ranking[i].score);
	}

	fclose(fp);


	return 0;
}