#include "DxLib.h"
#include "apple.h"
#include "hensuu.h"

int LoadSound() {
	if ((hen.FallSE = LoadSoundMem("sounds/SE2.wav")) == -1)return-1;
	if ((hen.ChachSE = LoadSoundMem("sounds/SE3.wav")) == -1)return-1;
	if ((hen.PoisonSE = LoadSoundMem("sounds/SE4.wav")) == -1)return-1;
	ChangeVolumeSoundMem(255, hen.FallSE);

	return 0;
}