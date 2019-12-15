//DOOM-MAN
//Función Principal

#include "StateManager.h"
#include "MenuState.h"
#include <SFML/Audio.hpp>

int main()
{
	basegame::core::StateManager doom_man; 
	doom_man.pushTop(new basegame::state::MenuState);
	doom_man.gameRun();
}