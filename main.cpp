#include "include.h"

int main()
{
	Init();

	while (true)
	{
		Update();
		Draw();

		EngineSync(30);	// 1초에 30프레임 고정
	}

	Release();

	return 0;
}