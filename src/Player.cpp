#include "Player.h"

my::Player::Player( const char* t_sprite_filename ) :
        sprite{ t_sprite_filename }
{
        // keep track of instance
        my::Player::objects.push_back( this );
}

void my::Player::update( float deltaTime )
{
        float movement;

        // determine movement direction
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) )
        {
                movement = 300;
                sprite.setFacing( 1 );
        }
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
        {
                movement = -300;
                sprite.setFacing( -1 );
        }

        sprite.setAnimation( abs( movement ) > 0.5 ? 1 : 0 );
        sprite.getBody().move( my::vecX( movement * deltaTime ) );
        sprite.update( deltaTime );
}

sf::RectangleShape& my::Player::getBody()
{
        return sprite.getBody();
}

my::Sprite& my::Player::getSprite()
{
        return sprite;
}
