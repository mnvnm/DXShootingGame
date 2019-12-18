#pragma once
class Bullet : public Sprite
{
public:
	Bullet(Vector2 pos, int angle , int pattern);
	~Bullet();

	int Pt;

	Vector2 static_pos;

	virtual void Update();

	void Pt1();
	void Pt2();
	void Pt3();
	void Pt4();
	void Pt5();
};

