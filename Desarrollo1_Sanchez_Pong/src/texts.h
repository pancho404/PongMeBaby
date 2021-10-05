#pragma once
#include "raylib.h"

const char britneyFontFilepath[] = "res/assets/Fonts/Circusia.ttf";

struct Text
{
	Font britneyFont;
	Vector2 textPos;
	Color textColor;
};

struct Button 
{
	Rectangle buttonRec;
	Text buttonText;
};

struct MenuTexts
{
	Text codeCredits;
	Text artCredits;
	Text audioCredits;
};

struct MenuInteractiveTexts
{
	Button play;
	Button options;
	Button credits;
	Button quit;
	Button back;
	Button britneySelection;
	Button britneySelectionTwo;
	Button songSelection;
	Button resumeButton;
	Button optionsButton;
	Button quitButton;	
	Button vsAI;
	Button vsPlayer;
};