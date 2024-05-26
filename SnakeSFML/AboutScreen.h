#ifndef ABOUT_SCREEN_H
#define ABOUT_SCREEN_H

#include <SFML/Graphics.hpp>

#include "Screen.h"

namespace sfSnake
{
class AboutScreen : public Screen
{
public:
	AboutScreen(std::size_t score);

	void handleInput(sf::RenderWindow& window) override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

private:
	sf::Font font_;
	sf::Text text_;
	unsigned score_;

};
}

#endif