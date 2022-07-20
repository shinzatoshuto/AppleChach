#pragma once

class TITLE {
public:
	int g_TitleImage;//タイトル画像
	int TitleBGM;//タイトルのBGM
	int applecursor;//タイトルのカーソル画像
	int Player2;
	int Player3;

private:
	int PlayerY = 0;
	int PlayerX = 0;
	int Time = 0;
	int Time2 = 0;

public:
	void DrawGameTitle(void);

private:
	void DrawPlayer();
};

extern TITLE title;