#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
using namespace std;


class GameObject;
class Component
{
	string tag = "Component";
public:
	virtual void awake() = 0;
	virtual void start() = 0;
	virtual void update(float) = 0;
	virtual void draw(RenderWindow&) {}
	virtual shared_ptr<GameObject> getThisComponentGameObject() = 0;
	virtual string& getSpecific_Tag() = 0;
};

