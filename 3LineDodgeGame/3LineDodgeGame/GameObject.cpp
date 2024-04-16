#include "raylib.h"
#include "GameObject.h"



GameObject::GameObject(float initX, float initY, float initRadius, float initXVelocity, float initYVelocity, Color initColor)
	: x(initX), y(initY), radius(initRadius), xVelocity(initXVelocity), yVelocity(initYVelocity), color(initColor) {}


void GameObject::DrawObject()
{
	DrawCircle(x,y,radius,color);
}

void GameObject::Update_GameObject()
{
	x += xVelocity;
	y += yVelocity;
}




// Getters
float GameObject::Get_X()
{
	return x;
}

float GameObject::Get_Y()
{
	return y;
}

float GameObject::Get_R()
{
	return radius;
}


float GameObject::Get_XVel()
{
	return xVelocity;
}

float GameObject::Get_YVel()
{
	return yVelocity;
}

Color GameObject::Get_C()
{
	return color;
}



//Setters

void GameObject::Set_X(float newX)
{
	this->x = newX;
}

void GameObject::Set_Y(float newY)
{
	this->y = newY;
}

void GameObject::Set_R(float newR)
{
	this->radius = newR;
}


void GameObject::Set_XVel(float newXVel)
{
	this->xVelocity = newXVel;
}

void GameObject::Set_YVel(float newYVel)
{
	this->yVelocity = newYVel;
}

void GameObject::Set_C(Color newC)
{
	this->color = newC;
}
