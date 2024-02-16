#include "CircleColliderComponent.h"
CircleColliderComponent::CircleColliderComponent(shared_ptr<GameObject> gameObject)
{
	this->gameObject = gameObject;
}

void CircleColliderComponent::awake()
{
	if (transform == NULL)
		transform = gameObject->getComponentOfType<TransformComponent>();
	else
		std::cout << "unable to load TransfomComponent in CircleColliderComponent.cpp";

	if (gameObjectSimpleGraphicComponent == NULL)
		gameObjectSimpleGraphicComponent =
		gameObject->getComponentOfType
		<SimpleGraphicComponent>();
	else
		std::cout << "unable to load GraphicComponent in CircleColliderComponent.cpp";
}

void CircleColliderComponent::start()
{
	SettingColliderVisual();
}

void CircleColliderComponent::SettingColliderVisual()
{
	float circleRadius = gameObjectSimpleGraphicComponent->getXTextureSize()/2;
	circle.setRadius(circleRadius);
	circle.setFillColor(Color(0,0,1,0));
	circle.setOutlineThickness(5);
	circle.setOutlineColor(Color::Green);
	circle.setScale(transform->getScale());
	circle.setOrigin(circleRadius , circleRadius );
	circle.setPosition(transform->getPosition());
}

void CircleColliderComponent::update(float dtAsSecond)
{
	if (!isColliderActive)
		return;
	circle.setPosition(transform->getPosition());
}

void CircleColliderComponent::draw(RenderWindow& window)
{
	if (!makeColliderVisualVisable)
		return;

	window.draw(circle);
}

FloatRect CircleColliderComponent::getColliderBound()
{
	thisGameObjectBound = circle.getGlobalBounds();
	return thisGameObjectBound;
}

bool CircleColliderComponent::getIsColliderActive()
{
	return isColliderActive;
}

void CircleColliderComponent::setIsColliderActive(bool active)
{
	this->isColliderActive = active;
}

void CircleColliderComponent::setMakeColliderVisualVisable(bool visable)
{
	this->makeColliderVisualVisable = visable;
}

shared_ptr<GameObject> CircleColliderComponent::getThisComponentGameObject()
{
	return gameObject;
}
