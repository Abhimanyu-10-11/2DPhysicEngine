#include "RectColliderComponent.h"


RectColliderComponent::RectColliderComponent(shared_ptr<GameObject> gameObject)
{
	this->gameObject = gameObject;
}
void RectColliderComponent::awake()
{
	if (gameObjecctTransform == NULL)
		gameObjecctTransform = gameObject->getComponentOfType<TransformComponent>();
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
	int collider_Boundry = 2;
	float x_TextureSize = 
		gameObjectGraphicComponent->getXTextureSize()+collider_Boundry;
	float y_TextrueSize =
		gameObjectGraphicComponent->getYTextureSize()+collider_Boundry;
	rect.setSize(Vector2f(x_TextureSize, y_TextrueSize));
	rect.setOrigin(x_TextureSize /2, y_TextrueSize /2);
	rect.setScale(Vector2f(
		gameObjecctTransform->getXScale(),
		gameObjecctTransform->getYScale()));
	rect.setFillColor(Color::Green);
	rect.setPosition(gameObjecctTransform->getXPosition(),
		gameObjecctTransform->getYPosition());
	

}



void RectColliderComponent::update(float dtAsSecond)
{

	if (!makeColliderVisualVisable)
		return;

	if (gameObjecctTransform != NULL)
	{
		rect.setPosition(
			gameObjecctTransform->getXPosition(), 
			gameObjecctTransform->getYPosition());

	}
}

void RectColliderComponent::draw(RenderWindow& window)
{
	if (!makeColliderVisualVisable)
		return;

	window.draw(rect);
	
}

FloatRect RectColliderComponent::getColliderBound()
{
	thisGameObjectBound = rect.getGlobalBounds();
	return thisGameObjectBound;
}

bool RectColliderComponent::getIsColliderActive()
{
	return isColliderActive;
}

void RectColliderComponent::setMakeColliderVisualVisable(bool visable)
{
	this->makeColliderVisualVisable = visable;
}

shared_ptr<GameObject> RectColliderComponent::getThisComponentGameObject()
{
	return gameObject;
}


