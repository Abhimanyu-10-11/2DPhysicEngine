#include "RigidbodyComponent.h"
#include"ColliderComponent.h"

RigidbodyComponent::RigidbodyComponent(shared_ptr<GameObject> gameObject)
{
	this->gameObject = gameObject;
}

void RigidbodyComponent::awake()
{
	if (transform == NULL)
		transform =
		static_pointer_cast<TransformComponent>
		(gameObject->findComponentWithSpecificTag("TransformComponent"));
	if (thisGameObjectColliderComponent == NULL)
	{
		thisGameObjectColliderComponent =
			static_pointer_cast<ColliderComponent>(gameObject->findComponentWithSpecificTag("ColliderComponent"));
	}

	
}

void RigidbodyComponent::start()
{
	gravityForce = Vector2f(gravity*mass);

	
}

void RigidbodyComponent::update(float dtAsSecond)
{
	
	
	fixedUpdateTimer += dtAsSecond;
	if (fixedUpdateTimer >= fixedUpdateCall)
	{
		fixedUpdate();
		fixedUpdateTimer = 0;
	}
	//Optimize this by not calling every frame
	collisionDetectionSystem();
}

void RigidbodyComponent::fixedUpdate()
{
	force = Vector2f(velocity*mass);
	velocity = Vector2f(0, 0);
	
	if (transform != NULL)
	{
		if (hasGravity)
		{
			transform->getPosition() += gravityForce * fixedUpdateCall;

		}

		if (collisionOut.isColliding && hasGravity)
		{
			transform->getPosition() += -gravityForce * fixedUpdateCall;
			
		}

		transform->getPosition() += force *fixedUpdateCall;
	}

}





string& RigidbodyComponent::getSpecific_Tag()
{
	return specific_Tag;
}

void RigidbodyComponent::setHasGravity(bool hasGravity)
{
	this->hasGravity = hasGravity;
}

bool RigidbodyComponent::getHasGravity()
{
	return hasGravity;
}

void RigidbodyComponent::setGravity(Vector2f gravity)
{
	this->gravity = gravity;
}



Vector2f RigidbodyComponent::getGravity()
{
	return gravity;
}

void RigidbodyComponent::setMass(float mass)
{
	this->mass = mass;
}

float RigidbodyComponent::getMass()
{
	return mass;
}

void RigidbodyComponent::setVelocity(Vector2f velocity)
{
	this->velocity = velocity;
}

void RigidbodyComponent::setVelocity(float x, float y)
{
	this->velocity = Vector2f(x, y);
}

Vector2f& RigidbodyComponent::getVelocity()
{
	return velocity;
}

shared_ptr<GameObject> RigidbodyComponent::getThisComponentGameObject()
{
	return gameObject;
}

CollisionOut& RigidbodyComponent::getCollisionOut()
{
	return collisionOut;
}
