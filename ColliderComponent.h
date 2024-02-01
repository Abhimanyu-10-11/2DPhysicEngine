#pragma once
#include"Component.h"

class ColliderComponent : public Component
{
public:
	string Specific_Tag = "ColliderComponent";
	bool isColliderActive = true;
	virtual void draw(RenderWindow&) = 0;
	virtual FloatRect getColliderBound() = 0;
	string& getSpecific_Tag()
	{
		return Specific_Tag;
	}
	virtual bool getIsColliderActive() = 0;
	virtual void setMakeColliderVisualVisable(bool) = 0;


};

