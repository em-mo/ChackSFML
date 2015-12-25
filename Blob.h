#pragma once
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Drawable.hpp>

namespace sf {
	class Event;
}

class Blob : public sf::Drawable
{
public:
	Blob();
	Blob(sf::Vector2f p);
	~Blob();

	void update(const sf::Event& event);
	virtual void Blob::draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Vector2f position;
};