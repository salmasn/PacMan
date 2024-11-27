#include "PacMan.h"

PacMan::PacMan(const std::string& textureFile, float initSpeed)
{
    if (!texture.loadFromFile(textureFile)) {
        std::cerr << "Erreur : Impossible de charger l'image de Pac-Man" << std::endl;
        exit(-1);
    }
    sprite.setTexture(texture);
    speed = initSpeed;

}


void PacMan::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

// Methodes pour deplacer Pac-Man
void PacMan::moveUp(float deltaTime) {
    sprite.move(0, -speed * deltaTime);  // Deplacer vers le haut
}

void PacMan::moveDown(float deltaTime) {
    sprite.move(0, speed * deltaTime);   // Deplacer vers le bas
}

void PacMan::moveLeft(float deltaTime) {
    sprite.move(-speed * deltaTime, 0);  // Deplacer vers la gauche
}

void PacMan::moveRight(float deltaTime) {
    sprite.move(speed * deltaTime, 0);   // Deplacer vers la droite
}

// Methode pour dessiner Pac-Man
void PacMan::draw(sf::RenderWindow& window) {
    window.draw(sprite);  // Dessiner Pac-Man dans la fenetre
}
/*vector2f structure a 2 dimention(x, y) */
sf::Vector2f PacMan::getPosition() const
{
    return sprite.getPosition();
}

//a qoui sert
/*
sf::FloatRect PacMan::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}
*/



