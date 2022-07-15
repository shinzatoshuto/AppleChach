#include"DxLib.h"
#include"variable.h"
#include"Font.h"
#include"End.h"

void END::DrawEnd() {
	//エンド画像表示
	DrawGraph(0, 0, EndImage, FALSE);
	
	DrawStringToHandle(65, 30, "Thank you for Playing !!", 0xffff00, font.fontEnd);

	if (++g_WaitTime < 90) PosY = 90 - g_WaitTime / 2;
	DrawStringToHandle(80, 60 + PosY, "タイトル　　AppleChach", 0xffffff, font.fontEndContent);
	DrawStringToHandle(80, 100 + PosY, "制作者　国際電子ビジネス専門学校", 0xffffff, font.fontEndContent);
	DrawStringToHandle(80, 130 + PosY, "　　　　　金城　大洋", 0xffffff, font.fontEndContent);
	DrawStringToHandle(80, 160 + PosY, "　　　　　志出盛　賢斗", 0xffffff, font.fontEndContent);
	DrawStringToHandle(80, 190 + PosY, "　　　　　城間　愛夢", 0xffffff, font.fontEndContent);
	DrawStringToHandle(80, 220 + PosY, "　　　　　新里　柊斗", 0xffffff, font.fontEndContent);
	DrawStringToHandle(80, 250 + PosY, "素材利用", 0xffffff, font.fontEndContent);
	DrawStringToHandle(80, 280 + PosY, "BGM　　　　魔王魂", 0xffffff, font.fontEndContent);
	DrawStringToHandle(80, 310 + PosY, "SE　　　　   魔王魂", 0xffffff, font.fontEndContent);
	DrawStringToHandle(80, 340 + PosY, "画像　　　イラスト屋", 0xffffff, font.fontEndContent);

	//タイムの加算処理&終了
	if (++g_WaitTime > 160) var.g_GameState = 99;
}
