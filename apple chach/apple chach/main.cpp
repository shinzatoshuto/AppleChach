#include<DxLib.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include"apple.h"
#include"Player.h"
#include "variable.h"
#include "Font.h"
#include "Ranking.h"
#include "Help.h"
#include "End.h"
#include"pad.h"
#include "UI.h"
#include "Title.h"
#include"Load.h"
#include"GameOver.h"

APPLE apple[APPLE_MAX];
Variable var;
PAD pad;
FONT font;
END end;
PLAYER player;
RANKING ranking;
HELP help;
UI ui;
TITLE title;
Load load;
GameOver GO;

//関数のプロトタイプ宣言
void GameInit(void);
void GameMain(void);

int nextTime;
int g_AppleCount[4];

//プログラム開始
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
	SetMainWindowText("Apple Catch");   //タイトルを設定
	ChangeWindowMode(TRUE);
	SetWindowSize(640, 480);
	if (DxLib_Init() == -1)return-1;
	SetDrawScreen(DX_SCREEN_BACK);
	if (load.LoadImages() == -1)return-1;
	if (ranking.ReadRanking() == -1)return-1;
	if (font.LoadFont() == -1)return-1;
	if (load.LoadSound() == -1)return-1;

	ChangeVolumeSoundMem(100, var.GameBGM);
	ChangeVolumeSoundMem(150, title.TitleBGM);


	//ゲームループ
	while (ProcessMessage() == 0 && var.g_GameState != 99 && !(pad.g_KeyFlg & PAD_INPUT_7))
	{
		pad.g_OldKey = pad.g_NowKey;
		pad.g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		pad.g_KeyFlg = pad.g_NowKey & ~pad.g_OldKey;

		ClearDrawScreen();

		switch (var.g_GameState) {
		case 0:title.DrawGameTitle();
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
		case 6:GO.DrawGameOver();
			break;
		case 7:ranking.InputRanking();
			break;
		}

		ScreenFlip();
	}
	DxLib_End();

	return 0;
}

//ゲーム初期処理
void GameInit(void) {
	//スコアの初期化
	var.Score = 0;

	//プレイヤーの初期設定
	player.InitPlayer();

	//りんごの初期設定
	for (int i = 0; i < APPLE_MAX; i++) {
		apple[i].InitApple();
	}
	//リンゴのカウントの初期化
	for (int i = 0; i < 4; i++) {
		g_AppleCount[i] = 0;
	}

	var.g_Time = 1800;


	pad.inputnum = 0;
	strcpy_s(pad.inputchar, 10, "         ");

	nextTime = var.g_Time - GetRand(MAX_INTERVAL);

	StopSoundMem(title.TitleBGM);
	PlaySoundMem(var.GameBGM, DX_PLAYTYPE_BACK);
	//ゲームメイン処理へ
	var.g_GameState = 5;

	//ポーズフラグ
	player.g_PauseFlg = 0;
}

//ゲームメイン
void GameMain(void) {
	DrawGraph(0, 0, var.GameImage, FALSE);
	for (int i = 0; i < APPLE_MAX; i++) {
		apple[i].AppleControl();
	}

	if (player.g_PauseFlg == 0) {
		if (--var.g_Time < nextTime) {
			for (int i = 0; i < APPLE_MAX; i++) {
				if (apple[i].CreateApple()) {
					nextTime -= GetRand(MAX_INTERVAL);
					break;
				}
			}
		}
	}
	player.PlayerControl();
	//UI描画
	ui.DrawUI();
}