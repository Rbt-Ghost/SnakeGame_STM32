class ModelListener
{
public:
    ModelListener() : model(0) {}
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    // --- ADAUGĂ ASTA ---
    // Aceasta este funcția pe care Modelul o va striga când se mișcă șarpele
    virtual void updateSnakeGame(int* xBody, int* yBody, int length, int score) {}
    // -------------------

protected:
    Model* model;
};
