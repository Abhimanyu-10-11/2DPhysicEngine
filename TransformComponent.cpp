#include "TransformComponent.h"
#include<SFML/Graphics.hpp>

TransformComponent::TransformComponent(shared_ptr< GameObject> gameObject)
{

	this->gameObject = gameObject;
}


void TransformComponent::update(float dtAsSecond)
{
	this->rotation += rotateValue * dtAsSecond;
}

shared_ptr<GameObject> TransformComponent::getThisComponentGameObject()
{
	return gameObject;
}

string& TransformComponent::getSpecific_Tag()
{
	return specific_Tag;
}

//float& TransformComponent::getXPosition()
//{
//	return xPos;
//}
//
//void TransformComponent::setXPosition(float xPos)
//{
//	this->xPos = xPos;
//}
//
//void TransformComponent::setYPosition(float yPos)
//{
//	this->yPos = yPos;
//}

Vector2f& TransformComponent::getPosition()
{
	return position;
}

void TransformComponent::setPosition(Vector2f position)
{
	this->position = position;
}

void TransformComponent::setPosition(float x, float y)
{
	this->position = Vector2f(x, y);
}

//float& TransformComponent::getYPosition()
//{
//	return yPos;
//}
//
//float TransformComponent::getXScale()
//{
//	return xScale;
//}
//
//void TransformComponent::setXScale(float xSize)
//{
//	this->xScale = xSize;
//}
//
//float TransformComponent::getYScale()
//{
//	return yScale;
//}

//void TransformComponent::setYScale(float ySize)
//{
//	this->yScale = ySize;
//}

Vector2f& TransformComponent::getScale()
{
	return scale;
}

void TransformComponent::setScale(Vector2f scale)
{
	this->scale = scale;
}

void TransformComponent::setScale(float x, float y)
{
	this->scale = Vector2f(x, y);
}

void TransformComponent::setRotation(float rotation)
{
	this->rotation = rotation;
}

float& TransformComponent::getRotation()
{
	return rotation;
}

void TransformComponent::rotate(float value)
{
	this->rotateValue = value;
}




