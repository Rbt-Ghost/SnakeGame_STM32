#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

// Constructorul
Model::Model() : modelListener(0), snakeLength(3), score(0), counter(0), direction(1)
{
    // Inițializare simplă a șarpelui (în afara ecranului inițial)
    for(int i = 0; i < SNAKE_MAX_LEN; i++) {
        snakeX[i] = -20;
        snakeY[i] = -20;
    }

    // Setăm capul șarpelui la o poziție vizibilă (ex: 5,5 în grilă)
    snakeX[0] = 5;
    snakeY[0] = 5;
}

// Funcția care rulează în buclă (tick)
void Model::tick()
{
    counter++;

    // Actualizăm logica doar o dată la 10 frame-uri (pentru a încetini jocul)
    if (counter % 10 == 0)
    {
        // --- AICI VEI SCRIE LOGICA JOCULUI MAI TÂRZIU ---

        // Trimitem datele către interfață (View)
        if (modelListener != 0)
        {
            modelListener->updateSnakeGame(snakeX, snakeY, snakeLength, score);
        }
    }
}
