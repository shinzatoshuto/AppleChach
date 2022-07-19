#include"DxLib.h"
#include"Font.h"

int FONT::LoadFont() {
	if((fontHelp = CreateFontToHandle("Tsunagi Gothic Black", 20, 1, DX_FONTTYPE_NORMAL))==-1)return-1;
	if((fontEnd = CreateFontToHandle("Tsunagi Gothic Black", 50, 1, DX_FONTTYPE_NORMAL))==-1)return-1;
	if((fontEndContent = CreateFontToHandle("ü‡ÉSÉVÉbÉN Medium", 20, 3, DX_FONTTYPE_NORMAL))==-1)return-1;
	if((fontRankingInput = CreateFontToHandle("Tsunagi Gothic Black", 30, 1, DX_FONTTYPE_NORMAL))==-1)return-1;
	if((fontPause = CreateFontToHandle("wb_font", 50, 5, DX_FONTTYPE_NORMAL))==-1)return-1;
	if((fontRanking = CreateFontToHandle("Courier New", 30, 50, DX_FONTTYPE_NORMAL))==1)return-1;

	return 0;
}
