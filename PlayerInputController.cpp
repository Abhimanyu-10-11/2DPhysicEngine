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
	if (rB == NULL)
		rB = static_pointer_cast<RigidbodyComponent>
		(gameObject->findComponentWithSpecificTag("RigidbodyComponent"));

	rB->setGravity(0);
	transform->setXPosition(0);
	transform->setYPosition(200); 
	
}

void PlayerInputController::start()
{
	

}

void PlayerInputController::update(float dtAsSecond)
{
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		transform->getXPosition() += 100 * dtAsSecond;
		
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		transform->getXPosition() -= 100 * dtAsSecond;
		
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		transform->getYPosition() -= 100 * dtAsSecond;
		
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		transform->getYPosition() += 100 * dtAsSecond;
		
	}

	if (rB->getCollisionOut().isColliding)
	{
		rB->setGravity(0);
		std::cout << "run ";
	}

}

string& PlayerInputController::getSpecific_Tag()
{
	return specific_Tag;
}
