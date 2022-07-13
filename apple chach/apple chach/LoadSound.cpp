#include "DxLib.h"
#include "apple.h"
#include "hensuu.h"

int LoadSound() {
	if ((hen.FallSE = LoadSoundMem("sounds/SE2.wav")) == -1)return-1;
	if ((hen.CatchSE = LoadSoundMem("sounds/SE3.wav")) == -1)return-1;
	if ((hen.PoisonSE = LoadSoundMem("sounds/SE4.wav")) == -1)return-1;
	if ((hen.GetAppleSE = LoadSoundMem("sounds/SE3.wav")) == -1)return-1;
	ChangeVolumeSoundMem(255, hen.FallSE);

	if ((hen.MoveSE = LoadSoundMem("sounds/SE6.wav")) == -1)return-1;
	if ((hen.ClickSE = LoadSoundMem("sounds/SE.wav")) == -1)return-1;
	if ((hen.CancelSE = LoadSoundMem("sounds/SE5.wav")) == -1)return-1;


	if ((hen.TitleBGM = LoadSoundMem("sounds/Title.mp3")) == -1)return-1;
	if ((hen.GameBGM = LoadSoundMem("sounds/Game.mp3")) == -1) return -1;

	return 0;
}