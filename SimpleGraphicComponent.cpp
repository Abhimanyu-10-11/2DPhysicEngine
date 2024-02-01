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


	//gameObjectTransformComponent->setXTextureSize(texture.getSize().x);
	//gameObjectTransformComponent->setYTextureSize(texture.getSize().y);

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
		xSpritePos = gameObjectTransformComponent
			->getXPosition();
		ySpritePos = gameObjectTransformComponent
			->getYPosition();
		spriteRotation = gameObjectTransformComponent->getRotation();
		sprite.setRotation(spriteRotation);
		sprite.setPosition(xSpritePos, ySpritePos);
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


