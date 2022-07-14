#include "DxLib.h"
#include "apple.h"
#include "hensuu.h"
#include "Player.h"

int APPLE::HitBoxPlayer(PLAYER* p) {
	//x,y‚Í¶ã‚ÌÀ•W‚Æ‚·‚é
	int sx1 = p->x - p->w / 2;
	int sy1 = p->y - p->h / 2;
	int sx2 = p->x + p->w / 2;
	int sy2 = p->y + p->h / 2;

	int dx1 = this->x;
	int dy1 = this->y;
	int dx2 = this->x + this->w;
	int dy2 = this->y + this->h;

	//’ZŒ`‚ªd‚È‚Á‚Ä‚¢‚ê‚Î“–‚½‚è
	if (sx1 < dx2 - 5 && dx1 < sx2 - 5 && sy1 < dy2 - 5 && dy1 < sy2 - 5 && player.flg == TRUE) {
		return TRUE;
	}
	return FALSE;
}