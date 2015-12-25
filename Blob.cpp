#include "Blob.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

Blob::Blob()
{
}

Blob::Blob(sf::Vector2f p)
	: position(p)
{
}

Blob::~Blob()
{
}

void Blob::update(const sf::Event& event) {
	position.x = event.mouseMove.x;
	position.y = event.mouseMove.y;
}

void Blob::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	const float RADIUS = 40;
	const sf::Vector2f centerOffset(-RADIUS, -RADIUS);
	sf::CircleShape shape(RADIUS);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(position + centerOffset);
	target.draw(shape, states);
}