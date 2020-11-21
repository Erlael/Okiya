#include <iostream>
#include <String>

#include <SFML/Graphics.hpp>

#include "Form.hpp"

using namespace std;
using namespace sf;

String form::Label::getText()
{
	return text;
}

void form::Label::setText(String text_)
{
	text = text_;
}

void form::Label::updateTextOrigin()
{
	FloatRect fRect = TXT.getLocalBounds();
	TXT.setOrigin(fRect.left + fRect.width / 2.0f,
		fRect.top + fRect.height / 2.0f);
}

Text& form::Label::display() {
	updateTextOrigin();
	TXT.setString(text);
	return TXT;
}

bool form::Button::select(Vector2i mouse_)
{
	if ((mouse_.x > x && mouse_.x < x + width) &&
		mouse_.y > y && mouse_.y < y + height) {
		return true;
	}
	else {
		return false;
	}
}

void form::Button::setStyle(String style_)
{
	if (style_ == "default") {
		BOX.setFillColor(Color(133, 84, 163));
	}
	else if (style_ == "hover") {
		BOX.setFillColor(Color(112, 72, 138));
	}
	else if (style_ == "disabled") {
		BOX.setFillColor(Color(200, 200, 200));
	}
}

void form::Button::setPosition(float x_, float y_)
{
	BOX.setPosition(x_, y_);
}

void form::Button::Create(float x_, float y_, float width_, float height_, String text_, size_t size_, Color buttonColor_, Color color_)
{
	font.loadFromFile("Fonts/Alcotton.ttf");

	x = x_;
	y = y_;
	width = width_;
	height = height_;
	text = text_;

	TXT.setFont(font);
	TXT.setCharacterSize(size_);
	TXT.setFillColor(color_);
	TXT.setString(text_);

	FloatRect fRect = TXT.getLocalBounds();
	TXT.setOrigin(fRect.left + fRect.width / 2.0f,
		fRect.top + fRect.height / 2.0f);

	TXT.setPosition(x_ + width_ / 2, y_ + height_ / 2);

	BOX.setSize(Vector2f(width_, height_));
	BOX.setPosition(x_, y_);
	BOX.setFillColor(buttonColor_);
	BOX.setOutlineThickness(2);
	BOX.setOutlineColor(Color(255, 236, 173));
}

Text& form::Button::displayText()
{
	updateTextOrigin();
	TXT.setString(text);
	return TXT;
}

RectangleShape& form::Button::displayButton()
{
	return BOX;
}

void form::Input::reText(char tmp_)
{
	text.erase(text.getSize() - 1);
	if (tmp_ != 8) {
		text += tmp_;
	}
	else {
		if (text.getSize() > 0) {
			text.erase(text.getSize() - 1);
		}
	}
	text += "|";
	TXT.setString(text);
}

bool form::Input::select()
{
	return focus;
}

bool form::Input::select(Vector2i mouse_)
{
	if ((mouse_.x > x && mouse_.x < x + width) &&
		(mouse_.y > y && mouse_.y < y + height)) {
		focus = true;
		text += "|";
	}
	else {
		if (text.getSize() > 0) {
			if (text[text.getSize() - 1] == 124) {
				text.erase(text.getSize() - 1);
			}
		}
		focus = false;
	}
	return true;
}

Text& form::Input::displayText()
{
	TXT.setString(text);
	return TXT;
}

RectangleShape& form::Input::displayBOX()
{
	return BOX;
}

String form::Input::readText()
{
	if (text[text.getSize() - 1] == '|') {
		text.erase(text.getSize() - 2);
	}

	return text;
}

Sprite& form::ImageButton::displaySprite()
{
	return SPRITE;
}
