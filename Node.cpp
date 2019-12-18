#include "DXUT.h"
#include "stdafx.h"

Node::Node()
{
	position = { 0,0 };
	scale = { 1,1 };
	rotation = 0;
	IsAlive = true;
	Speed = 100;
	rotation = 0;
	tag = L"";
}

Node::~Node()
{
}

