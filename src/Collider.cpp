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

        inf >> position.x; // position
        inf >> position.y;

        sf::Vector2f t_origin; // origin
        inf >> t_origin.x;
        inf >> t_origin.y;

        sf::Vector2f t_scale; // scale
        inf >> t_scale.x;
        inf >> t_scale.y;

        dimensions = my::vecM( t_size, t_scale ); // multiply by scale for correct size
        origin = my::vecM( t_origin, t_scale ); // multiply by scale for correct size

}



void my::Collider::update( sf::Vector2f t_position )
{
        position = t_position;
}
