#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Settings
{
private:
	Settings() {}
	Settings(const Settings&);
	Settings& operator=(Settings&);
public:
	Vector2f resolution;
	Vector2f canvas = Vector2f(1280, 720);
	static Settings& getInstance() {
		static Settings  instance;
		return instance;
	}
};