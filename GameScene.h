#pragma once
class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

public:
	Player player;
	Player2 player2;


	float CreateBulletTime;
	float CurBulletTime;

	virtual void Update();
	virtual void Render();
	virtual void Enter();
	virtual void Exit();

	void CreateBull();
};

