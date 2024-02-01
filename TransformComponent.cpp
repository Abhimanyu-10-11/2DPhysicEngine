#include "TransformComponent.h"
#include<SFML/Graphics.hpp>

TransformComponent::TransformComponent(shared_ptr< GameObject> gameObject)
{
	this->gameObject = gameObject;
}

void TransformComponent::awake()
{
}

void TransformComponent::start()
{
	//START
}

void TransformComponent::update(float dtAsSecond)
{
}

string& TransformComponent::getSpecific_Tag()
{
	return specific_Tag;
}

float& TransformComponent::getXPosition()
{
	return xPos;
}

void TransformComponent::setXPosition(float xPos)
{
	this->xPos = xPos;
}

void TransformComponent::setYPosition(float yPos)
{
	this->yPos = yPos;
}

float& TransformComponent::getYPosition()
{
	return yPos;
}

float TransformComponent::getXScale()
{
	return xScale;
}

void TransformComponent::setXScale(float xSize)
{
	this->xScale = xSize;
}

float TransformComponent::getYScale()
{
	return yScale;
}

void TransformComponent::setYScale(float ySize)
{
	this->yScale = ySize;
}




