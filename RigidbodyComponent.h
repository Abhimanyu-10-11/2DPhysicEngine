#pragma once
#include"Component.h"
#include"TransformComponent.h"
#include<SFML/Graphics.hpp>
#include"ColliderComponent.h"
#include"GameObject.h"
using namespace sf;
#define GRAVITY 90.80
#define MASS 1.0


class RigidbodyComponent : public Component
{
private:
	Vector2f gravity = Vector2f(0, GRAVITY);
	float mass = MASS;
	Vector2f velocity = Vector2f(0, 0);
	Vector2f force = Vector2f(0,0);

	CollisionOut collisionOut;//make this pointer of sometype


	std::shared_ptr<GameObject> gameObject;
	std::shared_ptr<TransformComponent> transform;
	std::shared_ptr<ColliderComponent> colliderComponent;
	string specific_Tag = "RigidbodyComponent";
	bool hasGravity = true;
	void collisionDetectionSystem();
	void CircleToCircleCollision(shared_ptr<ColliderComponent> otherColliderComponent);
	FloatRect thisGameObjectColliderBound;
	FloatRect colliderInterSection;
	void awake();
	void start();
	void update(float dtAsSecond);
	void fixedUpdate();
	float fixedUpdateCall = 0.02f;
	float fixedUpdateTimer = 0.0f;
public:
	RigidbodyComponent(shared_ptr<GameObject> gameObject);
	shared_ptr<GameObject> getThisComponentGameObject();
	string& getSpecific_Tag();
	void setHasGravity(bool hasGravity);
	bool getHasGravity();
	void setGravity(Vector2f gravity);
	Vector2f getGravity();
	void setMass(float mass);
	float getMass();
	void setVelocity(Vector2f velocity);
	void setVelocity(float x, float y);
	Vector2f& getVelocity();
	CollisionOut& getCollisionOut();

};

