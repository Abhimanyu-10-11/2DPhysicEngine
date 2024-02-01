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
	string Specific_Tag = "ColliderComponent";
	bool isColliderActive;
	virtual FloatRect getColliderBound() = 0;
	virtual shared_ptr<GameObject> getThisComponentGameObject()=0;
	string& getSpecific_Tag()
	{
		return Specific_Tag;
	}
	virtual bool getIsColliderActive() = 0;
//	ColliderComponent(shared_ptr<GameObject> gameObject);
//	void start();
//	void update(float dtAsSecond);
//	void draw(RenderWindow& window);

};

