#include "coreFunctions.h"


int screenWidth = 1280;

int screenHeight = 720;

void Deinit(Sprite& gameSprites, GameAudio& gameAudio, Font& britneyFont, MenuTexts& menuText, Text& text)
{
	UnloadAssets(gameSprites, gameAudio, britneyFont, menuText, text);
	CloseAudioDevice();
	CloseWindow();
}

void UnloadAssets(Sprite& gameSprites, GameAudio& gameAudio, Font& britneyFont, MenuTexts& menuText, Text& text)
{
	UnloadTextures(gameSprites);	
	UnloadFonts(britneyFont, menuText, text);
	UnloadAudio(gameAudio);
}

void UnloadAudio(GameAudio& gameAudio)
{
	UnloadSound(gameAudio.bonk);
	UnloadSound(gameAudio.bitch);
	UnloadMusicStream(gameAudio.toxic);
	UnloadMusicStream(gameAudio.circus);
	UnloadMusicStream(gameAudio.hitMe);
	UnloadMusicStream(gameAudio.gimme);
	UnloadMusicStream(gameAudio.womanizer);
	UnloadMusicStream(gameAudio.slave);
}

void UnloadTextures(Sprite& gameSprites)
{
	UnloadTexture(gameSprites.redBritney);
	UnloadTexture(gameSprites.redBritneyFlip);
	UnloadTexture(gameSprites.gimmeBritney);
	UnloadTexture(gameSprites.gimmeBritneyFlip);
	UnloadTexture(gameSprites.schoolBritney);
	UnloadTexture(gameSprites.schoolBritneyFlip);
	UnloadTexture(gameSprites.womBritney);
	UnloadTexture(gameSprites.womBritneyFlip);
	UnloadTexture(gameSprites.planeBritney);
	UnloadTexture(gameSprites.planeBritneyFlip);
	UnloadTexture(gameSprites.britneyBackground);
	UnloadTexture(gameSprites.blueConcert);
	UnloadTexture(gameSprites.concertPeople);
	UnloadTexture(gameSprites.discoBall);
	
}

void UnloadFonts(Font& britneyFont, MenuTexts& menuText, Text& text)
{
	UnloadFont(britneyFont);
	UnloadFont(menuText.artCredits.britneyFont);
	UnloadFont(menuText.audioCredits.britneyFont);
	UnloadFont(menuText.codeCredits.britneyFont);
	UnloadFont(text.britneyFont);
}

void Init(Sprite& gameSprites, GameAudio& gameAudio, Player& playerOne, Player& playerTwo, Ball& circle, bool& lastCollidedGreen, bool& lastCollidedUp, bool& roundActive, bool& playing, Scene& phases, Text& text, MenuInteractiveTexts& menuInteractiveTexts, MenuTexts& menuTexts, Music& inGameCurrentSong, Music& mainMenuCurrentSong, Font& britneyFont, bool& paused, bool& againstAI, int& timeCounter, int& timeForBoosts)
{
	timeForBoosts = 400;
	timeCounter = 0;
	phases = Scene::MainMenu;
	paused = false;
	britneyFont = LoadFont(britneyFontFilepath);
	text.britneyFont = LoadFont(britneyFontFilepath);
	text.textColor = MAROON;
	text.textPos.x = 250.0f;
	text.textPos.y = 380.0f;

	//PLAY BUTTON
	InitButton(britneyFont, menuInteractiveTexts.play, { 580.0f, 460.0f }, { 580.0f, 460.0f }, 300.0f, 60.0f);

	//OPTIONS BUTTON
	InitButton(britneyFont, menuInteractiveTexts.options, { 550.0f, 520.0f }, { 550.0f, 520.0f }, 300.0f, 60.0f);

	//CREDITS BUTTON	
	InitButton(britneyFont, menuInteractiveTexts.credits, { 550.0f, 580.0f }, { 550.0f, 580.0f }, 300.0f, 60.0f);

	//QUIT BUTTON	
	InitButton(britneyFont, menuInteractiveTexts.quit, { 580.0f, 640.0f }, { 580.0f, 640.0f }, 300.0f, 60.0f);

	//BACK BUTTON	
	InitButton(britneyFont, menuInteractiveTexts.back, { 580.0f, 460.0f }, { 580.0f, 460.0f }, 300.0f, 60.0f);

	//BRITNEY SELECTION BUTTON	
	InitButton(britneyFont, menuInteractiveTexts.britneySelection, { 100.0f, 100.0f }, { 580.0f, 460.0f }, 1000.0f, 50.0f);

	//PLAYER TWO BRITNEY SELECTION BUTTON	
	InitButton(britneyFont, menuInteractiveTexts.britneySelectionTwo, { 100.0f, 160.0f }, { 580.0f, 460.0f }, 1000.0f, 50.0f);

	//SONG SELECTION BUTTON	
	InitButton(britneyFont, menuInteractiveTexts.songSelection, { 100.0f, 350.0f }, { 580.0f, 460.0f }, 900.0f, 50.0f);

	//GAME MODE SELECTION BUTTONS

	//AI MODE
	InitButton(britneyFont, menuInteractiveTexts.vsAI, { GetScreenWidth() / 2 - 230.0f , GetScreenHeight() / 2 - 130.0f }, { GetScreenWidth() / 2 - 100.0f,GetScreenHeight() / 2 - 100.0f }, 500.0f, 60.0f);
	//PVP MODE
	InitButton(britneyFont, menuInteractiveTexts.vsPlayer, { (GetScreenWidth() / 2 - 230.0f), (GetScreenHeight() / 2 + 50.0f) }, { GetScreenWidth() / 2 - 100.0f, (float)(GetScreenHeight() / 2) }, 500.0f, 60.0f);

	//IN GAME MENU

	//RESUME BUTTON	
	InitButton(britneyFont, menuInteractiveTexts.resumeButton, { GetScreenWidth() / 2 - 90.0f , GetScreenHeight() / 2 - 130.0f }, { GetScreenWidth() / 2 - 40.0f,GetScreenHeight() / 2 - 100.0f }, 200.0f, 80.0f);

	//IN GAME OPTIONS BUTTON
	InitButton(britneyFont, menuInteractiveTexts.optionsButton, { GetScreenWidth() / 2 - 100.0f , GetScreenHeight() / 2 - 40.0f }, { GetScreenWidth() / 2 - 40.0f,GetScreenWidth() / 2 - 40.0f }, 200.0f, 80.0f);

	//IN GAME QUIT BUTTON
	InitButton(britneyFont, menuInteractiveTexts.quitButton, { (GetScreenWidth() / 2 - 60.0f), (GetScreenHeight() / 2 + 50.0f) }, { GetScreenWidth() / 2 - 40.0f, (float)(GetScreenHeight() / 2) }, 110.0f, 80.0f);

	//CREDITS TEXTS
	SetCredits(menuTexts);

	//SPRITES
	LoadSprites(gameSprites);

	//AUDIO
	InitAudio(gameAudio, inGameCurrentSong, mainMenuCurrentSong);

	//PLAYERS	
	SetPlayer(playerOne, { 150,310 }, 180, 30, 850.0f, gameSprites.redBritney, gameSprites, KEY_W, KEY_S);

	SetPlayer(playerTwo, { 1130,310 }, 180, 30, 850.0f, gameSprites.gimmeBritneyFlip, gameSprites, KEY_UP, KEY_DOWN);

	//BALL	
	SetBall(circle, { 640, 360 }, { 0.0f,0.0f }, 8.0f, 50.0f, gameSprites.discoBall);

	//ENVIROMENT	
	lastCollidedGreen = false;
	lastCollidedUp = false;
	playing = false;
	roundActive = false;
	againstAI = false;


}

void SetCredits(MenuTexts& menuTexts)
{
	menuTexts.codeCredits.britneyFont = LoadFont(britneyFontFilepath);
	menuTexts.codeCredits.textColor = MAROON;
	menuTexts.codeCredits.textPos.x = 220.0f;
	menuTexts.codeCredits.textPos.y = 250.0f;
	menuTexts.artCredits.britneyFont = LoadFont(britneyFontFilepath);
	menuTexts.artCredits.textColor = MAROON;
	menuTexts.artCredits.textPos.x = 100.0f;
	menuTexts.artCredits.textPos.y = 310.0f;
	menuTexts.audioCredits.britneyFont = LoadFont(britneyFontFilepath);
	menuTexts.audioCredits.textColor = MAROON;
	menuTexts.audioCredits.textPos.x = 300.0f;
	menuTexts.audioCredits.textPos.y = 370.0f;
}

void LoadSprites(Sprite& gameSprites)
{
	gameSprites.discoBall = LoadTexture(discoBallFilepath);
	gameSprites.redBritney = LoadTexture(redBritneyFilepath);
	gameSprites.redBritneyFlip = LoadTexture(redBritneyFlipFilepath);
	gameSprites.gimmeBritney = LoadTexture(gimmeBritneyFilepath);
	gameSprites.gimmeBritneyFlip = LoadTexture(gimmeBritneyFlipFilepath);
	gameSprites.schoolBritney = LoadTexture(schoolBritneyFilepath);
	gameSprites.schoolBritneyFlip = LoadTexture(schoolBritneyFlipFilepath);
	gameSprites.womBritney = LoadTexture(womBritneyFilepath);
	gameSprites.womBritneyFlip = LoadTexture(womBritneyFlipFilepath);
	gameSprites.planeBritney = LoadTexture(planeBritneyFilepath);
	gameSprites.planeBritneyFlip = LoadTexture(planeBritneyFlipFilepath);
	gameSprites.britneyBackground = LoadTexture(britneyBackgroundFilepath);
	gameSprites.blueConcert = LoadTexture(BlueConcertFilepath);
	gameSprites.concertPeople = LoadTexture(ConcertPeopleFilepath);
}

void InitAudio(GameAudio& gameAudio, Music& inGameCurrentSong, Music& mainMenuCurrentSong)
{
	gameAudio.toxic = LoadMusicStream(toxicFilepath);
	gameAudio.circus = LoadMusicStream(circusFilepath);
	gameAudio.hitMe = LoadMusicStream(hitMeFilepath);
	gameAudio.gimme = LoadMusicStream(gimmeFilepath);
	gameAudio.womanizer = LoadMusicStream(womanizerFilepath);
	gameAudio.slave = LoadMusicStream(slaveFilepath);
	gameAudio.bonk = LoadSound(bonkFilepath);
	gameAudio.bitch = LoadSound(bitchFilepath);
	inGameCurrentSong = gameAudio.toxic;
	mainMenuCurrentSong = gameAudio.slave;
	SetMusicVolume(gameAudio.toxic, 0.1f);
	SetMusicVolume(gameAudio.circus, 0.1f);
	SetMusicVolume(gameAudio.hitMe, 0.1f);
	SetMusicVolume(gameAudio.gimme, 0.1f);
	SetMusicVolume(gameAudio.womanizer, 0.1f);
	SetMusicVolume(gameAudio.slave, 0.1f);
	SetSoundVolume(gameAudio.bitch, 0.5f);
	SetSoundVolume(gameAudio.bonk, 0.1f);
	gameAudio.toxic.looping = true;
	gameAudio.circus.looping = true;
	gameAudio.hitMe.looping = true;
	gameAudio.gimme.looping = true;
	gameAudio.womanizer.looping = true;
}

void SetBall(Ball& ball, Vector2 pos, Vector2 speed, float setRadius, float acceleration, Texture2D sprite)
{
	ball.isBoosted = false;
	ball.center.x = pos.x;
	ball.center.y = pos.y;
	ball.radius = setRadius;
	ball.avatar = BLACK;
	ball.speed.x = speed.x;
	ball.speed.y = speed.y;
	ball.acceleration = acceleration;
	ball.texture = sprite;
}

void SetPlayer(Player& player, Vector2 pos, int height, int width, float speed, Texture2D sprite, Sprite gameSprites, int moveUpKey, int moveDownKey)
{
	player.isBoosted = false;
	player.shape.x = pos.x;
	player.shape.y = pos.y;
	player.shape.height = height;
	player.shape.width = width;
	player.texture = sprite;
	player.speed = speed;
	player.points = 0;
	player.moveUpKey = moveUpKey;
	player.moveDownKey = moveDownKey;
}

void InitButton(Font& britneyFont, Button& button, Vector2 recPos, Vector2 textPos, float width, float height)
{
	button.buttonText.britneyFont = britneyFont;
	button.buttonText.textColor = MAROON;
	button.buttonText.textPos.x = textPos.x;
	button.buttonText.textPos.y = textPos.y;
	button.buttonRec.x = recPos.x;
	button.buttonRec.y = recPos.y;
	button.buttonRec.width = width;
	button.buttonRec.height = height;
}

void Game()
{
	//INIT
	InitWindow(screenWidth, screenHeight, "Pong me baby one more time");
	InitAudioDevice();
	SetTargetFPS(60);

	Font britneyFont;
	Scene phases;
	GameMode gameMode;
	Text titleText;
	MenuTexts menuTexts;
	MenuInteractiveTexts menuInteractiveTexts;
	GameAudio gameAudio;
	Music inGameCurrentSong;
	Music mainMenuCurrentSong;
	Sprite gameSprites;
	Player playerOne;
	Player playerTwo;
	Ball circle;
	int timeCounter;
	int timeForBoosts;
	bool lastCollidedLeftBritney;
	bool lastCollidedUp;
	bool roundActive;
	bool paused;
	bool playing;
	bool againstAI;

	Init(gameSprites, gameAudio, playerOne, playerTwo, circle, lastCollidedLeftBritney, lastCollidedUp, roundActive, playing, phases, titleText, menuInteractiveTexts, menuTexts, inGameCurrentSong, mainMenuCurrentSong, britneyFont, paused, againstAI, timeCounter, timeForBoosts);

	while (!WindowShouldClose() && phases!=Scene::Quit)
	{
		switch (phases)
		{
		case Scene::MainMenu:
			StopPhaseMusic(inGameCurrentSong);
			MainMenu(menuInteractiveTexts, phases, gameAudio, gameSprites, titleText, mainMenuCurrentSong, playing);
			break;
		case Scene::Options:
			OptionsMenu(menuInteractiveTexts, phases, playerOne, gameSprites, playerTwo, inGameCurrentSong, gameAudio, playing);
			break;
		case Scene::Credits:
			CreditsMenu(menuInteractiveTexts, phases, gameSprites, menuTexts, roundActive);
			break;
		case Scene::Quit:
			Deinit(gameSprites, gameAudio, britneyFont, menuTexts, titleText);			
			break;
		case Scene::Play:						
			StopPhaseMusic(mainMenuCurrentSong);
			GameUpdate(playerOne, playerTwo, gameAudio, inGameCurrentSong, roundActive, playing, circle, lastCollidedLeftBritney, lastCollidedUp, paused, screenWidth, menuInteractiveTexts, phases, gameMode, timeCounter,timeForBoosts);
			GameDraw(roundActive, paused, playerOne, playerTwo, circle, britneyFont, gameSprites.concertPeople, menuInteractiveTexts);
			break;
		case Scene::GameOver:
			GameOverUpdate(phases, playerOne, playerTwo);
			ShowGameOver(playerOne, gameSprites, britneyFont);
			break;
		case Scene::ChooseGameMode:			
			ChooseGameMode(gameMode, menuInteractiveTexts, gameSprites, phases);
			break;
		default:
			break;
		}
		if (phases == Scene::MainMenu || phases == Scene::Options || phases == Scene::Credits)
		{
			UpdateMusicStream(mainMenuCurrentSong);
		}
	}		
	Deinit(gameSprites, gameAudio, britneyFont, menuTexts, titleText);
}

void StopPhaseMusic(Music& inGameCurrentSong)
{
	if (!IsMusicPlaying(inGameCurrentSong))
	{
		StopMusicStream(inGameCurrentSong);
	}
}

void ShowGameOver(Player player, Sprite gameSprites, Font britneyFont)
{	
	BeginDrawing();
	DrawTexture(gameSprites.britneyBackground, 0, 0, WHITE);
	if (player.points == 10)
	{
		DrawTextEx(britneyFont, "Player One Wins!", { GetScreenWidth() / 2.0f - 170.0f, GetScreenHeight() / 2.0f - 50.0f }, 60.0f, 0, MAROON);
	}
	else
	{
		DrawTextEx(britneyFont, "Player Two Wins!", { GetScreenWidth() / 2.0f - 170.0f, GetScreenHeight() / 2.0f - 50.0f }, 60.0f, 0, MAROON);
	}
	DrawTextEx(britneyFont, "Press ENTER to go back to the Main Menu", { GetScreenWidth() / 2.0f - 400.0f, GetScreenHeight() / 2.0f - 120.0f }, 60.0f, 0, MAROON);
	EndDrawing();
}

void GameOverUpdate(Scene& phases, Player& playerOne, Player& playerTwo)
{	
	if (IsKeyPressed(KEY_ENTER))
	{		
		phases = Scene::MainMenu;
	}
	playerOne.points = 0;
	playerTwo.points = 0;
	playerOne.isBoosted = false;
	playerTwo.isBoosted = false;
}

void ChooseGameMode(GameMode& gameMode, MenuInteractiveTexts& menuInteractiveTexts, Sprite& gameSprites, Scene& phases)
{
	GameModeMenuEvents(menuInteractiveTexts, gameMode, phases);
	BeginDrawing();
	DrawTexture(gameSprites.britneyBackground, 0, 0, WHITE);
	DrawTextRec(menuInteractiveTexts.vsAI.buttonText.britneyFont, "Press to play vs a simple AI", menuInteractiveTexts.vsAI.buttonRec, 50.0f, 0.0f, false, menuInteractiveTexts.vsAI.buttonText.textColor);
	DrawTextRec(menuInteractiveTexts.vsPlayer.buttonText.britneyFont, "Press to play against a friend", menuInteractiveTexts.vsPlayer.buttonRec, 50.0f, 0.0f, false, menuInteractiveTexts.vsPlayer.buttonText.textColor);
	EndDrawing();
	
}

void GameModeMenuEvents(MenuInteractiveTexts& menuInteractiveTexts, GameMode& gameMode, Scene& phases)
{
	if (!CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.vsAI.buttonRec))
	{
		menuInteractiveTexts.vsAI.buttonText.textColor = MAROON;
	}
	if (!CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.vsPlayer.buttonRec))
	{
		menuInteractiveTexts.vsPlayer.buttonText.textColor = MAROON;
	}

	if (CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.vsAI.buttonRec))
	{
		menuInteractiveTexts.vsAI.buttonText.textColor = GOLD;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			gameMode = GameMode::VsAI;
			phases = Scene::Play;
		}
	}
	if (CheckCollisionPointRec(GetMousePosition(), menuInteractiveTexts.vsPlayer.buttonRec))
	{
		menuInteractiveTexts.vsPlayer.buttonText.textColor = GOLD;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			gameMode = GameMode::VsPlayer;
			phases = Scene::Play;
		}
	}
}
