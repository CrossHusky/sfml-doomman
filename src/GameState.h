#ifndef EE_GAMESTATE_H_INCLUDED
#define EE_GAMESTATE_H_INCLUDED

#include "State.h"
#include "PacEngine.h"
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio.hpp>

namespace basegame{
	namespace core{
		class PointerPack;
	}
	namespace state{
		class GameState : public core::State
		{
		public:
			GameState();
			virtual void run(core::PointerPack& pack);
			bool loadMap();

		private:
			/* Métodos */
			void drawAll();
			void drawCherry(int x,int y);
			void drawBooster(int x,int y);
			void drawPill(int x,int y);
			void drawGhosts();
			/* Variables */
			sf::Text lives,score;
			bool mapOk;
			sf::Texture mAtlas;
			sf::Sprite guys[5],leftEye,rightEye;
			core::PointerPack * mPack;
			int currentMap,mScore,pacframe;
			std::string mMapNames[3];
			pac::PacEngine mEngine;
			sf::Clock mAnimClock;
			sf::Music mTheme;
		};
	}
}
#endif