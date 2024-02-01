#pragma once
#include"ColliderComponent.h"
#include"GameObject.h"
#include"TransformComponent.h"
#include"RigidbodyComponent.h"


class RectColliderComponent : public ColliderComponent///check this inheritance
{
private:
	shared_ptr<GameObject> gameObject;
	shared_ptr<TransformComponent> transform;

	FloatRect thisGameObjectBound;
	RectangleShape rect;
	//RectangleShape rectInvisiable;
	string componentName = "Rect"+ Specific_Tag;
	bool makeColliderVisualVisable = true;
	
public:
	RectColliderComponent(shared_ptr<GameObject> gameObject);
	void awake();
	void start();
	void SettingColliderVisual();
	void update(float dtAsSecond);
	void draw(RenderWindow& window); 
	FloatRect getColliderBound();
	bool getIsColliderActive();
	shared_ptr<GameObject> getThisComponentGameObject();

};

