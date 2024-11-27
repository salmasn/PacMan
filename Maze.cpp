#include "Maze.h"
#include <vector>
#include <SFML/Graphics.hpp>
 //int Maze::WINDOW_WIDTH = 800;
 //int Maze::WINDOW_HEIGHT = 800;
 int Maze::TILE_SIZE = 40;



// Constructeur par defaut avec une grille predefinie
Maze::Maze()
    : grid({
          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
          {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
          {1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
          {1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
          {1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
          {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
          {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
          {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1},
          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
          {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
          {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
          {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1},
          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        }), wallColor(sf::Color::Red), pathColor(sf::Color::Black) {

    // Créer des points dans les cellules de type chemin (0)
    for (int i = 0; i <grid.size(); i++) {
        for (int j = 0; j <grid[i].size();j++) {
            if (grid[i][j] == 0) {  // Si c'est un chemin
                points.push_back(Point(j * TILE_SIZE, i * TILE_SIZE));  // Ajouter un point
            }
        }
    }
}




// Constructeur avec grille personnalise
Maze::Maze(const std::vector<std::vector<int>>& customGrid)
    : grid(customGrid), wallColor(sf::Color::Red), pathColor(sf::Color::Black) {}




// Dessigner maze
void Maze::draw(sf::RenderWindow& window) const {
    for (int i = 0; i <grid.size();i++) {
        for (int j = 0; j <grid[i].size();j++) {
            sf::RectangleShape Case(sf::Vector2f(TILE_SIZE, TILE_SIZE));
            Case.setPosition(j * TILE_SIZE, i * TILE_SIZE);

           Case.setFillColor(grid[i][j] == 1 ? wallColor : pathColor);
            window.draw(Case);
        }
    }

    // Dessiner tous les points
   
    for (int i = 0; i < points.size(); i++) {
        points[i].draw(window);  
    }

}



bool Maze::isPath(int x, int y) const {
    // Vérifie si les coordonnées sont valides
    if (x < 0 || x >grid[0].size() || y < 0 || y >= grid.size()) {
        return false; // Hors limites
    }
    return grid[y][x] == 0; // Retourne vrai si c'est un chemin noir
}


// Méthode pour enlever un point lorsque Pac-Man le mange

bool Maze::removePoint(const sf::Vector2f& pacmanPosition) {
    for (int i = 0; i < points.size(); i++) {
        
        /*contains permet de vérifier si un point donné 
        (ici, pacmanPosition, qui est un objet sf::Vector2f représentant la 
        position de Pacman) se trouve à l'intérieur du rectangle.*/
        if (points[i].getBounds().contains(pacmanPosition)) {
            
            points.erase(points.begin() + i);  // Supprimer le point à l'indice i
            return true;  // Retourner true si le point a été supprimé
        }
    }
    return false;  // Retourner false si aucun point n'a été supprimé
}


/*
// Méthode pour obtenir le nombre de points restants
int Maze::getRemainingPoints() const {
    return points.size();
}
*/



