#pragma once

#define  RANKING_DATA  5

class RANKING {
public:
	//�����L���O�f�[�^�i�\���́j
	struct RankingData {
		int no;
		char name[11];
		long score;
	};

	//�����L���O�f�[�^�ϐ��錾
	struct RankingData  g_Ranking[RANKING_DATA];

	void DrawRanking(void);
	void InputRanking(void);
	void SortRanking(void);
	int SaveRanking(void);
	int ReadRanking(void);
};

extern RANKING ranking;