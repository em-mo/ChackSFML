#include "Actor.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

Actor::Actor(sf::Vector2f p, sf::Vector2f o, sf::Shape * s)
	: position(p), drawOffset(o), shape(s) {
}

Actor::~Actor() {
}

void Actor::invoke(const sf::Event& e) {
	position.x = static_cast<float>(e.mouseMove.x);
	position.y = static_cast<float>(e.mouseMove.y);
}

sf::Rect<float> Actor::getBoundingBox() {
	return shape->getGlobalBounds();
}

void Actor::update(const sf::Event& event) {
}

void Actor::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	shape->setFillColor(sf::Color::Green);
	shape->setPosition(position + drawOffset);
	target.draw(*shape, states);
}