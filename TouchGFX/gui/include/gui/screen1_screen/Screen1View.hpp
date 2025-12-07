#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void updateSnakeUI(int* xBody, int* yBody, int length);
    void updateFoodUI(int x, int y);
    void updateScore(int score);
    virtual void handleDragEvent(const touchgfx::DragEvent& evt);

protected:
    static const int MAX_SNAKE_LENGTH = 100;

    // --- MODIFICARE PENTRU PATTERN ---
    // Ecran 240x320 / 20px = 12x16 celule = 192 celule total.
    // Avem nevoie de jumătate din ele pentru modelul de șah (96).
    static const int NUM_GRID_PATTERN = 96;

    touchgfx::Box backgroundBox;             // Culoarea 1 (Fundal)
    touchgfx::Box gridPattern[NUM_GRID_PATTERN]; // Culoarea 2 (Pătrățele)
    // ---------------------------------

    touchgfx::Box snakeSegments[MAX_SNAKE_LENGTH];
    touchgfx::Box foodItem;
};

#endif // SCREEN1VIEW_HPP
