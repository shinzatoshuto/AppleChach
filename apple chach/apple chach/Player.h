#pragma once

class Chara {
public:
	int flg;				// 使用フラグ
	int x, y;				// 座標x, y
	int w, h;				// 幅 w 高さ h
	double angle;			// 機体の向き 
	int count;				/// タイミング用
	int point;
	int speed;
	int A, B, C, D;
	int charaimgs[4];

public:
	void PlayerControl();
};
extern Chara g_player;