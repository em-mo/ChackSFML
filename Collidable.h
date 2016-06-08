#pragma once
#include <SFML/Graphics/Rect.hpp>

class Collidable
{
public:
	Collidable();
	~Collidable();

	virtual sf::Rect<float> getBoundingBox() = 0;
};