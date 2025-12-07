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

void Screen1Presenter::updateSnakeGame(int* xBody, int* yBody, int length, int score, int foodX, int foodY)
{
    view.updateSnakeUI(xBody, yBody, length);
    view.updateFoodUI(foodX, foodY); // Vom crea asta în View
    view.updateScore(score);
}

void Screen1Presenter::userSetDirection(int d)
{
    model->setNewDirection(d);
}
