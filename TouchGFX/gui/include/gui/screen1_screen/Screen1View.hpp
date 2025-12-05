#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <touchgfx/widgets/Box.hpp> // Asigură-te că ai asta pentru snake

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    // --- ADAUGĂ ACESTE LINII AICI ---
    void updateSnakeUI(int* xBody, int* yBody, int length);
    void updateScore(int score);
    // --------------------------------

protected:
    // Aici ar trebui să ai deja array-ul de box-uri dacă l-ai pus anterior
    static const int MAX_SNAKE_LENGTH = 100;
    touchgfx::Box snakeSegments[MAX_SNAKE_LENGTH];
};

#endif // SCREEN1VIEW_HPP
