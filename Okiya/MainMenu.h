#pragma once
#include "Menu.h"
#include "Form.hpp"

class MainMenu : public Menu
{
private:
	form::Button play;
	form::Button exit;
	Clock clock;
	RenderWindow* window;
public:
	MainMenu();
	void Update(float delta);
	void Draw(float delta);
	void Run(RenderWindow& window);
};

