#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>

#include "Screen.h"
#include "Snake.h"
#include "Fruit.h"

namespace sfSnake
{
class GameScreen : public Screen
{
public:
	GameScreen(int level);

	void handleInput(sf::RenderWindow& window) override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

	void generateFruit();

private:
	Snake snake_;
	std::vector<Fruit> fruit_;
	sf::Texture fon_;
	sf::Sprite background_;
	sf::Font font_;
	sf::Text levelText_;
	sf::Text pointsText_;
	sf::Text timerText_;
	int timer;
	int seconds;
	int level;
	int poinstowin;
	int speed;
};
}

#endif