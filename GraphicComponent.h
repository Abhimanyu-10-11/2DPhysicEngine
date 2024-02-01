#pragma once
#include"Component.h"
class GameObject;

class GraphicComponent: public Component
{
public:
	string specific_Tag = "GraphicComponent";
	virtual void draw(RenderWindow&) = 0;
	virtual shared_ptr<GameObject> getThisComponentGameObject() = 0;
	virtual unsigned int getXTextureSize() = 0;
	virtual unsigned int getYTextureSize() = 0;
	virtual string& getSpecific_Tag()
	{
		return specific_Tag;
	}
};

