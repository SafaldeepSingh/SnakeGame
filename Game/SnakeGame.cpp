#include <iostream>
#include "Game.h"
using namespace std;
int main()
{
    bool playAgain;
    do
    {
        playAgain = false;
        Game game = Game();
        game.start();
        char check = Console::readCharacter();
        if (check == 'y')
        {
            playAgain = true;
        }
    } while (playAgain);
    return 0;
}

