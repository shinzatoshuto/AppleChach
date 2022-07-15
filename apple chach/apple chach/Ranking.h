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

	int g_RankingImage;

	//ランキングデータ変数宣言
	struct RankingData  g_Ranking[RANKING_DATA];

	int ReadRanking(void);
	void DrawRanking(void);
	void InputRanking(void);

private:
	void SortRanking(void);
	int SaveRanking(void);
};

extern RANKING ranking;