#include "gameFunctions.h"
#include <iostream>


void GameDraw(bool playing, bool paused, Player& playerOne, Player& playerTwo, Ball& circle, Font britneyFont, Texture2D background, MenuInteractiveTexts pauseButtons)
{

	BeginDrawing();

	ClearBackground(WHITE);

	DrawTexture(background, 0, 0, WHITE);

	if (!playing)
	{
		DrawTextEx(britneyFont, "Left Britney moves with W and S, Right Britney moves with Up and Down", { 180,0 }, 40.0f, 0.0f, MAROON);
		DrawTextEx(britneyFont, "Press SPACE to start, get to 10 points to win", { 200,280 }, 60.0f, 0, MAROON);
	}

	DrawPoints(playerOne, playerTwo, britneyFont);
	DrawBall(circle);
	DrawPlayers(playerOne, playerTwo);

	if (paused)
	{


		DrawRectangle(GetScreenWidth() / 4, GetScreenHeight() / 4, GetScreenWidth() / 2, GetScreenHeight() / 2, GOLD);
		DrawTextRec(britneyFont, "Resume", pauseButtons.resumeButton.buttonRec, 80.0f, 0.0f, false, pauseButtons.resumeButton.buttonText.textColor);
		DrawTextRec(britneyFont, "Options", pauseButtons.optionsButton.buttonRec, 80.0f, 0.0f, false, pauseButtons.optionsButton.buttonText.textColor);
		DrawTextRec(britneyFont, "Quit", pauseButtons.quitButton.buttonRec, 80.0f, 0.0f, false, pauseButtons.quitButton.buttonText.textColor);

	}
	else
	{
		DrawTextEx(britneyFont, "Pres P to pause", { GetScreenWidth() / 2 - 80.0f, GetScreenHeight() - 30.0f }, 30.0f, 0.0f, MAROON);
		if (playerOne.isBoosted)
		{
			DrawTextEx(britneyFont, "Left Britney turned up the beat!", { GetScreenWidth() / 2 - 200.0f, GetScreenHeight() / 2.0f }, 40.0f, 0.0f, MAROON);
		}
		else if (playerTwo.isBoosted)
		{
			DrawTextEx(britneyFont, "Right Britney turned up the beat!", { GetScreenWidth() / 2 - 200.0f, GetScreenHeight() / 2.0f }, 40.0f, 0.0f, MAROON);
		}
		else if (circle.isBoosted)
		{
			DrawTextEx(britneyFont, "Disco ball got bigger lets dance!", { GetScreenWidth() / 2 - 200.0f, GetScreenHeight() / 2.0f }, 40.0f, 0.0f, MAROON);
		}
		
	}

	EndDrawing();
}

void CheckMousePauseButtons(MenuInteractiveTexts& pauseButtons)
{
	if (!CheckCollisionPointRec(GetMousePosition(), pauseButtons.resumeButton.buttonRec))
	{
		pauseButtons.resumeButton.buttonText.textColor = MAROON;
	}
	if (!CheckCollisionPointRec(GetMousePosition(), pauseButtons.optionsButton.buttonRec))
	{
		pauseButtons.optionsButton.buttonText.textColor = MAROON;
	}
	if (!CheckCollisionPointRec(GetMousePosition(), pauseButtons.quitButton.buttonRec))
	{
		pauseButtons.quitButton.buttonText.textColor = MAROON;
	}
}

void DrawBall(Ball& circle)
{	
	if (circle.isBoosted)
	{
		DrawTextureEx(circle.texture, { circle.center.x,circle.center.y }, 0.0f, 1.5f, PURPLE);
	}
	else
	{
		DrawTexture(circle.texture, circle.center.x, circle.center.y, WHITE);
	}
	
}

void DrawPoints(Player& playerOne, Player& playerTwo, Font britneyFont)
{
	DrawTextEx(britneyFont, TextFormat("%i", playerOne.points), { 300,100 }, 60.0f, 0, GREEN);
	DrawTextEx(britneyFont, TextFormat("%i", playerTwo.points), { 960,100 }, 60.0f, 0, RED);
}

void MovePlayers(Player& playerOne, Player& playerTwo, GameMode gameMode, Ball circle)
{

	if (IsKeyDown(playerOne.moveUpKey) && playerOne.shape.y > 0)
	{
		playerOne.shape.y -= playerOne.speed * GetFrameTime();
	}
	if (IsKeyDown(playerOne.moveDownKey) && playerOne.shape.y <= 720 - playerOne.shape.height)
	{
		playerOne.shape.y += playerOne.speed * GetFrameTime();
	}
	if (gameMode == GameMode::VsPlayer)
	{
		if (IsKeyDown(playerTwo.moveUpKey) && playerTwo.shape.y > 0)
		{
			playerTwo.shape.y -= playerTwo.speed * GetFrameTime();
		}
		if (IsKeyDown(playerTwo.moveDownKey) && playerTwo.shape.y <= 720 - playerTwo.shape.height)
		{
			playerTwo.shape.y += playerTwo.speed * GetFrameTime();
		}
	}
	else if (gameMode == GameMode::VsAI)
	{
		if ((playerTwo.shape.y + playerTwo.shape.height / 2) + playerTwo.shape.height / 4 < circle.center.y)
		{
			playerTwo.shape.y += playerTwo.speed / 1.5f * GetFrameTime();
		}
		else if ((playerTwo.shape.y + playerTwo.shape.height / 2) - playerTwo.shape.height / 4 > circle.center.y)
		{
			playerTwo.shape.y -= playerTwo.speed / 1.5f * GetFrameTime();
		}
	}


}

void DrawPlayers(Player& playerOne, Player& playerTwo)
{
	DrawTexture(playerOne.texture, playerOne.shape.x, playerOne.shape.y, WHITE);
	DrawTexture(playerTwo.texture, playerTwo.shape.x, playerTwo.shape.y, WHITE);
}

void MoveBall(bool lastCollidedLeftBritney, bool lastCollidedUp, Ball& circle, Player playerOne, Player playerTwo)
{
	if (lastCollidedLeftBritney && lastCollidedUp) // If the ball last collisioned with the left player and the upper limit, it will go downwards and to the right
	{

		circle.center.x += circle.speed.x * GetFrameTime();
		circle.center.y += circle.speed.y * GetFrameTime();
	}
	if (!lastCollidedLeftBritney && lastCollidedUp) // If the ball last collisioned with the right player and the upper limit, it will go downwards and to the left
	{

		circle.center.x -= circle.speed.x * GetFrameTime();
		circle.center.y += circle.speed.y * GetFrameTime();
	}
	if (lastCollidedLeftBritney && !lastCollidedUp) // If the ball last collisioned with the left player and the bottom limit, it will go upwards and to the right
	{

		circle.center.x += circle.speed.x * GetFrameTime();
		circle.center.y -= circle.speed.y * GetFrameTime();
	}
	if (!lastCollidedLeftBritney && !lastCollidedUp) // If the ball last collisioned with the left player and the bottom limit, it will go upwards and to the left
	{

		circle.center.x -= circle.speed.x * GetFrameTime();
		circle.center.y -= circle.speed.y * GetFrameTime();
	}

	circle.speed.x += circle.acceleration * GetFrameTime();
	circle.speed.y += circle.acceleration * GetFrameTime();
}

void GameUpdate(Player& playerOne, Player& playerTwo, GameAudio& gameAudio, const Music& inGameCurrentSong, bool& roundActive, bool& playing, Ball& circle, bool& lastCollidedLeftBritney, bool& lastCollidedUp, bool& paused, int screenWidthm, MenuInteractiveTexts& pauseButtons, Scene& phases, GameMode& gameMode, int& timeCounter, int& timeForBoosts)
{
	if (gameMode != GameMode::NotChosen)
	{

		if (playing)
		{
			if (IsKeyPressed(KEY_P))
			{
				paused = !paused;

			}
			if (paused)
			{

				CheckMousePauseButtons(pauseButtons);
				PauseMenuEvents(pauseButtons, paused, phases, playerOne, playerTwo, roundActive, playing);
			}
			else if (!paused)
			{

				//INPUT
				MovePlayers(playerOne, playerTwo, gameMode, circle);
				//UPDATE
				if (!IsSoundPlaying(gameAudio.bitch))
				{
					PlayMusicStream(inGameCurrentSong);
				}
				UpdateMusicStream(inGameCurrentSong);

				if (!roundActive)
				{
					if (IsKeyPressed(KEY_SPACE))
					{
						circle.speed.x = 450.0f;
						circle.speed.y = circle.speed.x / 3.0f;
						roundActive = true;
					}

				}
				else
				{
					CollisionEvents(circle, playerOne, lastCollidedLeftBritney, gameAudio, playerTwo, lastCollidedUp, playing, GetScreenWidth(), roundActive);
					MoveBall(lastCollidedLeftBritney, lastCollidedUp, circle, playerOne, playerTwo);
					if (timeCounter % timeForBoosts == 0)
					{
						if (!playerOne.isBoosted && !playerTwo.isBoosted && !circle.isBoosted)
						{
							int boostAux = rand() % 3;
							if (boostAux == 0)
							{
								playerOne.speed += 200.0f;
								playerOne.isBoosted=true;
							}
							else if (boostAux == 1)
							{
								playerTwo.speed += 200.0f;
								playerTwo.isBoosted=true;
							}
							else if (boostAux==2)
							{
								circle.radius += 5.0f;
								circle.isBoosted = true;
							}
						}
						else if (playerOne.isBoosted || playerTwo.isBoosted || circle.isBoosted)
						{
							if (playerOne.isBoosted)
							{
								playerOne.speed -= 200.0f;
								playerOne.isBoosted = false;
							}
							else if (playerTwo.isBoosted)
							{
								playerTwo.speed -= 200.0f;
								playerTwo.isBoosted = false;
							}
							else if (circle.isBoosted)
							{
								circle.radius -= 5.0f;
								circle.isBoosted = false;
							}
						}


					}
				}
			}
		}
		else if (!playing)
		{

			phases = Scene::GameOver;
		}
	}
	else
	{

		phases = Scene::ChooseGameMode;
	}
	timeCounter++;
}

void PauseMenuEvents(MenuInteractiveTexts& pauseButtons, bool& paused, Scene& phases, Player& playerOne, Player& playerTwo, bool& roundActive, bool& playing)
{
	if (CheckCollisionPointRec(GetMousePosition(), pauseButtons.resumeButton.buttonRec))
	{
		pauseButtons.resumeButton.buttonText.textColor = SKYBLUE;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			paused = false;
		}
	}
	if (CheckCollisionPointRec(GetMousePosition(), pauseButtons.optionsButton.buttonRec))
	{
		pauseButtons.optionsButton.buttonText.textColor = SKYBLUE;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			phases = Scene::Options;
		}
	}
	if (CheckCollisionPointRec(GetMousePosition(), pauseButtons.quitButton.buttonRec))
	{
		pauseButtons.quitButton.buttonText.textColor = SKYBLUE;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			phases = Scene::MainMenu;
			playerOne.points = 0;
			playerTwo.points = 0;
			roundActive = false;
			playing = false;
			paused = false;
		}
	}
}

void CollisionEvents(Ball& circle, Player& playerOne, bool& lastCollidedLeftBritney, GameAudio& gameAudio, Player& playerTwo, bool& lastCollidedUp, bool& playing, int screenWidth, bool& roundActive)
{
	CollideWithPlayers(circle, playerOne, lastCollidedLeftBritney, gameAudio, playerTwo, lastCollidedUp);
	CollideWithEnviroment(circle, lastCollidedUp);
	AddGoal(circle, playerTwo, playerOne, playing, screenWidth, roundActive);
}

void AddGoal(Ball& circle, Player& playerTwo, Player& playerOne, bool& playing, int screenWidth, bool& roundActive)
{
	if (circle.center.x <= 0)
	{
		playerTwo.points++;
		Reset(circle, playerOne, playerTwo, roundActive);
	}
	else if (circle.center.x >= screenWidth)
	{
		playerOne.points++;
		Reset(circle, playerOne, playerTwo, roundActive);
	}

	if (playerOne.points == 10 || playerTwo.points == 10)
	{
		playing = false;
	}
}

void CollideWithEnviroment(Ball& circle, bool& lastCollidedUp)
{

	if (circle.center.y <= 0) //Check collision between the ball and the upper limit
	{
		lastCollidedUp = true;
	}
	if (circle.center.y >= GetScreenHeight() - circle.radius) //Check collision between the ball and the bottom limit
	{
		lastCollidedUp = false;
	}

}

void CollideWithPlayers(Ball& circle, Player& playerOne, bool& lastCollidedLeftBritney, GameAudio& gameAudio, Player& playerTwo, bool& lastCollidedUp)
{
	if (CheckCollisionCircleRec(circle.center, circle.radius, playerOne.shape)) //Check collision between the ball and the left player
	{
		if (circle.center.y < playerOne.shape.y + playerOne.shape.height / 2)
		{
			if (circle.speed.y > 0)
			{
				lastCollidedUp = false;
			}

		}
		else if (circle.center.y > playerOne.shape.y + playerOne.shape.height / 2)
		{
			if (circle.speed.y < 0)
			{
				lastCollidedUp = true;
			}
		}
		lastCollidedLeftBritney = true;
		PlaySound(gameAudio.bonk);
	}
	if (CheckCollisionCircleRec(circle.center, circle.radius, playerTwo.shape)) //Check collision between the ball and the right player
	{
		if (circle.center.y < playerTwo.shape.y + playerTwo.shape.height / 2)
		{
			if (circle.speed.y > 0)
			{
				lastCollidedUp = true;
			}
		}
		else if (circle.center.y > playerTwo.shape.y + playerTwo.shape.height / 2)
		{
			if (circle.speed.y < 0)
			{
				lastCollidedUp = false;
			}
		}
		lastCollidedLeftBritney = false;
		PlaySound(gameAudio.bonk);
	}
}

void Reset(Ball& circle, Player& playerOne, Player& playerTwo, bool& playing)
{
	circle.center.x = 640;
	circle.center.y = 360;
	playerOne.shape.x = 200;
	playerOne.shape.y = 310;
	playerTwo.shape.x = 1080;
	playerTwo.shape.y = 310;
	circle.speed.x = 0.0f;
	circle.speed.y = 0.0f;
	playing = false;
}



