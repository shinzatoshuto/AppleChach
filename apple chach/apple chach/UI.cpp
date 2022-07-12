#include"DxLib.h"
#include"hensuu.h"
#include"UI.h"

void UI::UIimages() {
	//UIの枠表示
	DrawBox(SCREEN_WIDTH - 130, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x00ffff, TRUE);

	//制限時間の表示
	SetFontSize(25);
	DrawFormatString(520, 20, 0x000000, "制限時間");
	DrawFormatString(560, 60, 0x000000, "%d", hen.g_Time / 60);

	//りんごを取った数を表示
	SetFontSize(16);
	for (int i = 0; i < 4; i++) {
		DrawRotaGraph(528 + i * 30, 120, 0.5f, 0, hen.AppleImages[i], TRUE, FALSE);
		DrawFormatString(520 + i * 30, 140, 0x000000, "%02d", g_AppleCount[i]);
	}

	SetFontSize(30);
	DrawFormatString(530, 180, 0x000000, "スコア");
	SetFontSize(20);
	DrawFormatString(543, 220, 0x000000, "%06d", hen.Score);
}