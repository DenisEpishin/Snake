#include <SFML/Graphics.hpp>

#include <random>
#include <memory>

#include "GameScreen.h"
#include "GameOverScreen.h"
#include "MenuScreen.h"
#include "NextLevelScreen.h"
#include "Game.h"

using namespace sfSnake;

GameScreen::GameScreen(int l) : snake_()
{
	fon_.loadFromFile("grass.jpg");
	background_.setTexture(fon_);

	font_.loadFromFile("Fonts/game_over.ttf");
	timerText_.setFont(font_);
	pointsText_.setFont(font_);
	levelText_.setFont(font_);
	timer = 910;
	level = l;
	poinstowin = l;
	if (l == 1) speed = 5;
	else if (l == 2) speed = 4;
	else if (l == 3) speed = 3;
	else if (l == 4) speed = 2;
	else speed = 1;

}
	

void GameScreen::handleInput(sf::RenderWindow& window)
{
	snake_.handleInput();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		Game::Screen = std::make_shared<MenuScreen>();
}

void GameScreen::update(sf::Time delta)
{
	if (fruit_.size() == 0)
		generateFruit();
	
	int speed_koef = timer % speed;
	if (speed_koef == 0) {
		snake_.update(delta);
	}
	snake_.checkFruitCollisions(fruit_);
	timer--;
	seconds = timer / 30;

	if (snake_.hitSelf() || timer<0)
		Game::Screen = std::make_shared<GameOverScreen>(snake_.getSize() - 5 + (level - 1) * 10);
	else if (snake_.getSize() - 5 >= poinstowin)
		Game::Screen = std::make_shared<NextLevelScreen>(level + 1);
}

void GameScreen::render(sf::RenderWindow& window)
{
	window.draw(background_);

	levelText_.setString(
		"Level " + std::to_string(level)
	);
	timerText_.setString(
		"\n\nTIME LEFT " + std::to_string(seconds)
	);
	pointsText_.setString(
		"\n\n\n\nPOINTS " + std::to_string(snake_.getSize()-5) + "/" + std::to_string(poinstowin)
	);
	window.draw(levelText_);
	window.draw(timerText_);
	window.draw(pointsText_);

	snake_.render(window);

	for (auto fruit : fruit_)
		fruit.render(window);
}

void GameScreen::generateFruit()
{
	static std::default_random_engine engine;
	engine.seed(time(NULL));
	static std::uniform_int_distribution<int> xDistribution(0, Game::Width - SnakeNode::Width);
	static std::uniform_int_distribution<int> yDistribution(1, Game::Height - SnakeNode::Height);

	fruit_.push_back(Fruit(sf::Vector2f(xDistribution(engine), yDistribution(engine))));
}

