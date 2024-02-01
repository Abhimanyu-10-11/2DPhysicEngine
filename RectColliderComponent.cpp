#include "RectColliderComponent.h"


RectColliderComponent::RectColliderComponent(shared_ptr<GameObject> gameObject)
{
	this->gameObject = gameObject;
}
void RectColliderComponent::awake()
{
	if (transform == NULL)
		transform =
		static_pointer_cast<TransformComponent>
		(gameObject->findComponentWithSpecificTag("TransformComponent"));

}

void RectColliderComponent::start()
{

		SettingColliderVisual();

}

void RectColliderComponent::SettingColliderVisual()
{
	int colliderBoundry = 5;
	rect.setSize(Vector2f(
		transform->getXTextureSize() + colliderBoundry,
		transform->getYTextureSize() + colliderBoundry));
	rect.setScale(Vector2f(transform->getXScale(),
		transform->getYScale()));
	rect.setFillColor(Color::Green);
	rect.setPosition(transform->getXPosition(),
		transform->getYPosition());
	
	
	//rectInvisiable
	//rectInvisiable.setSize(Vector2f(
	//	transform->getXTextureSize(),
	//	transform->getYTextureSize()));
	//rectInvisiable.setScale(Vector2f(
	//	transform->getXScale(),
	//	transform->getYScale()));
	//rectInvisiable.setFillColor(Color::Black);

}



void RectColliderComponent::update(float dtAsSecond)
{
	thisGameObjectBound = rect.getGlobalBounds();

	if (!makeColliderVisualVisable)
		return;

	if (transform != NULL)
	{
		rect.setPosition(transform->getXPosition(), 
			transform->getYPosition());
		/*rectInvisiable.setPosition(transform->getXPosition(),
			transform->getYPosition());*/

	}
}

void RectColliderComponent::draw(RenderWindow& window)
{
	if (!makeColliderVisualVisable)
		return;

	//window.draw(rectInvisiable);
	window.draw(rect);
	
}


FloatRect RectColliderComponent::getColliderBound()
{
	return thisGameObjectBound;
}

bool RectColliderComponent::getIsColliderActive()
{
	return isColliderActive;
}

shared_ptr<GameObject> RectColliderComponent::getThisComponentGameObject()
{
	return gameObject;
}


