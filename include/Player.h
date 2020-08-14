#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"
#include "HH.h"

namespace my
{
        class Player
        {
                my::Sprite sprite;

        public:
                Player( const char* t_sprite_filename );

                void update( float deltaTime );

                sf::RectangleShape& getBody();
                my::Sprite& getSprite();
        };
}

#endif // PLAYER_H
