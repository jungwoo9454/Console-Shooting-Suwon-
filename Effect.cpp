#include "include.h"
Effect effects[D_EFFECT_MAX];

char effectBody[3][3][3] =
{
	{
		{' ', ' ', ' '},
		{' ', '*', ' '},
		{' ', ' ', ' '}
	},

	{
		{' ', '*', ' '},
		{'*', '*', '*'},
		{' ', '*', ' '}
	},

	{
		{'*', ' ', '*'},
		{' ', '*', ' '},
		{'*', ' ', '*'}
	}
};

void EffectInit()
{
	for (int i = 0;i < D_EFFECT_MAX;i++)
	{
		effects[i].x = 0;
		effects[i].y = 0;
		effects[i].isAlive = false;
		effects[i].index = 0;
		effects[i].indexUpdateTime = 0;
		effects[i].bColor = BLACK;
		effects[i].fColor = YELLOW;
	}
}

void EffectUpdate()
{
	for (int i = 0;i < D_EFFECT_MAX;i++)
	{
		if (effects[i].isAlive && effects[i].indexUpdateTime < GetTickCount())
		{
			effects[i].index++;
			effects[i].indexUpdateTime = GetTickCount() + 300;

			if (effects[i].index >= 3)
				effects[i].isAlive = false;
		}
	}
}

void EffectDraw()
{
	for (int i = 0;i < D_EFFECT_MAX;i++)
	{
		if (effects[i].isAlive)
		{
			DrawChar(effects[i].x - 1, effects[i].y - 1,
				effectBody[effects[i].index][0][0], effects[i].fColor, effects[i].bColor);
			DrawChar(effects[i].x, effects[i].y - 1,
				effectBody[effects[i].index][0][1], effects[i].fColor, effects[i].bColor);
			DrawChar(effects[i].x + 1, effects[i].y - 1,
				effectBody[effects[i].index][0][2], effects[i].fColor, effects[i].bColor);

			DrawChar(effects[i].x - 1, effects[i].y,
				effectBody[effects[i].index][1][0], effects[i].fColor, effects[i].bColor);
			DrawChar(effects[i].x, effects[i].y,
				effectBody[effects[i].index][1][1], effects[i].fColor, effects[i].bColor);
			DrawChar(effects[i].x + 1, effects[i].y,
				effectBody[effects[i].index][1][2], effects[i].fColor, effects[i].bColor);

			DrawChar(effects[i].x - 1, effects[i].y + 1,
				effectBody[effects[i].index][2][0], effects[i].fColor, effects[i].bColor);
			DrawChar(effects[i].x, effects[i].y + 1,
				effectBody[effects[i].index][2][1], effects[i].fColor, effects[i].bColor);
			DrawChar(effects[i].x + 1, effects[i].y + 1,
				effectBody[effects[i].index][2][2], effects[i].fColor, effects[i].bColor);
		}
	}
}

void CreateEffect(int x, int y)
{
	for (int i = 0; i < D_EFFECT_MAX;i++)
	{
		if (effects[i].isAlive == false)
		{
			effects[i].indexUpdateTime = GetTickCount() + 300;
			effects[i].index = 0;
			effects[i].y = y;
			effects[i].x = x;
			effects[i].isAlive = true;
			break;
		}
	}
}
