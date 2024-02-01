#include "RectColliderComponent.h"


RectColliderComponent::RectColliderComponent(shared_ptr<GameObject> gameObject)
{
	this->gameObject = gameObject;
}
void RectColliderComponent::awake()
{
	if (gameObjecctTransform == NULL)
		gameObjecctTransform =
		static_pointer_cast<TransformComponent>
		(gameObject->findComponentWithSpecificTag("TransformComponent"));
	else
		std::cout << "unable to load TransfomComponent in RectColliderComponent.cpp";

	if (gameObjectGraphicComponent == NULL)
		gameObjectGraphicComponent = static_pointer_cast<GraphicComponent>(gameObject->findComponentWithSpecificTag("GraphicComponent"));
	else 
		std::cout << "unable to load GraphicComponent in RectColliderComponent.cpp";

}

void RectColliderComponent::start()
{
		SettingColliderVisual();

}

void RectColliderComponent::SettingColliderVisual()
{
	int colliderBoundry = 5;
	unsigned int xTextureSize = 
		gameObjectGraphicComponent->getXTextureSize()+colliderBoundry;
	unsigned int yTextrueSize =
		gameObjectGraphicComponent->getYTextureSize()+colliderBoundry;
	rect.setSize(Vector2f(
		xTextureSize,
		yTextrueSize));
	rect.setOrigin(xTextureSize/2, yTextrueSize/2);
	rect.setScale(Vector2f(gameObjecctTransform->getXScale(),
		gameObjecctTransform->getYScale()));
	rect.setFillColor(Color::Green);
	rect.setPosition(gameObjecctTransform->getXPosition(),
		gameObjecctTransform->getYPosition());
	
	
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

	if (gameObjecctTransform != NULL)
	{
		rect.setPosition(gameObjecctTransform->getXPosition(), 
			gameObjecctTransform->getYPosition());
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


