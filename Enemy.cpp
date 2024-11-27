#include "Enemy.h"
#include <iostream>
#include <cmath> // Pour std::floor

// Constructeur
Enemie::Enemie(const std::string& textureFile, float initSpeed) : direction(0), movementTimer(0)
{
    if (!texture.loadFromFile(textureFile)) {
        std::cerr << "Erreur de chargement de la texture de l'ennemi!" << std::endl;
    }
    sprite.setTexture(texture);
    speed = initSpeed;
}

// Methode pour positionner l'ennemi
void Enemie::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

// M�thode pour obtenir la position de l'ennemi
sf::Vector2f Enemie::getPosition() const {
    return sprite.getPosition();
}


// Methode pour deplacer l'ennemi
void Enemie::move(float deltaTime, const Maze& maze) {
    // Conversion de la position de l'ennemi en coordonn�es de grille
    sf::Vector2f position = sprite.getPosition();

    //pour obtenir l'indice de la grill associe
    int gridX = std::floor(position.x / TILE_SIZE);
    int gridY = std::floor(position.y / TILE_SIZE);

    // Incremente le timer
    movementTimer += deltaTime;

    // Se d�placer uniquement apr�s un certain intervalle
    if (movementTimer >= 0.5f) { // 0.5s entre les mouvements
        movementTimer = 0; // Reinitialiser le timer

        // Calcul de la nouvelle position en fonction de la direction actuelle
        int newGridX = gridX, newGridY = gridY;
        switch (direction) {
        case 0: // Gauche
            newGridX -= 1;
            break;
        case 1: // Droite
            newGridX += 1;
            break;
        case 2: // Haut
            newGridY += 1;
            break;
        case 3: // bas
            newGridY -= 1;
            break;
        }

        // V�rification si le d�placement est valide
        if (maze.isPath(newGridX, newGridY)) {
            // Appliquer le mouvement
            sprite.setPosition(newGridX * TILE_SIZE, newGridY * TILE_SIZE);
        }
        // Passer � la direction suivante (0 -> 1 -> 2 -> 3)
        direction = (direction + 1) % 4;

    }
}


// M�thode pour dessiner l'ennemi
void Enemie::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

bool Enemie::checkCollision(const PacMan& pacMan) const
{
    // R�cup�rer la position de Pac-Man
    sf::Vector2f pacPosition = pacMan.getPosition();

    // R�cup�rer la position de l'ennemi
    sf::Vector2f enemyPosition = sprite.getPosition();

    // V�rifier si les positions se chevauchent
    return std::abs(pacPosition.x - enemyPosition.x) < TILE_SIZE &&
        std::abs(pacPosition.y - enemyPosition.y) < TILE_SIZE;
}


// M�thode pour tuer l'ennemi (r�initialisation de sa position)
void Enemie::die() {
    //sprite.setPosition(-100, -100); // D�place l'ennemi en dehors de l'�cran
}
