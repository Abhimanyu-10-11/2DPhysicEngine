#pragma once
#include<vector>
#include"GameObject.h"
#include"SimpleGraphicComponent.h"
#include"TransformComponent.h"
#include"RigidbodyComponent.h"

using namespace std;
class GameObjectAndComponentCreator
{
private:
	vector<shared_ptr<GameObject>> allGameObject;	
	void createComponentsforGameObject(shared_ptr<GameObject> gameObject, vector<string>& componentsList);
public:
	GameObjectAndComponentCreator();
	vector<shared_ptr<GameObject>> 
		getAllGameObjectList();
	void createGameObject(string name,vector<string>& componentsList);

};

