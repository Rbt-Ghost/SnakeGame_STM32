#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/Utils.hpp>
#include <stdlib.h> // pentru abs()

Screen1View::Screen1View()
{
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();

    // 1. Inițializare Șarpe (Verde)
    for (int i = 0; i < MAX_SNAKE_LENGTH; i++)
    {
        // Folosim direct 20 sau constanta GRID_SIZE dacă e definită static
        snakeSegments[i].setWidth(20);
        snakeSegments[i].setHeight(20);
        snakeSegments[i].setColor(touchgfx::Color::getColorFromRGB(0, 255, 0)); // Verde
        snakeSegments[i].setVisible(false); // Invizibil la start
        add(snakeSegments[i]);
    }

    // 2. Inițializare Mâncare (Roșie)
    foodItem.setWidth(20);
    foodItem.setHeight(20);
    foodItem.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0)); // Roșu
    foodItem.setVisible(false);
    add(foodItem);
}

// --- ACEASTA ESTE FUNCȚIA CARE LIPSEA ---
void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}
// ----------------------------------------

void Screen1View::updateSnakeUI(int* xBody, int* yBody, int length)
{
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
    // Aici vei pune logica pentru scor (TextArea)
    // textScore.invalidate();
    // Unicode::snprintf(...)
    // textScore.invalidate();
}

void Screen1View::handleDragEvent(const touchgfx::DragEvent& evt)
{
    int dx = evt.getDeltaX();
    int dy = evt.getDeltaY();

    if (abs(dx) > abs(dy))
    {
        if (abs(dx) > 5)
        {
            if (dx > 0) presenter->userSetDirection(1); // Dreapta
            else        presenter->userSetDirection(3); // Stânga
        }
    }
    else
    {
        if (abs(dy) > 5)
        {
            if (dy > 0) presenter->userSetDirection(2); // Jos
            else        presenter->userSetDirection(0); // Sus
        }
    }
}
