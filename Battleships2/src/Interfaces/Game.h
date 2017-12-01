/*
 * Game.h
 *
 *  Created on: Oct 27, 2017
 *      Author: HZinovatna
 */

#ifndef SRC_INTERFACES_GAME_H_
#define SRC_INTERFACES_GAME_H_

#include "Observer.h"
#include <vector>

namespace game {
	enum shotState {MISSED, INJURED, KILLED};

	class Game {
	public:
		Game();
		virtual ~Game();

		virtual void start() = 0;

		virtual void attach(Observer* observer) = 0;
		virtual void detach(Observer* observer) = 0;

		virtual void notify() = 0;

		virtual std::vector<std::vector<int> > getPlayer1Ships() = 0;

	};
}

#endif /* SRC_INTERFACES_GAME_H_ */
