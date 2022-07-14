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
#include "UI.h"

APPLE apple[APPLE_MAX];
HENSUU hen;
PAD pad;
FONT font;
END end;
PLAYER player;
RANKING ranking;
HELP help;
UI ui;

//関数のプロトタイプ宣言
void GameInit(void);
void GameMain(void);

void DrawGameTitle(void);
void DrawGameOver(void);

int LoadImages();

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
	if (LoadImages() == -1)return-1;
	if (ranking.ReadRanking() == -1)return-1;
	if (font.LoadFont() == -1)return-1;
	if (LoadSound() == -1)return-1;

	ChangeVolumeSoundMem(100, hen.GameBGM);
	ChangeVolumeSoundMem(150, hen.TitleBGM);


	//ゲームループ
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

//ゲームタイトル表示
void DrawGameTitle(void) {
	static int MenuNo = 0;
	if (CheckSoundMem(hen.TitleBGM) == 0)
	PlaySoundMem(hen.TitleBGM, DX_PLAYTYPE_BACK);
	//メニューカーソル移動処理
	if (hen.g_KeyFlg & PAD_INPUT_DOWN) {
		if (++MenuNo > 3)MenuNo = 0;
		PlaySoundMem(hen.MoveSE, DX_PLAYTYPE_BACK);
	}
	if (hen.g_KeyFlg & PAD_INPUT_UP) {
		if (--MenuNo < 0)MenuNo = 3;
		PlaySoundMem(hen.MoveSE, DX_PLAYTYPE_BACK);
	}

	//Zキーでメニュー選択
	if (hen.g_KeyFlg & PAD_INPUT_A) {
		hen.g_GameState = MenuNo + 1;
		PlaySoundMem(hen.ClickSE, DX_PLAYTYPE_BACK);
	}

	//タイトル画像表示
	DrawGraph(0, 0, hen.g_TitleImage, FALSE);

	//メニューカーソル
	DrawRotaGraph(430, 300 + MenuNo * 42, 0.7f, 0, hen.applecursor, TRUE);
}

//ゲーム初期処理
void GameInit(void) {
	//スコアの初期化
	hen.Score = 0;

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

	hen.g_Time = 1800;


	pad.inputnum = 0;
	strcpy_s(pad.inputchar, 10, "         ");

	nextTime = hen.g_Time - GetRand(MAX_INTERVAL);

	StopSoundMem(hen.TitleBGM);
	PlaySoundMem(hen.GameBGM, DX_PLAYTYPE_BACK);
	//ゲームメイン処理へ
	hen.g_GameState = 5;

	//ポーズフラグ
	hen.g_PauseFlg = 0;
}

//ゲームメイン
void GameMain(void) {
	DrawGraph(0, 0, hen.GameImage, FALSE);
	player.PlayerControl();
	for (int i = 0; i < APPLE_MAX; i++) {
		apple[i].AppleControl();
	}

	//UI描画
	ui.DrawUI();

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

//ゲームオーバー画像描画処理
void DrawGameOver(void) {
	//Bボタンでメニューに戻る
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
	DrawString(220, 170, "ゲームオーバー", 0xcc0000);
	SetFontSize(18);

	DrawRotaGraph(215, 220, 0.5f, 0, hen.AppleImages[0], TRUE, FALSE);
	DrawRotaGraph(215, 240, 0.5f, 0, hen.AppleImages[1], TRUE, FALSE);
	DrawRotaGraph(215, 260, 0.5f, 0, hen.AppleImages[2], TRUE, FALSE);
	DrawRotaGraph(215, 280, 0.5f, 0, hen.AppleImages[3], TRUE, FALSE); 

	DrawFormatString(210, 212, 0xFFFFFF, "%6d x   150 = %6d", g_AppleCount[0], g_AppleCount[0] * 150);
	DrawFormatString(210, 233, 0xFFFFFF, "%6d x   300 = %6d", g_AppleCount[1], g_AppleCount[1] * 300);
	DrawFormatString(210, 254, 0xFFFFFF, "%6d x   500 = %6d", g_AppleCount[2], g_AppleCount[2] * 500);
	DrawFormatString(210, 275, 0xFFFFFF, "%6d x -1000 = %6d", g_AppleCount[3], g_AppleCount[3] * -1000);

	DrawString(310, 310, "スコア", 0x000000);
	DrawFormatString(260, 310, 0xFFFFFF, "             = %6d", hen.Score);
	SetFontSize(25);
	DrawString(150, 450, "---- Bボタンで戻る ----", 0xffffff, 0);
}