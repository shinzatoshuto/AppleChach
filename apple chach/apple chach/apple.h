#pragma once
#include"hensuu.h"
const int APPLE_MAX = 7;

class APPLE {
public:
	int x, y, w, h;
	int type;
	int flg;
	int img;
	int point;
	int speed;
	int A, B, C, D;
	int appleimgs[4];
	int applespeed[4] = { 1,5,7,10 };//‚µ‘‚«

public:
	int CreateApple();
	void AppleControl();
	int HitBoxPlayer(PLAYER* p);
};

extern APPLE apple[APPLE_MAX];