#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

// --- ȘTERGE linia: #include <gui/model/Model.hpp> ---
// Folosim doar forward declaration:
class Model;

class ModelListener
{
public:
    ModelListener() : model(0) {}

    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    // Funcția apelată din Model când se schimbă jocul
    virtual void updateSnakeGame(int* xBody, int* yBody, int length, int score, int foodX, int foodY) {}

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
