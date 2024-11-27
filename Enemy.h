#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Maze.h" 
#include "PacMan.h"
#include "Personnage.h"


class Enemie :public Personnage {
private:
    static const int TILE_SIZE = 40;
    //sf::Sprite sprite;   // L'image de l'ennemi
    //sf::Texture texture; // La texture de l'ennemi
    //float speed;         // Vitesse de d�placement de l'ennemi
    int direction;       // indique dans quel direction l'ennemi se deplace  (0: gauche, 1: droite, 2: haut, 3: Bas)
    float movementTimer; // Timer pour contr�ler le rythme du mouvement

public:
    // Constructeur
    Enemie(const std::string& textureFile, float initSpeed);

    // M�thode pour positionner l'ennemi
    void setPosition(float x, float y);

    // M�thode pour obtenir la position de l'ennemi
    sf::Vector2f getPosition() const;

    // M�thode pour d�placer l'ennemi
    void move(float deltaTime, const Maze& maze);

    // M�thode pour dessiner l'ennemi
    void draw(sf::RenderWindow& window);

    //tester la collisione entre enemie et pacman
    bool checkCollision(const PacMan& pacMan) const;

};
