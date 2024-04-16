#include "Bullet.h"

Bullet::Bullet(float x, float y, float radius, float xVelocity, float yVelocity, Color color)
	:bullet_object(x, y, radius, xVelocity, yVelocity, color)
{
}




GameObject& Bullet::Get_BulletObject()
{
	return bullet_object;
}

void Bullet::Draw_Bullet()
{
	DrawCircle(bullet_object.Get_X(), bullet_object.Get_Y(), bullet_object.Get_R(), ORANGE);
}
