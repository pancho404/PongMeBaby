#include "menuFunctions.h"

static int aux = 1;

static int playerTwoAux = 1;

static int songAux = 1;

void MainMenuEvents(MenuInteractiveTexts& menuInteractiveTexts, Scene& phases, GameAudio& gameAudio, bool& playing)
{
	//Button color changes if the mouse isn't over it
	if (!CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.play.buttonRec))
	{
		menuInteractiveTexts.play.buttonText.textColor = MAROON;
	}
	if (!CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.options.buttonRec))
	{
		menuInteractiveTexts.options.buttonText.textColor = MAROON;
	}
	if (!CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.credits.buttonRec))
	{
		menuInteractiveTexts.credits.buttonText.textColor = MAROON;
	}
	if (!CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.quit.buttonRec))
	{
		menuInteractiveTexts.quit.buttonText.textColor = MAROON;
	}
	
	//Button interactions with mouse left click
	if (CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.play.buttonRec))
	{
		menuInteractiveTexts.play.buttonText.textColor = GOLD;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			phases = Scene::ChooseGameMode;
			playing = true;
			PlaySound(gameAudio.bitch);
		}
	}
	if (CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.options.buttonRec))
	{
		menuInteractiveTexts.options.buttonText.textColor = GOLD;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			phases = Scene::Options;
		}
	}
	if (CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.credits.buttonRec))
	{
		menuInteractiveTexts.credits.buttonText.textColor = GOLD;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			phases = Scene::Credits;
		}
	}
	if (CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.quit.buttonRec))
	{
		menuInteractiveTexts.quit.buttonText.textColor = GOLD;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			phases = Scene::Quit;
		}
	}
}

void BackButtonEvents(MenuInteractiveTexts& menuInteractiveTexts, Scene& phases, Scene phaseToGo, bool playing)
{
	if (playing)
	{
		phaseToGo = Scene::Play;
	}

	if (!CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.back.buttonRec))
	{
		menuInteractiveTexts.back.buttonText.textColor = MAROON;
	}
	if (CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.back.buttonRec))
	{
		menuInteractiveTexts.back.buttonText.textColor = GOLD;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			phases = phaseToGo;		
		}
	}
}

void ChangeSong(Music& inGameCurrentSong, GameAudio& gameAudio)
{
	songAux++;

	if (songAux > 5)
	{
		songAux = 1;
	}

	switch ((Songs)songAux)
	{
	case Songs::Toxic:
		inGameCurrentSong = gameAudio.toxic;

		break;
	case Songs::GimmeMore:
		inGameCurrentSong = gameAudio.gimme;

		break;
	case Songs::Womanizer:
		inGameCurrentSong = gameAudio.womanizer;

		break;
	case Songs::HitMe:
		inGameCurrentSong = gameAudio.hitMe;

		break;
	case Songs::Circus:
		inGameCurrentSong = gameAudio.circus;

		break;
	default:
		break;
	}
}

void ChangeBritneyOne(Player& playerOne, Sprite& gameSprites)
{
	aux++;

	if (aux > 5)
	{
		aux = 1;
	}
	switch ((Britneys)aux)
	{
	case Britneys::Red:
		playerOne.texture = gameSprites.redBritney;	
		break;
	case Britneys::Gimme:
		playerOne.texture = gameSprites.gimmeBritney;		
		break;
	case Britneys::Plane:
		playerOne.texture = gameSprites.planeBritney;		
		break;
	case Britneys::Wom:
		playerOne.texture = gameSprites.womBritney;		
		break;
	case Britneys::School:
		playerOne.texture = gameSprites.schoolBritney;	
		break;
	default:
		break;
	}
}

void ChangeBritneyTwo(Player& playerTwo, Sprite& gameSprites)
{
	playerTwoAux++;

	if (playerTwoAux > 5)
	{
		playerTwoAux = 1;
	}
	switch ((Britneys)playerTwoAux)
	{
	case Britneys::Red:
		playerTwo.texture = gameSprites.redBritneyFlip;
		break;
	case Britneys::Gimme:
		playerTwo.texture = gameSprites.gimmeBritneyFlip;	
		break;
	case Britneys::Plane:
		playerTwo.texture = gameSprites.planeBritneyFlip;	
		break;
	case Britneys::Wom:
		playerTwo.texture = gameSprites.womBritneyFlip;	
		break;
	case Britneys::School:
		playerTwo.texture = gameSprites.schoolBritneyFlip;		
		break;
	default:
		break;
	}

}

void OptionEvents(MenuInteractiveTexts& menuInteractiveTexts, Player& playerOne, Sprite& gameSprites, Player& playerTwo, Music& inGameCurrentSong, GameAudio& gameAudio)
{
	if (!CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.britneySelection.buttonRec))
	{
		menuInteractiveTexts.britneySelection.buttonText.textColor = MAROON;
	}
	if (!CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.britneySelectionTwo.buttonRec))
	{
		menuInteractiveTexts.britneySelectionTwo.buttonText.textColor = MAROON;
	}
	if (!CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.songSelection.buttonRec))
	{
		menuInteractiveTexts.songSelection.buttonText.textColor = MAROON;
	}
	if (CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.britneySelection.buttonRec))
	{
		menuInteractiveTexts.britneySelection.buttonText.textColor = GOLD;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			ChangeBritneyOne(playerOne, gameSprites);
		}
	}
	if (CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.britneySelectionTwo.buttonRec))
	{
		menuInteractiveTexts.britneySelectionTwo.buttonText.textColor = GOLD;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			ChangeBritneyTwo(playerTwo, gameSprites);
		}
	}
	if (CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.songSelection.buttonRec))
	{
		menuInteractiveTexts.songSelection.buttonText.textColor = GOLD;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			ChangeSong(inGameCurrentSong, gameAudio);
		}
	}
}

void CreditsMenu(MenuInteractiveTexts& menuInteractiveTexts, Scene& phases, Sprite& gameSprites, MenuTexts& menuTexts, bool playing)
{
	BackButtonEvents(menuInteractiveTexts, phases, Scene::MainMenu, playing);
	DrawCredits(gameSprites, menuTexts, menuInteractiveTexts);
}

void DrawCredits(Sprite& gameSprites, MenuTexts& menuTexts, MenuInteractiveTexts& menuInteractiveTexts)
{
	BeginDrawing();
	DrawTexture(gameSprites.britneyBackground, 0, 0, WHITE);
	DrawTextEx(menuTexts.codeCredits.britneyFont, "Coding and Development by Francisco Sanchez", menuTexts.codeCredits.textPos, 60.0f, 0.0f, menuTexts.codeCredits.textColor);
	DrawTextEx(menuTexts.artCredits.britneyFont, "Art by Guadalupe Ferreira Le Roi and Yoel Motillo La Pira", menuTexts.artCredits.textPos, 60.0f, 0.0f, menuTexts.artCredits.textColor);
	DrawTextEx(menuTexts.audioCredits.britneyFont, "All songs belong to Britney Spears", menuTexts.audioCredits.textPos, 60.0f, 0.0f, menuTexts.audioCredits.textColor);
	DrawTextRec(menuInteractiveTexts.back.buttonText.britneyFont, "Back", menuInteractiveTexts.back.buttonRec, 60.0f, 0.0f, false, menuInteractiveTexts.back.buttonText.textColor);
	ClearBackground(WHITE);
	EndDrawing();
}

void MainMenu(MenuInteractiveTexts& menuInteractiveTexts, Scene& phases, GameAudio& gameAudio, Sprite& gameSprites, Text& titleText, Music& mainMenuCurrentSong, bool& playing)
{
	if (!IsMusicPlaying(mainMenuCurrentSong))
	{
		PlayMusicStream(mainMenuCurrentSong);
	}
	UpdateMusicStream(mainMenuCurrentSong);
	MainMenuEvents(menuInteractiveTexts, phases, gameAudio, playing);
	DrawMainMenu(gameSprites, titleText, menuInteractiveTexts);
}

void DrawMainMenu(Sprite& gameSprites, Text& titleText, MenuInteractiveTexts& menuInteractiveTexts)
{
	BeginDrawing();
	DrawTexture(gameSprites.britneyBackground, 0, 0, WHITE);
	DrawTextEx(titleText.britneyFont, "Pong me baby one more time", titleText.textPos, 90.0f, 0.0f, titleText.textColor);
	DrawTextRec(menuInteractiveTexts.play.buttonText.britneyFont, "Play", menuInteractiveTexts.play.buttonRec, 60.0f, 0.0f, false, menuInteractiveTexts.play.buttonText.textColor);
	DrawTextRec(menuInteractiveTexts.options.buttonText.britneyFont, "Options", menuInteractiveTexts.options.buttonRec, 60.0f, 0.0f, false, menuInteractiveTexts.options.buttonText.textColor);
	DrawTextRec(menuInteractiveTexts.credits.buttonText.britneyFont, "Credits", menuInteractiveTexts.credits.buttonRec, 60.0f, 0.0f, false, menuInteractiveTexts.credits.buttonText.textColor);
	DrawTextRec(menuInteractiveTexts.quit.buttonText.britneyFont, "Quit", menuInteractiveTexts.quit.buttonRec, 60.0f, 0.0f, false, menuInteractiveTexts.quit.buttonText.textColor);
	ClearBackground(WHITE);
	EndDrawing();
}

void OptionsMenu(MenuInteractiveTexts& menuInteractiveTexts, Scene& phases, Player& playerOne, Sprite& gameSprites, Player& playerTwo, Music& inGameCurrentSong, GameAudio& gameAudio, bool playing)
{
	BackButtonEvents(menuInteractiveTexts, phases, Scene::MainMenu, playing);
	OptionEvents(menuInteractiveTexts, playerOne, gameSprites, playerTwo, inGameCurrentSong, gameAudio);
	DrawOptionsMenu(gameSprites, menuInteractiveTexts, playerOne, playerTwo);
	EndDrawing();
}

void DrawOptionsMenu(Sprite& gameSprites, MenuInteractiveTexts& menuInteractiveTexts, Player& playerOne, Player& playerTwo)
{
	BeginDrawing();
	DrawTexture(gameSprites.britneyBackground, 0, 0, WHITE);
	DrawTextRec(menuInteractiveTexts.britneySelection.buttonText.britneyFont, "Press to change player one's Britney", menuInteractiveTexts.britneySelection.buttonRec, 50.0f, 0.0f, false, menuInteractiveTexts.britneySelection.buttonText.textColor);
	DrawTextRec(menuInteractiveTexts.britneySelectionTwo.buttonText.britneyFont, "Press to change player two's Britney", menuInteractiveTexts.britneySelectionTwo.buttonRec, 50.0f, 0.0f, false, menuInteractiveTexts.britneySelectionTwo.buttonText.textColor);
	DrawTextRec(menuInteractiveTexts.songSelection.buttonText.britneyFont, "Press to change song", menuInteractiveTexts.songSelection.buttonRec, 50.0f, 0.0f, false, menuInteractiveTexts.songSelection.buttonText.textColor);
	DrawTextRec(menuInteractiveTexts.back.buttonText.britneyFont, "Back", menuInteractiveTexts.back.buttonRec, 60.0f, 0.0f, false, menuInteractiveTexts.back.buttonText.textColor);
	DrawTexture(playerOne.texture, menuInteractiveTexts.britneySelection.buttonRec.x + 800.0f, menuInteractiveTexts.britneySelection.buttonRec.y - 30.0f, WHITE);
	DrawTexture(playerTwo.texture, menuInteractiveTexts.britneySelectionTwo.buttonRec.x + 1000.0f, menuInteractiveTexts.britneySelectionTwo.buttonRec.y - 90.0f, WHITE);
	switch ((Songs)songAux)
	{
	case Songs::Toxic:
		DrawTextEx(menuInteractiveTexts.songSelection.buttonText.britneyFont, "Toxic", { menuInteractiveTexts.songSelection.buttonRec.x + 600.0f, menuInteractiveTexts.songSelection.buttonRec.y }, 50.0f, 0, MAROON);
		break;
	case Songs::GimmeMore:
		DrawTextEx(menuInteractiveTexts.songSelection.buttonText.britneyFont, "Gimme More", { menuInteractiveTexts.songSelection.buttonRec.x + 600.0f, menuInteractiveTexts.songSelection.buttonRec.y }, 50.0f, 0, MAROON);
		break;
	case Songs::Womanizer:
		DrawTextEx(menuInteractiveTexts.songSelection.buttonText.britneyFont, "Womanizer", { menuInteractiveTexts.songSelection.buttonRec.x + 600.0f, menuInteractiveTexts.songSelection.buttonRec.y }, 50.0f, 0, MAROON);
		break;
	case Songs::HitMe:
		DrawTextEx(menuInteractiveTexts.songSelection.buttonText.britneyFont, "Hit me baby One more Time", { menuInteractiveTexts.songSelection.buttonRec.x + 600.0f, menuInteractiveTexts.songSelection.buttonRec.y }, 50.0f, 0, MAROON);
		break;
	case Songs::Circus:
		DrawTextEx(menuInteractiveTexts.songSelection.buttonText.britneyFont, "Circus", { menuInteractiveTexts.songSelection.buttonRec.x + 600.0f, menuInteractiveTexts.songSelection.buttonRec.y }, 50.0f, 0, MAROON);
		break;
	default:
		break;
	}
}
