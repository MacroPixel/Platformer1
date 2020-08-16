#include "Player.h"

my::Player::Player( const char* t_sprite_filename ) :
        sprite{ t_sprite_filename }, collider( t_sprite_filename )
{
        // keep track of instance
        my::Player::objects.push_back( this );
}



void my::Player::update( float deltaTime )
{
        float movement; // SE

        // determine movement direction
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) )
        {
                movement = 120;
                sprite.setFacing( 1 );
        }
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
        {
                movement = -120;
                sprite.setFacing( -1 );
        }

        // if movement is large enough, use walking animation; otherwise, use standing
        sprite.setAnimation( abs( movement ) > 0.5 ? 1 : 0 );

        sprite.getBody().move( my::vecX( movement * deltaTime ) ); // translate sprite.body
        sprite.update( deltaTime ); // SE

        collider.update( sprite.getBody().getPosition() ); // update collision box
}



// getter for sprite.body
sf::RectangleShape& my::Player::getBody()
{
        return sprite.getBody();
}



// SE
my::Sprite& my::Player::getSprite()
{
        return sprite;
}



// SE
my::Collider& my::Player::getCollider()
{
        return collider;
}
