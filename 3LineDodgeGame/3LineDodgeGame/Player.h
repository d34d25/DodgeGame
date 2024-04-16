#pragma once
#include "raylib.h"
#include "GameObject.h"

class Player
{

private:

	GameObject player_object;

	float max_speed;

	float line_spacing;

	Rectangle play_area;

	void Check_PlayerCollisions();

public:

	Player(float x, float y, float radius, float xVelocity, Color color, float lineSpace, Rectangle area);

	void Move_Player();

	GameObject& Get_PlayerObject();

};

