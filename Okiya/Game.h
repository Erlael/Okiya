#pragma once
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "Play.h"

using namespace sf;

class Game
{
private:
	RenderWindow window;
	ContextSettings settings;
	Clock clock;
	View view;
	MainMenu mainMenu;
	Play play;

	void Load();
	void Update(float delta);
	void Draw(float delta);

public:
	enum class State
	{
		MainMenu,
		Play
	};
	static State state;
	Game();
	~Game();
	void Run();
};

