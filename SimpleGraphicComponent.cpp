#include"SimpleGraphicComponent.h"
#include<iostream>


SimpleGraphicComponent::SimpleGraphicComponent(shared_ptr<GameObject> gameObject)
{
	this->gameObject = gameObject;	
}

void SimpleGraphicComponent::awake()
{
	if (transform == NULL)
		transform =
		gameObject->getComponentOfType<TransformComponent>();
	else
		std::cout << "SimpleGraphicComponent loading transfom component failed";



}


void SimpleGraphicComponent::start()
{
	
	sprite.setTexture(texture);
	sprite.setScale(transform->getScale());

}

void SimpleGraphicComponent::update(float)
{
	
	if (transform != NULL)
	{

		spriteRotation = transform->getRotation();
		sprite.setRotation(spriteRotation);
		sprite.setPosition(transform->getPosition());
	}
}

void SimpleGraphicComponent::draw(RenderWindow& window)
{	
	window.draw(sprite);
}

void SimpleGraphicComponent::assignSprite(string name)
{
	String tex = "graphics/"+name;
	if (!texture.loadFromFile(tex))
	{
		std::cout << "Unable to load Texture";
	}
	xTextrueSize = texture.getSize().x;
	yTextureSize = texture.getSize().y;
	sprite.setOrigin(xTextrueSize / 2, yTextureSize / 2);
	sprite.setTexture(texture);


}

shared_ptr<GameObject> SimpleGraphicComponent::getThisComponentGameObject()
{
	return gameObject;
}

unsigned int SimpleGraphicComponent::getXTextureSize()
{
	return xTextrueSize;
}

unsigned int SimpleGraphicComponent::getYTextureSize()
{
	return yTextureSize;
}


