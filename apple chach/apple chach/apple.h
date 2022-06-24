#pragma once
const int APPLE_MAX = 7;

class APPLE {
public:
	int x,y,w,h;
	int type;
	int flg;
	int img;
	int point;
	int speed;
public:
	void CreateApple();
	void AppleControl();
	int HitBoxPlayer();
};