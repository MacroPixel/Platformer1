#ifndef SPRITE_H
#define SPRITE_H

#include "HH.h"

namespace my
{
        class Sprite
        {
                // rectangle that texture is mapped to
                sf::RectangleShape body;

                // SE
                sf::Texture texture;

                // these are all used for the animation
                unsigned int* imageTotalX; // holds array of total images in each animation
                unsigned int imageTotalY; // holds total number of animations
                sf::Vector2u imageCurrent; // holds current frame (x & y)
                float* switchTime; // pointer because of spritesheets with multiple animations

                float totalTime; // holds the time elapsed since the last frame switch (in seconds)
                // this time is then compared to the switch time array

                int facing; // stores x scale modifier (1 for normal, -1 for facing other direction)

                sf::IntRect uvRect; // this is the actual rectangle structure that

        public:
                // cons/dest
                Sprite( const char* t_filename );
                ~Sprite();

                // getter for actual rectangle w/ texture
                sf::RectangleShape& getBody();

                void update( float deltaTime ); // should be called every frame to forward animation
                void setAnimation( unsigned int row ); // sets animation, resets frame if changed
                void setFacing( int facing ); // SE

                sf::Vector2f fileReadSize( const char* t_filename ); // this is to initialize body using direct initialization
        };
}

#endif // SPRITE_H
