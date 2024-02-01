#pragma once
#include"GraphicComponent.h"
#include"TransformComponent.h"
#include"GameObject.h"

class SimpleGraphicComponent : public GraphicComponent
{
private:
	shared_ptr<GameObject> gameObject;
	Texture texture;
	Sprite sprite;
	shared_ptr<TransformComponent> gameObjectTransformComponent;
	string specific_Tag = "SimpleGraphicComponent";
public:
	SimpleGraphicComponent(shared_ptr<GameObject> gameObject);
	void awake();
	void start();
	void update(float);
	void draw(RenderWindow& window);
	string& getSpecific_Tag();
	//Give filename only no need of extension //"graphic/------"
	void assignSprite(string name);
};

