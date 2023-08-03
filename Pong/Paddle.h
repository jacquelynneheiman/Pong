#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Paddle
{
private:
	const float m_DefaultSpeed = 100.0f;

	float m_Height;
	float m_Width;
	float m_Speed;

	float m_TopBounds;
	float m_BottomBounds;
	
	RectangleShape m_Shape;
	Vector2f m_Position;
	Color m_color;

	Keyboard::Key m_UpKey;
	Keyboard::Key m_DownKey;

	Vector2f GetOrigin();

public:
	Paddle(float width, float height, float speed, Color color, Vector2f position, Keyboard::Key upKey, Keyboard::Key downKey);
	void Update(float deltaTime);
	void SetPosition(float x, float y);
	void SetPosition(Vector2f position);
	RectangleShape GetShape();
};

