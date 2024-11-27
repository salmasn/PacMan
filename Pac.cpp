#include <SFML/Graphics.hpp>
#include <iostream>
#include "PacMan.h"
//#include "Maze.h"
#include "Enemy.h"

const int CELL_SIZE = 40;    // Taille d'une cellule (40x40 pixels)
const int GRID_WIDTH = 30;   // Largeur du labyrinthe en cellules
const int GRID_HEIGHT = 25;  // Hauteur du labyrinthe en cellules

int main() {
    // Création du labyrinthe
    Maze maze;

    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pac-Man Game");

    // Vitesse de Pac-Man
    float speed = 100.0f;

    // Création de Pac-Man
    PacMan pacman("pac.png", speed);
    pacman.setPosition(40, 40);

    sf::Clock clock;

    // Variable de score
    int score = 0;


    //LES ENEMY

     // Cr�ation des ennemis
    Enemie enemy("enemy1.png", 50.0f);
    enemy.setPosition(400.0f, 100.0f); // Position initiale de l'ennemi

    Enemie enemy1("enemy1.png", 50.0f);
    enemy1.setPosition(80.0f, 80.0f); // Position initiale de l'ennemi1

    Enemie enemy2("enemy1.png", 50.0f);
    enemy2.setPosition(500.0f, 500.0f);

    Enemie enemy3("enemy1.png", 50.0f);
    enemy3.setPosition(400.0f, 360.0f); // Position initiale de l'ennemi3
    std::vector<Enemie*> enemies = { &enemy, &enemy1, &enemy2, &enemy3 };

    // Chargement de la police
    sf::Font font;
    if (!font.loadFromFile("Roboto-Black.ttf")) {
        std::cerr << "Erreur : Impossible de charger la police." << std::endl;
        return -1;
    }

    // Création des textes
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10.f, GRID_HEIGHT * CELL_SIZE + 10.f);

    sf::Text endMessage;
    endMessage.setFont(font);
    endMessage.setCharacterSize(36);
    endMessage.setFillColor(sf::Color::White);
    endMessage.setString("Game Over! Score: 0");

    // Création du rectangle de fond
    sf::RectangleShape backgroundRect(sf::Vector2f(400, 100));  // Dimensions du rectangle
    backgroundRect.setFillColor(sf::Color(50, 50, 50, 200));   // Couleur gris semi-transparent
    backgroundRect.setOutlineColor(sf::Color::Yellow);         // Couleur de la bordure
    backgroundRect.setOutlineThickness(5);                    // Épaisseur de la bordure

    // Positionnement au centre de la fenêtre
    backgroundRect.setPosition(150, 200);

    // Coordonnées de la cellule de fin
    const int END_CELL_X = 19; // Dernière colonne
    const int END_CELL_Y = 13; // Dernière ligne

    // Indicateur pour savoir si le jeu est terminé
    bool isGameOver = false;

    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Calcul de deltaTime
        sf::Time deltaTime = clock.restart();
        float deltaSeconds = deltaTime.asSeconds();

        if (!isGameOver) {
            // Gestion des mouvements avec les méthodes de Pac-Man
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                sf::Vector2f proposedPosition = pacman.getPosition() + sf::Vector2f(0, -speed * deltaSeconds);
                int pacmanCellX =proposedPosition.x / CELL_SIZE;
                int pacmanCellY = proposedPosition.y / CELL_SIZE;

                if (maze.isPath(pacmanCellX, pacmanCellY)) {
                    pacman.moveUp(deltaSeconds);
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                sf::Vector2f proposedPosition = pacman.getPosition() + sf::Vector2f(0, speed * deltaSeconds);
                int pacmanCellX = proposedPosition.x / CELL_SIZE;
                int pacmanCellY = proposedPosition.y / CELL_SIZE;

                if (maze.isPath(pacmanCellX, pacmanCellY)) {
                    pacman.moveDown(deltaSeconds);
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sf::Vector2f proposedPosition = pacman.getPosition() + sf::Vector2f(-speed * deltaSeconds, 0);
                int pacmanCellX = proposedPosition.x / CELL_SIZE;
                int pacmanCellY = proposedPosition.y / CELL_SIZE;

                if (maze.isPath(pacmanCellX, pacmanCellY)) {
                    pacman.moveLeft(deltaSeconds);
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                sf::Vector2f proposedPosition = pacman.getPosition() + sf::Vector2f(speed * deltaSeconds, 0);
                int pacmanCellX = proposedPosition.x / CELL_SIZE;
                int pacmanCellY = proposedPosition.y / CELL_SIZE;

                if (maze.isPath(pacmanCellX, pacmanCellY)) {
                    pacman.moveRight(deltaSeconds);
                }
            }

            // Vérifiez si Pac-Man atteint la cellule finale
            int pacmanCellX = pacman.getPosition().x / CELL_SIZE;
            int pacmanCellY = pacman.getPosition().y / CELL_SIZE;

            if (pacmanCellX == END_CELL_X && pacmanCellY == END_CELL_Y) {
                isGameOver = true;

                // Mettez à jour le message de fin avec le score final
                endMessage.setString("Great! Score: " + std::to_string(score));

                // Centrer le message
                endMessage.setPosition(
                    backgroundRect.getPosition().x + (backgroundRect.getSize().x - endMessage.getGlobalBounds().width) / 2,
                    backgroundRect.getPosition().y + (backgroundRect.getSize().y - endMessage.getGlobalBounds().height) / 2
                );
            }


        
            for (auto& e : enemies) {
                e->move(deltaSeconds, maze); // D�placer l'ennemi
            }

            // V�rification des collisions entre Pac-Man et les ennemis
            for (auto& e : enemies) {
                if (e->checkCollision(pacman)) { // Appel avec l'objet Pac-Man
                    isGameOver = true;  // Collision d�tect�e, fin du jeu
                    break;
                }
            }
        }



     


       
        



        // Mise à jour du score lorsqu'un point est mangé
        if (!isGameOver && maze.removePoint(pacman.getPosition())) {
            score += 4;  // Ajouter 4 au score
        }

        // Dessiner
        window.clear(sf::Color::Black);
        maze.draw(window);
        enemy1.draw(window);
        enemy2.draw(window);
        enemy3.draw(window);

        if (!isGameOver) {
            pacman.draw(window);
        }
        else {
            // Affichez le message de fin
            window.draw(backgroundRect);
            window.draw(endMessage);
        }





      

        window.display();
    }

    return 0;
}
