#include <functional>

class GameObject;

typedef std::function<void(GameObject*)> GameAction;
typedef std::function<bool(GameObject*)> Where;

class Observer
{
protected:
	std::vector<GameAction> actions;
	std::vector<GameObject*> gameObjects;
	std::vector<Where> query;

public:
	Observer();

	virtual ~Observer();

	void AddTo(Where q, GameAction a, GameObject* go);

	void UpdateUnirx();
};