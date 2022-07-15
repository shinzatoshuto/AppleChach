#pragma once

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int MAX_INTERVAL = 1 * 60;

extern int g_AppleCount[4];

class Variable {
public:
	//変数の宣言
	int g_GameState = 0;
	int Score = 0;  // スコア
	int g_Time;   //時間

	int AppleImages[4];//リンゴの画像
	int PlayerImages[3];//キャラ画像

	int GameImage;

	//BGM
	int GameBGM;
};
extern Variable var;