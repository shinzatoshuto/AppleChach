#include"DxLib.h"
#include"Help.h"
#include"variable.h"
#include"Font.h"
#include"pad.h"
#include"Load.h"

void HELP::DrawHelp() {
	//Bボタンでメニューに戻る
	if (pad.g_KeyFlg & PAD_INPUT_2) {
		var.g_GameState = 0;
		PlaySoundMem(load.CancelSE, DX_PLAYTYPE_BACK);
	}
	//ゲーム開始
	if (pad.g_KeyFlg & PAD_INPUT_A) {
		var.g_GameState = 1;
		PlaySoundMem(load.ClickSE, DX_PLAYTYPE_BACK);
	}

	//ヘルプ画像表示
	DrawGraph(0, 0, HelpImage, FALSE);
	DrawRotaGraph(480, 250, 0.7f, 0, GamepadImage, TRUE);

	DrawBox(10, 130, 310, 355, 0xffffff, 1);
    DrawStringToHandle(20, 140, "左右に動いて落ちてくる\n様々なリンゴを拾うゲームです。", 0x000000, font.fontHelp);
	DrawStringToHandle(20, 180, "※上下移動はできません", 0x000000, font.fontHelp);
	DrawStringToHandle(20, 200, "制限時間は30秒です。", 0x000000, font.fontHelp);
	DrawStringToHandle(20, 220, "左スティック：移動", 0xff00ff, font.fontHelp);
	DrawStringToHandle(20, 240, "Aボタン：決定  Bボタン：戻る", 0xff00ff, font.fontHelp);
	DrawStringToHandle(20, 260, "プレイ中にSTARTボタンを押すと\nポーズに移行します。", 0xff00ff, font.fontHelp);
	DrawStringToHandle(20, 300, "(もう一度押すと\nプレイ画面に戻ります)", 0xff00ff, font.fontHelp);

	SetFontSize(20);
	DrawBox(10, 355, 310, 475, 0xffffff, 1);
	DrawStringToHandle(20, 360, "リンゴ一覧", 0x000000, font.fontHelp);
	DrawGraph(20, 380, var.AppleImages[0], TRUE);
	DrawString(62, 395, "+150P", 0x000000, 0);
	DrawGraph(120, 380, var.AppleImages[1], TRUE);
	DrawString(162, 395, "+300P", 0x000000, 0);
	DrawGraph(20, 430, var.AppleImages[2], TRUE);
	DrawString(62, 445, "+500P", 0x000000, 0);
	DrawGraph(120, 430, var.AppleImages[3], TRUE);
	DrawString(160, 445, "-1000P", 0xff0000, 0);

	SetFontSize(23);
	DrawString(470, 420, "戻る[Bボタン]", 0xff0000,1);
	DrawString(420, 450, "ゲームへ[Aボタン]", 0x0000ff,1);

	//DrawStringToHandle(20, 120, "ヘルプ画面", 0xffffff, font.fontHelp);
}