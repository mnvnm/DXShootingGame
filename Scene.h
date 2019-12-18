#pragma once
class Scene
{
public:
	Scene();
	~Scene();

	vector<Node*> nodes;
public:
	virtual void Update();
	virtual void Render();
	virtual void Enter();
	virtual void Exit();

	static bool Scene::Comp(Node* a, Node* b);

	bool Scene::AABB(WCHAR* a, WCHAR* b);

};    

