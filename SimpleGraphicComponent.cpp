#include"SimpleGraphicComponent.h"
#include<iostream>

SimpleGraphicComponent::SimpleGraphicComponent(shared_ptr<GameObject> gameObject)
{
	String tex = "graphics/player.png";
	if (!texture.loadFromFile(tex))
	{
		std::cout << "Unable to load Texture";
	}

	this->gameObject = gameObject;	
}

void SimpleGraphicComponent::update(float)
{
	if(gameObjectTransformComponent == NULL)
		gameObjectTransformComponent =
		static_pointer_cast<TransformComponent>
		(gameObject->findComponentWithSpecificTag("transform"));

	sprite.setTexture(texture);
	if (gameObjectTransformComponent != NULL)
	{
		float x = gameObjectTransformComponent
			->getXPosition();
		float y = gameObjectTransformComponent
			->getYPosition();
		sprite.setPosition(x, y);
	}
}

void SimpleGraphicComponent::draw(RenderWindow& window)
{	
	window.draw(sprite);
}

String& SimpleGraphicComponent::getSpecific_Tag()
{
	return specific_Tag;
}
