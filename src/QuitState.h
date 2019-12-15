#ifndef EE_QUITSTATE_H_INCLUDED
#define EE_QUITSTATE_H_INCLUDED

//Pausa para salir

#include "State.h"
#include "StateManager.h"
#include <string>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

/*Muestra en pantalla text y toma como argumentos S o N, según sea, saldrá o no del juego.
Solo disponible en GameState*/

namespace basegame{
	namespace state{
		class QuitState : public core::State
		{
		public:
			virtual void run(core::PointerPack& pack)
			{
				sf::Text text("Salir? [S]i/[N]o",*pack.Font);
				text.setPosition(154.0f,268.0f);
				sf::Event eve;
				while(1)
				{
					while(pack.Window->pollEvent(eve))
					{
						if(eve.type==sf::Event::KeyPressed&&eve.key.code==sf::Keyboard::S)
						{
							pack.Manager->leaveBottom(1); // Salir
							return;
						}
						if(eve.type==sf::Event::KeyPressed&&eve.key.code==sf::Keyboard::N)
						{
							pack.Manager->popTop(1); // Seguir
							return;
						}
					}
					pack.Window->clear();
					pack.Window->draw(text);
					pack.Window->display();
				}
			}
		};
	}
}
#endif