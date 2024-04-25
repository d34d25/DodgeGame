#pragma once
#include <vector>
#include "raylib.h"
#include "GameObject.h"
#include "Bullet.h"

class BulletSpawner
{
private:

	GameObject spawner_object;

	std::vector<Bullet> bullet_vector;

	float line_spacing;

	Rectangle play_area;

	float bullet_XVel, bullet_YVel;

	int max_bullets;

	int i;

	GameObject bullet_atm;

public:

	BulletSpawner(float x, float y, float lineSpacing, Rectangle area);

	void Shoot_Bullet(float xVel, float yVel, int delay);

	void Draw_Spawner();

	void Draw_Bullets();

    std::vector<Bullet>& Get_BulletVector();

};

