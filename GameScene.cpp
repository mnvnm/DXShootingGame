#include "DXUT.h"
#include "stdafx.h"

GameScene::GameScene()
{
	player.Settexture(L"EmptyProject.jpg", 0);
	nodes.push_back(&player);
	player.position = { 200, 200 };
	player.tag = L"P1";

	player2.Settexture(L"EmptyProject.jpg", 0);
	nodes.push_back(&player2);
	player2.position = { 400, 200 };
	player2.tag = L"P2";

	CreateBulletTime = 0.4f;
	CurBulletTime = 0;
}

GameScene::~GameScene()
{
}

void GameScene::Update()
{
	Scene::Update();
	printf("GameScene");

	if (AABB(L"P1", L"P2"))
	{
		printf("충돌이당");
	}

	CreateBull();

	
}

void GameScene::Render()
{
	Scene::Render();
}
	

void GameScene::Enter()
{
	Scene::Enter();
}

void GameScene::Exit()
{
	Scene::Exit();
}

void GameScene::CreateBull()
{
	CurBulletTime += D_INS->fdt;

	if (CurBulletTime >= CreateBulletTime)
	{
		if (DXUTIsKeyDown ('1'))
		{
			CurBulletTime = 0;
			float r = -115;
			for (int i = 0; i < 4 ; i++)
			{
				nodes.push_back(new Bullet(D_INS->PlayerPos, r,1));
				r += 15;
			}
		}
		if (DXUTIsKeyDown('2'))
		{
			CurBulletTime = 0;
			float r = 0;
			for (int i = 0; i < 45; i++)
			{
				nodes.push_back(new Bullet(D_INS->PlayerPos, r, 2));
				r += 8;
			}
		}
		if (DXUTIsKeyDown('3'))
		{
			CurBulletTime = 0;
			nodes.push_back(new Bullet(D_INS->PlayerPos, 90, 3));
			nodes.push_back(new Bullet(D_INS->PlayerPos, 270, 3));
		}
		if (DXUTIsKeyDown('4'))
		{
			CurBulletTime = 0;
			nodes.push_back(new Bullet(D_INS->PlayerPos, 0, 4));
			nodes.push_back(new Bullet(D_INS->PlayerPos, 180, 4));
		}
		if (DXUTIsKeyDown('5'))
		{
			CurBulletTime = 0;
			nodes.push_back(new Bullet(D_INS->PlayerPos, 45 ,  3));
			nodes.push_back(new Bullet(D_INS->PlayerPos, 225, 3));
			nodes.push_back(new Bullet(D_INS->PlayerPos, -45, 4));
			nodes.push_back(new Bullet(D_INS->PlayerPos, 135, 4));
		}
	}
}
