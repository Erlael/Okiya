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
	Vector2f coordinates;
	int player;
	Sprite sprite;
public:
	Card(string path);
	Sprite& GetSprite();
};

