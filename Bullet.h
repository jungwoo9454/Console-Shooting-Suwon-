#pragma once
struct Bullet
{
	bool isAlive;	// true => 사용중, false => 미사용(대기상태)
	int x;
	int y;
	char body;
	WORD fColor;
	WORD bColor;
};

void BulletInit();
void BulletUpdate();
void BulletDraw();

void BulletMove();
void BulletClipping();

void CreateBullet(int x, int y);

extern Bullet bullet[D_BULLET_MAX];