#include "Paddle.h"

using namespace sf;

Paddle::Paddle(float width, float height, float speed, Color color, Vector2f position, Keyboard::Key upKey, Keyboard::Key downKey)
{
	m_Width = width;
	m_Height = height;
	m_Position = position;

	Vector2f paddleSize(m_Width, m_Height);
	Vector2f origin = GetOrigin();

	m_Shape.setSize(paddleSize);
	m_Shape.setOrigin(origin);
	m_Shape.setPosition(position);

	if (speed > 0)
	{
		m_Speed = speed;
	}
	else
	{
		m_Speed = m_DefaultSpeed;
	}

	m_color = color;

	m_TopBounds = 0 ;
	m_BottomBounds = 1080 - paddleSize.y;

	m_UpKey = upKey;
	m_DownKey = downKey;
}
void Paddle::Update(float deltaTime)
{
	if (Keyboard::isKeyPressed(m_UpKey))
	{
		m_Position.y -= m_Speed * deltaTime;

		if (m_Position.y < m_TopBounds)
		{
			m_Position.y = m_TopBounds;
		}
	}

	if (Keyboard::isKeyPressed(m_DownKey))
	{
		m_Position.y += m_Speed * deltaTime;

		if (m_Position.y > m_BottomBounds)
		{
			m_Position.y = m_BottomBounds;
		}
	}

	m_Shape.setPosition(m_Position);
}

Vector2f Paddle::GetOrigin()
{
	Vector2f origin;

	origin.x = m_Shape.getLocalBounds().width / 2;
	origin.y = m_Shape.getLocalBounds().height / 2;

	return origin;
}

RectangleShape Paddle::GetShape()
{
	return m_Shape;
}

void Paddle::SetPosition(float x, float y)
{
	m_Position = Vector2f(x, y);
	m_Shape.setPosition(m_Position);
}

void Paddle::SetPosition(Vector2f position)
{
	m_Position = position;
	m_Shape.setPosition(m_Position);
}