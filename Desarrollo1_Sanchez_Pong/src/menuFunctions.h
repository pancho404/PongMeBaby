#pragma once


#include "phaseManager.h"
#include "texts.h"
#include "assets.h"
#include "objects.h"

enum class Britneys { Red = 1, Gimme, Plane, Wom, School };

enum class Songs {Toxic=1, GimmeMore, Womanizer, HitMe, Circus};

void MainMenuEvents(MenuInteractiveTexts& menuInteractiveTexts, Scene& phases, GameAudio& gameAudio, bool& playing);

void BackButtonEvents(MenuInteractiveTexts& menuInteractiveTexts, Scene& phases, Scene phaseToGo, bool playing);

void ChangeBritneyOne(Player& playerOne, Sprite& gameSprites);

void ChangeBritneyTwo(Player& playerTwo, Sprite& gameSprites);

void ChangeSong(Music& inGameCurrentSong, GameAudio& gameAudio);

void OptionEvents(MenuInteractiveTexts& menuInteractiveTexts, Player& playerOne, Sprite& gameSprites, Player& playerTwo, Music& inGameCurrentSong, GameAudio& gameAudio);

void DrawOptionsMenu(Sprite& gameSprites, MenuInteractiveTexts& menuInteractiveTexts, Player& playerOne, Player& playerTwo);

void OptionsMenu(MenuInteractiveTexts& menuInteractiveTexts, Scene& phases, Player& playerOne, Sprite& gameSprites, Player& playerTwo, Music& inGameCurrentSong, GameAudio& gameAudio, bool playing);

void DrawMainMenu(Sprite& gameSprites, Text& titleText, MenuInteractiveTexts& menuInteractiveTexts);

void MainMenu(MenuInteractiveTexts& menuInteractiveTexts, Scene& phases, GameAudio& gameAudio, Sprite& gameSprites, Text& titleText, Music& mainMenuCurrentSong, bool& playing);

void DrawCredits(Sprite& gameSprites, MenuTexts& menuTexts, MenuInteractiveTexts& menuInteractiveTexts);

void CreditsMenu(MenuInteractiveTexts& menuInteractiveTexts, Scene& phases, Sprite& gameSprites, MenuTexts& menuTexts, bool playing);
