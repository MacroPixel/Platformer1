#include "HH.h"
#include "Sprite.h"
#include "Player.h"

// instantiate static member variables
std::vector<my::Player*> my::Player::objects;

int main()
{
        sf::RenderWindow window;
        window.create( sf::VideoMode( 1280, 720 ), "Epic Platformer" );

        new my::Player( "texture/guy/testfile.spr" );

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

                my::updateAll( deltaTime );
                my::drawAll( window );

                window.display();
        }

        return 0;
}
