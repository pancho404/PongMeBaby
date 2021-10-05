#pragma once
#include "raylib.h"

struct Player
{
	Rectangle shape;	
	float speed;
	int points;
	Texture2D texture;
	int moveUpKey;
	int moveDownKey;
	bool isBoosted;
};

struct Ball
{
	bool isBoosted;
	Vector2 center;
	Vector2 speed;
	float radius;
	float acceleration;
	Color avatar;
	Texture2D texture;
};