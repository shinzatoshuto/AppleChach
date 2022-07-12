#include"DxLib.h"
#include"hensuu.h"
#include"Font.h"
#include"End.h"

void END::DrawEnd() {
	//エンド画像表示
	//DrawGraph(0, 0, hen.EndImg, FALSE);

	DrawStringToHandle(65, 30, "Thank you for Playing !!", 0xffff00, font.fonten);

	if (++hen.g_WaitTime < 90)hen.PosY = 90 - hen.g_WaitTime / 2;
	DrawStringToHandle(80, 70 + hen.PosY, "タイトル　　AppleChach", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 110 + hen.PosY, "制作者　国際電子ビジネス専門学校", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 150 + hen.PosY, "　　　　　金城　大洋", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 190 + hen.PosY, "　　　　　志出盛　賢斗", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 230 + hen.PosY, "　　　　　城間　愛夢", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 270 + hen.PosY, "　　　　　新里　柊斗", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 310 + hen.PosY, "素材利用", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 350 + hen.PosY, "BGM　　　　魔王魂", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 390 + hen.PosY, "SE　　　　   魔王魂", 0xffffff, font.fontensc);

	//タイムの加算処理&終了
	if (++hen.g_WaitTime > 160) hen.g_GameState = 99;
}
