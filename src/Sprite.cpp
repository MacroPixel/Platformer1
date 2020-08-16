#include "Sprite.h"

my::Sprite::Sprite( const char* t_filename ) :
        body( fileReadSize( t_filename ) ), imageCurrent( 0, 1 )
{
        // initializes ifstream object, which can then allow file stuff to be inserted into variables
        std::ifstream inf{ t_filename };

        // loads texture using what's in the file
        std::string textureFilename;
        inf >> textureFilename;
        texture.loadFromFile( textureFilename );

        // loads rectangle size (single image unscaled) from the file
        sf::Vector2f t_size;
        inf >> t_size.x;
        inf >> t_size.y;

        // loads rectangle position
        sf::Vector2f t_position;
        inf >> t_position.x;
        inf >> t_position.y;

        // loads rectangle origin
        sf::Vector2f t_origin;
        inf >> t_origin.x;
        inf >> t_origin.y;

        // loads rectangle scale
        sf::Vector2f t_scale;
        inf >> t_scale.x;
        inf >> t_scale.y;

        // updates the body rect with aforementioned variables
        // (body rect is what the player actually sees)
        body.setTexture( &texture );
        body.setSize( t_size );
        body.setPosition( t_position );
        body.setOrigin( t_origin );
        body.setScale( t_scale );

        facing = 1; // facing doesn't need to read from file
        inf >> imageTotalY; // reads total number of animations from file

        // initalizes two arrays that containing a value for each animation; dynamic allocation used because non-compile-time constant
        imageTotalX = new unsigned int[ imageTotalY ];
        switchTime = new float[ imageTotalY ];

        // this fills the arrays in based on the file
        for( int i = 0; i < static_cast<int>( imageTotalY ); ++i )
                inf >> imageTotalX[ i ];
        for( int i = 0; i < static_cast<int>( imageTotalY ); ++i )
                inf >> switchTime[ i ];

        totalTime = 0; // no time has elapsed yet

        // this rectangle determines what part of the spritesheet we can see; we only want the "window" to be the dimensions of one image
        uvRect.width = t_size.x;
        uvRect.height = t_size.y;
}




my::Sprite::~Sprite()
{
        // prevent memory leak
        delete[] imageTotalX;
        delete[] switchTime;
}




// getter for actual rectangle w/ texture
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
                // while loop used in case image must be incremented multiple times
                while ( totalTime >= switchTimeC )
                        totalTime -= switchTimeC;
                ++( imageCurrent.x );

                // wrap image back around if exceeding frame count for current animation
                if ( imageCurrent.x >= imageTotalX[ imageCurrent.y ] )
                        imageCurrent.x = 0;
        }

        // update the rectangle position
        uvRect.left = ( imageCurrent.x ) * uvRect.width;
        uvRect.top = imageCurrent.y * uvRect.height;

        body.setTextureRect( uvRect ); // this actually updates the texture
        body.setScale( sf::Vector2f( abs( body.getScale().x ) * facing, body.getScale().y ) ); // this flips the texture around kf needed
}




// sets animation, resets frame if changed
void my::Sprite::setAnimation( unsigned int row )
{
        if ( imageCurrent.y != row )
        {
                imageCurrent = sf::Vector2u( 0, row );
                update( 0 );
        }
}




// SE
void my::Sprite::setFacing( int facing )
{
        this->facing = facing;
        update( 0 );
}




// this is to initialize body using direct initialization
sf::Vector2f my::Sprite::fileReadSize( const char* t_filename )
{
        std::ifstream inf{ t_filename };
        sf::Vector2f returnValue;

        inf >> returnValue.x;
        inf >> returnValue.y;

        return returnValue;
}
