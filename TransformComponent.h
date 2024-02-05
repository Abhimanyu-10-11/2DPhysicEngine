#pragma once
#include"Component.h"
#include"GameObject.h"

class TransformComponent : public Component
{
private:
	shared_ptr<GameObject> gameObject;
	const float XSCALE = 1;
	const float YSCALE = 1;
	Vector2f position;
	float rotation = 0;
	float rotateValue = 0;
	Vector2f scale = Vector2f(XSCALE,YSCALE);
public:
	string specific_Tag = "TransformComponent";
		TransformComponent() {}
	TransformComponent(shared_ptr<GameObject> gameObject);
	void awake(){}
	void start(){}
	void update(float dtAsSecond);
	shared_ptr<GameObject> getThisComponentGameObject();
	string& getSpecific_Tag();
	//position
	Vector2f& getPosition();
	void setPosition(Vector2f position);
	void setPosition(float x, float y);
	//scale
	Vector2f& getScale();
	void setScale(Vector2f scale);
	void setScale(float x, float y);
	//rotation
	void setRotation(float rotation);
	float& getRotation();
	void rotate(float value);

	


};

