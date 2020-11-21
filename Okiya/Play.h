#pragma once
#include <SFML/Graphics.hpp>
#include "Field.h"

using namespace sf;

class Play
{
	RenderWindow* window;
	Clock clock;
	Sprite background;

	Field field;
public:
	Play();
	void Update(float delta);
	void Draw(float delta);
	void Run(RenderWindow& window);
};

