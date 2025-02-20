#include "include.h"
Player player;
void PlayerInit()
{
	player.bColor = BLACK;
	player.fColor = WHITE;
	player.x = 60;
	player.y = 15;
	player.body = 'A';
}

void PlayerUpdate()
{
	PlayerMove();
	PlayerClipping();

	if (GetAsyncKeyState(VK_SPACE))
	{
		CreateBullet(player.x, player.y);
	}
}

void PlayerDraw()
{
	DrawChar(player.x, player.y, player.body, player.fColor, player.bColor);
}

void PlayerMove()
{
	// 0,0(왼쪽위) ~ 119, 29(오른쪽아래)
	if (GetAsyncKeyState('W'))
		player.y--;

	if (GetAsyncKeyState('A'))
		player.x--;

	if (GetAsyncKeyState('S'))
		player.y++;

	if (GetAsyncKeyState('D'))
		player.x++;
}

void PlayerClipping()
{
	// 플레이어 Space(VK_SPACE)키를 누르면 플레이어 위치에 총알 생성
	// 총알은 위로 이동

	if (player.x < 0)
		player.x = 0;

	if (player.x > 119)
		player.x = 119;

	if (player.y < 0)
		player.y = 0;

	if (player.y > 29)
		player.y = 29;
}
