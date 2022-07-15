#pragma once

class PAD {
private:
	int cursorX = 0;
	int cursorY = 0;
	const int OffSetX = 120;
	const int OffSetY = 250;

public:
	char inputchar[10];
	int inputnum = 0;
	int g_OldKey;    // 前回の入力キー
	int g_NowKey;    // 今回の入力キー
	int g_KeyFlg;    // 入力キー情報

public:
	void DrawInput(void);
};

extern PAD pad;