#pragma once
#include"Component.h"
#include"TransformComponent.h"
#include"ColliderComponent.h"
#include"GameObject.h"
#include<SFML/Graphics.hpp>
using namespace sf;
struct CollisionOut
{
	std::shared_ptr<GameObject> collidedGameObject;
	bool isColliding = false;
};

class RigidbodyComponent : public Component
{
private:
	const float GRAVITY = 90.80f;
	float gravity = GRAVITY;
	CollisionOut collisionOut;//make this pointer of sometype
	

	std::shared_ptr<GameObject> gameObject;
	
	std::shared_ptr<TransformComponent> gameObjectTransformComponent;
	std::shared_ptr<ColliderComponent> thisGameObjectColliderComponent;
	string specific_Tag = "RigidbodyComponent";
	bool hasGravity = true;
	void collisionDetectionSystem();
	FloatRect thisGameObjectColliderBound;
public:
	RigidbodyComponent(shared_ptr<GameObject> gameObject);
	void awake();
	void start();
	void update(float dtAsSecond);
	string& getSpecific_Tag();
	void setHasGravity(bool hasGravity);
	bool getHasGravity();
	void setGravity(float gravity);
	float getGravity();
	CollisionOut& getCollisionOut();

};

