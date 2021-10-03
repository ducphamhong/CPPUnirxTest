#include "Observer.h"

Observer::Observer()
{

}

Observer::~Observer()
{

}

void Observer::AddTo(Where q, GameAction a, GameObject* go)
{
	query.push_back(q);
	actions.push_back(a);
	gameObjects.push_back(go);
}

void Observer::UpdateUnirx()
{
	for (int i = 0, n = (int)actions.size(); i < n; i++)
	{
		if (query[i](gameObjects[i]))
			actions[i](gameObjects[i]);
	}
}