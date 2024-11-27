#include <SFML/Graphics.hpp>
#include <iostream>



class Point {
private:
    sf::Vector2f position;
    sf::CircleShape shape;

public:
    Point(float x, float y);
    

/*sf::FloatRect : structure de données rectangle  défini par ses coordonnées (left, top)
et sa taille (width, height), tous exprimés en float.
shape.getGlobalBounds() : shape est un objet de type sf::CircleShape (un cercle, dans ce cas).
La méthode getGlobalBounds() de sf::Shape (dont sf::CircleShape hérite) retourne un objet sf::FloatRect
qui représente le rectangle englobant du cercle. Ce rectangle englobe complètement le cercle
*/
    sf::FloatRect getBounds() const {
        return shape.getGlobalBounds();
    }



    void draw(sf::RenderWindow& window) const;
       
    

};

