#pragma once
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Drawable.hpp>
#include "EventUser.h"


class Blob : public sf::Drawable, public EventUser
{
public:
	Blob();
	Blob(sf::Vector2f p);
	~Blob();

	void update(const sf::Event& event);
	virtual void Blob::draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void invoke(const sf::Event& e);
private:
	sf::Vector2f position;
};