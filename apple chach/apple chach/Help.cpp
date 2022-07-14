#include"DxLib.h"
#include"Help.h"
#include"hensuu.h"
#include"Font.h"

void HELP::DrawHelp() {
	//�X�y�[�X�L�[�Ń��j���[�ɖ߂�
	if (hen.g_KeyFlg & PAD_INPUT_2) hen.g_GameState = 0;
	//z�Q�[���J�n
	if (hen.g_KeyFlg & PAD_INPUT_A) hen.g_GameState = 1;

	//�^�C�g���摜�\��
	DrawGraph(0, 0, hen.HelpImage, FALSE);
	//SetFontSize(16);

	DrawString(20, 160, "����͗����Ă��郊���S���E���Q�[���ł��B", 0x000000, 0);
	DrawString(20, 180, "���E�ɓ����ė����Ă���l�X�ȃ����S���E���܂��B", 0x000000, 0);
	DrawString(20, 200, "���㉺�ړ��͂ł��܂���", 0x000000, 0);
	DrawString(20, 220, "�������Ԃ�30�b�ł��B", 0x000000, 0);
	DrawString(20, 250, "�����S�ꗗ", 0x000000, 0);
	DrawGraph(20, 260, hen.AppleImages[0], TRUE);
	DrawString(62, 275, "+150P", 0x0000ff, 0);
	DrawGraph(120, 260, hen.AppleImages[1], TRUE);
	DrawString(162, 275, "+300P", 0x0000ff, 0);
	DrawGraph(220, 260, hen.AppleImages[2], TRUE);
	DrawString(262, 275, "+500P", 0x0000ff, 0);
	DrawString(20, 315, "�ԁA���A�ΐF�̃����S���Ƃ�ƃX�R�A���������B", 0x000000, 0);
	DrawGraph(20, 335, hen.AppleImages[3], TRUE);
	DrawString(60, 350, "-1000P", 0xff0000, 0);
	DrawString(20, 385, "�Ń����S�ɐG���Ƃ������������B", 0x000000, 0);
	DrawString(20, 425, "�v���C����START�{�^���������ƃ|�[�Y�Ɉڍs���܂��B", 0x000000, 0);
	DrawString(20, 445, "(������x�����ƃv���C��ʂɖ߂�܂�)", 0x000000, 0);
	DrawString(490, 450, "�Q�[����[A�{�^��]", 0x000000, 0);
	DrawString(524, 430, "�߂�[B�{�^��]", 0x000000, 0);

	DrawStringToHandle(20, 120, "�w���v���", 0xffffff, font.font00);
}