#pragma once
#include"GraphicComponent.h"
#include"TransformComponent.h"
#include"GameObject.h"

class ColliderComponent : public GraphicComponent
{

//private:
//	shared_ptr<GameObject> gameObject;
//	shared_ptr<TransformComponent> transform;
//
public:
	string tag = "ColliderComponent";
	virtual FloatRect getColliderBound() = 0;
	virtual shared_ptr<GameObject> getThisComponentGameObject()=0;
	string& getSpecific_Tag()
	{
		return tag;
		std::cout << "something";
	}
//	ColliderComponent(shared_ptr<GameObject> gameObject);
//	void start();
//	void update(float dtAsSecond);
//	void draw(RenderWindow& window);

};

