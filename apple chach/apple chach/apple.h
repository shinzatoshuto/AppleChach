#pragma once
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

public:
	int CreateApple();
	void AppleControl();
	int HitBoxPlayer();
};

extern APPLE apple[APPLE_MAX];