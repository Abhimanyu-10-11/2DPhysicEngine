#include"RigidbodyComponent.h"

#include"PhysicEngine.h"
#include"MathMy.h"

using namespace pe;
GameObjectAndComponentCreator* PhysicEngine::gOAndC;

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
//			Vector2f normal = transform->getPosition() - Vector2f(otherGameObjectBound.left + otherGameObjectBound.width/2,otherGameObjectBound.top + otherGameObjectBound.height/2);
//			normal = MyMath::normalize(normal);
//
//			/*Vector2f normal = transform->getPosition() - Vector2f(
//				colliderInterSection.left+colliderInterSection.width/2,
//				colliderInterSection.top+colliderInterSection.height/2
//			);*/
//			Vector2f forwardVector = Vector2f(0, 1);
//			float angle = MyMath::angle(normal, forwardVector);
//			Vector2f x = normal * cos(angle);
//			Vector2f y = normal * sin(angle);
//			
//			transform->getPosition().x += x.x;
//			transform->getPosition().y += y.y;
//			
//			
//			collisionOut.collidedGameObject = colliderComponent->getThisComponentGameObject();
//			collisionOut.isColliding = true;
//		}
//
//	}
//
//}

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

		if (thisGameObjectColliderBound.intersects(otherGameObjectBound, colliderInterSection))
		{

			Vector2f normal = transform->getPosition() - Vector2f(otherGameObjectBound.left + otherGameObjectBound.width / 2, otherGameObjectBound.top + otherGameObjectBound.height / 2);
			normal = MyMath::normalize(normal);


			transform->getPosition() += normal;




			collisionOut.collidedGameObject = colliderComponent->getThisComponentGameObject();
			collisionOut.isColliding = true;
		}

	}

}

