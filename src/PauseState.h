#ifndef EE_PAUSESTATE_H_INCLUDED
#define EE_PAUSESTATE_H_INCLUDED
// Pausa
#include "State.h"
#include "StateManager.h"
#include <string>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Audio.hpp>

/* Muestra "PAUSA" en pantalla, regresa al estado anterior si se presiona "P" */

namespace basegame{
	namespace state{
		class PauseState : public core::State
		{
		public:
			virtual void run(core::PointerPack& pack)
			{
				sf::Text text1("PAUSA",*pack.Font);
				text1.setPosition(204.0f,258.0f);
				sf::Event eve;
				while(1)
				{
					while(pack.Window->pollEvent(eve))
					{
						if(eve.type==sf::Event::KeyPressed&&eve.key.code==sf::Keyboard::P)
						{
							pack.Manager->popTop(1);
							return;
						}
					}
					pack.Window->clear();
					pack.Window->draw(text1);
					pack.Window->display();
				}
			}
		};
	}
}
#endif