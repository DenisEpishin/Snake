#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>

#include "Game.h"
#include "GameScreen.h"
#include "NextLevelScreen.h"
#include "MenuScreen.h"

using namespace sfSnake;

NextLevelScreen::NextLevelScreen(std::size_t score) : score_(score)
{
	font_.loadFromFile("Fonts/game_over.ttf");
	text_.setFont(font_);
	text2_.setFont(font_);
	text_.setString("LEVEL " + std::to_string(score_)
	);
	text_.setFillColor(sf::Color::Red);
	text2_.setString("\n\nPRESS SPACE TO CONTINUE"
	);

	sf::FloatRect textBounds = text_.getLocalBounds();
	text_.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2);
	text_.setPosition(Game::Width / 2, Game::Height / 2);
	
	textBounds = text2_.getLocalBounds();
	text2_.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2);
	text2_.setPosition(Game::Width / 2, 40+Game::Height / 2);
}

void NextLevelScreen::handleInput(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		Game::Screen = std::make_shared<GameScreen>(score_);
}

void NextLevelScreen::update(sf::Time delta)
{

}

void NextLevelScreen::render(sf::RenderWindow& window)
{
	window.draw(text_);
	window.draw(text2_);
}