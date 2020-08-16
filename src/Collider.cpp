#include "Collider.h"
#include <string>
#include <fstream>


my::Collider::Collider( const char* t_filename )
//                position( 640, 360 ), origin( 32, 32 ), dimensions( 64, 64 )
{
        std::string placeholder; // used to extract garbage into
        std::ifstream inf{ t_filename };

        inf >> placeholder; // filename

        sf::Vector2f t_size; // real size
        inf >> t_size.x;
        inf >> t_size.y;

        inf >> posX; // position
        inf >> posY;

        sf::Vector2f t_origin; // origin
        inf >> t_origin.x;
        inf >> t_origin.y;

        sf::Vector2f t_scale; // scale
        inf >> t_scale.x;
        inf >> t_scale.y;

        sizeX = t_size.x * t_scale.x;
        sizeY = t_size.x * t_scale.y;
        originX = t_origin.x * t_scale.x;
        originY = t_origin.y * t_scale.y;

}



bool my::Collider::checkCollision( const my::Collider& solid, float& outputPos )
{
        sf::Vector2f deltaPos; sf::Vector2f minDeltaPos; sf::Vector2f result;
        deltaPos.x = abs( posX - solid.posX ); deltaPos.y = abs( posY - solid.posY );
        minDeltaPos.x = ( sizeX + solid.sizeX ) / 2; minDeltaPos.y = ( sizeY + solid.sizeY ) / 2;
        result.x = deltaPos.x - minDeltaPos.x; result.y = deltaPos.y - minDeltaPos.y;

        outputPos = ( posX < solid.posX ?
                solid.posX - solid.originX - sizeX + originX :
                solid.posX - solid.originX + solid.sizeX + originX );

        return ( result.x < 0 && result.y < 0 );
}



void my::Collider::update( sf::Vector2f t_position )
{
        posX = t_position.x;
        posY = t_position.y;
}
