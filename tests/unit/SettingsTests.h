#ifndef SETTINGSTESTS_H
#define SETTINGSTESTS_H

#include <gtest/gtest.h>
#include <libraries/mame_interface/Settings.h>
#include <QString>

class SettingsTests : public ::testing::Test {
	protected:
		virtual void SetUp() {
			settings = 0;
			settings = new Settings(true);
		}

		virtual void TearDown() {
			delete settings;
		}

		Settings* settings;
};

#endif
