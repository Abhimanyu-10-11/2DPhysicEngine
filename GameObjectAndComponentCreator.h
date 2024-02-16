#pragma once
#include<vector>
#include<SFML/Graphics.hpp>
#include"GameObject.h"
#include"ColliderComponent.h"
#include"RigidbodyComponent.h"

using namespace std;
class GameObjectAndComponentCreator
{
private:

	vector<shared_ptr<GameObject>> allGameObject;
	vector <shared_ptr<ColliderComponent>> allColliderComponent;

	void createGameObject();
	void createComponentsforGameObject(shared_ptr<GameObject> gameObject);

	///
	string gameObjectName;
	string spritefile;
	vector<string> componentList;
	Vector2f pos = Vector2f(0,0);
public:
	GameObjectAndComponentCreator();
	vector<shared_ptr<GameObject>> 
		getAllGameObjectList();
	vector<shared_ptr<ColliderComponent>> getAllColliderComponents();

};

