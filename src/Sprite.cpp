#include "Sprite.h"

my::Sprite::Sprite( const char* t_filename ) :
        body( fileReadSize( t_filename ) ), imageCurrent( 0, 1 )
{
        // read stuff from .spr file
        std::ifstream inf{ t_filename };

        // main texture stuff
        std::string textureFilename;
        inf >> textureFilename;
        texture.loadFromFile( textureFilename );

        sf::Vector2f t_size;
        inf >> t_size.x;
        inf >> t_size.y;

        inf >> position.x;
        inf >> position.y;

        sf::Vector2f t_origin;
        inf >> t_origin.x;
        inf >> t_origin.y;

        sf::Vector2f t_scale;
        inf >> t_scale.x;
        inf >> t_scale.y;

        body.setTexture( &texture );
        body.setSize( t_size );
        body.setPosition( position );
        body.setOrigin( t_origin );
        body.setScale( t_scale );

        // facing doesn't need to read from file
        facing = 1;

        // animation stuff
        inf >> imageTotalY;

        imageTotalX = new unsigned int[ imageTotalY ];
        switchTime = new float[ imageTotalY ];

        for( int i = 0; i < static_cast<int>( imageTotalY ); ++i )
                inf >> imageTotalX[ i ];
        for( int i = 0; i < static_cast<int>( imageTotalY ); ++i )
                inf >> switchTime[ i ];

        frameTotal = 8;
        totalTime = 0;

        uvRect.width = t_size.x;
        uvRect.height = t_size.y;
}

my::Sprite::~Sprite()
{
        delete[] imageTotalX;
        delete[] switchTime;
}

sf::RectangleShape& my::Sprite::getBody()
{
        return body;
}

void my::Sprite::update( float deltaTime )
{
        // increment time and set the rect position to that of the correct animation
        totalTime += deltaTime;

        // this is to make referencing thingy easier
        const float& switchTimeC = switchTime[ imageCurrent.y ];

        if ( totalTime >= switchTimeC ) // this means more than the time between frames has elapsed, so we should switch
        {
                while ( totalTime >= switchTimeC )
                        totalTime -= switchTimeC;
                ++( imageCurrent.x );

                if ( imageCurrent.x >= imageTotalX[ imageCurrent.y ] )
                        imageCurrent.x = 0;
        }

        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Z ) )
        {
                std::cout << uvRect.width << '\n';
        }

        // update the rectangle position
        uvRect.left = ( imageCurrent.x % frameTotal ) * uvRect.width;
        uvRect.top = imageCurrent.y * uvRect.height;

        body.setTextureRect( uvRect ); // this actually updates the texture
        body.setScale( sf::Vector2f( abs( body.getScale().x ) * facing, body.getScale().y ) );
}

void my::Sprite::setAnimation( unsigned int row )
{
        if ( imageCurrent.y != row )
        {
                imageCurrent = sf::Vector2u( 0, row );
                update( 0 );
        }
}

void my::Sprite::setFacing( int facing )
{
        this->facing = facing;
        update( 0 );
}

sf::Vector2f my::Sprite::fileReadSize( const char* t_filename )
{
        std::ifstream inf{ t_filename };
        sf::Vector2f returnValue;

        inf >> returnValue.x;
        inf >> returnValue.y;

        return returnValue;
}
