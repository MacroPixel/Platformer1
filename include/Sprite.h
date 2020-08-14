#ifndef SPRITE_H
#define SPRITE_H

#include "HH.h"

namespace my
{
        class Sprite
        {
                sf::RectangleShape body;

                sf::Texture texture;
                sf::Vector2f size;
                sf::Vector2f position;

                unsigned int* imageTotalX;
                unsigned int imageTotalY;
                sf::Vector2u imageCurrent;
                unsigned int frameTotal;
                float* switchTime;

                float totalTime;
                int facing;

                sf::IntRect uvRect;

        public:
                Sprite( const char* t_filename );

                sf::RectangleShape& getBody();

                void update( float deltaTime );
                void setAnimation( unsigned int row );
                void setFacing( int facing );

                sf::Vector2f fileReadSize( const char* t_filename );
        };
}

#endif // SPRITE_H
