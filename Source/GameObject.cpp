#include "GameObject.h"

GameObject::GameObject()
{
	for (int i = 0; i < 10; i++)
	{
		behavior.push_back(new Behavior(this));
	}
}

GameObject::~GameObject()
{
	for (int i = 0; i < 10; i++)
	{
		delete behavior[i];
	}
	behavior.clear();
}

void GameObject::Update()
{
	for (Behavior* b : behavior)
		b->Update();
}

void GameObject::InitUnirx()
{
	for (Behavior* b : behavior)
		b->InitUnirx();
}