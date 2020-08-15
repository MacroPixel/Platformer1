#include "HH.h"
#include "Sprite.h"
#include "Player.h"
#include "Block.h"

// these static member variables hold pointers to every instance of that object
// I'm pretty sure they have to be instantiated here to be usable
std::vector<my::Player*> my::Player::objects;
std::vector<my::Block*> my::Block::objects;

int main()
{
        // this creates the window, assigning it to the "window" variable
        sf::RenderWindow window;
        window.create( sf::VideoMode( 1280, 720 ), "Epic Platformer" );

        // this dynamically allocates a player; this doesn't necessarily cause a memory leak because it's address is stored in my::Player::objects
        new my::Player( "texture/player_spritesheet.spr" );

        // this creates 10 blocks, each one next to each other; memory leak is avoided for the same reason as with the player object
        for( int i = 0; i < 10; ++i )
        {
                my::Block* tempBlock = new my::Block( "texture/block.spr" );
                tempBlock->getBody().setPosition( sf::Vector2f( 32 + ( i * 64 ), 32 ) );
        }

        // clock is used with deltaTime, so they're both instantiated here
        sf::Clock clock;
        float deltaTime;

        // MAIN LOOP

        while ( window.isOpen() )
        {
                // update deltaTime to store number of seconds since last frame
                deltaTime = clock.restart().asSeconds();

                // EVENT CHECKING

                sf::Event event;
                while ( window.pollEvent( event ) )
                {
                        if ( event.type == sf::Event::Closed )
                                window.close();
                }

                // draw window
                window.clear( sf::Color::White );

                // SE
                my::updateAll( deltaTime );
                my::drawAll( window );

                window.display();
        }

        // success
        return 0;
}
