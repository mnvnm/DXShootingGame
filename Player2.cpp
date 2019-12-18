#include "DXUT.h"
#include "stdafx.h"

Player2::Player2()
{
}

Player2::~Player2()
{
}

void Player2::Update()
{
	if (DXUTIsKeyDown('W'))
	{
		position.y -= 5;
	}
	if (DXUTIsKeyDown('S'))
	{
		position.y += 5;
	}
	if (DXUTIsKeyDown('A'))
	{
		position.x -= 5;
	}
	if (DXUTIsKeyDown('D'))
	{
		position.x += 5;
	}

}

void Player2::Render()
{
	Sprite::Render();
}