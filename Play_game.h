#include "Scene.h"
class Play_game :
    public Scene
{
public:
    enum State {
        EPause,
        EPlaying,
        EGameClear,
        EGameOver
        ,State_num
    };
    Play_game(class Game* game);
    void Init();
    void Update();
    void Draw();
    void ChangeState();
    void NextScene();
private:
    int Play_gameImg = 0;
    class Play_game* GameState[State_num];
    State CurState;
};