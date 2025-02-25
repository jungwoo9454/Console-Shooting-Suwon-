#include "include.h"
Enemy enemys[D_ENEMY_MAX];
DWORD createEnemyTime;
void EnemyInit()
{
	for (int i = 0;i < D_ENEMY_MAX;i++)
	{
		enemys[i].x = 0;
		enemys[i].y = 0;
		enemys[i].isAlive = false;
		enemys[i].body = ' ';
		enemys[i].fColor = RED;
		enemys[i].bColor = RED;
	}
}

void EnemyUpdate()
{
	// 1000 = 1초
	//	20시 10분 0.51초	20시 10분 0.5초
	if (GetTickCount() > createEnemyTime)
	{
		// deltatime
		createEnemyTime = GetTickCount() + 500;
		CreateEnemy(rand() % 120, -1);
	}
	EnemyMove();
	EnemyClipping();
}

void EnemyDraw()
{
	for (int i = 0;i < D_ENEMY_MAX;i++)
		if (enemys[i].isAlive)
			DrawChar(enemys[i].x, enemys[i].y, enemys[i].body, enemys[i].fColor, enemys[i].bColor);
}

void EnemyMove()
{
	for (int i = 0;i < D_ENEMY_MAX;i++)
		if (enemys[i].isAlive)
			enemys[i].y++;
}

void EnemyClipping()
{
	for (int i = 0;i < D_ENEMY_MAX;i++)
		if (enemys[i].isAlive && enemys[i].y >= 30)
			enemys[i].isAlive = false;
}

// x 0~119
void CreateEnemy(int x, int y)
{
	for (int i = 0;i < D_ENEMY_MAX;i++)
	{
		if (enemys[i].isAlive == false)
		{
			enemys[i].x = x;
			enemys[i].y = y;
			enemys[i].isAlive = true;
			break;
		}
	}
}

void BulletEnemyCollision()
{
	for (int i = 0;i < D_BULLET_MAX;i++)
	{
		if (bullet[i].isAlive)
		{
			for (int j = 0;j < D_ENEMY_MAX;j++)
			{
				if (enemys[j].isAlive &&
					bullet[i].x == enemys[j].x && 
					(bullet[i].y == enemys[j].y || bullet[i].y - 1 == enemys[j].y))
				{
					bullet[i].isAlive = false;
					enemys[j].isAlive = false;
					CreateEffect(enemys[j].x, enemys[j].y);
					break;
				}
			}
		}
	}
}
