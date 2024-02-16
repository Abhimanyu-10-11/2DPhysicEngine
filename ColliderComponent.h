#pragma once
#include"Component.h"
struct CollisionOut
{
	std::shared_ptr<GameObject> collidedGameObject;
	bool isColliding = false;
};

enum  CollisionType
{
	Circle,
	Box
};
class ColliderComponent : public Component
{
public:
	
	string Tag = "ColliderComponent";
	bool isColliderActive = true;
	virtual void draw(RenderWindow&) = 0;
	virtual FloatRect getColliderBound() = 0;
	string& getSpecific_Tag()
	{
		return Tag;
	}
	virtual int getCollisionType() = 0;
	virtual float getRadius() { return 0.0f; }
	virtual bool getIsColliderActive() = 0;
	virtual void setMakeColliderVisualVisable(bool) = 0;


};

