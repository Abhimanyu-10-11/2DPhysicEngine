#pragma once
#include"Component.h"

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
	virtual bool getIsColliderActive() = 0;
	virtual void setMakeColliderVisualVisable(bool) = 0;


};

