#ifndef CUSTOMFUNCTIONS_H_INCLUDED
#define CUSTOMFUNCTIONS_H_INCLUDED

namespace my
{
        class Player;
}

namespace my
{
        void updateAll( float deltaTime );
        void drawAll( sf::RenderWindow& window );

        sf::Vector2f vecX( float x );
        sf::Vector2f vecY( float y );
}

#endif // CUSTOMFUNCTIONS_H_INCLUDED
