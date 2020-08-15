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
}
