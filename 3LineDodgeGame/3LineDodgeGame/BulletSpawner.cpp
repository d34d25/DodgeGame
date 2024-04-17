#include <iostream>
#include <cstdlib> // for rand()
#include "BulletSpawner.h"

BulletSpawner::BulletSpawner(float x, float y, float lineSpacing, Rectangle area)
	: spawner_object(x, y, 1.0f, 0.0f, 0.0f, YELLOW), bullet_atm(0, 0, 0, 0, 0, WHITE)
{
	bullet_XVel = 0.0f;
	bullet_YVel = 0.0f;

	line_spacing = lineSpacing;
	play_area = area;
	max_bullets = 5;
	i = 0;
}

void BulletSpawner::Shoot_Bullet(float xVel, float yVel, int delay) //paraemeters are present so I be able to shoot bullets to the right or left
{
	static int shootTimer = 0;

	shootTimer++;

		if (i < max_bullets)
		{
			if (shootTimer >= delay)
			{
				shootTimer = 0;

				int random_bulletType = rand() % 3;
				//std::cout << random_bulletType;

				switch (random_bulletType)
				{
				case 1: //straight
					bullet_XVel = xVel;
					bullet_YVel = 0.0f;

					break;

				case 2: //bounce

					bullet_XVel = xVel;
					bullet_YVel = yVel;

					break;

				case 3:	//shift

					break;

				default:
					break;
				}

				Bullet newBullet
				(spawner_object.Get_X(),
					spawner_object.Get_Y(),
					6.0f,
					bullet_XVel,
					bullet_YVel,
					RAYWHITE);

				bullet_vector.push_back(newBullet);
				//std::cout << "bullet created";
				i++;

			}
			
			
		}
		
		for (int idx = 0; idx < bullet_vector.size(); idx++)
		{
			Bullet& currentBullet = bullet_vector[idx];

			if (currentBullet.Get_BulletObject().Get_Y() < play_area.y || currentBullet.Get_BulletObject().Get_Y() > play_area.height) //check for collisions on Y
			{
				currentBullet.Get_BulletObject().Set_YVel(currentBullet.Get_BulletObject().Get_YVel() * -1);  //bounce
			}

			if (currentBullet.Get_BulletObject().Get_X() < play_area.x || currentBullet.Get_BulletObject().Get_X() > play_area.width + 100) // check if the bullets are outside the area on X
			{
				auto bulletToDelete = bullet_vector.begin() + idx;
				bullet_vector.erase(bulletToDelete);
				i--;    //decrease counter for each bullet deleted 
			}


			currentBullet.Get_BulletObject().Update_GameObject();

		}
		
	
	
	
}

void BulletSpawner::Draw_Spawner()
{
	DrawCircle(spawner_object.Get_X(), spawner_object.Get_Y(), 10, YELLOW);
}

void BulletSpawner::Draw_Bullets()
{
	for (auto idx = 0; idx < bullet_vector.size(); idx++)
	{
		Bullet& currentBullet = bullet_vector[idx];

		currentBullet.Draw_Bullet();
	}
}



std::vector<Bullet>& BulletSpawner::Get_BulletVector() {
	return bullet_vector;
}