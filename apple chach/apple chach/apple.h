#pragma once
#include"hensuu.h"
#include "Player.h"
const int APPLE_MAX = 7;

class APPLE {
private:
	const int applespeed[4] = { 2, 5, 10, 1 };
	int x, y, w, h;
	int type;
	int flg;
	int img;
	int point;
	int speed;
	int appleimgs[4];

	int GetType();
public:
	void InitApple();
	int CreateApple();
	void AppleControl();
	int HitBoxPlayer(PLAYER* p);
};

extern APPLE apple[APPLE_MAX];