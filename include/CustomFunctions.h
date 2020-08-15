#ifndef CUSTOMFUNCTIONS_H_INCLUDED
#define CUSTOMFUNCTIONS_H_INCLUDED

namespace my
{
        // used to run functions on vector of dynamic object ptrs
        void updateAll( float deltaTime );
        void drawAll( sf::RenderWindow& window );

        // creates a vector with only a x or y value (for conciseness)
        sf::Vector2f vecX( float x );
        sf::Vector2f vecY( float y );
}

#endif // CUSTOMFUNCTIONS_H_INCLUDED
