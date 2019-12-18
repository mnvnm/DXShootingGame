#include "DXUT.h"
#include "stdafx.h"

Sprite::Sprite()
{
	Color = D3DXCOLOR(255, 255, 255, 255);
	anchor = { 0.5f,0.5f };

	sprite = nullptr;
	texture = nullptr;
}

Sprite::~Sprite()
{
}

void Sprite::Render()
{
	D3DXMatrixTransformation2D(&matrix, &anchor, 0, &scale, &anchor, rotation, &position);

	sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	sprite->SetTransform(&matrix);

	Vector3 center(info.Width, info.Height, 0);
	center.x *= anchor.x;
	center.y *= anchor.y;

	sprite->Draw(texture, &ImgRect, &center, nullptr, Color);

	SetRect(&ColRect, position.x - (info.Width * scale.x / 2), position.y - (info.Height * scale.y / 2),
		position.x + (info.Width * scale.x / 2), position.y + (info.Height * scale.y / 2));

	//위
	D_INS->DrawLine(Vector2(ColRect.left, ColRect.top), Vector2(ColRect.right, ColRect.top), D3DXCOLOR(255, 0, 0, 255));
	//오른쪽
	D_INS->DrawLine(Vector2(ColRect.right, ColRect.top), Vector2(ColRect.right, ColRect.bottom), D3DXCOLOR(255, 0, 0, 255));
	//아래
	D_INS->DrawLine(Vector2(ColRect.right, ColRect.bottom), Vector2(ColRect.left, ColRect.bottom), D3DXCOLOR(255, 0, 0, 255));
	//왼쪽
	D_INS->DrawLine(Vector2(ColRect.left, ColRect.top), Vector2(ColRect.left, ColRect.bottom), D3DXCOLOR(255, 0, 0, 255));

	sprite->End(); 

}

void Sprite::Update()
{

}

void Sprite::Settexture(WCHAR* path, int nLayer)
{
	D3DXCreateSprite(DXUTGetD3D9Device(), &sprite);
	D3DXCreateTextureFromFileEx(DXUTGetD3D9Device(), path, -2, -2, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, &info, nullptr, &texture);

	SetRect(&ImgRect, 0, 0, info.Width, info.Height);

	
}
