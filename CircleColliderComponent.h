#pragma once
#include"ColliderComponent.h"
#include"TransformComponent.h"
#include"SimpleGraphicComponent.h"


class CircleColliderComponent : public ColliderComponent
{
private:
	shared_ptr<GameObject> gameObject;
	shared_ptr<TransformComponent> transform;
	shared_ptr<SimpleGraphicComponent> gameObjectSimpleGraphicComponent;
	FloatRect thisGameObjectBound;
	CircleShape circle;
	string componentName = "Circle" + Tag;
	bool makeColliderVisualVisable = true;
public:
	CircleColliderComponent(shared_ptr<GameObject> gameObject);
	void awake();
	void start();
	void SettingColliderVisual();
	//CollisionType CollisionType();
	void update(float dtAsSecond);
	void draw(RenderWindow& window);
	FloatRect getColliderBound();
	void setIsColliderActive(bool active);
	bool getIsColliderActive();
	float getRadius();
	void setMakeColliderVisualVisable(bool visable);
	int getCollisionType();
	shared_ptr<GameObject>
		getThisComponentGameObject();

};

