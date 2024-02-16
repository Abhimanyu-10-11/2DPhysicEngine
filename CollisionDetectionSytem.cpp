#include"RigidbodyComponent.h"
#include"PhysicEngine.h"


using namespace pe;
GameObjectAndComponentCreator* PhysicEngine::gOAndC;

void RigidbodyComponent::collisionDetectionSystem()
{
	if (!thisGameObjectColliderComponent->getIsColliderActive())
		return;



}


























//void RigidbodyComponent::collisionDetectionSystem()
//{
//	if (!thisGameObjectColliderComponent->getIsColliderActive())
//		return;
//
//	collisionOut.isColliding = false;
//	for (auto colliderComponent : PhysicEngine::gOAndC->getAllColliderComponents())
//	{
//		if (colliderComponent == thisGameObjectColliderComponent)
//			continue;
//
//		thisGameObjectColliderBound = thisGameObjectColliderComponent
//			->getColliderBound();
//		FloatRect otherGameObjectBound = colliderComponent->getColliderBound();
//
//		if (thisGameObjectColliderBound.intersects(otherGameObjectBound,colliderInterSection))
//		{
//			
//			collisionOut.collidedGameObject = colliderComponent->getThisComponentGameObject();
//			collisionOut.isColliding = true;
//		}
//
//	}
//
//}



