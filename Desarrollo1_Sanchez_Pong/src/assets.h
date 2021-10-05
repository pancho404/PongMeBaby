#pragma once
#include "raylib.h"


const char toxicFilepath[] = "res/assets/Music/Toxic.mp3";

const char hitMeFilepath[] = "res/assets/Music/HitMe.mp3";

const char circusFilepath[] = "res/assets/Music/Circus.mp3";

const char womanizerFilepath[] = "res/assets/Music/Womanizer.mp3";

const char gimmeFilepath[] = "res/assets/Music/Gimme.mp3";

const char slaveFilepath[] = "res/assets/Music/Slave.mp3";

const char bonkFilepath[] = "res/assets/Sounds/pongSound.mp3";

const char bitchFilepath[] = "res/assets/Sounds/bitch.mp3";

const char redBritneyFilepath[] = "res/assets/Sprites/RedBritney.png";

const char redBritneyFlipFilepath[] = "res/assets/Sprites/RedBritneyFlip.png";

const char gimmeBritneyFilepath[] = "res/assets/Sprites/GimmeBritney.png";

const char gimmeBritneyFlipFilepath[] = "res/assets/Sprites/GimmeBritneyFlip.png";

const char schoolBritneyFilepath[] = "res/assets/Sprites/SchoolBritney.png";

const char schoolBritneyFlipFilepath[] = "res/assets/Sprites/SchoolBritneyFlip.png";

const char womBritneyFilepath[] = "res/assets/Sprites/WomBritney.png";

const char womBritneyFlipFilepath[] = "res/assets/Sprites/WomBritneyFlip.png";

const char planeBritneyFilepath[] = "res/assets/Sprites/PlaneBritney.png";

const char planeBritneyFlipFilepath[] = "res/assets/Sprites/PlaneBritneyFlip.png";

const char discoBallFilepath[] = "res/assets/Sprites/DiscoBall.png";

const char britneyBackgroundFilepath[] = "res/assets/Sprites/BritneyBackground.png";

const char ConcertPeopleFilepath[] = "res/assets/Sprites/ConcertPeople.png";

const char BlueConcertFilepath[] = "res/assets/Sprites/Escenario.png";



struct GameAudio
{
	Sound bonk;
	Sound bitch;
	Music toxic;
	Music circus;
	Music gimme;
	Music womanizer;
	Music hitMe;	
	Music slave;	
};

struct Sprite
{
	Texture2D redBritney;
	Texture2D redBritneyFlip;
	Texture2D schoolBritney;
	Texture2D schoolBritneyFlip;
	Texture2D planeBritney;
	Texture2D planeBritneyFlip;
	Texture2D womBritney;
	Texture2D womBritneyFlip;
	Texture2D gimmeBritney;
	Texture2D gimmeBritneyFlip;
	Texture2D discoBall;
	Texture2D britneyBackground;
	Texture2D concertPeople;
	Texture2D blueConcert;
};