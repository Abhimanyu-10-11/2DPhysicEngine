#include"RigidbodyComponent.h"
#include"PhysicEngine.h"
#include"MathMy.h"


using namespace pe;
GameObjectAndComponentCreator* PhysicEngine::gOAndC;

Vector2f ownPosition;
Vector2f otherPosition;
Vector2f axis;
Vector2f normal;
float depth;

void RigidbodyComponent::collisionDetectionSystem()
{
	if (!colliderComponent->getIsColliderActive())
		return;

	for (auto otherColliderComponent : 
		PhysicEngine::gOAndC->getAllColliderComponents())
	{
		if (otherColliderComponent == colliderComponent)
			continue;

		if (!otherColliderComponent->getIsColliderActive())
			continue;

		if (colliderComponent->getCollisionType() == CollisionType::Circle && otherColliderComponent->getCollisionType() == CollisionType::Circle)
		{
			CircleToCircleCollision(otherColliderComponent);
		}

	}

}



void RigidbodyComponent::CircleToCircleCollision(shared_ptr<ColliderComponent> otherColliderComponent)
{
	
	ownPosition = transform->getPosition();
		otherPosition = otherColliderComponent->getThisComponentGameObject()->getComponentOfType<TransformComponent>()->getPosition();
		float ownRadius = colliderComponent->getRadius();
		float otherRadius = otherColliderComponent->getRadius();
		axis = otherPosition - ownPosition;
		float axisLength = MyMath::getMagnitude(axis);
	

		if (axisLength < ownRadius + otherRadius)
		{
			normal = MyMath::normalize(axis);
			depth = ownRadius + otherRadius - axisLength;

			if (depth < ownRadius + otherRadius)
				transform->getPosition() += -normal * (depth / 2);

		}
}

























/*
void RigidbodyComponent::collisionDetectionSystem()
{
	if (!thisGameObjectColliderComponent->getIsColliderActive())
		return;

	collisionOut.isColliding = false;
	for (auto colliderComponent : PhysicEngine::gOAndC->getAllColliderComponents())
	{
		if (colliderComponent == thisGameObjectColliderComponent)
			continue;

		thisGameObjectColliderBound = thisGameObjectColliderComponent
			->getColliderBound();
		FloatRect otherGameObjectBound = colliderComponent->getColliderBound();

		if (thisGameObjectColliderBound.intersects(otherGameObjectBound,colliderInterSection))
		{
			
			collisionOut.collidedGameObject = colliderComponent->getThisComponentGameObject();
			collisionOut.isColliding = true;
		}

	}

}
*/


