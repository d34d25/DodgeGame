#include <iostream>
#include <vector>
#include "raylib.h"
#include "Player.h"
#include "Bullet.h"
#include "BulletSpawner.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    static const int screenWidth = 800;
    static const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    float playable_area_width = screenWidth * 0.75;
    float playable_area_height = screenHeight * 0.75;

    static Rectangle playable_area = {(screenWidth - playable_area_width) / 2, (screenHeight - playable_area_height) / 4, playable_area_width, playable_area_height};

    float line_spacing = playable_area_height  / 4;

    float middleLineY = playable_area.y + 2 * line_spacing;
   

    Player myPlayer(screenWidth/2, middleLineY, 10 ,0, RED, line_spacing, playable_area);

    std::vector<BulletSpawner> spawn_vector;

    BulletSpawner spawn_one(playable_area.x, (line_spacing / 3) + line_spacing , line_spacing, playable_area);
    BulletSpawner spawn_two(playable_area.x, (line_spacing / 3) + line_spacing * 2, line_spacing, playable_area);
    BulletSpawner spawn_three(playable_area.x, (line_spacing / 3) + line_spacing * 3, line_spacing, playable_area);
    //BulletSpawner spawn_four(parameters);
    //BulletSpawner spawn_five(parameters);
    //BulletSpawner spawn_six(parameters);

    spawn_vector.push_back(spawn_one);
    spawn_vector.push_back(spawn_two);
    spawn_vector.push_back(spawn_three);
    //the same for the rest of spawners



    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        myPlayer.Move_Player();
        myPlayer.Get_PlayerObject().Update_GameObject();


        if (!spawn_vector.empty())
        {
            for (auto i = 0; i < spawn_vector.size(); i++)
            {
                BulletSpawner& currentSpawnPoint = spawn_vector[i];

                currentSpawnPoint.Shoot_Bullet(3.0f, 3.0f, 60);
               // std::cout << "bullet shot";
            }
        }


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        DrawRectangleLinesEx(playable_area, 7, RAYWHITE);

        for (int i = 1; i <= 3; i++)
        {
            float y = playable_area.y + line_spacing * i;
            DrawLine(playable_area.x, y, playable_area.x + playable_area.width, y, RAYWHITE);
        }

        myPlayer.Get_PlayerObject().DrawObject();

        if (!spawn_vector.empty())
        {
            for (auto i = 0; i < spawn_vector.size(); i++)
            {
                BulletSpawner& currentSpawnPoint = spawn_vector[i];
                currentSpawnPoint.Draw_Spawner();
                currentSpawnPoint.Draw_Bullets();
            }
        }


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}