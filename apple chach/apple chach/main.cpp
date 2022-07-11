#include<DxLib.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include"apple.h"
#include"hensuu.h"
#include"pad.h"

#define  RANKING_DATA  5

APPLE apple[APPLE_MAX];
HENSUU hen;
PAD pad;

//定数の宣言
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//const int ENEMY_MAX = 8;
//const int ITEM_MAX = 3;

//自機の初期値
const int PLAYER_POS_X = SCREEN_WIDTH / 2;
const int PLAYER_POS_Y = SCREEN_HEIGHT - 80;
const int PLAYER_WIDTH = 30;
const int PLAYER_HEIGHT = 100;
const int PLAYER_SPEED = 5;
//const int PLAYER_HP = 1000;
//const int PLAYER_FUEL = 20000;
//const int PLAYER_BARRIER = 3;
//const int PLAYER_BARRIERUP = 10;

//自機の構造体
//struct PLAYER {
//	int flg;
//	int x, y;
//	int w, h;
//	double angle;
//	int count;
//	int speed;
//	int hp;
//	int fuel;
//	int bari;
//	int baricnt;
//	int bariup;
//};

//自機
PLAYER g_player;

////敵機の構造体
//struct ENEMY {
//	int flg;
//	int type;
//	int img;
//	int x, y, w, h;
//	int speed;
//	int point;
//	int cnt;
//};
//
////敵機
//struct ENEMY g_enemy[ENEMY_MAX];
//struct ENEMY g_enemy00 = { TRUE,0,0,0,-50,63,120,0,1 };
//struct ENEMY g_enemyCn = { TRUE,4,0,0,-50,18,18,0,1 };
//
//struct ENEMY g_item[ITEM_MAX];
//struct ENEMY g_item00 = { TRUE,0,0,0,-50,50,50,0,1 };

//ランキングデータ（構造体）
struct RankingData {
	int no;
	char name[11];
	long score;
};

//ランキングデータ変数宣言
struct RankingData  g_Ranking[RANKING_DATA];

//関数のプロトタイプ宣言
void GameInit(void);
void GameMain(void);

void DrawGameTitle(void);
void DrawGameOver(void);
void DrawEnd(void);
void DrawHelp(void);

void DrawRanking(void);
void InputRanking(void);
void SortRanking(void);
int SaveRanking(void);
int ReadRanking(void);

int LoadImages();
void PlayerControl();

int nextTime;
int g_AppleCount[4];
int GameSound;

int font00;
int fonten;
int fontensc;
int fontran;
int fontrans;
int fontpose;

void DrawInput(void) {
	static int cursorX = 0;
	static int cursorY = 0;

	if (hen.g_KeyFlg & PAD_INPUT_RIGHT) {
		if (++cursorX > 12)cursorX = 0;
	}
	if (hen.g_KeyFlg & PAD_INPUT_LEFT) {
		if (--cursorX < 0)cursorX = 12;
	}
	if (hen.g_KeyFlg & PAD_INPUT_DOWN) {
		if (++cursorY > 4)cursorY = 0;
	}
	if (hen.g_KeyFlg & PAD_INPUT_UP) {
		if (--cursorY < 0)cursorY = 4;
	}

	int x = cursorX * 32;
	int y = cursorY * 32;
	DrawBox(x, y, x + 32, y + 32, 0x0000FF, 1);

	const char* ALPHAchar = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 26; i++) {
		SetFontSize(32);
		DrawFormatString(0 + i % 13 * 32, i / 13 * 32, 0xffff00, "%c", ALPHAchar[i]);
	}
	const char* alphachar = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 26; i++) {
		SetFontSize(32);
		DrawFormatString(0 + i % 13 * 32, i / 13 * 32 + 64, 0xffff00, "%c", alphachar[i]);
	}
	const char* numchar = "0123456789";
	for (int i = 0; i < 10; i++) {
		SetFontSize(32);
		DrawFormatString(0 + i * 32, 128, 0xffff00, "%c", numchar[i]);
	}
}

//プログラム開始
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
	SetMainWindowText("Apple Catch");   //タイトルを設定
	ChangeWindowMode(TRUE);
	SetWindowSize(640, 480);
	if (DxLib_Init() == -1)return-1;
	SetDrawScreen(DX_SCREEN_BACK);
	if (LoadImages() == -1)return-1;
	if (ReadRanking() == -1)return-1;
	if (LoadSound() == -1)return-1;
	if ((GameSound = LoadSoundMem("sounds/Game.mp3")) == -1) return -1;
	ChangeVolumeSoundMem(100, GameSound);

	//フォント
	font00 = CreateFontToHandle("Tsunagi Gothic Black", 20, 1, DX_FONTTYPE_NORMAL);
	fonten = CreateFontToHandle("Tsunagi Gothic Black", 50, 1, DX_FONTTYPE_NORMAL);
	fontensc = CreateFontToHandle("游ゴシック Medium", 20, 3, DX_FONTTYPE_NORMAL);
	fontran = CreateFontToHandle("Tsunagi Gothic Black", 40, 1, DX_FONTTYPE_NORMAL);
	fontrans = CreateFontToHandle("Tsunagi Gothic Black", 30, 1, DX_FONTTYPE_NORMAL);
	fontpose = CreateFontToHandle("wb_font", 50, 5, DX_FONTTYPE_NORMAL);


	//ゲームループ
	while (ProcessMessage() == 0 && hen.g_GameState != 99 && !(hen.g_KeyFlg & PAD_INPUT_7))
	{
		hen.g_OldKey = hen.g_NowKey;
		hen.g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		hen.g_KeyFlg = hen.g_NowKey & ~hen.g_OldKey;

		ClearDrawScreen();
		if (false)
		switch (hen.g_GameState) {
		case 0:DrawGameTitle();
			break;
		case 1:GameInit();
			break;
		case 2:DrawRanking();
			break;
		case 3:DrawHelp();
			break;
		case 4:DrawEnd();
			break;
		case 5:GameMain();
			break;
		case 6:DrawGameOver();
			break;
		case 7:InputRanking();
			break;
		}
		DrawInput();

		ScreenFlip();
	}
	DxLib_End();

	return 0;
}

//ゲームタイトル表示
void DrawGameTitle(void) {
	static int MenuNo = 0;

	//メニューカーソル移動処理
	if (hen.g_KeyFlg & PAD_INPUT_DOWN) {
		if (++MenuNo > 3)MenuNo = 0;
	}
	if (hen.g_KeyFlg & PAD_INPUT_UP) {
		if (--MenuNo < 0)MenuNo = 3;
	}

	//Zキーでメニュー選択
	if (hen.g_KeyFlg & PAD_INPUT_A)hen.g_GameState = MenuNo + 1;

	//タイトル画像表示
	DrawGraph(0, 0, hen.g_TitleImage, FALSE);

	//メニュー
	//DrawGraph(120, 200, hen.g_Menu, TRUE);

	//メニューカーソル
	DrawRotaGraph(430, 300 + MenuNo * 42, 0.7f, 0, hen.applecursor, TRUE);

	for (int i = 0; i < 14; i++) {
		DrawRotaGraph(i * 45, 200, 0.5, 0, pad.ALAN[i], TRUE);
	}
}

//ゲーム初期処理
void GameInit(void) {
	//スコアの初期化
	hen.Score = 0;

	//プレイヤーの初期設定
	g_player.flg = TRUE;
	g_player.x = PLAYER_POS_X;
	g_player.y = PLAYER_POS_Y;
	g_player.w = PLAYER_WIDTH;
	g_player.h = PLAYER_HEIGHT;
	g_player.count = 0;
	g_player.speed = PLAYER_SPEED;

	//りんごの初期設定
	for (int i = 0; i < APPLE_MAX; i++) {
		apple[i].flg = FALSE;
	}
	//リンゴのカウントの初期化
	for (int i = 0; i < 4; i++) {
		g_AppleCount[i] = 0;
	}

	hen.g_Time = 1800;




	nextTime = hen.g_Time - GetRand(MAX_INTERVAL);

	PlaySoundMem(GameSound, DX_PLAYTYPE_BACK);
	//ゲームメイン処理へ
	hen.g_GameState = 5;

	//ポーズフラグ
	hen.g_PauseFlg = 0;
}

//ゲームランキング描画表示
void DrawRanking(void) {
	//スペースキーでメニューに戻る
	if (hen.g_KeyFlg & PAD_INPUT_2)  hen.g_GameState = 0;
	//ランキング画像表示
	DrawGraph(0, 0, hen.g_RankingImage, FALSE);
	//ランキング一覧を表示
	//SetFontSize(18);
	for (int i = 0; i < RANKING_DATA; i++) {
		DrawFormatStringToHandle(140, 170 + i * 35, 0xffffff, fontran,"%2d %10s %10d", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
	}
	SetFontSize(25);
	DrawString(150, 450, "---- Bボタンで戻る ----", 0xffffff, 0);
}

////ゲームヘルプ描画処理
void DrawHelp(void) {
	//スペースキーでメニューに戻る
	if (hen.g_KeyFlg & PAD_INPUT_M) hen.g_GameState = 0;
	//zゲーム開始
	if (hen.g_KeyFlg & PAD_INPUT_A) hen.g_GameState = 1;

	//タイトル画像表示
	DrawGraph(0, 0, hen.HelpImage, FALSE);
	//SetFontSize(16);

	DrawString(20, 160, "これは落ちてくるリンゴを拾うゲームです。", 0x000000, 0);
	DrawString(20, 180, "左右に動いて落ちてくる様々なリンゴを拾います。", 0x000000, 0);
	DrawString(20, 200, "※上下移動はできません", 0x000000, 0);
	DrawString(20, 220, "制限時間は30秒です。", 0x000000, 0);
	DrawString(20, 250, "リンゴ一覧", 0x000000, 0);
	DrawGraph(20, 260, hen.AppleImages[0], TRUE);
	DrawString(62, 275, "+150P", 0x0000ff, 0);
	DrawGraph(120, 260, hen.AppleImages[1], TRUE);
	DrawString(162, 275, "+300P", 0x0000ff, 0);
	DrawGraph(220, 260, hen.AppleImages[2], TRUE);
	DrawString(262, 275, "+500P", 0x0000ff, 0);
	DrawString(20, 315, "赤、黄、緑色のリンゴをとるとスコアが増えるよ。", 0x000000, 0);
	DrawGraph(20, 335, hen.AppleImages[3], TRUE);
	DrawString(60, 350, "-1000P", 0xff0000, 0);
	DrawString(20, 385, "毒リンゴに触れるとすこあが減るよ。", 0x000000, 0);
	DrawString(20, 425, "プレイ中にSTARTボタンを押すとポーズに移行します。", 0x000000, 0);
	DrawString(20, 445, "(もう一度押すとプレイ画面に戻ります)", 0x000000, 0);
	DrawString(490, 450, "ゲームへ[Aボタン]", 0x000000, 0);
	DrawString(524, 430, "戻る[Bボタン]", 0x000000, 0);

	DrawStringToHandle(20, 120, "ヘルプ画面", 0xffffff, font00);
}


//ゲームエンド描画処理
void DrawEnd(void) {
	

	//エンド画像表示
	DrawGraph(0, 0, hen.EndImg, FALSE);

	DrawStringToHandle(65, 30, "Thank you for Playing !!", 0xffff00, fonten);

	if (++hen.g_WaitTime < 90)hen.PosY = 90 - hen.g_WaitTime / 2;
	DrawStringToHandle(80, 70 + hen.PosY, "タイトル　　AppleChach", 0xffffff, fontensc);
	DrawStringToHandle(80, 110 + hen.PosY, "制作者　国際電子ビジネス専門学校", 0xffffff, fontensc);
	DrawStringToHandle(80, 150 + hen.PosY, "　　　　　金城　大洋", 0xffffff, fontensc);
	DrawStringToHandle(80, 190 + hen.PosY, "　　　　　志出盛　賢斗", 0xffffff, fontensc);
	DrawStringToHandle(80, 230 + hen.PosY, "　　　　　城間　愛夢", 0xffffff, fontensc);
	DrawStringToHandle(80, 270 + hen.PosY, "　　　　　新里　柊斗", 0xffffff, fontensc);
	DrawStringToHandle(80, 310 + hen.PosY, "素材利用", 0xffffff, fontensc);
	DrawStringToHandle(80, 350 + hen.PosY, "BGM　　　　魔王魂", 0xffffff, fontensc);
	DrawStringToHandle(80, 390 + hen.PosY, "SE　　　　   魔王魂", 0xffffff, fontensc);

	//タイムの加算処理&終了
	if (++hen.g_WaitTime > 160) hen.g_GameState = 99;
}

//ゲームメイン
void GameMain(void) {
	DrawGraph(0, 0, hen.Backimg, FALSE);
	PlayerControl();
	for (int i = 0; i < APPLE_MAX; i++) {
		apple[i].AppleControl();
	}
	if (hen.g_PauseFlg == 0) {
		if (--hen.g_Time < nextTime) {
			for (int i = 0; i < APPLE_MAX; i++) {
				if (apple[i].CreateApple()) {
					nextTime -= GetRand(MAX_INTERVAL);
					break;
				}
			}
		}
	}
}

void PlayerControl() {
	//ゲームオーバー処理へ
	if (hen.g_Time <= 0) {
		StopSoundMem(GameSound);
		hen.g_GameState = 6;
	}

	//上下左右移動
	if (hen.g_PauseFlg == 0) {
		if (g_player.flg == TRUE || true) {
			if (hen.g_NowKey & PAD_INPUT_LEFT) g_player.x -= g_player.speed;
			if (hen.g_NowKey & PAD_INPUT_RIGHT) g_player.x += g_player.speed;
		}
	}
	//画面をはみ出さないようにする
	if (g_player.x < 16)  g_player.x = 16;
	if (g_player.x > SCREEN_WIDTH - 146)  g_player.x = SCREEN_WIDTH - 146;
	//if (g_player.y < 60)  g_player.y = 60;
	//if (g_player.y > SCREEN_HEIGHT - 60)  g_player.y = SCREEN_HEIGHT - 60;

	
	//プレイヤーの表示
	//if (g_player.flg == TRUE) {
	if (g_player.flg == TRUE || (hen.g_PauseFlg == FALSE && g_player.flg == FALSE && --g_player.count % 20 == 0)) {
		if (hen.g_NowKey & PAD_INPUT_LEFT) {
			//po-zu
			if (hen.g_PauseFlg == FALSE) {
				//DrawGraph(g_player.x - 86, g_player.y - g_player.h / 2, hen.g_Player[0], TRUE);
				DrawRotaGraph(g_player.x, g_player.y, 1, 0, hen.g_Player[0], TRUE);
			}
			else {
				//DrawGraph(g_player.x - 86, g_player.y - 125, hen.g_Player[2], TRUE);
				DrawRotaGraph(g_player.x, g_player.y, 1, 0, hen.g_Player[2], TRUE);
			}
		}
		else if (hen.g_NowKey & PAD_INPUT_RIGHT) {
			//po-zu
			if (hen.g_PauseFlg == FALSE) {
				//DrawGraph(g_player.x - 86, g_player.y - g_player.h / 2, hen.g_Player[1], TRUE);
				DrawRotaGraph(g_player.x, g_player.y, 1, 0, hen.g_Player[1], TRUE);
			}
			else {
				//DrawGraph(g_player.x - 86, g_player.y - 125, hen.g_Player[2], TRUE);
				DrawRotaGraph(g_player.x, g_player.y, 1, 0, hen.g_Player[2], TRUE);
			}
		}
		else {
			//DrawGraph(g_player.x - 86, g_player.y - 125, hen.g_Player[2], TRUE);
			DrawRotaGraph(g_player.x, g_player.y, 1, 0, hen.g_Player[2], TRUE);
		}
	}
	if (hen.g_PauseFlg == TRUE) {
		//DrawGraph(g_player.x - 86, g_player.y - 125, hen.g_Player[2], TRUE);
		DrawRotaGraph(g_player.x, g_player.y, 1, 0, hen.g_Player[2], TRUE);
	}
		if (g_player.count <= 0) g_player.flg = TRUE;

	//ポーズフラグ
	if (hen.g_NowKey & PAD_INPUT_B && hen.g_PauseFlg == FALSE) {
		hen.g_PauseFlg = TRUE;
		StopSoundMem(GameSound);
	}
	if (hen.g_NowKey & PAD_INPUT_X && hen.g_PauseFlg == TRUE) {
		hen.g_PauseFlg = FALSE;
		PlaySoundMem(GameSound, DX_PLAYTYPE_BACK, FALSE);
		
	}
	if (hen.g_PauseFlg == TRUE) {
		DrawStringToHandle(120, 180, "ぽーずちゅう", 0x000000, fontpose);
	}
	
	//UIの枠表示
	DrawBox(SCREEN_WIDTH - 130, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x00ffff, TRUE);

	//制限時間の表示
	SetFontSize(25);
	DrawFormatString(520, 20, 0x000000, "制限時間");
	DrawFormatString(560, 60, 0x000000, "%d", hen.g_Time / 60);

	//りんごを取った数を表示
	SetFontSize(16);
	for (int i = 0; i < 4; i++) {
		DrawRotaGraph(528 + i * 30, 120, 0.5f, 0, hen.AppleImages[i], TRUE, FALSE);
		DrawFormatString(520 + i * 30, 140, 0x000000, "%02d", g_AppleCount[i]);
	}

	SetFontSize(30);
	DrawFormatString(530, 180, 0x000000, "スコア");
	SetFontSize(20);
	DrawFormatString(543, 220, 0x000000, "%06d", hen.Score);
}

//ゲームオーバー画像描画処理
void DrawGameOver(void) {
	//スペースキーでメニューに戻る
	if (hen.g_KeyFlg & PAD_INPUT_M) {
		if (g_Ranking[RANKING_DATA - 1].score >= hen.Score) {
			hen.g_GameState = 0;
		}
		else {
			hen.g_GameState = 7;
		}
	}

	DrawBox(150, 150, 490, 330, 0x009900, TRUE);
	DrawBox(150, 150, 490, 330, 0x000000, FALSE);

	SetFontSize(20);
	DrawString(220, 170, "ゲームオーバー", 0xcc0000);
	SetFontSize(18);

	DrawRotaGraph(215, 220, 0.5f, 0, hen.AppleImages[0], TRUE, FALSE);
	DrawRotaGraph(215, 240, 0.5f, 0, hen.AppleImages[1], TRUE, FALSE);
	DrawRotaGraph(215, 260, 0.5f, 0, hen.AppleImages[2], TRUE, FALSE);
	DrawRotaGraph(215, 280, 0.5f, 0, hen.AppleImages[3], TRUE, FALSE); 

	DrawFormatString(210, 212, 0xFFFFFF, "%6d x   150 = %6d", g_AppleCount[0], g_AppleCount[0] * 150);
	DrawFormatString(210, 233, 0xFFFFFF, "%6d x   300 = %6d", g_AppleCount[1], g_AppleCount[1] * 300);
	DrawFormatString(210, 254, 0xFFFFFF, "%6d x   500 = %6d", g_AppleCount[2], g_AppleCount[2] * 500);
	DrawFormatString(210, 275, 0xFFFFFF, "%6d x -1000 = %6d", g_AppleCount[3], g_AppleCount[3] * -1000);

	DrawString(310, 310, "スコア", 0x000000);
	DrawFormatString(260, 310, 0xFFFFFF, "             = %6d", hen.Score);
	SetFontSize(25);
	DrawString(150, 450, "---- Bボタンで戻る ----", 0xffffff, 0);
}

//ランキング入力処理
void InputRanking(void) {
	//ランキング画像表示
	DrawGraph(0, 0, hen.g_RankingImage, FALSE);
	SetFontSize(20);

	//名前入力指示文字列の描画
	DrawStringToHandle(110, 140, "ランキングに登録します", 0xffffff, fontrans);
	DrawStringToHandle(110, 170, "名前を英字で入力してください", 0xffffff, fontrans);

	//名前の入力
	DrawString(110, 210, ">", 0xffffff);
	DrawBox(120, 205, 260, 235, 0x000055, TRUE);
	for (int i = 0; i < 13; i++) {
		DrawGraph(i * 50, 200, pad.ALAN[i], TRUE);
	}

	if (KeyInputSingleCharString(130, 210, 10, g_Ranking[4].name, FALSE) == 1) {
		g_Ranking[4].score = hen.Score;
		SortRanking();
		SaveRanking();
		hen.g_GameState = 2;
	}
}

//ランキング並び替え
void SortRanking(void) {
	int i, j;
	RankingData work;

	//選択ソート
	for (i = 0; i < 4; i++) {
		for (j = i + 1; j < 5; j++) {
			if (g_Ranking[i].score <= g_Ranking[j].score) {
				work = g_Ranking[i];
				g_Ranking[i] = g_Ranking[j];
				g_Ranking[j] = work;
			}
		}
	}

	//順位付け
	for (i = 0; i < 5; i++) {
		g_Ranking[i].no = 1;
	}
	//得点が同じだった場合は、同じ順位とする
	//同順位があった場合の次の順位はデータ個数が加算された順位とする
	for (i = 0; i < 4; i++) {
		for (j = i + 1; j < 5; j++) {
			if (g_Ranking[i].score > g_Ranking[j].score) {
				g_Ranking[j].no++;
			}
		}
	}
}

//ランキングデータの保存
int SaveRanking(void) {
	FILE* fp;
#pragma warning(disable:4996)

	//ファイルオープン
	if ((fp = fopen("rankingdata.txt", "w")) == NULL) {
		//エラー処理
		printf("Ranking Data Error\n");
		return-1;
	}

	//ランキングデータ分配列データを書き込む
	for (int i = 0; i < 5; i++) {
		fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
	}

	//ファイルクローズ
	fclose(fp);

	return 0;
}

//ランキングデータ読み込み
int ReadRanking(void) {
	FILE* fp;
#pragma warning(disable:4996)
	if ((fp = fopen("rankingdata.txt", "r")) == NULL) {
		printf("Ranking Data Error\n");
		return-1;
	}

	for (int i = 0; i < 5; i++) {
		fscanf(fp, "%2d %10s %10d\n", &g_Ranking[i].no, g_Ranking[i].name, &g_Ranking[i].score);
	}

	fclose(fp);

	
	return 0;
}