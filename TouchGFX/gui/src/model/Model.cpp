Model::Model() : modelListener(0), snakeLength(3), score(0), counter(0), direction(1)
{
    // Inițializează șarpele la o poziție de start
    snakeX[0] = 5; snakeY[0] = 5;
    // ... restul corpului
}

void Model::tick()
{
    counter++;
    if (counter % 10 == 0) // Executăm logica doar la fiecare 10 frame-uri (jocul e prea rapid altfel)
    {
        // 1. LOGICA DE MIȘCARE AICI
        // (Mută corpul, mută capul în funcție de 'direction')

        // ... codul tău de snake ...

        // 2. Notificăm interfața grafică
        if (modelListener != 0)
        {
            modelListener->updateSnakeGame(snakeX, snakeY, snakeLength, score);
        }
    }
}
