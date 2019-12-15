#ifndef EE_SCORESTATE_H_INCLUDED
#define EE_SCORESTATE_H_INCLUDED
// Estado de Puntuaciones
#include "State.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio.hpp>

namespace basegame{
	namespace state{
		class ScoreState : public core::State
		{
		public:
			ScoreState(int score); // Recibe la puntuación
			virtual ~ScoreState(); 
			virtual void run(core::PointerPack& pack);
		private:
			// Para el manejo del archivo
			std::vector<sf::Text> mLines;
			int mWritingTo,mScore;
			std::string mWritingLine;
		};
	}
}
#endif