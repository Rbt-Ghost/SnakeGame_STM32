#ifndef MODEL_HPP
#define MODEL_HPP

#include <gui/model/ModelListener.hpp>

class Model
{
public:
    Model();
    void tick();
    void bind(ModelListener* listener) { modelListener = listener; }

    // Funcție nouă pentru a primi input de la ecran
    void setNewDirection(int d);

protected:
    ModelListener* modelListener;

    static const int SNAKE_MAX_LEN = 100;
    static const int GRID_W = 20; // 480 / 20 = 24 celule (aprox)
    static const int GRID_H = 13; // 272 / 20 = 13 celule (aprox)

    int snakeX[SNAKE_MAX_LEN];
    int snakeY[SNAKE_MAX_LEN];
    int snakeLength;

    // Variabile noi pentru mâncare
    int foodX;
    int foodY;

    int score;
    int counter;
    int currentDirection; // 0=Sus, 1=Dr, 2=Jos, 3=St
    int nextDirection;    // Buffer pentru a preveni schimbarea bruscă (ex: stânga->dreapta instant)
};

#endif // MODEL_HPP
