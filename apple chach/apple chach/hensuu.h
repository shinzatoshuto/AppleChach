#pragma once
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int ENEMY_MAX = 8;
const int ITEM_MAX = 3;
const int MAX_INTERVAL = 3 * 60;

struct PLAYER {
	int flg;
	int x, y;
	int w, h;
	double angle;
	int count;
	int speed;
	int hp;
	int fuel;
	int bari;
	int baricnt;
	int bariup;
};

extern PLAYER g_player;

extern int g_AppleCount[4];

class HENSUU {
public:
	//変数の宣言
	int g_OldKey;    // 前回の入力キー
	int g_NowKey;    // 今回の入力キー
	int g_KeyFlg;    // 入力キー情報

	int g_GameState = 0;

	int g_TitleImage;
	int g_Menu, applecursor;

	int Score = 0;  // スコア
	int g_Time;   //時間

	int g_RankingImage;

	int g_Item[2];

	int g_WaitTime = 0;  //待ち時間
	int g_EndImage;
	int HelpImage;

	int g_Mileage; //走行距離
	int g_EnemyCount1, g_EnemyCount2, g_EnemyCount3, g_EnemyCount4; //敵カウント
	int g_Teki[4]; //キャラ画像変数

	int g_StageImage;
	int AppleImages[4];//リンゴの画像

	int CharaImages[3];//キャラ画像

	int Backimg;

	int g_Car, g_Barrier;
	int g_Player[3];
	int g_Back = 0;
	int v[3] = { -1,0,1 };
};
extern HENSUU hen;