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
	float xSpritePos = 0;
	float ySpritePos = 0;
	float spriteRotation = 0;
	shared_ptr<TransformComponent> transform;
	string componentName = "Simple"+specific_Tag;
	unsigned int xTextrueSize = 0;
	unsigned int yTextureSize = 0;
public:
	SimpleGraphicComponent() {}
	SimpleGraphicComponent(
		shared_ptr<GameObject> gameObject);
	void awake();
	void start();
	void update(float);
	void draw(RenderWindow& window);
	shared_ptr<GameObject> getThisComponentGameObject();
	//Give filename only no need of extension //"graphic/------"
	void assignSprite(string name);
	//textrue Size
	unsigned int getXTextureSize();
	unsigned int getYTextureSize();
};

