#pragma once
class Player : public Sprite
{
public:
	Player();
	~Player();

	virtual void Update();
	virtual void Render();
};

