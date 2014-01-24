#include "SettingsTests.h"

#include <gtest/gtest.h>

TEST_F(SettingsTests, can_create) {
	ASSERT_FALSE(settings == 0);
}

TEST_F(SettingsTests, default_path_to_mame_is_blank) {
	ASSERT_STRCASEEQ("", settings->GetMamePath().toStdString().c_str());
}

TEST_F(SettingsTests, default_path_to_roms_is_blank) {
	ASSERT_STRCASEEQ("", settings->GetRomsPath().toStdString().c_str());
}

TEST_F(SettingsTests, default_path_to_game_list_is_blank) {
	ASSERT_STRCASEEQ("", settings->GetGameListPath().toStdString().c_str());
}

TEST_F(SettingsTests, can_change_mame_path) {
	QString expectedPath = "/home/user/mame0151/mame";
	settings->SetMamePath(expectedPath);

	ASSERT_STRCASEEQ(expectedPath.toStdString().c_str(), settings->GetMamePath().toStdString().c_str());
}

TEST_F(SettingsTests, can_change_rom_path) {
	QString expectedPath = "/home/user/mame0151/roms";
	settings->SetRomsPath(expectedPath);

	ASSERT_STRCASEEQ(expectedPath.toStdString().c_str(), settings->GetRomsPath().toStdString().c_str());
}

TEST_F(SettingsTests, can_change_game_list_path) {
	QString expectedPath = "/home/user/mame0151/roms/gameList.txt";
	settings->SetGameListPath(expectedPath);

	ASSERT_STRCASEEQ(expectedPath.toStdString().c_str(), settings->GetGameListPath().toStdString().c_str());
}

