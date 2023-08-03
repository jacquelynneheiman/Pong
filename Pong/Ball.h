#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
	RectangleShape m_Shape;

	float m_Width;
	float m_Height;
	float m_Speed;
	
	Color m_Color;

	bool m_isInPlay;

public:
	Ball(float width, float height, float speed, Color color, Vector2f position);
	void Update(float deltaTime);
	void Drop();
	void SetPosition(float x, float y);
	void SetPosition(Vector2f position);
	RectangleShape GetShape();
};

