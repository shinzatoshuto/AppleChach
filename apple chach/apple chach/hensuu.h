#pragma once

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int MAX_INTERVAL = 1 * 60;

extern int g_AppleCount[4];

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

	int AppleImages[4];//リンゴの画像
	int PlayerImages[3];//キャラ画像

	int GameImage;
	int g_RankingImage;
	int EndImage;

	//SE
	int FallSE, CatchSE, PoisonSE, GetAppleSE; //Apple SE
	int MoveSE, ClickSE, CancelSE; //Button SE

	//BGM
	int GameBGM;
};
extern HENSUU hen;