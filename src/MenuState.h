#ifndef EE_MENUSTATE_H_INCLUDED
#define EE_MENUSTATE_H_INCLUDED

// Declaración del Menú

#include "State.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace basegame{
	namespace state{
		class MenuState : public core::State
		{
		public:
			virtual void run(core::PointerPack& pack); // Ejecuta el menú
		private:
			sf::Text mTitle,mPlay,mHigh,mQuit; // Textos en pantalla
			sf::Music mStart; // Música de inicio
			sf::Texture mBackground; // Fondo
			sf::Sprite mBG; //Sprite del Fondo para mostrar en pantalla
		};
	}
}

#endif