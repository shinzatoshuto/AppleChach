
#include"DxLib.h"
#include"apple.h"
#include"Player.h"
#include"variable.h"
#include"pad.h"
#include"Title.h"
#include"Help.h"
#include "Load.h"
#include"End.h"
#include"Ranking.h"

//画像読み込み
int Load::LoadImages() {
	//タイトル
	if ((title.g_TitleImage = LoadGraph("images/back/Title.png")) == -1)return-1;
	
	//メニュー
	if ((title.applecursor = LoadGraph("images/apple/fruit_ringo.png")) == -1)return-1;
	
	//ランキング画像データの読み込み
	if ((ranking.g_RankingImage = LoadGraph("images/back/Ranking1.png")) == -1)return-1;
	
	//ヘルプ
	if ((help.HelpImage = LoadGraph("images/back/Help.png")) == -1)return-1;

	//リンゴ
	if ((var.AppleImages[0] = LoadGraph("images/apple/fruit_ringo.png")) == -1)return -1;
	if ((var.AppleImages[1] = LoadGraph("images/apple/fruit_apple_yellow.png")) == -1)return -1;
	if ((var.AppleImages[2] = LoadGraph("images/apple/fruit_ao_ringo.png")) == -1)return -1;
	if ((var.AppleImages[3] = LoadGraph("images/apple/apple_doku_ringo.png")) == -1)return -1;

	//プレイヤー
	if ((var.PlayerImages[0] = LoadGraph("images/miniplayer/figure_hashiru2.png")) == -1)return -1;
	if ((var.PlayerImages[1] = LoadGraph("images/miniplayer/figure_hashiru.png")) == -1)return -1;
	if ((var.PlayerImages[2] = LoadGraph("images/miniplayer/figure_aura2_orange_black.png")) == -1)return -1;

	//背景画像
	if ((var.GameImage = LoadGraph("images/back/bg_natural_mori.png")) == -1)return-1;

	//エンド画像
	if ((end.EndImage = LoadGraph("images/back/bg_yamamichi.png")) == -1)return-1;
	
	return 0;
}