#include "Field.h"
#include <chrono>
#include <random>

Field::Field()
{
	cards = vector<vector<Card*>>(4, vector<Card*>(4));

	vector<Vector2i> cardPreLocation{
		Vector2i(0,0), Vector2i(0,1), Vector2i(0,2), Vector2i(0,3),
		Vector2i(1,0), Vector2i(1,1), Vector2i(1,2), Vector2i(1,3),
		Vector2i(2,0), Vector2i(2,1), Vector2i(2,2), Vector2i(2,3),
		Vector2i(3,0), Vector2i(3,1), Vector2i(3,2), Vector2i(3,3)
	};

	string cardTexture[] = {
		"Images/crescent_city.png", "Images/crescent_spruce.png", "Images/crescent_house.png", "Images/crescent_bridge.png",
		"Images/moon_city.png", "Images/moon_spruce.png", "Images/moon_house.png", "Images/moon_bridge.png",
		"Images/star_city.png", "Images/star_spruce.png", "Images/star_house.png", "Images/star_bridge.png",
		"Images/comet_city.png", "Images/comet_spruce.png", "Images/comet_house.png", "Images/comet_bridge.png"
	};


	shuffle(cardPreLocation.begin(), cardPreLocation.end(), std::default_random_engine((unsigned int)std::chrono::system_clock::now().time_since_epoch().count()));

	int temp = 0;
	for (auto i : cardPreLocation) {
		cards[i.x][i.y] = new Card(cardTexture[temp++], Vector2f(20 + (float)i.x * (128 + 10), 84 + (float)i.y * (128 + 10)));
	}
}

void Field::Draw(RenderWindow& window)
{
	for (size_t i = 0; i < cards.size(); i++) {
		for (size_t j = 0; j < cards[i].size(); j++) {
			window.draw(cards[i][j]->GetSprite());
		}
	}
}
