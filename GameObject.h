#pragma once
#include"Component.h"
#include<vector>
using namespace std;
using namespace sf;

class GameObject
{


private:
	vector<shared_ptr<Component>> components;
	string name = "";
	int objectId = 0;
public:
	static int totalNumberOfGameObjectEverCreated;
	string tag = "GameObject";
	GameObject(string name);
	void start();
	void update(float dtAsSecond);
	void draw(RenderWindow& window);
	void addComponent(shared_ptr<Component>  component);
	shared_ptr<Component> findComponentWithSpecificTag(string component);
	String getName();

};

