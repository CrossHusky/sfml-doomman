/* Menú */

#include "MenuState.h"
#include "StateManager.h"
#include <SFML/Window/Event.hpp>
#include "ScoreState.h"
#include "GameState.h"
#include <SFML/Audio.hpp>

namespace basegame{
	namespace state{
		void MenuState::run(core::PointerPack& pack)
		{
			// Manejo de atributos de los objetos del Menú
			mBackground.loadFromFile("background.png");
			mBG.setTexture(mBackground);
			
			mStart.openFromFile("start.ogg");
			mStart.play();
			
			mTitle.setFont(*pack.Font);
			mPlay.setFont(*pack.Font);
			mHigh.setFont(*pack.Font);
			mQuit.setFont(*pack.Font);
			
			mTitle.setColor(sf::Color::Black);
			mPlay.setColor(sf::Color::Black);
			mHigh.setColor(sf::Color::Black);
			mQuit.setColor(sf::Color::Black);
			
			mTitle.setOutlineColor(sf::Color::White);
			mPlay.setOutlineColor(sf::Color::White);
			mHigh.setOutlineColor(sf::Color::White);
			mQuit.setOutlineColor(sf::Color::White);
			
			mTitle.setOutlineThickness(6);
			mPlay.setOutlineThickness(6);
			mHigh.setOutlineThickness(6);
			mQuit.setOutlineThickness(6);

			mTitle.setString("DOOM-MAN");
			mPlay.setString("[J]ugar!");
			mHigh.setString("[P]untuaciones!");
			mQuit.setString("[S]alir!");

			mTitle.setCharacterSize(128);
			
			mTitle.setPosition(50.f,150.f);
			mPlay.setPosition(150.f,305.f);
			mHigh.setPosition(150.f,340.f);
			mQuit.setPosition(150.f,375.f);
			
			sf::Event eve;
			
			while(true)
			{
				while(pack.Window->pollEvent(eve))
				{
					if(eve.type==sf::Event::Closed||(eve.type==sf::Event::KeyPressed&&eve.key.code==sf::Keyboard::S))
					{
						pack.Manager->popTop(100); // Salir
						return;
					}
					else if(eve.type==sf::Event::KeyPressed)
					{
						if(eve.key.code==sf::Keyboard::J)
						{
							pack.Manager->pushTop(new GameState()); // Modo de Juego
							return;
						}
						if(eve.key.code==sf::Keyboard::P)
						{
							pack.Manager->pushTop(new ScoreState(-1)); //Modo de Puntuación
							return;
						}
					}
				}
				
				// Limpiar pantalla
				pack.Window->clear();
				// Mostrar objetos en pantalla
				pack.Window->draw(mBG);
				pack.Window->draw(mTitle);
				pack.Window->draw(mPlay);
				pack.Window->draw(mHigh);
				pack.Window->draw(mQuit);
				// Actualizar pantalla
				pack.Window->display();
			}
		}
	}
}