#include "DXUT.h"
#include "stdafx.h"

Player::Player()
{
	rotation = 5;

}

Player::~Player()
{
}

void Player::Update()
{
	if (DXUTIsKeyDown(VK_UP))
	{
		position.y -= 5;
	}
	if (DXUTIsKeyDown(VK_DOWN))
	{
		position.y += 5;
	}
	if (DXUTIsKeyDown(VK_LEFT))
	{
		position.x -= 5;
	}
	if (DXUTIsKeyDown(VK_RIGHT))
	{
		position.x += 5;
	}

	printf("%f %f\n", position.x, position.y);


	D_INS->PlayerPos = position;
}

void Player::Render()
{
	Sprite::Render();
}
