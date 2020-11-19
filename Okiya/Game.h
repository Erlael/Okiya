#pragma once
#include <SFML/Graphics.hpp>
#include "MainMenu.h"

using namespace sf;

class Game
{
private:
	RenderWindow window;
	ContextSettings settings;
	Clock clock;
	View view;
	MainMenu mainMenu;

	void Load();
	void Update(float delta);
	void Draw(float delta);
public:
	Game();
	~Game();
	void Run();
};

