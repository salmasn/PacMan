#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include"Personnage.h"
class PacMan :public Personnage
{
private:
   // sf::Sprite sprite;   // L'image de Pac-Man
    //sf::Texture texture;  // La texture de Pac-Man
    //float speed;          // Vitesse de deplacement de Pac-Man

public:
    // Constructeur
    PacMan(const std::string& textureFile, float initSpeed);


    // Methode pour positionner Pac-Man
    void setPosition(float x, float y);


    // Methodes pour deplacer Pac-Man
    void moveUp(float deltaTime);


    void moveDown(float deltaTime);



    void moveLeft(float deltaTime);



    void moveRight(float deltaTime);


    // Methode pour dessiner Pac-Man
    void draw(sf::RenderWindow& window);

    //recuperer position de pacman
    sf::Vector2f getPosition() const;

    /*
    sf::FloatRect getGlobalBounds() const; 
    */




};

