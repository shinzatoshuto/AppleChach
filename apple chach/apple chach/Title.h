#pragma once

class TITLE {
public:
	int g_TitleImage;//タイトル画像
	int TitleBGM;//タイトルのBGM
	int applecursor;//タイトルのカーソル画像

public:
	void DrawGameTitle(void);
};

extern TITLE title;