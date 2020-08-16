#include "HH.h"
#include "Player.h"
#include "Block.h"

namespace my
{
        void updateAll( float deltaTime )
        {
                // player
                for( auto ptr : my::Player::objects )
                {
                        ptr->update( deltaTime );
                }
        }




        void drawAll( sf::RenderWindow& window )
        {
                // player
                for( auto ptr : my::Player::objects )
                {
                        window.draw( ptr->getBody() );
                }

                // blocks
                for( auto ptr : my::Block::objects )
                {
                        window.draw( ptr->getBody() );
                }
        }




        sf::Vector2f vecX( float x )
        {
                return sf::Vector2f( x, 0 );
        }




        sf::Vector2f vecY( float y )
        {
                return sf::Vector2f( 0, y );
        }



        sf::Vector2f vecM( sf::Vector2f vecA, sf::Vector2f vecB )
        {
                return sf::Vector2f( vecA.x * vecB.x, vecA.y * vecB.y );
        }



        void drawRect( float x1, float y1, float x2, float y2, sf::RenderWindow& window )
        {
                sf::RectangleShape tempRect( sf::Vector2f( abs( x1 - x2 ), abs( y1 - y2 ) ) );
                tempRect.setPosition( sf::Vector2f( x1, y1 ) );
                tempRect.setFillColor( sf::Color::Transparent );
                tempRect.setOutlineColor( sf::Color::Red );
                tempRect.setOutlineThickness( 1 );

                window.draw( tempRect );
        }

        void drawCollider( my::Collider& col, sf::RenderWindow& window )
        {
                drawRect( col.position.x - col.origin.x, col.position.y - col.origin.y, col.position.x + col.dimensions.x - col.origin.x, col.position.y + col.dimensions.y - col.origin.y, window );
        }
}
