#ifndef BLOCK_H
#define BLOCK_H

#include "HH.h"
#include "Sprite.h"

namespace my
{
        class Block
        {
                my::Sprite sprite;

        public:
                static std::vector<my::Block*> objects;

                Block( const char* t_sprite_filename );

                sf::RectangleShape& getBody();
                my::Sprite& getSprite();
        };
}


#endif // BLOCK_H
