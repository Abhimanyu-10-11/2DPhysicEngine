#include "RectColliderComponent.h"


RectColliderComponent::RectColliderComponent(shared_ptr<GameObject> gameObject)
{
	this->gameObject = gameObject;
}
void RectColliderComponent::awake()
{
	if (transform == NULL)
		transform = gameObject->getComponentOfType<TransformComponent>();
	else
		std::cout << "unable to load TransfomComponent in RectColliderComponent.cpp";

	if (gameObjectSimpleGraphicComponent == NULL)
		gameObjectSimpleGraphicComponent =
				gameObject->getComponentOfType
					<SimpleGraphicComponent>();
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
		gameObjectSimpleGraphicComponent->getXTextureSize()+collider_Boundry;
	float y_TextrueSize =
		gameObjectSimpleGraphicComponent->getYTextureSize()+collider_Boundry;
	rect.setSize(Vector2f(x_TextureSize, y_TextrueSize));
	rect.setOrigin(x_TextureSize /2, y_TextrueSize /2);
	rect.setScale(transform->getScale());
	rect.setFillColor(Color(0,0,1,0));
	rect.setOutlineThickness(5.0f);
	rect.setOutlineColor(Color::Green);
	rect.setPosition(transform->getPosition());
}



void RectColliderComponent::update(float dtAsSecond)
{

	if (!isColliderActive)
		return;

	
	rect.setPosition(transform->getPosition());
	rect.setRotation(transform->getRotation());
	
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

void RectColliderComponent::setIsColliderActive(bool active)
{
	this->isColliderActive = active;
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


