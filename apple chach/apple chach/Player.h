#pragma once
#include "variable.h"

class PLAYER {
public:
	const int PLAYER_POS_X = SCREEN_WIDTH / 2 - 50;
	const int PLAYER_POS_Y = SCREEN_HEIGHT - 80;
	const int PLAYER_WIDTH = 30;
	const int PLAYER_HEIGHT = 100;
	const int PLAYER_SPEED = 5;

	int flg;
	int x, y;
	int w, h;
	int count;
	int speed;

	int inertia;
	int DirFlg;

public:
	void InitPlayer();
	void PlayerControl();
	void PlayerInertia();
};

extern PLAYER player;