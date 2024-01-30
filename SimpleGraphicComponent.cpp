#include"SimpleGraphicComponent.h"
#include<iostream>


SimpleGraphicComponent::SimpleGraphicComponent(shared_ptr<GameObject> gameObject)
{
	String tex = "graphics/player.png";
	if (!texture.loadFromFile(tex))
	{
		std::cout << "Unable to load Texture";
	}
	sprite.setTexture(texture);

	this->gameObject = gameObject;	
}

void SimpleGraphicComponent::start()
{
	if (gameObjectTransformComponent == NULL)
		gameObjectTransformComponent =
		static_pointer_cast<TransformComponent>
		(gameObject->findComponentWithSpecificTag("transform"));
}

void SimpleGraphicComponent::update(float)
{
	

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

void SimpleGraphicComponent::assignSprite(string name)
{
	String tex = "graphics/"+name;
	if (!texture.loadFromFile(tex))
	{
		std::cout << "Unable to load Texture";
	}
	sprite.setTexture(texture);
}


