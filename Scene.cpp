#pragma once
#include "DXUT.h"
#include "stdafx.h"

Scene::Scene()
{
}

Scene::~Scene()
{

}

void Scene::Update()
{
	for (auto n : nodes)
	{
		if (n->IsAlive)
		{
			n->Update();
		}
	}
}

void Scene::Render()
{
	sort(nodes.begin(), nodes.end(), Comp);
	for (auto n : nodes)
	{
		if (n->IsAlive)
		{
			n->Render();
		}
	}
}

void Scene::Enter()
{
}

void Scene::Exit()
{
}
bool Scene::Comp(Node* a, Node* b)
{
	return(a->Layer < b->Layer);
}
bool Scene::AABB(WCHAR* a, WCHAR* b)//Ãæµ¹
{
	for (auto n : nodes)
	{
		if (n->tag == a)
		{
			for (auto n2 : nodes)
			{
				if (n2->tag == b)
				{
					RECT r;
					if (IntersectRect(&r, &n->ColRect, &n2->ColRect))
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	return false;
}
