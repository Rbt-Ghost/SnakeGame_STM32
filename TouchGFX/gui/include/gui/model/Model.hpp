#ifndef MODEL_HPP
#define MODEL_HPP

#include <gui/model/ModelListener.hpp>

class Model
{
public:
    Model();
    void tick();
    void bind(ModelListener* listener) { modelListener = listener; }
    void setNewDirection(int d);

protected:
    ModelListener* modelListener;

    static const int SNAKE_MAX_LEN = 100;

    // --- FIX 4: Definire corectă Grid (pentru ecran 240x320 sau 320x240) ---
    // Dacă ai ecran 320x240 și bloc de 20px: 320/20 = 16, 240/20 = 12
    // Dacă ai ecran 240x320: 240/20 = 12, 320/20 = 16
    // Ajustează numerele de mai jos în funcție de rezoluția ta din TouchGFX!
    static const int GRID_WIDTH  = 12; // Exemplu pentru lățime ecran 240px
    static const int GRID_HEIGHT = 16; // Exemplu pentru înălțime ecran 320px

    int snakeX[SNAKE_MAX_LEN];
    int snakeY[SNAKE_MAX_LEN];
    int snakeLength;

    int foodX;
    int foodY;

    int score;
    int counter;
    int currentDirection;
    int nextDirection;

    // --- FIX 1: Variabilă pentru starea jocului ---
    bool isGameRunning;
    bool isGameOver;

    void resetGame(); // Funcție helper
};

#endif // MODEL_HPP
