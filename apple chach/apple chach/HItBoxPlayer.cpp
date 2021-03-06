#include "DxLib.h"
#include "apple.h"
#include "variable.h"
#include "Player.h"

int APPLE::HitBoxPlayer(PLAYER* p) {
	//x,yは中心座標とする
	int sx1 = p->x - p->w / 2;
	int sy1 = p->y - p->h / 2;
	int sx2 = p->x + p->w / 2;
	int sy2 = p->y + p->h / 2;

	int dx1 = this->x;// -(this->w / 2);
	int dy1 = this->y;// -(this->h / 2);
	int dx2 = this->x + this->w;
	int dy2 = this->y + this->h;

	//短形が重なっていれば当たり
	if (sx1 < dx2 - 5 && dx1 < sx2 - 5 && sy1 < dy2 - 5 && dy1 < sy2 - 5 && player.flg == TRUE) {
		return TRUE;
	}
	return FALSE;
}