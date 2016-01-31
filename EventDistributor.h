#pragma once
#include <vector>
#include <SFML/Window/Event.hpp>
class EventUser {
public:
	virtual void invoke(const sf::Event& e) = 0;
};

class EventDistributor {
public:
	EventDistributor() {};
	void registerUser(EventUser& user);
	void distribute(const sf::Event& e);
private:
	std::vector<EventUser*> users;
};