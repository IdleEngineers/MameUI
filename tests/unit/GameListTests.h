#ifndef GAMELISTTESTS_H
#define GAMELISTTESTS_H

#include <gtest/gtest.h>
#include <libraries/mame_interface/GameList.h>
#include <QMap>
#include <QString>

class GameListTests : public ::testing::Test {
	protected:
		virtual void SetUp() {
			gl = 0;
			gl = new GameList();
		}

		virtual void TearDown() {
			delete gl;
		}

		static void FillTestGamesMap(QMap<QString, QString>& Map);

		GameList* gl;
};

#endif
