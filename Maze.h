#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Point.h"
class Maze {
private:
    //static  int WINDOW_WIDTH ;
    //static  int WINDOW_HEIGHT ;
    static  int TILE_SIZE ; // Taille d'une case de la grille

    // La grille du labyrinthe
    std::vector<std::vector<int>> grid;
    sf::Color wallColor;
    sf::Color pathColor;
    std::vector<Point> points;  // Liste des points

public:
    // Constructeur par defaut avec un labyrinthe predefini
    Maze();

    // Constructeur pour un labyrinthe personnalis�
    Maze(const std::vector<std::vector<int>>& customGrid);

  

    // Methode pour dessiner le labyrinthe dans la fen�tre SFML
    void draw(sf::RenderWindow& window) const;
   
    // Vérifie si une cellule est un chemin
     bool isPath(int x, int y) const;

     // Enlever un point quand Pac-Man le mange
     bool removePoint(const sf::Vector2f& pacmanPosition);  
     
     // Retourne le nombre de points restants
    // int getRemainingPoints() const;  
    
   /*  const std::vector<Point>& getPoints() const { return points; }  // Accéder aux points


    // Ajoutez une nouvelle méthode dans Maze pour vérifier la sortie
    bool isExit(int x, int y) const {
        // Vérifiez si Pac-Man se trouve dans la cellule de sortie (cellule noire en bas à droite)
        return (x == GRID_WIDTH - 1 && y == GRID_HEIGHT - 1 && grid[y][x] == 0);  // Dernière cellule noire
    }
    */
   
};
