#pragma once

class Chara {
public:
	int x, y, w, h;
	int type;
	int flg;
	int img;
	int point;
	int speed;
	int A, B, C, D;
	int charaimgs[4];

public:
	void PlayerControl();
};