#pragma once
#include <iostream>
#include <vector>
#include <set>
#include "Card.h"

using namespace std;

class Field
{
	vector<vector<Card*>> cards;

public:
	Field();

	void Draw(RenderWindow& window);
};