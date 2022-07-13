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
	//変数の宣言
	int g_OldKey;    // 前回の入力キー
	int g_NowKey;    // 今回の入力キー
	int g_KeyFlg;    // 入力キー情報

	int g_GameState = 0;
	int Score = 0;  // スコア
	int g_Time;   //時間
	int g_PauseFlg;  //ポーズフラグ
	//int g_WaitTime = 0;  //待ち時間
	//int PosY;

	int applecursor;//タイトルのカーソル画像
	int AppleImages[4];//リンゴの画像
	int PlayerImages[3];//キャラ画像

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