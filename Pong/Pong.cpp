#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
#include <string>

using namespace sf;
using namespace std;   

void HandleInput();
void Update();
void Render();

const Vector2f resolution(1920, 1080);

VideoMode vm(1920, 1080);
RenderWindow gameWindow(vm, "Pong", Style::Fullscreen);

Clock gameClock;

Paddle player1(20, 200, 500, Color::White, Vector2f(30, 540), Keyboard::W, Keyboard::S);
Paddle player2(20, 200, 500, Color::White, Vector2f(1920 - 30, 540), Keyboard::Up, Keyboard::Down);

Ball ball(20, 20, 650, Color::White, Vector2f(960, 540));

Font gameFont;

Text player1ScoreText;
Text player2ScoreText;

int player1Score;
int player2Score;

RectangleShape screenDivider;

bool isGameStarted = false;
bool isPaused = true;

Text gameTitle;
Text howToPlay;
Text paused;

int main()
{
	gameFont.loadFromFile("Fonts/DS-DIGI.ttf");

	player1ScoreText.setFont(gameFont);
	player1ScoreText.setCharacterSize(50);
	player1ScoreText.setString("Score: 0");
	player1ScoreText.setOrigin(player1ScoreText.getLocalBounds().width / 2, player1ScoreText.getLocalBounds().height / 2);
	player1ScoreText.setPosition((960 / 2), player1ScoreText.getLocalBounds().height * 2);

	player2ScoreText.setFont(gameFont);
	player2ScoreText.setCharacterSize(50);
	player2ScoreText.setString("Score: 0");
	player2ScoreText.setOrigin(player2ScoreText.getLocalBounds().width / 2, player2ScoreText.getLocalBounds().height / 2);
	player2ScoreText.setPosition((960 + (960 / 2)), player2ScoreText.getLocalBounds().height * 2);

	screenDivider.setSize(Vector2f(10, 1020));
	screenDivider.setOrigin(screenDivider.getLocalBounds().width / 2, screenDivider.getLocalBounds().height / 2);
	screenDivider.setFillColor(Color::White);
	screenDivider.setPosition(960, 540);

	gameTitle.setFont(gameFont);
	gameTitle.setCharacterSize(150);
	gameTitle.setString("Pong");
	gameTitle.setOrigin(gameTitle.getLocalBounds().width / 2, gameTitle.getLocalBounds().height / 2);
	gameTitle.setPosition(960, 150);

	howToPlay.setFont(gameFont);
	howToPlay.setCharacterSize(50);
	howToPlay.setString("How to Play:\n\t Player 1 - W / S\n\t Player 2 - Up / Down\n\nUse the paddles to hit the ball.\nIf the ball enters your goal the other player earns a point.\nThe first player to score 5 goals wins the game.\n\nPress Space to Start...");
	howToPlay.setOrigin(howToPlay.getLocalBounds().width / 2, howToPlay.getLocalBounds().height / 2);
	howToPlay.setPosition(960, 600);

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

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		isGameStarted = true;
		isPaused = false;
		
		player1Score = 0;
		player2Score = 0;

		ball.SetPosition(960, 540);
		player1.SetPosition(30, 540);
		player2.SetPosition(1890, 540);
	}

	if (Keyboard::isKeyPressed(Keyboard::Tab))
	{
		isPaused = true;
	}
}

void Update()
{
	float deltaTime = gameClock.restart().asSeconds();

	if (!isPaused)
	{
		player1.Update(deltaTime);
		player2.Update(deltaTime);

		ball.Update(deltaTime);
	}

	player1ScoreText.setString("Score: " + to_string(player1Score));
	player2ScoreText.setString("Score: " + to_string(player2Score));
}

void Render()
{
	gameWindow.clear();

	if (!isPaused && isGameStarted)
	{
		//gameWindow.draw(screenDivider);

		gameWindow.draw(player1ScoreText);
		gameWindow.draw(player2ScoreText);

		gameWindow.draw(ball.GetShape());
	}
	else if (isPaused && isGameStarted)
	{
		gameWindow.draw(paused);
	}

	if (!isGameStarted && isPaused)
	{
		gameWindow.draw(gameTitle);
		gameWindow.draw(howToPlay);
	}
	
	gameWindow.draw(player1.GetShape());
	gameWindow.draw(player2.GetShape());

	gameWindow.display();
}