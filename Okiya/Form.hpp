#pragma once
#include <iostream>
#include <String>

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace form {

	class Label {
	public:
		Label(String text_ = "Text", float x_ = 0, float y_ = 0, bool center_ = false, size_t size_ = 20, Color color_ = Color::White) {
			font.loadFromFile("Fonts/Alcotton.ttf");

			x = x;
			y = y;
			text = text_;

			TXT.setFont(font);
			TXT.setCharacterSize(size_);
			TXT.setFillColor(color_);
			TXT.setPosition(x_, y_);
			TXT.setString(text_);

			if (center_) {
				updateTextOrigin();
			}
		}

		String getText();
		void setText(String text_);

		void updateTextOrigin();

		Text& display();

	protected:
		float x;
		float y;

		Font font;
		String text;
		Text TXT;
	};
	class Button : public Label {
	public:
		Button(float x_ = 0, float y_ = 0, float width_ = 200, float height_ = 50, String text_ = "", size_t size_ = 20, Color buttonColor_ = Color(133, 133, 133), Color color_ = Color::White) {
			Create(x_, y_, width_, height_, text_, size_, buttonColor_, color_);
		}

		bool select(Vector2i mouse_);

		void setStyle(String style);
		void setPosition(float x_, float y_);

		void Create(float x_ = 0, float y_ = 0, float width_ = 200, float height_ = 50, String text_ = "", size_t size_ = 20, Color buttonColor_ = Color(133, 133, 133), Color color_ = Color::White);

		Text& displayText();
		RectangleShape& displayButton();

	protected:
		float width;
		float height;

		RectangleShape BOX;
	};
	class ImageButton : public Button {
	public:
		ImageButton(float x_ = 0, float y_ = 0, float width_ = 0, float height_ = 0, String image_ = "", String text_ = "", size_t size_ = 20, Color buttonColor_ = Color(133, 133, 133), Color color_ = Color::White) {
			x = x_;
			y = y_;
			width = width_;
			height = height_;
			text = text_;

			BOX.setSize(Vector2f(width_, height_));
			BOX.setPosition(x_, y_);
			BOX.setFillColor(buttonColor_);
			BOX.setOutlineThickness(2);
			BOX.setOutlineColor(Color(66, 66, 66));

			TEXTURE.loadFromFile(image_);
			SPRITE.setTexture(TEXTURE, true);
			SPRITE.setScale(width_ / SPRITE.getLocalBounds().width, height_ / SPRITE.getLocalBounds().height);
			SPRITE.setPosition(x_, y_);
		}

		Sprite& displaySprite();
	private:
		Texture TEXTURE;
		Sprite SPRITE;
	};
	class Input : public Button {
	public:
		Input(float x_ = 0, float y_ = 0, float width_ = 200, float height_ = 50, String text_ = "", size_t size_ = 20, Color buttonColor_ = Color(133, 133, 133), Color color_ = Color::White) {
			x = x_;
			y = y_;
			width = width_;
			height = height_;
			text = text_;
			focus = false;

			TXT.setFont(font);
			TXT.setCharacterSize(size_);
			TXT.setFillColor(color_);
			TXT.setPosition(x_ + 10, y_ + height_ / 4);
			TXT.setString(text_);

			FloatRect fRect = TXT.getLocalBounds();
			TXT.setOrigin(fRect.left + fRect.width / 2.0f,
				fRect.top + fRect.height / 2.0f);

			BOX.setSize(Vector2f(width_, height_));
			BOX.setPosition(x, y);
			BOX.setFillColor(buttonColor_);
			BOX.setOutlineThickness(2);
			BOX.setOutlineColor(Color(66, 66, 66));
		}

		void reText(char tmp_);
		bool select();
		bool select(Vector2i mouse_);

		Text& displayText();
		RectangleShape& displayBOX();
		String readText();

	protected:
		bool focus;
	};
} // namespace form