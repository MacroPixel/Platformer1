#ifndef CUSTOMFUNCTIONS_H_INCLUDED
#define CUSTOMFUNCTIONS_H_INCLUDED

namespace my
{
        class Collider;
}

namespace my
{
        // used to run functions on vector of dynamic object ptrs
        void updateAll( float deltaTime );
        void drawAll( sf::RenderWindow& window );

        // creates a vector with only a x or y value (for conciseness)
        sf::Vector2f vecX( float x );
        sf::Vector2f vecY( float y );

        // multiplies two vectors together
        sf::Vector2f vecP( const sf::Vector2f& vecA, const sf::Vector2f& vecB );
        sf::Vector2f vecM( const sf::Vector2f& vecA, const sf::Vector2f& vecB );

        // draws a rectangle outline (for debugging)
        void drawRect( float x1, float y1, float x2, float y2, sf::RenderWindow& window );
        void drawCollider( my::Collider& col, sf::RenderWindow& window );
}

#endif // CUSTOMFUNCTIONS_H_INCLUDED
