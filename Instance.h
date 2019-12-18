#pragma once
enum SCENE
{
	E_GAME,
	E_MENU,
	E_MAX
};

class Instance // 纠包府 面倒贸府 殿殿阑 包府 
{
public:

	Instance();
	~Instance();

private:
	static Instance* instance;
public:
	IDirect3DDevice9* pDevice;
	float fdt;
	float fTimeScale;
	float fTotalTime;
	int nFPS;
	Sprite s;

	Scene* CurScene;
	Scene* SceneList[E_MAX];

	Vector2 PlayerPos;

public:
	static Instance* Ins();

	void ChangeScene(SCENE scene);

	void Update();
	void Render();
	void Init();
	void Destory();
	void Instance::DrawLine(Vector2 from, Vector2 to, D3DXCOLOR color);
	void Instance::drawPoint(Vector2 at, D3DXCOLOR color);
	void Instance::DrawCircle(Vector2 center, float r, D3DXCOLOR color);

	
};