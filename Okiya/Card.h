#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

class Card
{
private:
	string element1, element2;
	int player;
	Sprite sprite;
public:
	Card(string path, Vector2f position);
	Sprite& GetSprite();
};

