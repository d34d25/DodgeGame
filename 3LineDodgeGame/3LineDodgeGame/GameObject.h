#pragma once
#include "raylib.h"

class GameObject
{
private:

	float x, y, radius, xVelocity, yVelocity;

	Color color;

public:
	
	GameObject(float initX, float initY, float initRadius, float initXVelocity, float initYVelocity, Color initColor);

	void DrawObject();

	void Update_GameObject();



	float Get_X();

	float Get_Y();

	float Get_R();

	float Get_XVel();

	float Get_YVel();

	Color Get_C();

	void Set_X(float newX);

	void Set_Y(float newY);

	void Set_R(float newR);

	void Set_XVel(float newXVel);

	void Set_YVel(float newYVel);

	void Set_C(Color newC);
};

