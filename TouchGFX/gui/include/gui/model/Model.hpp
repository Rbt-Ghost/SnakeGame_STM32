class Model : public ModelListener
{
public:
    Model();
    void tick(); // Funcția standard TouchGFX

protected:
    // Variabilele jocului
    int snakeX[100];
    int snakeY[100];
    int snakeLength;
    int score;
    int counter; // Pentru a încetini jocul
    int direction; // 0=Sus, 1=Dr, 2=Jos, 3=St
};
