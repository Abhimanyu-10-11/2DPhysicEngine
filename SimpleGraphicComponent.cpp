#include"SimpleGraphicComponent.h"
#include<iostream>


SimpleGraphicComponent::SimpleGraphicComponent(shared_ptr<GameObject> gameObject)
{

	this->gameObject = gameObject;	

	
}

void SimpleGraphicComponent::awake()
{
	if (gameObjectTransformComponent == NULL)
		gameObjectTransformComponent =
		static_pointer_cast<TransformComponent>
		(gameObject->findComponentWithSpecificTag("TransformComponent"));
	else
		std::cout << "SimpleGraphicComponent loading transfom component failed";

	gameObjectTransformComponent->setXTextureSize(texture.getSize().x);
	gameObjectTransformComponent->setYTextureSize(texture.getSize().y);

}

void SimpleGraphicComponent::start()
{

	float x = gameObjectTransformComponent->getXScale();
	float y = gameObjectTransformComponent->getXScale();
	sprite.setTexture(texture);
	sprite.setScale(x, y);

}



void SimpleGraphicComponent::update(float)
{
	
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

string& SimpleGraphicComponent::getSpecific_Tag()
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


