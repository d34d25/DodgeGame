#pragma once
#include "raylib.h"
#include "GameObject.h"

class Bullet
{
private:

	GameObject bullet_object;


public:

	Bullet(float x, float y, float radius, float xVelocity, float yVelocity, Color color);


	GameObject& Get_BulletObject();

	void Draw_Bullet();
};

