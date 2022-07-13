#include"DxLib.h"
#include"hensuu.h"
#include"Font.h"
#include"End.h"

void END::DrawEnd() {
	//エンド画像表示
	DrawGraph(0, 0, hen.EndImage, FALSE);
	
	DrawStringToHandle(65, 30, "Thank you for Playing !!", 0xffff00, font.fonten);

	if (++g_WaitTime < 90) PosY = 90 - g_WaitTime / 2;
	DrawStringToHandle(80, 70 + PosY, "タイトル　　AppleChach", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 110 + PosY, "制作者　国際電子ビジネス専門学校", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 150 + PosY, "　　　　　金城　大洋", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 190 + PosY, "　　　　　志出盛　賢斗", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 230 + PosY, "　　　　　城間　愛夢", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 270 + PosY, "　　　　　新里　柊斗", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 310 + PosY, "素材利用", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 350 + PosY, "BGM　　　　魔王魂", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 390 + PosY, "SE　　　　   魔王魂", 0xffffff, font.fontensc);

	//タイムの加算処理&終了
	if (++g_WaitTime > 160) hen.g_GameState = 99;
}
