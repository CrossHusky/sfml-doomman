#ifndef EE_STATE_H_INCLUDED
#define EE_STATE_H_INCLUDED

namespace basegame{
	namespace core{
		class PointerPack;
		class State
		{
		public:
			virtual void run(PointerPack& pack)=0;
			virtual ~State(){}
		};
	}
}

#endif