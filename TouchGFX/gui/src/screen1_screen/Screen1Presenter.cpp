#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::updateSnakeGame(int* xBody, int* yBody, int length, int score)
{
    // Trimite datele mai departe către View
    view.updateSnakeUI(xBody, yBody, length);
    view.updateScore(score);
}
