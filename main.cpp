#include "Game.h"
#include "SDL/include/SDL.h"


int main(int argc, char* args[])
{
    Game game;
    if (!game.Init()) return -1;
    bool end = false;
    while (!end)
    {

        end = game.Update();
        //game.ProcessAudio();
        game.Draw();
    }
    return 0;
}




	