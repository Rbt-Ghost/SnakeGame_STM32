#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

// Șterge sau comentează linia de mai sus (#include <gui/model/Model.hpp>)
// Adaugă linia de mai jos:
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

    // --- ADAUGĂ ACEASTĂ FUNCȚIE VIRTUALĂ ---
    virtual void updateSnakeGame(int* xBody, int* yBody, int length, int score) {}
    // ---------------------------------------

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
