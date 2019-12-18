#pragma once
class Sprite : public Node
{
public:
	Sprite();
	~Sprite();
public:
	LPDIRECT3DTEXTURE9 texture;
	LPD3DXSPRITE sprite;
	
	virtual void Render();
    virtual void Update();
	void Settexture(WCHAR*path, int nLayer);
};

