#pragma once
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Shape.hpp>
#include "EventDistributor.h"
#include "Collidable.h"
#include <memory>

class Actor : public sf::Drawable, public EventUser, public Collidable
{
public:
	Actor() = delete;
	Actor(Actor&& other) = default;
	Actor(sf::Vector2f p, sf::Vector2f o, sf::Shape * s);
	~Actor();

	void update(const sf::Event& event);
	virtual void Actor::draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void invoke(const sf::Event& e);

	// Inherited via Collidable
	virtual sf::Rect<float> getBoundingBox() override;
private:
	sf::Vector2f position;
	sf::Vector2f drawOffset;
	std::unique_ptr<sf::Shape> shape;
};