#include "HH.h"
#include "Sprite.h"
#include "Player.h"

int main()
{
        sf::RenderWindow window;
        window.create( sf::VideoMode( 1280, 720 ), "Epic Platformer" );

        my::Player player( "texture/guy/testfile.spr" );

        sf::Clock clock;
        float deltaTime;

        while ( window.isOpen() )
        {
                deltaTime = clock.restart().asSeconds();

                sf::Event event;
                while ( window.pollEvent( event ) )
                {
                        if ( event.type == sf::Event::Closed )
                                window.close();
                }

                window.clear( sf::Color::White );

                player.getSprite().update( deltaTime );

                if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Num1 ) )
                        player.getSprite().setAnimation( 0 );
                if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Num2 ) )
                        player.getSprite().setAnimation( 1 );
                if ( sf::Keyboard::isKeyPressed( sf::Keyboard::F ) )
                        player.getSprite().setFacing( -1 );
                if ( sf::Keyboard::isKeyPressed( sf::Keyboard::G ) )
                        player.getSprite().setFacing( 1 );

                window.draw( player.getBody() );

                window.display();
        }

        return 0;
}
