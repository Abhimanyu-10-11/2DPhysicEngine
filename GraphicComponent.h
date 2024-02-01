#pragma once
#include"Component.h"

class GraphicComponent: public Component
{
public:
	string specific_Tag = "GraphicComponent";
	virtual void draw(RenderWindow&) = 0;
	virtual unsigned int getXTextureSize() = 0;
	virtual unsigned int getYTextureSize() = 0;
	virtual void assignSprite(string name) = 0;
	virtual string& getSpecific_Tag()
	{
		return specific_Tag;
	}
};

