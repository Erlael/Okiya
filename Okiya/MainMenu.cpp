#include "MainMenu.h"
#include <iostream>
#include "Card.h"
#include "Game.h"

using namespace std;

MainMenu::MainMenu()
{
	window = nullptr;
	play.Create(440.0f, 360.0f, 400.0f, 80.0f, L"Играть", 40U, Color(133, 84, 163), Color::Black);
	exit.Create(440.0f, 540.0f, 400.0f, 80.0f, L"Выход", 40U, Color(133, 84, 163), Color::Black);
	Texture& bg = *(new Texture());
	bg.loadFromFile("Images/MainMenu.png");
	background.setTexture(bg);
}

void MainMenu::Update(float delta)
{
	Event event;

	Vector2i pixelPos = Mouse::getPosition(*window);
	Vector2f worldPos = window->mapPixelToCoords(pixelPos);
	Vector2i worldMouse = Vector2i(worldPos);

	play.select(worldMouse) ? play.setStyle("hover") : play.setStyle("default");
	exit.select(worldMouse) ? exit.setStyle("hover") : exit.setStyle("default");

	while (window->pollEvent(event))
	{
		switch (event.type) {
		case Event::Closed:
			window->close();
			break;
		case Event::MouseButtonReleased:
			switch (event.mouseButton.button)
			{
			case Mouse::Left:
				if (play.select(worldMouse)) {
					Game::state = Game::State::Play;
					return;
				}
				if (exit.select(worldMouse)) {
					window->close();
				}
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}

	return;

}

void MainMenu::Draw(float delta)
{
	window->clear(Color(240, 117, 224));

	window->draw(background);

	window->draw(play.displayButton());
	window->draw(play.displayText());

	window->draw(exit.displayButton());
	window->draw(exit.displayText());

	window->display();
}

void MainMenu::Run(RenderWindow& window)
{
	this->window = &window;
	float delta = clock.restart().asSeconds();

	while (window.isOpen() && Game::state == Game::State::MainMenu)
	{
		delta = clock.restart().asSeconds();
		Update(delta);
		Draw(delta);
	}
}
