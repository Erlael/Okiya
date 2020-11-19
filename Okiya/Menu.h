#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Menu
{
public:
	virtual void Update(float delta) = 0;
	virtual void Draw(float delta) = 0;
	virtual void Run(RenderWindow& window) = 0;
};

