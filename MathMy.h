#pragma once
#include<SFML/Graphics.hpp>
#include<cmath>
#include<iostream>

class MyMath
{

public:
	static sf::Vector2f normalize(sf::Vector2f vector)
	{
		int magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);
		return sf::Vector2f(vector.x /= magnitude,
			vector.y /= magnitude);

	}
	static float getMagnitude(sf::Vector2f vector)
	{
		int magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);
		return magnitude;

	}
	static float angle(sf::Vector2f vect_A, sf::Vector2f vect_B)
	{

		int angle = 0;
		float magA = getMagnitude(vect_A);
		float magB = getMagnitude(vect_B);
		float A_B = vect_A.x * vect_B.x + vect_A.y * vect_B.y;

		angle = A_B / magA * magB;
	
		return angle;
	}
	

};
