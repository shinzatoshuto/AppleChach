#include "DxLib.h"
#include "Chara.h"
#include"hensuu.h"

void Chara::PlayerControl(void) {
	if (g_player.flg == true)
	{
		if (hen.g_NowKey & PAD_INPUT_LEFT)g_player.x -= g_player.speed;
		if (hen.g_NowKey & PAD_INPUT_RIGHT)g_player.x += g_player.speed;
	}

}