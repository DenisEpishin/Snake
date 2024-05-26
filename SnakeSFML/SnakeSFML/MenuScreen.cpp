#include <SFML/Graphics.hpp>

#include <memory>

#include "GameScreen.h"
#include "MenuScreen.h"
#include "AboutScreen.h"
#include "Game.h"

using namespace sfSnake;

MenuScreen::MenuScreen()
{
	font_.loadFromFile("Fonts/game_over.ttf");
	text_.setFont(font_);
	text_.setString(
		"\n\n\n\n\n\n\n\n\nPress [SPACE] to play"
		"\n\nPress [F1] to about info"
		"\n\nPress [ESC] to quit"
	);

	snakeText_.setFont(font_);
	snakeText_.setString("Snake!");
	snakeText_.setFillColor(sf::Color::Green);
	snakeText_.setCharacterSize(64);
	snakeText_.setStyle(sf::Text::Bold);

	fon_.loadFromFile("grass.jpg");
	background_.setTexture(fon_);

	sf::FloatRect textBounds = text_.getLocalBounds();
	text_.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2);
	text_.setPosition(Game::Width / 2, Game::Height / 2);

	sf::FloatRect snakeTextBounds = snakeText_.getLocalBounds();
	snakeText_.setOrigin(snakeTextBounds.left + snakeTextBounds.width / 2,
		snakeTextBounds.top + snakeTextBounds.height / 2);
	snakeText_.setPosition(Game::Width / 2, Game::Height / 4);
}

void MenuScreen::handleInput(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		Game::Screen = std::make_shared<GameScreen>(1);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
		Game::Screen = std::make_shared<AboutScreen>(snake_.getSize());
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();
}

void MenuScreen::update(sf::Time delta)
{
	static bool movingLeft = false;
	static bool movingRight = true;
	snake_.randMove();

	if (movingRight)
	{
		snakeText_.rotate(delta.asSeconds());

		if (static_cast<int>(snakeText_.getRotation()) == 10)
		{
			movingRight = false;
			movingLeft = true;
		}
	}

	if (movingLeft)
	{
		snakeText_.rotate(-delta.asSeconds());

		if (static_cast<int>(snakeText_.getRotation()) == (360 - 10))
		{
			movingLeft = false;
			movingRight = true;
		}
	}
}

void MenuScreen::render(sf::RenderWindow& window)
{
	window.draw(background_);


	snake_.render(window);
	window.draw(text_);
	window.draw(snakeText_);


}