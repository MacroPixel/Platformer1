#ifndef BLOCK_H
#define BLOCK_H

#include "HH.h"
#include "Sprite.h"
#include "Collider.h"

namespace my
{
        class Block
        {
                my::Sprite sprite;
                my::Collider collider;

        public:
                static std::vector<my::Block*> objects;

                Block( const char* t_sprite_filename );

                sf::RectangleShape& getBody(); // getter for sprite.body
                my::Sprite& getSprite(); // SE
                my::Collider& getCollider(); // SE
        };
}


#endif // BLOCK_H
