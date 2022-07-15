#include "DxLib.h"
#include "apple.h"
#include "variable.h"
#include "Title.h"
#include "Load.h"
#include "Load.h"

int Load::LoadSound() {
	if ((load.FallSE = LoadSoundMem("sounds/SE2.wav")) == -1)return-1;
	if ((load.CatchSE = LoadSoundMem("sounds/SE3.wav")) == -1)return-1;
	if ((load.PoisonSE = LoadSoundMem("sounds/SE4.wav")) == -1)return-1;
	ChangeVolumeSoundMem(255, load.FallSE);

	if ((load.MoveSE = LoadSoundMem("sounds/SE6.wav")) == -1)return-1;
	if ((load.ClickSE = LoadSoundMem("sounds/SE.wav")) == -1)return-1;
	if ((load.CancelSE = LoadSoundMem("sounds/SE5.wav")) == -1)return-1;


	if ((title.TitleBGM = LoadSoundMem("sounds/Title.mp3")) == -1)return-1;
	if ((var.GameBGM = LoadSoundMem("sounds/Game.mp3")) == -1) return -1;

	return 0;
}