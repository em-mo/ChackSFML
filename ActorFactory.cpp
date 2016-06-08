#include "ActorFactory.h"
#include "Actor.h"
#include <SFML\Graphics\CircleShape.hpp>

ActorFactory::ActorFactory()
{
}

ActorFactory::~ActorFactory()
{
}

Actor ActorFactory::blob() {
	const float RADIUS = 20;
	return Actor(sf::Vector2f(0, 0), sf::Vector2f(-RADIUS, -RADIUS),
		new sf::CircleShape(RADIUS));
}