#include <iostream>
#include "Card.h"
#include "Utils.h"

using namespace std;

Card::Card(string path)
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
}

Sprite& Card::GetSprite()
{
	return sprite;
}
