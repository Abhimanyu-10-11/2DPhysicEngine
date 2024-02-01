#include "RigidbodyComponent.h"
#include"ColliderComponent.h"

#include"PhysicEngine.h"
using namespace pe;
GameObjectAndComponentCreator* PhysicEngine::gOAndC;


RigidbodyComponent::RigidbodyComponent(shared_ptr<GameObject> gameObject)
{
	this->gameObject = gameObject;
}

void RigidbodyComponent::awake()
{
	if (gameObjectTransformComponent == NULL)
		gameObjectTransformComponent =
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
	thisGameObjectColliderBound = static_pointer_cast<ColliderComponent>(gameObject->findComponentWithSpecificTag("ColliderComponent"))->getColliderBound();
	
	
}

void RigidbodyComponent::update(float dtAsSecond)
{
	if (gameObjectTransformComponent != NULL)
	{
		if(hasGravity)
			gameObjectTransformComponent->getYPosition() += gravity *dtAsSecond;
	}
	//Optimize this by not calling every frame
	collisionDetectionSystem();
}

void RigidbodyComponent::collisionDetectionSystem()
{
	collisionOut.isColliding = false;
	for (auto colliderComponent : PhysicEngine::gOAndC->getAllColliderComponents())
	{
		if (colliderComponent == thisGameObjectColliderComponent)
			continue;
		
			if (thisGameObjectColliderBound.intersects(colliderComponent->getColliderBound()))
			{
				collisionOut.collidedGameObject = colliderComponent->getThisComponentGameObject();
				collisionOut.isColliding = true;
			}
	
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

void RigidbodyComponent::setGravity(float gravity)
{
	this->gravity = gravity;
}



float RigidbodyComponent::getGravity()
{
	return gravity;
}

CollisionOut& RigidbodyComponent::getCollisionOut()
{
	return collisionOut;
}
