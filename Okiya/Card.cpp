#include <iostream>
#include "Card.h"
#include "Utils.h"

using namespace std;

Card::Card(string path, Vector2f position)
{
	player = 0;

	vector<string> tmp = Utils::split(path, '/');
	tmp = Utils::split(tmp.back(), '.');
	tmp = Utils::split(tmp.front(), '_');

	element1 = tmp[0];
	element2 = tmp[1];

	Texture& texture = *(new Texture());
	texture.loadFromFile(path);
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

Sprite& Card::GetSprite()
{
	return sprite;
}
