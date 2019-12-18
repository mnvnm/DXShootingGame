#pragma once
class Node;

class Node
{
public:
	Node();
	virtual ~Node();

public:
	Vector2 position;
	Vector2 scale;
	float rotation;
	bool IsAlive;
	Matrix matrix;
	WCHAR* tag;
	D3DXCOLOR Color;
	D3DXIMAGE_INFO info;
	RECT ImgRect;
	RECT ColRect;
	Vector2 anchor;
	int Layer;
	float Speed;
	virtual void Render() = 0;
	virtual void Update() = 0;
};

