#pragma once

class GameObject;

class Behavior
{
protected:
	int state;

	GameObject* gameObject;

public:
	Behavior(GameObject* gameObject);

	virtual ~Behavior();

	void InitUnirx();

	void Update();

	void DoSomeThing0();

	void DoSomeThing1();
};