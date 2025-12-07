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
    void updateFoodUI(int x, int y); // Funcție nouă
    void updateScore(int score);

    // --- Funcție TouchGFX pentru detectare SWIPE ---
    virtual void handleDragEvent(const touchgfx::DragEvent& evt);

protected:
    static const int MAX_SNAKE_LENGTH = 100;
    static const int GRID_SIZE = 20;

    touchgfx::Box snakeSegments[MAX_SNAKE_LENGTH];
    touchgfx::Box foodItem; // Pătrățelul roșu (Mâncarea)
};

#endif // SCREEN1VIEW_HPP
