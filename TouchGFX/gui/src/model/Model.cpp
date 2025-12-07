#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <stdlib.h> // Pentru rand()

Model::Model() : modelListener(0), snakeLength(3), score(0), counter(0),
                 currentDirection(1), nextDirection(1)
{
    // 1. Start Snake la mijloc
    for(int i = 0; i < SNAKE_MAX_LEN; i++) {
        snakeX[i] = -100; snakeY[i] = -100;
    }
    snakeX[0] = 5; snakeY[0] = 5; // Cap
    snakeX[1] = 4; snakeY[1] = 5;
    snakeX[2] = 3; snakeY[2] = 5;

    // 2. Start Mâncare
    foodX = 10;
    foodY = 5;
}

void Model::tick()
{
    counter++;

    // Viteza jocului: O dată la 10 frame-uri (cca 6 ori/secundă)
    if (counter % 10 == 0)
    {
        // A. Actualizăm direcția (doar dacă nu e opusă)
        // Previne ca șarpele să intre în el însuși (ex: merge dreapta, tu apeși stânga)
        if ((nextDirection == 0 && currentDirection != 2) ||
            (nextDirection == 1 && currentDirection != 3) ||
            (nextDirection == 2 && currentDirection != 0) ||
            (nextDirection == 3 && currentDirection != 1))
        {
            currentDirection = nextDirection;
        }

        // B. Mutăm Corpul (fiecare segment ia locul celui din față)
        for (int i = snakeLength; i > 0; i--)
        {
            snakeX[i] = snakeX[i-1];
            snakeY[i] = snakeY[i-1];
        }

        // C. Mutăm Capul
        switch (currentDirection)
        {
            case 0: snakeY[0]--; break; // Sus
            case 1: snakeX[0]++; break; // Dreapta
            case 2: snakeY[0]++; break; // Jos
            case 3: snakeX[0]--; break; // Stânga
        }

        // D. Verificăm Coliziune cu Mâncarea
        if (snakeX[0] == foodX && snakeY[0] == foodY)
        {
            score += 10; // Adaugă scor
            if (snakeLength < SNAKE_MAX_LEN)
            {
                snakeLength++; // Crește șarpele
            }

            // Generează mâncare nouă (simplu)
            // Notă: Ideal ar fi să verifici să nu cadă pe șarpe, dar pentru început e ok
            foodX = rand() % 20; // 0..19
            foodY = rand() % 12; // 0..11
        }

        // E. Trimitem totul la View
        if (modelListener != 0)
        {
            // Observă că am adăugat foodX și foodY la parametri!
            modelListener->updateSnakeGame(snakeX, snakeY, snakeLength, score, foodX, foodY);
        }
    }
}

void Model::setNewDirection(int d)
{
    nextDirection = d;
}
