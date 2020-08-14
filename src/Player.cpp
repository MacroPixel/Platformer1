#include "Player.h"

my::Player::Player( const char* t_sprite_filename ) :
        sprite{ t_sprite_filename } {}

void my::Player::update( float deltaTime )
{
        sprite.getBody().move( my::vecX( 400 * deltaTime ) );
}

sf::RectangleShape& my::Player::getBody()
{
        return sprite.getBody();
}

my::Sprite& my::Player::getSprite()
{
        return sprite;
}
