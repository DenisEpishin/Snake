#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>

#include "Game.h"
#include "GameScreen.h"
#include "AboutScreen.h"
#include "MenuScreen.h"

using namespace sfSnake;

AboutScreen::AboutScreen(std::size_t score) : score_(score)
{
	font_.loadFromFile("Fonts/game_over.ttf");
	text_.setFont(font_);
	text_.setString("There is a field on which the game will"
		"\n\ntake place."
		"\n\nFood randomly appears on this field in the form"
		"\n\nof a red circle."

		"\n\nThere is a snake that is controlled using the"
		"\n\narrows on the keyboard."

		"\n\nThe game has a timer and a level system. If "
		"\n\nthe player manages to collect food in 30 seconds,"
		"\n\nthen he goes to the next level, the speed of"
		"\n\nthe snake increases and it is necessary to collect"
		"\n\nmore points."
		"\n\nThe goal of the game is to score the most points."
		"\n\nThe game ends when the snake crashes into a wall"
		"\n\nor itself."


	);
	text_.setFillColor(sf::Color::Red);

	sf::FloatRect textBounds = text_.getLocalBounds();
	text_.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2);
	text_.setPosition(Game::Width / 2, Game::Height / 2);
}

void AboutScreen::handleInput(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		Game::Screen = std::make_shared<MenuScreen>();
}

void AboutScreen::update(sf::Time delta)
{

}

void AboutScreen::render(sf::RenderWindow& window)
{
	window.draw(text_);
}