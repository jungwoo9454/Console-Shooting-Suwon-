#pragma once
struct Enemy
{
	bool isAlive;	// true => 사용중, false => 미사용(대기상태)
	int x;
	int y;
	char body;
	WORD fColor;
	WORD bColor;
};

void EnemyInit();
void EnemyUpdate();
void EnemyDraw();
	 
void EnemyMove();
void EnemyClipping();

void CreateEnemy(int x, int y);

void BulletEnemyCollision();