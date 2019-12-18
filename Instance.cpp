#include "DXUT.h"
#include "stdafx.h"

Instance::Instance()
{
	pDevice = DXUTGetD3D9Device();

	SceneList[E_GAME] = new GameScene();
	SceneList[E_MENU] = new MenuScene();

	CurScene = SceneList[E_GAME];
	CurScene->Enter();
}

Instance::~Instance()
{
}

Instance* Instance::Ins()
{
	if (instance == nullptr)
	{
		instance = new Instance();
	}
	return instance;
}

void Instance::ChangeScene(SCENE scene)
{
	if (SceneList[scene] != nullptr)
	{
		CurScene->Exit();
		CurScene = SceneList[scene];
		CurScene->Enter();
	}
}

void Instance::Update()
{
	if (CurScene != nullptr)
	{
		CurScene->Update();
	}
}

void Instance::Render()
{
	if (CurScene != nullptr)
	{
		CurScene->Render();
	}
}

void Instance::Init()
{
	//s.Settexture(L"EmptyProject.jpg", 0);
}

void Instance::Destory()
{
	exit(0);
}

void Instance::DrawLine(Vector2 from, Vector2 to, D3DXCOLOR color)
{
	LPD3DXLINE line;
	D3DXCreateLine(pDevice, &line);
	D3DXVECTOR2 lines[] = { from, to };
	line->Begin();
	line->Draw(lines, 2, color);
	line->End();
	line->Release();
}

void Instance::drawPoint(Vector2 at, D3DXCOLOR color)
{
	DrawLine(at, at + Vector2(0.0f, 1.0f), color);
}

void Instance::DrawCircle(Vector2 center, float r, D3DXCOLOR color)
{
	const float step = 2 * D3DX_PI / 180;
	float angle = 0;
	for (int i = 0; i < 180; i++) {
		DrawLine(center + Vector2(r * cos(angle), r * sin(angle)),
			center + Vector2(r * cos(angle + step), r * sin(angle + step)), color);
		angle += step;
	}
}


