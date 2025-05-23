#pragma once
#include<SFML/Graphics.hpp>
#include"GameObject.h"
#include"ScriptComponent.h"
#include"TransformComponent.h"
#include"RigidbodyComponent.h"

class PlayerInputController : public ScriptingComponent
{
private:
	shared_ptr<GameObject> gameObject;
	string specific_Tag = "PlayerInputController";
	shared_ptr<TransformComponent> transform;
	shared_ptr<RigidbodyComponent> rB;
	float speed = 200;
public:
	PlayerInputController(shared_ptr<GameObject> gameObject);
	void awake();
	void start();
	void update(float dtAsSecond);
	shared_ptr<GameObject> getThisComponentGameObject();
	string& getSpecific_Tag();
};

