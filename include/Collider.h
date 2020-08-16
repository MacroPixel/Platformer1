#ifndef COLLIDER_H
#define COLLIDER_H

#include "HH.h"

namespace my
{
        class Collider
        {
                sf::Vector2f position;
                sf::Vector2f dimensions;
                sf::Vector2f origin;
        public:
                Collider( const char* t_filename );

                void update( sf::Vector2f position );

                friend void my::drawCollider( my::Collider& col, sf::RenderWindow& window );
        };
}

#endif // COLLIDER_H
