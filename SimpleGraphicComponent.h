#pragma once
#include"Component.h"
#include"TransformComponent.h"
#include"GameObject.h"

class SimpleGraphicComponent : public Component
{
private:
	shared_ptr<GameObject> gameObject;
	Texture texture;
	Sprite sprite;
	shared_ptr<TransformComponent> gameObjectTransformComponent;
	int xPos = 0;
	int yPos = 0;
	float size = 1; 
	String specific_Tag = "graphic";
public:
	SimpleGraphicComponent(shared_ptr<GameObject> gameObject);
	void start();
	void update(float);
	void draw(RenderWindow& window);
	String& getSpecific_Tag();
	//Give filename only no need of extension //"graphic/------"
	void assignSprite(string name);
};

