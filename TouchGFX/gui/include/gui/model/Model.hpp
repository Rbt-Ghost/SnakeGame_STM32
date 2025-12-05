#ifndef MODEL_HPP
#define MODEL_HPP

// --- ASIGURĂ-TE CĂ AI ACEST INCLUDE ---
#include <gui/model/ModelListener.hpp>

class Model
{
public:
    Model();
    void tick();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

protected:
    ModelListener* modelListener;

    // --- VARIABILELE PENTRU SNAKE ---
    static const int SNAKE_MAX_LEN = 100;
    int snakeX[SNAKE_MAX_LEN];
    int snakeY[SNAKE_MAX_LEN];
    int snakeLength;
    int score;
    int counter;
    int direction; // 0=Sus, 1=Dr, 2=Jos, 3=St
};

#endif // MODEL_HPP
