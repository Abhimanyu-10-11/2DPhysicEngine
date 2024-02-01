#pragma once
#include<vector>
#include"GameObject.h"
#include"ColliderComponent.h"
#include"RigidbodyComponent.h"

using namespace std;
class GameObjectAndComponentCreator
{
private:
	string gameObjectName;
	string spritefile;
	vector<string> componentList;

	vector<shared_ptr<GameObject>> allGameObject;
	vector <shared_ptr<ColliderComponent>> allColliderComponent;

	void createGameObject();
	void createComponentsforGameObject(shared_ptr<GameObject> gameObject);
public:
	GameObjectAndComponentCreator();
	vector<shared_ptr<GameObject>> 
		getAllGameObjectList();
	vector<shared_ptr<ColliderComponent>> getAllColliderComponents();

};

