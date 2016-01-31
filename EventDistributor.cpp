#pragma once
#include "EventUser.h"

void EventDistributor::registerUser(EventUser* user) {
	users.push_back(user);
}

void EventDistributor::distribute(const sf::Event& e) {
	for (auto u : users)
		u->invoke(e);
}