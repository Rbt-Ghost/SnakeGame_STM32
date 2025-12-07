#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <stdlib.h> // rand()

Model::Model() : modelListener(0), score(0), counter(0),
                 currentDirection(1), nextDirection(1),
                 isGameRunning(false), isGameOver(false) // Jocul începe oprit
{
    resetGame();
}

void Model::resetGame()
{
    // Inițializare șarpe
    snakeLength = 3;
    for(int i = 0; i < SNAKE_MAX_LEN; i++) {
        snakeX[i] = -100; snakeY[i] = -100;
    }

    // Punem șarpele în mijlocul ecranului
    int startX = GRID_WIDTH / 2;
    int startY = GRID_HEIGHT / 2;

    snakeX[0] = startX;     snakeY[0] = startY;
    snakeX[1] = startX - 1; snakeY[1] = startY;
    snakeX[2] = startX - 2; snakeY[2] = startY;

    score = 0;
    currentDirection = 1; // Dreapta
    nextDirection = 1;
    isGameRunning = false; // Așteaptă input
    isGameOver = false;

    // Generăm prima mâncare
    foodX = rand() % GRID_WIDTH;
    foodY = rand() % GRID_HEIGHT;
}

void Model::tick()
{
    // --- FIX 1: Dacă jocul nu rulează, nu facem nimic ---
    if (!isGameRunning || isGameOver)
    {
        // Totuși, trimitem datele ca să se deseneze starea inițială
        if (modelListener != 0 && counter == 0)
        {
             modelListener->updateSnakeGame(snakeX, snakeY, snakeLength, score, foodX, foodY);
             counter++;
        }
        return;
    }

    counter++;
    if (counter % 10 == 0)
    {
        // Actualizare direcție
        if ((nextDirection == 0 && currentDirection != 2) ||
            (nextDirection == 1 && currentDirection != 3) ||
            (nextDirection == 2 && currentDirection != 0) ||
            (nextDirection == 3 && currentDirection != 1))
        {
            currentDirection = nextDirection;
        }

        // Calculăm viitoarea poziție a capului
        int newHeadX = snakeX[0];
        int newHeadY = snakeY[0];

        switch (currentDirection)
        {
            case 0: newHeadY--; break; // Sus
            case 1: newHeadX++; break; // Dreapta
            case 2: newHeadY++; break; // Jos
            case 3: newHeadX--; break; // Stânga
        }

        // --- FIX 3: Verificare Coliziune cu Pereții ---
        if (newHeadX < 0 || newHeadX >= GRID_WIDTH ||
            newHeadY < 0 || newHeadY >= GRID_HEIGHT)
        {
            isGameOver = true; // S-a lovit de zid
            // Aici ai putea reseta jocul automat:
            resetGame();
            return;
        }

        // Verificare coliziune cu propriul corp
        for (int i = 1; i < snakeLength; i++)
        {
            if (newHeadX == snakeX[i] && newHeadY == snakeY[i])
            {
                resetGame();
                return;
            }
        }

        // Mutăm corpul
        for (int i = snakeLength; i > 0; i--)
        {
            snakeX[i] = snakeX[i-1];
            snakeY[i] = snakeY[i-1];
        }

        // Mutăm capul
        snakeX[0] = newHeadX;
        snakeY[0] = newHeadY;

        // Verificăm mâncarea
        if (snakeX[0] == foodX && snakeY[0] == foodY)
        {
            score += 10;
            if (snakeLength < SNAKE_MAX_LEN) snakeLength++;

            // --- FIX 4: Mâncarea se spawnează STRICT în grid ---
            foodX = rand() % GRID_WIDTH;
            foodY = rand() % GRID_HEIGHT;
        }

        if (modelListener != 0)
        {
            modelListener->updateSnakeGame(snakeX, snakeY, snakeLength, score, foodX, foodY);
        }
    }
}

void Model::setNewDirection(int d)
{
    // --- FIX 1: Primul swipe pornește jocul ---
    if (!isGameRunning) {
        isGameRunning = true;
    }

    nextDirection = d;
}
