#include "TransformComponent.h"
#include<SFML/Graphics.hpp>

TransformComponent::TransformComponent(shared_ptr< GameObject> gameObject)
{
	this->gameObject = gameObject;
}

void TransformComponent::update(float dtAsSecond)
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		xPos = xPos - dtAsSecond * 100;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		xPos = xPos + dtAsSecond*100;
	}

}

String& TransformComponent::getSpecific_Tag()
{
	return specific_Tag;
}

float& TransformComponent::getXPosition()
{
	return xPos;
}

float& TransformComponent::getYPosition()
{
	return yPos;
}

