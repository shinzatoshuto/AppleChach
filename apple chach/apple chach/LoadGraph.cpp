#include"DxLib.h"
#include"apple.h"

APPLE apple;

//画像読み込み
int LoadImages() {
	//タイトル
	if ((g_TitleImage = LoadGraph("images/Title.bmp")) == -1)return-1;
	//メニュー
	if ((g_Menu = LoadGraph("images/menu.bmp")) == -1)return-1;
	if ((g_Cone = LoadGraph("images/cone.bmp")) == -1)return-1;
	//ランキング画像データの読み込み
	if ((g_RankingImage = LoadGraph("images/Ranking.bmp")) == -1)return-1;

	//エンディング
	if ((g_EndImage = LoadGraph("images/End.bmp")) == -1)return-1;

	//リンゴ
	if ((apple.A = LoadGraph("images/apple/fruit_ringo.png")) == -1)return -1;

	//プレイヤー

	return 0;
}