#include "Game.h"
#include "Settings.h"
#include "Card.h"

Game::Game()
{
	Settings& st = Settings::getInstance();
	st.resolution = Vector2f(960, 540);
	settings.antialiasingLevel = 2;
	window.create(VideoMode(st.resolution.x, st.resolution.y), "Okiya", Style::Default, settings);
	view = window.getDefaultView();
	view.zoom(1280 / st.resolution.x);
	view.setCenter(640, 360);
	window.setView(view);
}

Game::~Game()
{
}

void Game::Load()
{

}

void Game::Update(float delta)
{
	Event event;
	while (window.pollEvent(event))
	{
		switch (event.type) {
		case Event::Closed:
			window.close();
			break;
		default:
			break;
		}
	}
	mainMenu.Run(window);
}

void Game::Draw(float delta)
{
	window.clear();



	window.display();
}

void Game::Run()
{
	Load();
	float delta = clock.restart().asSeconds();
	while (window.isOpen())
	{
		delta = clock.restart().asSeconds();
		Update(delta);
		Draw(delta);
	}
}
