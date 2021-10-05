#pragma once
#include "menuFunctions.h"




//Players X and Y position are updated via Input
void MovePlayers(Player& playerOne, Player& playerTwo, GameMode gameMode, Ball circle);

//The ball moves depending on the collisions
void MoveBall(bool lastCollidedGreen, bool lastCollidedUp, Ball& circle, Player playerOne, Player playerTwo);

//The game gets drawn
void GameDraw(bool playing, bool paused, Player& playerOne, Player& playerTwo, Ball& circle, Font britneyFont, Texture2D background, MenuInteractiveTexts pauseButtons);

void CheckMousePauseButtons(MenuInteractiveTexts& pauseButtons);

//The ball gets drawn
void DrawBall(Ball& circle);

//Both player score get drawn
void DrawPoints(Player& playerOne, Player& playerTwo, Font britneyFont);

//Players are drawn
void DrawPlayers(Player& playerOne, Player& playerTwo);

//Checks collision with players and acts basing on the result
void CollideWithPlayers(Ball& circle, Player& playerOne, bool& lastCollidedLeftBritney, GameAudio& gameAudio, Player& playerTwo, bool& lastCollidedUp);

//Checks collision with the enviroment and acts basing on the result
void CollideWithEnviroment(Ball& circle, bool& lastCollidedUp);

//Checks collision with the side limits and acts basing on the result
void AddGoal(Ball& circle, Player& playerTwo, Player& playerOne, bool& playing, int screenWidth, bool& roundActive);

//Contains the CollideWithPlayers, CollideWithEnviroment and AddGoal
void CollisionEvents(Ball& circle, Player& playerOne, bool& lastCollidedLeftBritney, GameAudio& gameAudio, Player& playerTwo, bool& lastCollidedUp, bool& playing, int screenWidth, bool& roundActive);

//Update
void GameUpdate(Player& playerOne, Player& playerTwo, GameAudio& gameAudio, const Music& inGameCurrentSong, bool& roundActive, bool& playing, Ball& circle, bool& lastCollidedLeftBritney, bool& lastCollidedUp, bool& paused, int screenWidth, MenuInteractiveTexts& pauseButtons, Scene& phases, GameMode& gameMode, int& timeCounter, int& timeForBoosts);

void PauseMenuEvents(MenuInteractiveTexts& pauseButtons, bool& paused, Scene& phases, Player& playerOne, Player& playerTwo, bool& roundActive, bool& playing);

//Variables get reseted every time a player scores
void Reset(Ball& circle, Player& playerOne, Player& playerTwo, bool& playing);