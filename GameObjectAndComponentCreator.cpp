#include "GameObjectAndComponentCreator.h"
#include"SimpleGraphicComponent.h"
#include"TransformComponent.h"
#include"RigidbodyComponent.h"
#include"PlayerInputController.h"
#include"RectColliderComponent.h"

GameObjectAndComponentCreator::GameObjectAndComponentCreator()
{
	vector<string> componentList;
	componentList.push_back("RectColliderComponent");
	componentList.push_back("SimpleGraphicComponent");
	componentList.push_back("RigidbodyComponent");
	componentList.push_back("PlayerInputController");
	createGameObject("player", componentList);
	componentList.pop_back();
	createGameObject("player1", componentList);

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

vector<shared_ptr<ColliderComponent>> GameObjectAndComponentCreator::getAllColliderComponents()
{
	return allColliderComponent;
}


void GameObjectAndComponentCreator::
createComponentsforGameObject(shared_ptr<GameObject> gameObject, vector<string>& componentsList)
{
	gameObject->addComponent(make_shared<TransformComponent>(gameObject));

	for (string component : componentsList)
	{
		if (component == "RigidbodyComponent")
		{
			shared_ptr<RigidbodyComponent> RC = make_shared<RigidbodyComponent>(gameObject);
			gameObject->addComponent(RC);
			
		}

		if (component == "SimpleGraphicComponent")
		{
			gameObject->addComponent(make_shared<SimpleGraphicComponent>(gameObject));
		}
		if (component == "PlayerInputController")
		{

			gameObject->addComponent(make_shared<PlayerInputController>(gameObject));
			
		}
		if (component == "RectColliderComponent")
		{
			shared_ptr<RectColliderComponent> RCC = make_shared<RectColliderComponent>(gameObject);
			gameObject->addComponent(RCC);
			allColliderComponent.push_back(RCC);

		}
	}

}
