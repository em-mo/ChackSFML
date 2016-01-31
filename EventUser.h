#pragma once
#include <vector>
#include <SFML/Window/Event.hpp>
class EventUser {
public:
	virtual void invoke(const sf::Event& e) = 0;
};

class EventDistributor {
public:
	EventDistributor(sf::Event::EventType type) : handledType(type) {}
	void registerUser(EventUser* user);
	void distribute(const sf::Event& e);
private:
	sf::Event::EventType handledType;
	std::vector<EventUser*> users;
};