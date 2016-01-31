#include <SFML/Graphics.hpp>
#include "Blob.h"
#include "EventUser.h"
int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	EventDistributor mouseMovedDistributor(sf::Event::MouseMoved);
	Blob blob;
	mouseMovedDistributor.registerUser(&blob);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseMoved:
				mouseMovedDistributor.distribute(event);
				break;
			default:
				break;
			}
		}
		window.clear();
		window.draw(blob);
		window.display();
	}

	return 0;
}
