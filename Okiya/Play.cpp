#include "Play.h"
#include "Game.h"

Play::Play()
{
	window = nullptr;

	field = Field();

	//Texture& bg = *(new Texture());
	//bg.loadFromFile("Images/MainMenu.png");
	//background.setTexture(bg);
}

void Play::Update(float delta)
{
	Event event;

	Vector2i pixelPos = Mouse::getPosition(*window);
	Vector2f worldPos = window->mapPixelToCoords(pixelPos);
	Vector2i worldMouse = Vector2i(worldPos);

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
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

void Play::Draw(float delta)
{
	//window->clear(Color(240, 117, 224));
	window->clear(Color::Black);

	window->draw(background);

	field.Draw(*window);

	window->display();
}

void Play::Run(RenderWindow& window)
{
	this->window = &window;
	float delta = clock.restart().asSeconds();

	while (window.isOpen() && Game::state == Game::State::Play)
	{
		delta = clock.restart().asSeconds();
		Update(delta);
		Draw(delta);

	}
}
