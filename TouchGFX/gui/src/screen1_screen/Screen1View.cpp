#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Color.hpp> // <--- ADAUGĂ ACEASTĂ LINIE
#include <touchgfx/Utils.hpp>

Screen1View::Screen1View()
{
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();

    // Inițializăm segmentele șarpelui
    for (int i = 0; i < MAX_SNAKE_LENGTH; i++)
    {
        snakeSegments[i].setWidth(20);  // Mărimea unui pătrățel
        snakeSegments[i].setHeight(20);
        snakeSegments[i].setColor(touchgfx::Color::getColorFromRGB(0, 255, 255)); // Cyan
        snakeSegments[i].setVisible(false); // Invizibil la start

        // Adăugăm la containerul creat în Designer (gameContainer)
        // Dacă nu ai un container numit 'gameContainer', folosește 'add(snakeSegments[i])'
        // gameContainer.add(snakeSegments[i]);
        add(snakeSegments[i]);
    }
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

// --- IMPLEMENTAREA FUNCȚIILOR LIPSĂ ---

void Screen1View::updateSnakeUI(int* xBody, int* yBody, int length)
{
    const int GRID_SIZE = 20; // Trebuie să fie la fel cu mărimea setată mai sus

    for (int i = 0; i < MAX_SNAKE_LENGTH; i++)
    {
        if (i < length)
        {
            // Segment activ
            snakeSegments[i].invalidate(); // Șterge poziția veche

            // Calculează poziția reală (Grid * Mărime)
            int pixelX = xBody[i] * GRID_SIZE;
            int pixelY = yBody[i] * GRID_SIZE;

            snakeSegments[i].setXY(pixelX, pixelY);

            if (!snakeSegments[i].isVisible())
            {
                snakeSegments[i].setVisible(true);
            }

            snakeSegments[i].invalidate(); // Desenează poziția nouă
        }
        else
        {
            // Segment inactiv (restul cozii)
            if (snakeSegments[i].isVisible())
            {
                snakeSegments[i].invalidate();
                snakeSegments[i].setVisible(false);
                snakeSegments[i].invalidate();
            }
        }
    }
}

void Screen1View::updateScore(int score)
{
    // Dacă ai un TextArea numit 'textScore' cu wildcard
    // Unicode::snprintf(textScoreBuffer, TEXTSCORE_SIZE, "%d", score);
    // textScore.invalidate();
}
