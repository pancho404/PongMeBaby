#pragma once

#include "gameFunctions.h"
#include "raylib.h"


extern int screenWidth;

extern int screenHeight;

//Sets ball information
void SetBall(Ball& ball, Vector2 pos, Vector2 speed, float setRadius, float acceleration, Texture2D sprite);

//Sets player information
void SetPlayer(Player& player, Vector2 pos, int height, int width, float speed, Texture2D sprite, Sprite gameSprites, int moveUpKey, int moveDownKey);

//Initializes a specific button
void InitButton(Font& britneyFont, Button& button, Vector2 recPos, Vector2 textPos, float width, float height);

//Variables get initialized
void Init(Sprite& gameSprites, GameAudio& gameAudio, Player& playerOne, Player& playerTwo, Ball& circle, bool& lastCollidedGreen, bool& lastCollidedUp, bool& roundActivo, bool& playing, Scene& phases, Text& text, MenuInteractiveTexts& menuInteractiveTexts, MenuTexts& menuTexts, Music& inGameCurrentSong, Music& mainMenuCurrentSong, Font& britneyFont, bool& paused, bool& againstAI, int& timeCounter, int& timeForBoosts);

void SetCredits(MenuTexts& menuTexts);

void LoadSprites(Sprite& gameSprites);

void InitAudio(GameAudio& gameAudio, Music& inGameCurrentSong, Music& mainMenuCurrentSong);

//Assets get unloaded from the memory
void UnloadAssets(Sprite& gameSprites, GameAudio& gameAudio, Font& britneyFont, MenuTexts& menuText, Text& text);

//Variables get deinitialized
void Deinit(Sprite& gameSprites, GameAudio& gameAudio, Font& britneyFont, MenuTexts& menuText, Text& text);

//Audio get unloaded from the memory
void UnloadAudio(GameAudio& gameAudio);

//Textures get unloaded from the memory
void UnloadTextures(Sprite& gameSprites);

//Font gets unloaded from the memory
void UnloadFonts (Font& britneyFont, MenuTexts& menuText, Text& text);

//Global Function contains everything
void Game();

void StopPhaseMusic(Music& music);

void ShowGameOver(Player player, Sprite gameSprites, Font britneyFont);

void ChooseGameMode(GameMode& gameMode, MenuInteractiveTexts& menuInteractiveTexts, Sprite& gameSprites, Scene& phases);

void GameModeMenuEvents(MenuInteractiveTexts& menuInteractiveTexts, GameMode& gameMode, Scene& phases);

void GameOverUpdate(Scene& phases, Player& playerOne, Player& playerTwo);
