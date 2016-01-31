#pragma once
#include "EventDistributor.h"
#include <unordered_map>

class EventHandler {
public:
	EventHandler();
	~EventHandler();
	
	void registerUser(sf::Event::EventType type, EventUser& user);
	void process(const sf::Event& event);
private:
	std::unordered_map<sf::Event::EventType, EventDistributor> distributors;
};

