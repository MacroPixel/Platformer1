#include "Block.h"

my::Block::Block( const char* t_sprite_filename ) :
        sprite{ t_sprite_filename }
{
        // keep track of instance
        my::Block::objects.push_back( this );
}

sf::RectangleShape& my::Block::getBody()
{
        return sprite.getBody();
}

my::Sprite& my::Block::getSprite()
{
        return sprite;
}
