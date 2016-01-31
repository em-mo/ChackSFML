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

void Blob::invoke(const sf::Event& e) {
	position.x = static_cast<float>(e.mouseMove.x);
	position.y = static_cast<float>(e.mouseMove.y);
}

void Blob::update(const sf::Event& event) {
}

void Blob::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	const float RADIUS = 20;
	const sf::Vector2f centerOffset(-RADIUS, -RADIUS);
	sf::CircleShape shape(RADIUS);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(position + centerOffset);
	target.draw(shape, states);
}