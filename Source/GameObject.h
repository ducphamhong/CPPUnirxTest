#pragma once

#include <vector>
#include "Behavior.h"
#include "Observer.h"

class GameObject : public Observer
{
protected:
	std::vector<Behavior*> behavior;

public:
	GameObject();

	virtual ~GameObject();

	void Update();

	inline Observer* AsObserver()
	{
		return this;
	}

	void InitUnirx();
};