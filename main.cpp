#include <SFML/Graphics.hpp>
#include "Actor.h"
#include "EventHandler.h"
#include "ActorFactory.h"
class WindowCloser : public EventUser {
public:
	WindowCloser(sf::RenderWindow& window) : window(&window) {};
	virtual void invoke(const sf::Event& e) { window->close(); }
private:
	sf::RenderWindow* window;
};

ActorFactory actorFactory;
int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	EventHandler eventHandler;
	Actor blob = actorFactory.blob();
	eventHandler.registerUser(sf::Event::Closed, WindowCloser(window));
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
