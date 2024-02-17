#include "PlayerInputController.h"


PlayerInputController::PlayerInputController(shared_ptr<GameObject> gameObject)
{
	this->gameObject = gameObject;
}

void PlayerInputController::awake()
{
	if (transform == NULL)
		transform = static_pointer_cast<TransformComponent>
		(gameObject->findComponentWithSpecificTag("TransformComponent"));
	else
		std::cout << "unable to laod TransFormComponent in PlayerInputController.cpp";

	if (rB == NULL)
		rB = static_pointer_cast<RigidbodyComponent>
		(gameObject->findComponentWithSpecificTag("RigidbodyComponent"));
	else
		std::cout << "unable to laod RigidbodyComponent in PlayerInputController.cpp";

	
	transform->setPosition(0,-50);
	
	
	
}

void PlayerInputController::start()
{
	

}

void PlayerInputController::update(float dtAsSecond)
{
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		transform->getPosition().x += speed * dtAsSecond;
		
		
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		transform->getPosition().x -= speed * dtAsSecond;		
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		transform->getPosition().y -= speed * dtAsSecond;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		transform->getPosition().y += speed * dtAsSecond;	
	}
	

	transform->rotate(0);
	if (Keyboard::isKeyPressed(Keyboard::E))
	{
		transform->rotate(50);
	}
	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		transform->rotate(-50);
	}



			
	if (Keyboard::isKeyPressed(Keyboard::F))
	{
		rB->setVelocity(100, -200);
	}


}

shared_ptr<GameObject> PlayerInputController::getThisComponentGameObject()
{
	return gameObject;
}

string& PlayerInputController::getSpecific_Tag()
{
	return specific_Tag;
}
