#include "EventHandler.h"

EventHandler::EventHandler() {
}


EventHandler::~EventHandler() {
}

void EventHandler::registerUser(sf::Event::EventType type, EventUser& user) {
	distributors[type].registerUser(user);
}

void EventHandler::process(const sf::Event& event) {
	distributors[event.type].distribute(event);
}