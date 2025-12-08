#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/Utils.hpp>
#include <stdlib.h>

Screen1View::Screen1View()
{
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();

    // ========================================================
    // 1. CONFIGURARE CULORI (HEX convertit în RGB)
    // ========================================================
    const colortype COLOR_GRID_BG   = touchgfx::Color::getColorFromRGB(66, 24, 105);  // #421869
    const colortype COLOR_GRID_TILE = touchgfx::Color::getColorFromRGB(153, 91, 213); // #995BD5

    const colortype COLOR_SNAKE_HEAD = touchgfx::Color::getColorFromRGB(80, 151, 36); // #509724
    const colortype COLOR_SNAKE_BODY = touchgfx::Color::getColorFromRGB(150, 215, 76); // #96D74C
    const colortype COLOR_FOOD       = touchgfx::Color::getColorFromRGB(255, 0, 0);   // Roșu
    // ========================================================

    const int CELL_SIZE = 20;
    const int COLS = 12; // 240 / 20
    const int ROWS = 16; // 320 / 20

    // --- A. Desenare Fundal Grid (Culoarea închisă) ---
    backgroundBox.setXY(0, 0);
    backgroundBox.setWidth(240);
    backgroundBox.setHeight(320);
    backgroundBox.setColor(COLOR_GRID_BG);
    add(backgroundBox);

    // --- B. Desenare Model Șah (Culoarea deschisă) ---
    int boxIndex = 0;
    for (int y = 0; y < ROWS; y++)
    {
        for (int x = 0; x < COLS; x++)
        {
            // Desenăm pătrățelul doar dacă poziția este "impară"
            if ((x + y) % 2 != 0)
            {
                if (boxIndex < NUM_GRID_PATTERN)
                {
                    gridPattern[boxIndex].setXY(x * CELL_SIZE, y * CELL_SIZE);
                    gridPattern[boxIndex].setWidth(CELL_SIZE);
                    gridPattern[boxIndex].setHeight(CELL_SIZE);
                    gridPattern[boxIndex].setColor(COLOR_GRID_TILE);

                    add(gridPattern[boxIndex]);
                    boxIndex++;
                }
            }
        }
    }

    // --- 2. Inițializare Șarpe cu noile culori ---
    for (int i = 0; i < MAX_SNAKE_LENGTH; i++)
    {
        snakeSegments[i].setWidth(CELL_SIZE);
        snakeSegments[i].setHeight(CELL_SIZE);

        if (i == 0)
        {
            // Capul Șarpelui (#509724)
            snakeSegments[i].setColor(COLOR_SNAKE_HEAD);
        }
        else
        {
            // Corpul Șarpelui (#96D74C)
            snakeSegments[i].setColor(COLOR_SNAKE_BODY);
        }

        snakeSegments[i].setVisible(false);
        add(snakeSegments[i]);
    }

    // --- 3. Mâncare ---
    foodItem.setWidth(CELL_SIZE);
    foodItem.setHeight(CELL_SIZE);
    foodItem.setColor(COLOR_FOOD);
    foodItem.setVisible(false);
    add(foodItem);

    // --- 4. Scor ---
    // Îl scoatem din lista de desenare (de sub fundal)
        remove(Score);
        remove(box1);

        // Îl adăugăm din nou (astfel va fi desenat ultimul, DEASUPRA fundalului)
        add(Score);
        add(box1);

        // Forțăm redesenarea
        Score.invalidate();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

// ... Restul funcțiilor (updateSnakeUI, etc.) rămân neschimbate ...
// Asigură-te că le păstrezi!
void Screen1View::updateSnakeUI(int* xBody, int* yBody, int length)
{
   // ... codul tău existent ...
   const int GRID_SIZE = 20;
    for (int i = 0; i < MAX_SNAKE_LENGTH; i++)
    {
        if (i < length)
        {
            snakeSegments[i].invalidate();
            snakeSegments[i].setXY(xBody[i] * GRID_SIZE, yBody[i] * GRID_SIZE);
            if (!snakeSegments[i].isVisible()) snakeSegments[i].setVisible(true);
            snakeSegments[i].invalidate();
        }
        else
        {
            if (snakeSegments[i].isVisible())
            {
                snakeSegments[i].invalidate();
                snakeSegments[i].setVisible(false);
                snakeSegments[i].invalidate();
            }
        }
    }
}

void Screen1View::updateFoodUI(int x, int y)
{
    const int GRID_SIZE = 20;
    foodItem.invalidate();
    foodItem.setXY(x * GRID_SIZE, y * GRID_SIZE);
    if (!foodItem.isVisible()) foodItem.setVisible(true);
    foodItem.invalidate();
}

void Screen1View::updateScore(int score)
{
    Unicode::snprintf(ScoreBuffer, SCORE_SIZE, "%d", score);
    Score.invalidate();
}

void Screen1View::handleDragEvent(const touchgfx::DragEvent& evt)
{
    int dx = evt.getDeltaX();
    int dy = evt.getDeltaY();
    if (abs(dx) > abs(dy))
    {
        if (abs(dx) > 5) presenter->userSetDirection(dx > 0 ? 1 : 3);
    }
    else
    {
        if (abs(dy) > 5) presenter->userSetDirection(dy > 0 ? 2 : 0);
    }
}
