#pragma once
#include"Component.h"
#include"GameObject.h"

class TransformComponent : public Component
{
private:
	shared_ptr<GameObject> gameObject;
	const float XSCALE = 1;
	const float YSCALE = 1;
	float xPos = 0;
	float yPos = 0;
	float rotation = 0;
	float xScale = XSCALE;
	float yScale = YSCALE;
public:
	string specific_Tag = "TransformComponent";
	TransformComponent(shared_ptr<GameObject> gameObject);
	void awake();
	void start();
	void update(float dtAsSecond);
	string& getSpecific_Tag();
	//position
	float& getXPosition();
	void setXPosition(float xPos);
	float& getYPosition();
	void setYPosition(float yPos);
	//scale
	float getXScale();
	void setXScale(float xPos);
	float getYScale();
	void setYScale(float yPos);

	


};

