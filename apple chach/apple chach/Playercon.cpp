#include "DxLib.h"
#include "Player.h"
#include"hensuu.h"


void Player::PlayerControl(void) {
	if (player.flg == true)
	{
		if (hen.g_NowKey & PAD_INPUT_LEFT)g_player.x -= g_player.speed;
		if (hen.g_NowKey & PAD_INPUT_RIGHT)g_player.x += g_player.speed;
	}

}