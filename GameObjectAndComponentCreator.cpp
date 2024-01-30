#include "GameObjectAndComponentCreator.h"

GameObjectAndComponentCreator::GameObjectAndComponentCreator()
{
	vector<string> componentList;
	componentList.push_back("graphic");
	componentList.push_back("rigidbody");
	createGameObject("player", componentList);
	componentList.pop_back();
	createGameObject("player", componentList);

}

vector<shared_ptr<GameObject>> GameObjectAndComponentCreator::getAllGameObjectList()
{
	return allGameObject;
}

void GameObjectAndComponentCreator::createGameObject(string name , vector<string>& componentsList)
{
	shared_ptr<GameObject> gameObject = make_shared<GameObject>(name);
	allGameObject.push_back(gameObject);
	createComponentsforGameObject(gameObject, componentsList);
}

void GameObjectAndComponentCreator::
createComponentsforGameObject(shared_ptr<GameObject> gameObject, vector<string>& componentsList)
{
	gameObject->addComponent(make_shared<TransformComponent>(gameObject));

	for (string component : componentsList)
	{
		if (component == "rigidbody")
		{
			gameObject->addComponent(make_shared<RigidbodyComponent>(gameObject));
		}

		if (component == "graphic")
		{
			gameObject->addComponent(make_shared<SimpleGraphicComponent>(gameObject));
		}
	}

}
