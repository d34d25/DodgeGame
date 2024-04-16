#include <iostream>
#include "raylib.h"
#include"raymath.h"
#include "GameObject.h"
#include "Player.h"



Player::Player(float x, float y, float radius, float xVelocity, Color color, float lineSpace, Rectangle playableArea)
    : player_object(x, y, radius, xVelocity, 0.0f, color)
{
    max_speed = 7.0f; 
    line_spacing = lineSpace;
    play_area = playableArea;
}


void Player::Move_Player()
{
    float desiredMove = 0.0f;
    bool is_moving = false;

    if (IsKeyDown(KEY_RIGHT))
    {
        is_moving = true;
        desiredMove = 5.0f; 
        std::cout << "Right Key Pressed\n";
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        is_moving = true;
        desiredMove = -5.0f; // Negative for left movement
        std::cout << "Left Key Pressed\n";
    }

    if (is_moving)
    {
        // Clamp velocity to avoid exceeding max speed
        player_object.Set_XVel(Clamp(player_object.Get_XVel() + desiredMove, -max_speed, max_speed));
    }
    else
    {
        player_object.Set_XVel(0.0f);
    }
    
    

    if (IsKeyPressed(KEY_UP))
    {
        // Check if player is not already on the top line
        if (player_object.Get_Y() > play_area.y + line_spacing) {
            player_object.Set_Y(player_object.Get_Y() - line_spacing); // Move Up (subtract line spacing)
        }
    }
    else if (IsKeyPressed(KEY_DOWN))
    {
        // Check if player is not already on the bottom line
        float bottomLimit = play_area.y + play_area.height - line_spacing;
        if (player_object.Get_Y() < bottomLimit) {
            player_object.Set_Y(player_object.Get_Y() + line_spacing); // Move Down (add line spacing)
        }
    }

    Check_PlayerCollisions();

}

void Player::Check_PlayerCollisions()
{
    if (player_object.Get_X() - player_object.Get_R() < play_area.x)
    {
        player_object.Set_XVel(0.0f);
        player_object.Set_X(play_area.x + player_object.Get_R());
    }
    else if (player_object.Get_X() + player_object.Get_R() > play_area.width + 100) {
        // Player has collided with the right edge
        player_object.Set_XVel(0.0f);
        player_object.Set_X(play_area.width - player_object.Get_R() + 100); // Snap to right edge
    }
}


GameObject& Player::Get_PlayerObject() {
    return player_object;
}
