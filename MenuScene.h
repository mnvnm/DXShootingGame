#pragma once
class MenuScene : public Scene
{
public:
	MenuScene();
	~MenuScene();

	virtual void Update();
	virtual void Render();
	virtual void Enter();
	virtual void Exit();
};

