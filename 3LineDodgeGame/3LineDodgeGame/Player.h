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

	int hp;

public:

	Player(float x, float y, float radius, float xVelocity, Color color, float lineSpace, Rectangle area);

	void Move_Player();

	GameObject& Get_PlayerObject();

	void Check_EnemyCollisions(GameObject bullet_object);

	int Get_HP();

};

