#include "DXUT.h"
#include "stdafx.h"

Bullet::Bullet(Vector2 pos, int angle, int pattern)
{
	Settexture(L"EmptyProject.jpg", 0);
	Speed = 350;
	position = pos;
	rotation = angle;
	tag = L"B";
	Pt = pattern;

	static_pos = D_INS->PlayerPos;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (position.y < -10 || IsAlive == false)
	{
		IsAlive = false;
		position = { 1000,10000 };
	}

	/*for (int i = 0; i < 72; i++)
	{
		rotation += 5;
	Dir.y = sin(D3D	}*/

	if (position.x > 640) IsAlive = false;
	if (position.x < 0) IsAlive = false;
	if (position.y > 480) IsAlive = false;
	if (position.y < 0) IsAlive = false;

	switch (Pt)
	{
	case 1:
		Pt1();
		break;
	case 2:
		Pt2();
		break;
	case 3:
		Pt3();
		break;
	case 4:
		Pt4();
		break;
	case 5:
		Pt5();
		break;
	}
}

void Bullet::Pt1()
{
	Vector2 Dir;
	Dir.y = sin(D3DX_PI / 180 * rotation) * Speed * D_INS->fdt;
	Dir.x = cos(D3DX_PI / 180 * rotation) * Speed * D_INS->fdt;
	position += Dir;
}

void Bullet::Pt2()
{
	Vector2 Dir;
	Dir.y = sin(D3DX_PI / 180 * rotation) * Speed * D_INS->fdt;
	Dir.x = cos(D3DX_PI / 180 * rotation) * Speed * D_INS->fdt;
	position += Dir;
}

void Bullet::Pt3()
{
	position.x = static_pos.x - sin(D3DX_PI * position.y / 180.0) * 100;
	Pt1();
}

void Bullet::Pt4()
{
	position.y = static_pos.y - sin(D3DX_PI * position.x / 180.0) * 100;
	Pt2();
}

void Bullet::Pt5()
{
	position.y = static_pos.y - sin(D3DX_PI * position.x / 180.0) * 100;
	
}
