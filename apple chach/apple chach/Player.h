#pragma once
#include "variable.h"

class PLAYER {
private:
	const int PLAYER_POS_X = SCREEN_WIDTH / 2 - 50;
	const int PLAYER_POS_Y = SCREEN_HEIGHT - 80;
	const int PLAYER_WIDTH = 30;
	const int PLAYER_HEIGHT = 100;
	const int PLAYER_SPEED = 5;

public:
	int x, y;
	int w, h;
	int flg;
	int count;
	int g_PauseFlg;  //ポーズフラグ

private:
	int speed;
	int inertia;
	int DirFlg;

public:
	void InitPlayer();
	void PlayerControl();
};

extern PLAYER player;