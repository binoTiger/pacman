#pragma once
#include <iostream>
#include <sstream>
#include <fstream>

#include <SFML/Graphics.hpp>

const int DeleteKey = 8;
const int EnterKey = 13;
const int EscapeKey = 27;
const std::string FontPath = "../fonts/arialmt.ttf";

class TextBox {
public:
	TextBox(int size, sf::Color color, bool isSelected, std::string defaultText)
		: _isSelected(isSelected)
	{
		_text.str(defaultText);

		_textbox.setCharacterSize(size);
		_textbox.setFillColor(sf::Color::White);

		if (_isSelected) {
			_textbox.setString(_text.str() + "_");
		}
		else {
			_textbox.setString("");
		}
	}
	void setSelected(bool isSelected)
	{
		_isSelected = isSelected;
		_textbox.setString(_text.str() + "_");

		if (!isSelected) {
			std::string t = _text.str();
			std::string newT = "";
			for (int i = 0; i < t.length(); i++) {
				newT += t[i];
			}
			_textbox.setString(newT);
		}
	}

	std::string GetText()
	{
		return _text.str();
	}

	void setLimit(bool tOf, int lim)
	{
		_hasLimit = tOf;
		_limit = lim - 1;
	}

	void drawText(sf::RenderWindow& window)
	{
		window.draw(_textbox);
	}

	void typedOn(sf::Event input)
	{
		if (_isSelected) {
			int typedChar = input.text.unicode;
			if (typedChar < 128) {
				if (_hasLimit) {
					if (_text.str().length() <= _limit) {
						inputLogic(typedChar);
					}
					else if (_text.str().length() > _limit && typedChar == DeleteKey) {
						deleteLastChar();
					}
				}
				else {
					inputLogic(typedChar);
				}
			}
		}
	}

	void setFont(sf::Font& font) {
		_textbox.setFont(font);
	}

	void setPosition(sf::Vector2f pos) {
		_textbox.setPosition(pos);
	}

private:
	void inputLogic(int typedChar)
	{
		if (typedChar != DeleteKey && typedChar != EnterKey && typedChar != EscapeKey) {
			_text << static_cast<char>(typedChar);
		}
		else if (typedChar == DeleteKey) {
			if (_text.str().length() > 0) {
				deleteLastChar();
			}
		}
		_textbox.setString(_text.str() + "_");

	}

	void deleteLastChar()
	{
		std::string t = _text.str();
		std::string newT = "";
		for (int i = 0; i < t.length() - 1; ++i) {
			newT += t[i];
		}
		_text.str("");
		_text << newT;
		_textbox.setString(_text.str());
	}

	sf::Text _textbox;
	std::ostringstream _text;
	bool _isSelected = false;
	bool _hasLimit;
	int _limit;
};
