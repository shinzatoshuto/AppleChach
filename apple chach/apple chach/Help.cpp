#include"DxLib.h"
#include"Help.h"
#include"hensuu.h"
#include"Font.h"

void HELP::DrawHelp() {
	//スペースキーでメニューに戻る
	if (hen.g_KeyFlg & PAD_INPUT_M) hen.g_GameState = 0;
	//zゲーム開始
	if (hen.g_KeyFlg & PAD_INPUT_A) hen.g_GameState = 1;

	//タイトル画像表示
	DrawGraph(0, 0, hen.HelpImage, FALSE);
	//SetFontSize(16);

	DrawString(20, 160, "これは落ちてくるリンゴを拾うゲームです。", 0x000000, 0);
	DrawString(20, 180, "左右に動いて落ちてくる様々なリンゴを拾います。", 0x000000, 0);
	DrawString(20, 200, "※上下移動はできません", 0x000000, 0);
	DrawString(20, 220, "制限時間は30秒です。", 0x000000, 0);
	DrawString(20, 250, "リンゴ一覧", 0x000000, 0);
	DrawGraph(20, 260, hen.AppleImages[0], TRUE);
	DrawString(62, 275, "+150P", 0x0000ff, 0);
	DrawGraph(120, 260, hen.AppleImages[1], TRUE);
	DrawString(162, 275, "+300P", 0x0000ff, 0);
	DrawGraph(220, 260, hen.AppleImages[2], TRUE);
	DrawString(262, 275, "+500P", 0x0000ff, 0);
	DrawString(20, 315, "赤、黄、緑色のリンゴをとるとスコアが増えるよ。", 0x000000, 0);
	DrawGraph(20, 335, hen.AppleImages[3], TRUE);
	DrawString(60, 350, "-1000P", 0xff0000, 0);
	DrawString(20, 385, "毒リンゴに触れるとすこあが減るよ。", 0x000000, 0);
	DrawString(20, 425, "プレイ中にSTARTボタンを押すとポーズに移行します。", 0x000000, 0);
	DrawString(20, 445, "(もう一度押すとプレイ画面に戻ります)", 0x000000, 0);
	DrawString(490, 450, "ゲームへ[Aボタン]", 0x000000, 0);
	DrawString(524, 430, "戻る[Bボタン]", 0x000000, 0);

	DrawStringToHandle(20, 120, "ヘルプ画面", 0xffffff, font.font00);
}