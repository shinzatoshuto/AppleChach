#include "DxLib.h"
#include "Player.h"
#include"variable.h"
#include "Font.h"
#include "pad.h"

void PLAYER::InitPlayer() {
	flg = TRUE;
	x = PLAYER_POS_X;
	y = PLAYER_POS_Y;
	w = PLAYER_WIDTH;
	h = PLAYER_HEIGHT;
	count = 0;
	speed = PLAYER_SPEED;
	DirFlg = 0;
}

void PLAYER::PlayerControl() {
	//ゲームオーバー処理へ
	if (var.g_Time <= 0) {
		StopSoundMem(var.GameBGM);
		var.g_GameState = 6;
	}

	//左右移動
	if (player.g_PauseFlg == 0) {
		if (pad.g_NowKey & PAD_INPUT_LEFT) {
			x -= speed;
			inertia = 5;
			DirFlg = 1;
		}
		else if (pad.g_NowKey & PAD_INPUT_RIGHT) {
			x += speed;
			inertia = 5;
			DirFlg = 2;
		}
		else {
			if (inertia != 0) {//x += inertia * -1 - 1;
				if (DirFlg == 1) x -= inertia--;
				else if (DirFlg == 2) x += inertia--;

			}
		}

	}
	//画面をはみ出さないようにする
	if (x < 16)  x = 16;
	if (x > SCREEN_WIDTH - 146)  x = SCREEN_WIDTH - 146;

	//プレイヤーの表示
	if (flg == TRUE || (player.g_PauseFlg == FALSE && flg == FALSE && --count % 20 == 0)) {
		if (pad.g_NowKey & PAD_INPUT_LEFT) {
			//po-zu
			if (player.g_PauseFlg == FALSE) {
				DrawRotaGraph(x, y, 1, 0, var.PlayerImages[0], TRUE);
			}
			else {
				DrawRotaGraph(x, y, 1, 0, var.PlayerImages[2], TRUE);
			}
		}
		else if (pad.g_NowKey & PAD_INPUT_RIGHT) {
			//po-zu
			if (player.g_PauseFlg == FALSE) {
				DrawRotaGraph(x, y, 1, 0, var.PlayerImages[1], TRUE);
			}
			else {
				DrawRotaGraph(x, y, 1, 0, var.PlayerImages[2], TRUE);
			}
		}
		else {
			DrawRotaGraph(x, y, 1, 0, var.PlayerImages[2], TRUE);
		}
	}
	if (player.g_PauseFlg == TRUE) {
		DrawRotaGraph(x, y, 1, 0, var.PlayerImages[2], TRUE);
	}
	if (count <= 0) flg = TRUE;

	//ポーズフラグ
	if (pad.g_NowKey & PAD_INPUT_B && player.g_PauseFlg == FALSE) {
		player.g_PauseFlg = TRUE;
		StopSoundMem(var.GameBGM);
	}
	if (pad.g_NowKey & PAD_INPUT_X && player.g_PauseFlg == TRUE) {
		player.g_PauseFlg = FALSE;
		PlaySoundMem(var.GameBGM, DX_PLAYTYPE_BACK, FALSE);

	}
	if (player.g_PauseFlg == TRUE) {
		DrawStringToHandle(120, 180, "ぽーずちゅう", 0x000000, font.fontPause);
	}
}