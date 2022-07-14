#pragma once

#define  RANKING_DATA  5

class RANKING {
public:
	//ランキングデータ（構造体）
	struct RankingData {
		int no;
		char name[11];
		long score;
	};

	//ランキングデータ変数宣言
	struct RankingData  g_Ranking[RANKING_DATA];

	void DrawRanking(void);
	void InputRanking(void);
	void SortRanking(void);
	int SaveRanking(void);
	int ReadRanking(void);
};

extern RANKING ranking;