#include "GameObjectAndComponentCreator.h"
#include"SimpleGraphicComponent.h"
#include"TransformComponent.h"
#include"RigidbodyComponent.h"
#include"PlayerInputController.h"
#include"RectColliderComponent.h"
#include"CircleColliderComponent.h"
GameObjectAndComponentCreator::GameObjectAndComponentCreator()
{

	gameObjectName = "player";
	spritefile = "player.png";
	componentList.push_back("SimpleGraphicComponent");
	componentList.push_back("RigidbodyComponent");
	componentList.push_back("PlayerInputController");
	componentList.push_back("CircleColliderComponent");
	createGameObject();

	//second object;
	componentList.clear();
	gameObjectName = "bloaterZombie";
	spritefile = "bloaterZombie.png";
	componentList.push_back("CircleColliderComponent");
	componentList.push_back("SimpleGraphicComponent");
	//componentList.push_back("RigidbodyComponent");
	createGameObject();
	createGameObject();



}

vector<shared_ptr<GameObject>> GameObjectAndComponentCreator::getAllGameObjectList()
{
	return allGameObject;
}



void GameObjectAndComponentCreator::createGameObject()
{
	shared_ptr<GameObject> gameObject = make_shared<GameObject>();
	gameObject->setName(gameObjectName);
	allGameObject.push_back(gameObject);
	createComponentsforGameObject(gameObject);
}

vector<shared_ptr<ColliderComponent>> GameObjectAndComponentCreator::getAllColliderComponents()
{
	return allColliderComponent;
}


void GameObjectAndComponentCreator::
createComponentsforGameObject(shared_ptr<GameObject> gameObject)
{


	shared_ptr<TransformComponent> TC = make_shared<TransformComponent>(gameObject);
	gameObject->addComponent(TC);

	for (string component : this->componentList)
	{
		if (component == "RigidbodyComponent")
		{
			shared_ptr<RigidbodyComponent> RC = make_shared<RigidbodyComponent>(gameObject);
			gameObject->addComponent(RC);
			
		}

		if (component == "SimpleGraphicComponent")
		{
			shared_ptr<SimpleGraphicComponent> SGC =
				make_shared<SimpleGraphicComponent>(gameObject);
			SGC->assignSprite(spritefile);
			gameObject->addComponent(SGC);
		}

		if (component == "RectColliderComponent")
		{
			shared_ptr<RectColliderComponent> RCC = make_shared<RectColliderComponent>(gameObject);
			gameObject->addComponent(RCC);
			allColliderComponent.push_back(RCC);

		}
		if (component == "CircleColliderComponent")
		{
			shared_ptr<CircleColliderComponent> CCC = make_shared<CircleColliderComponent>(gameObject);
			gameObject->addComponent(CCC);
			allColliderComponent.push_back(CCC);
		}

		if (component == "PlayerInputController")
		{

			gameObject->addComponent(make_shared<PlayerInputController>(gameObject));
			
		}
	}

}
