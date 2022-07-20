#pragma once

class END
{
private:
	int PosY = 0;
	int g_WaitTime = 0;

public:
	int EndImage;
	int Player;

public:
	void DrawEnd(void);

private:
	void DrawPlayer();
};

extern END end;
