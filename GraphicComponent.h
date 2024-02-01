#pragma once
#include"Component.h"

class GraphicComponent: public Component
{
	string tag = "GraphicComponent";
public:
	virtual void draw(RenderWindow&) = 0;
};

