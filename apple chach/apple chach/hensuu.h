#pragma once

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int MAX_INTERVAL = 1 * 60;

//struct PLAYER {
//	int flg;
//	int x, y;
//	int w, h;
//	int count;
//	int speed;
//};
//
//extern PLAYER g_player;

extern int g_AppleCount[4];

int LoadSound();

class HENSUU {
public:
	//�ϐ��̐錾
	int g_OldKey;    // �O��̓��̓L�[
	int g_NowKey;    // ����̓��̓L�[
	int g_KeyFlg;    // ���̓L�[���

	int g_GameState = 0;
	int Score = 0;  // �X�R�A
	int g_Time;   //����
	int g_PauseFlg;  //�|�[�Y�t���O
	//int g_WaitTime = 0;  //�҂�����
	//int PosY;

	int applecursor;//�^�C�g���̃J�[�\���摜
	int AppleImages[4];//�����S�̉摜
	int PlayerImages[3];//�L�����摜

	int g_TitleImage;
	int GameImage;
	int g_RankingImage;
	int HelpImage;
	int EndImage;

	//SE
	int FallSE, CatchSE, PoisonSE, GetAppleSE; //Apple SE
	int MoveSE, ClickSE, CancelSE; //Button SE

	//BGM
	int TitleBGM;
	int GameBGM;
};
extern HENSUU hen;