#include "DxLib.h"
#include "apple.h"
#include "hensuu.h"

int APPLE::HitBoxPlayer(PLAYER* p) {
	//x,yは中心座標とする
	int sx1 = p->x - p->w;
	int sy1 = p->y - p->h;
	int sx2 = p->x + p->w;
	int sy2 = p->y + p->h;

	int dx1 = this->x - (this->w / 2);
	int dy1 = this->y - (this->h / 2);
	int dx2 = dx1 + this->w;
	int dy2 = dy1 + this->h;

	//短形が重なっていれば当たり
	if (sx1 < dx2 - 5 && dx1 < sx2 - 5 && sy1 < dy2 - 5 && dy1 < sy2 - 5) {
		return TRUE;
	}
	return FALSE;
}