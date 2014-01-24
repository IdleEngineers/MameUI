#ifndef GAMELISTTESTS_H
#define GAMELISTTESTS_H

#include <gtest/gtest.h>
#include <libraries/mame_interface/GameList.h>

class GameListTests : public ::testing::Test {
	protected:
		virtual void SetUp() {
			gl = 0;
			gl = new GameList();
		}

		virtual void TearDown() {
			delete gl;
		}

		GameList* gl;
};

#endif // GAMELISTTESTS_H
