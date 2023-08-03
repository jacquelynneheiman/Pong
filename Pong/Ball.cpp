#include "Ball.h"

Ball::Ball(float width, float height, float speed, Color color, Vector2f position)
{
	m_Width = width;
	m_Height = height;
	m_Speed = speed;
	m_Color = color;

	m_Shape.setSize(Vector2f(m_Width, m_Height));
	m_Shape.setFillColor(m_Color);
	m_Shape.setOrigin(m_Shape.getLocalBounds().width / 2, m_Shape.getLocalBounds().height / 2);
	m_Shape.setPosition(position);
}

void Ball::Update(float deltaTime)
{
	if (m_isInPlay)
	{

	}
}

void Ball::Drop()
{
	m_isInPlay = true;
}

void Ball::SetPosition(float x, float y)
{
	m_Shape.setPosition(x, y);
}

void Ball::SetPosition(Vector2f position)
{
	m_Shape.setPosition(position);
}

RectangleShape Ball::GetShape()
{
	return m_Shape;
}


