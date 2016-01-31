#include <SFML/Graphics.hpp>
#include "Blob.h"
#include "EventHandler.h"

class WindowCloser : public EventUser {
public:
	WindowCloser(sf::RenderWindow& window) : window(&window) {};
	virtual void invoke(const sf::Event& e) { window->close(); }
private:
	sf::RenderWindow* window;
};

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	EventHandler eventHandler;
	Blob blob;
	WindowCloser windowCloser(window);
	eventHandler.registerUser(sf::Event::Closed, windowCloser);
	eventHandler.registerUser(sf::Event::MouseMoved, blob);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			eventHandler.process(event);
		}
		window.clear();
		window.draw(blob);
		window.display();
	}

	return 0;
}
