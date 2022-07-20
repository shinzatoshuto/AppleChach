#include "GameOver.h"
#include "DxLib.h"
#include "variable.h"
#include "ranking.h" 
#include "pad.h"
#include "Load.h"

void GameOver::DrawGameOver(void) {
	//Bボタンでメニューに戻る
	if (pad.g_KeyFlg & PAD_INPUT_2) {
		PlaySoundMem(load.CancelSE, DX_PLAYTYPE_BACK);
		if (ranking.g_Ranking[RANKING_DATA - 1].score >= var.Score) {
			var.g_GameState = 0;
		}
		else {
			var.g_GameState = 7;
		}
	}
	DrawGraph(0, 0, GameOverImage, TRUE);
	DrawBox(150, 150, 490, 330, 0x00ffff, TRUE);
	DrawBox(150, 150, 490, 330, 0x000000, FALSE);

	SetFontSize(20);
	DrawString(255, 170, "ゲームオーバー", 0xcc0000);
	SetFontSize(18);

	DrawRotaGraph(215, 220, 0.5f, 0, var.AppleImages[0], TRUE, FALSE);
	DrawRotaGraph(215, 240, 0.5f, 0, var.AppleImages[1], TRUE, FALSE);
	DrawRotaGraph(215, 260, 0.5f, 0, var.AppleImages[2], TRUE, FALSE);
	DrawRotaGraph(215, 280, 0.5f, 0, var.AppleImages[3], TRUE, FALSE);

	DrawFormatString(210, 212, 0x000000, "%6d x   150 = %6d", g_AppleCount[0], g_AppleCount[0] * 150);
	DrawFormatString(210, 233, 0x000000, "%6d x   300 = %6d", g_AppleCount[1], g_AppleCount[1] * 300);
	DrawFormatString(210, 254, 0x000000, "%6d x   500 = %6d", g_AppleCount[2], g_AppleCount[2] * 500);
	DrawFormatString(210, 275, 0xFF00FF, "%6d x -1000 = %6d", g_AppleCount[3], g_AppleCount[3] * -1000);

	DrawString(290, 310, "スコア", 0x000000);
	DrawFormatString(210, 310, 0x000000, "               = %6d", var.Score);
	SetFontSize(25);
	DrawString(160, 450, "---- Bボタンで戻る ----", 0xffffff, 0);
}