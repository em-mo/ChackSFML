#include <SFML/Graphics.hpp>
#include "Blob.h"
int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	Blob blob;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseMoved:
				blob.update(event);
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