#include <SFML/Graphics.hpp>
#include <iostream>



class Point {
private:
    sf::Vector2f position;
    sf::CircleShape shape;

public:
    Point(float x, float y);
    

/*sf::FloatRect : structure de donn�es rectangle  d�fini par ses coordonn�es (left, top)
et sa taille (width, height), tous exprim�s en float.
shape.getGlobalBounds() : shape est un objet de type sf::CircleShape (un cercle, dans ce cas).
La m�thode getGlobalBounds() de sf::Shape (dont sf::CircleShape h�rite) retourne un objet sf::FloatRect
qui repr�sente le rectangle englobant du cercle. Ce rectangle englobe compl�tement le cercle
*/
    sf::FloatRect getBounds() const {
        return shape.getGlobalBounds();
    }



    void draw(sf::RenderWindow& window) const;
       
    

};

