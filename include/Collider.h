#ifndef COLLIDER_H
#define COLLIDER_H

#include "HH.h"

namespace my
{
        class Collider
        {
                float posX; float posY;
                float originX; float originY;
                float sizeX; float sizeY;
        public:
                Collider( const char* t_filename );

                void update( sf::Vector2f position );
                bool checkCollision( const my::Collider& solid, float& outputPos );

                friend void my::drawCollider( my::Collider& col, sf::RenderWindow& window );
        };
}

#endif // COLLIDER_H
