
#include "GameListTests.h"

TEST_F(GameListTests, can_create_a_game_list) {
	ASSERT_FALSE(gl == 0);
}

TEST_F(GameListTests, can_get_games_list_as_pair_of_name_and_description) {
	QMap<QString, QString> games;
	QMap<QString, QString> expectedGames;
	FillTestGamesMap(expectedGames);

	bool ReadGameList = gl->GetGameListFromFile("sample_game_list.txt", games);

	ASSERT_TRUE(ReadGameList);
	ASSERT_EQ(expectedGames.count(), games.count());

	for(QMap<QString, QString>::Iterator iter(expectedGames.begin()); iter != expectedGames.end(); ++iter) {
		QString expectedLongName = iter.value();
		QString gamesShortName = games[iter.key()];
		ASSERT_STRCASEEQ(expectedLongName.toStdString().c_str(), gamesShortName.toStdString().c_str());
	}
}


void GameListTests::FillTestGamesMap(QMap<QString, QString>& Map) {
	Map.insert(QString("\"005\""), QString("005"));
	Map.insert(QString("\"10-Yard Fight (World, set 1)\""), QString("10yard"));
	Map.insert(QString("\"10-Yard Fight '85 (US, Taito license)\""), QString("10yard85"));
	Map.insert(QString("\"10-Yard Fight (Japan)\""), QString("10yardj"));
	Map.insert(QString("\"Eleven Beat\""), QString("11beat"));
	Map.insert(QString("\"18 Wheeler (set 1)\""), QString("18w"));
	Map.insert(QString("\"18 Wheeler (set 2)\""), QString("18w2"));
	Map.insert(QString("\"18 Wheeler Deluxe (Rev A) (JPN)\""), QString("18wheelr"));
	Map.insert(QString("\"18 Wheeler (Rev A) (JPN)\""), QString("18wheels"));
	Map.insert(QString("\"1941: Counter Attack (World 900227)\""), QString("1941"));
	Map.insert(QString("\"1941: Counter Attack (Japan)\""), QString("1941j"));
	Map.insert(QString("\"1941: Counter Attack (World)\""), QString("1941r1"));
	Map.insert(QString("\"1941: Counter Attack (USA 900227)\""), QString("1941u"));
}
