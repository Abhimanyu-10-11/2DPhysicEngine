#pragma once
#include"Component.h"
#include"TransformComponent.h"
#include"GameObject.h"


class RigidbodyComponent : public Component
{
private:
	const float GRAVITY = 90.80f;

	std::shared_ptr<GameObject> gameObject;
	std::shared_ptr<TransformComponent> gameObjectTransformComponent;
	String specific_Tag = "rigidbody";
public:
	RigidbodyComponent(shared_ptr<GameObject> gameObject);
	void start();
	void update(float dtAsSecond);
	void draw(RenderWindow& window){}
	String& getSpecific_Tag();
};

