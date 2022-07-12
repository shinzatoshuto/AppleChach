#include"DxLib.h"
#include"Font.h"

int FONT::Fontset() {
	if((font00 = CreateFontToHandle("Tsunagi Gothic Black", 20, 1, DX_FONTTYPE_NORMAL))==-1)return-1;
	if((fonten = CreateFontToHandle("Tsunagi Gothic Black", 50, 1, DX_FONTTYPE_NORMAL))==-1)return-1;
	if((fontensc = CreateFontToHandle("游ゴシック Medium", 20, 3, DX_FONTTYPE_NORMAL))==-1)return-1;
    if((fontran = CreateFontToHandle("Tsunagi Gothic Black", 40, 1, DX_FONTTYPE_NORMAL))==-1)return-1;
	 if((fontrans = CreateFontToHandle("Tsunagi Gothic Black", 30, 1, DX_FONTTYPE_NORMAL))==-1)return-1;
	 if((fontpose = CreateFontToHandle("wb_font", 50, 5, DX_FONTTYPE_NORMAL))==-1)return-1;
	if((fontking = CreateFontToHandle("MS ゴシック", 30, 5, DX_FONTTYPE_NORMAL))==1)return-1;
}
//if ((hen.g_TitleImage = LoadGraph("images/back/Title.jpg")) == -1)return-1;