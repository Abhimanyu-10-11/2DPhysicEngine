#include "RigidbodyComponent.h"

RigidbodyComponent::RigidbodyComponent(shared_ptr<GameObject> gameObject)
{
	this->gameObject = gameObject;
}

void RigidbodyComponent::update(float dtAsSecond)
{
	if (gameObjectTransformComponent == NULL)
		gameObjectTransformComponent =
		static_pointer_cast<TransformComponent>
		(gameObject->findComponentWithSpecificTag("transform"));

	if (gameObjectTransformComponent != NULL)
	{

		gameObjectTransformComponent->getYPosition() += GRAVITY *dtAsSecond;
	}
}

String& RigidbodyComponent::getSpecific_Tag()
{
	return specific_Tag;
}
