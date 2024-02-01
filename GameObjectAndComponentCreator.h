#pragma once
#include<vector>
#include"GameObject.h"
#include"ColliderComponent.h"
#include"RigidbodyComponent.h"

using namespace std;
class GameObjectAndComponentCreator
{
private:
	vector<shared_ptr<GameObject>> allGameObject;
	vector <shared_ptr<ColliderComponent>> allColliderComponent;

	void createComponentsforGameObject(shared_ptr<GameObject> gameObject, vector<string>& componentsList);
public:
	GameObjectAndComponentCreator();
	void createGameObject(string name,vector<string>& componentsList);

	vector<shared_ptr<GameObject>> 
		getAllGameObjectList();
	vector<shared_ptr<ColliderComponent>> getAllColliderComponents();

};

