
#include"DxLib.h"
#include"apple.h"
#include"Player.h"
#include"variable.h"
#include"pad.h"

//�摜�ǂݍ���
int LoadImages() {
	//�w�i�摜

	//�^�C�g��
	if ((hen.g_TitleImage = LoadGraph("images/back/Title.jpg")) == -1) return -1;
	//���C��
	if ((hen.GameImage = LoadGraph("images/back/bg_natural_mori.jpg")) == -1) return-1;
	//�w���v
	if ((hen.HelpImage = LoadGraph("images/back/Help.jpg")) == -1) return -1;
	//�G���h�摜
	if ((hen.EndImage = LoadGraph("images/back/bg_yamamichi.jpg")) == -1) return-1;

	//���j���[�J�[�\���̃A�C�R��
	if ((hen.applecursor = LoadGraph("images/apple/fruit_ringo.png")) == -1) return -1;
	//�����L���O�摜�f�[�^�̓ǂݍ���
	if ((hen.g_RankingImage = LoadGraph("images/back/Ranking1.png")) == -1) return -1;

	//�����S
	if ((hen.AppleImages[0] = LoadGraph("images/apple/fruit_ringo.png")) == -1) return -1;
	if ((hen.AppleImages[1] = LoadGraph("images/apple/fruit_apple_yellow.png")) == -1) return -1;
	if ((hen.AppleImages[2] = LoadGraph("images/apple/fruit_ao_ringo.png")) == -1) return -1;
	if ((hen.AppleImages[3] = LoadGraph("images/apple/apple_doku_ringo.png")) == -1) return -1;
	
	//�v���C���[
	if ((hen.PlayerImages[0] = LoadGraph("images/miniplayer/figure_hashiru2.png")) == -1) return -1;
	if ((hen.PlayerImages[1] = LoadGraph("images/miniplayer/figure_hashiru.png")) == -1) return -1;
	if ((hen.PlayerImages[2] = LoadGraph("images/miniplayer/figure_aura2_orange_black.png")) == -1) return -1;
	
	return 0;
}