#include"DxLib.h"
#include"hensuu.h"
#include"Font.h"
#include"End.h"

void END::DrawEnd() {
	//�G���h�摜�\��
	DrawGraph(0, 0, hen.EndImage, FALSE);
	
	DrawStringToHandle(65, 30, "Thank you for Playing !!", 0xffff00, font.fonten);

	if (++g_WaitTime < 90) PosY = 90 - g_WaitTime / 2;
	DrawStringToHandle(80, 70 + PosY, "�^�C�g���@�@AppleChach", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 110 + PosY, "����ҁ@���ۓd�q�r�W�l�X���w�Z", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 150 + PosY, "�@�@�@�@�@����@��m", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 190 + PosY, "�@�@�@�@�@�u�o���@���l", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 230 + PosY, "�@�@�@�@�@��ԁ@����", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 270 + PosY, "�@�@�@�@�@�V���@�A�l", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 310 + PosY, "�f�ޗ��p", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 350 + PosY, "BGM�@�@�@�@������", 0xffffff, font.fontensc);
	DrawStringToHandle(80, 390 + PosY, "SE�@�@�@�@   ������", 0xffffff, font.fontensc);

	//�^�C���̉��Z����&�I��
	if (++g_WaitTime > 160) hen.g_GameState = 99;
}
