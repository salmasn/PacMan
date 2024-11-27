#include "Point.h"

Point::Point(float x, float y)
{ 
        position = sf::Vector2f(x, y);
        shape.setRadius(8);  // Taille du point
        shape.setFillColor(sf::Color::Yellow);  // Couleur du point
        shape.setPosition(position);
}

void Point::draw(sf::RenderWindow& window) const
{
        window.draw(shape);
}
