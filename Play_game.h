#include "Scene.h"
class Play_game :
    public Scene
{
public:
    Play_game(class Game* game);
    void Init();
    void Draw();
    void NextScene();
private:
    int Play_gameImg = 0;

};