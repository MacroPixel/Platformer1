#include "Block.h"

my::Block::Block( const char* t_sprite_filename ) :
        sprite{ t_sprite_filename }, collider( t_sprite_filename )
{
        // keep track of instance
        my::Block::objects.push_back( this );
}



// SE
sf::RectangleShape& my::Block::getBody()
{
        return sprite.getBody();
}



// SE
my::Sprite& my::Block::getSprite()
{
        return sprite;
}



// SE
my::Collider& my::Block::getCollider()
{
        return collider;
}
