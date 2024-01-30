#pragma once
#include"Component.h"
#include"GameObject.h"

class TransformComponent : public Component
{
private:
	shared_ptr<GameObject> gameObject;
	float xPos = 100;
	float yPos = 100; 
public:
	String specific_Tag = "transform";
	TransformComponent(shared_ptr<GameObject> gameObject);
	void update(float dtAsSecond);
	void draw(RenderWindow& window)
	{

	}
	String& getSpecific_Tag();
	float& getXPosition();
	float& getYPosition();

};

