#include <SFML/Graphics.hpp>

using namespace sf;

void HandleInput();
void Update();
void Render();

const Vector2f resolution(1920, 1080);

VideoMode vm(1920, 1080);
RenderWindow gameWindow(vm, "Pong", Style::Fullscreen);

int main()
{
	while (gameWindow.isOpen())
	{
		HandleInput();
		Update();
		Render();
	}

	return 0;
}

void HandleInput()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		gameWindow.close();
	}
}

void Update()
{

}

void Render()
{

}