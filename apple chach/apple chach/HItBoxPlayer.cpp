#include "DxLib.h"
#include "apple.h"
#include "hensuu.h"
#include "Player.h"

int APPLE::HitBoxPlayer(PLAYER* p) {
	//x,y�͒��S���W�Ƃ���
	int sx1 = p->x - p->w / 2;
	int sy1 = p->y - p->h / 2;
	int sx2 = p->x + p->w / 2;
	int sy2 = p->y + p->h / 2;
	//DrawBox(sx1 + 10, sy1, sx2 + 10, sy2, 0xff0000, TRUE);

	int dx1 = this->x;// -(this->w / 2);
	int dy1 = this->y;// -(this->h / 2);
	int dx2 = this->x + this->w;
	int dy2 = this->y + this->h;

	//�Z�`���d�Ȃ��Ă���Γ�����
	if (sx1 < dx2 - 5 && dx1 < sx2 - 5 && sy1 < dy2 - 5 && dy1 < sy2 - 5 && player.flg == TRUE) {
		return TRUE;
	}
	return FALSE;
}