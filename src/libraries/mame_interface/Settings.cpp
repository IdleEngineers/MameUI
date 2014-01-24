#include "Settings.h"

#include <QSettings>
#include <QDebug>

const QString Settings::MamePathKey("MamePathKey");
const QString Settings::RomsPathKey("RomsPathKey");
const QString Settings::GameListPathKey("GameListPathKey");

Settings::Settings(bool TestingMode)
	: mamePath("")
	, romsPath("")
	, gameListPath("")
	, testingMode(TestingMode)
{
	LoadSettings();
}

Settings::~Settings() {
	StoreSettings();
}

QString Settings::GetMamePath() {
	return(mamePath);
}

QString Settings::GetRomsPath() {
	return(romsPath);
}

QString Settings::GetGameListPath() {
	return(gameListPath);
}

void Settings::SetMamePath(QString MamePath) {
	mamePath = MamePath;
}

void Settings::SetRomsPath(QString RomsPath) {
	romsPath = RomsPath;
}

void Settings::SetGameListPath(QString GameListPath) {
	gameListPath = GameListPath;
}

void Settings::LoadSettings() {
	if(!testingMode) {
		qDebug() << "Loading Settings from disk...";
		QSettings settings;
		settings.beginGroup("MUI");
		settings.beginGroup("Settings");
		mamePath = settings.value(MamePathKey, "").toString();
		romsPath = settings.value(RomsPathKey, "").toString();
		gameListPath = settings.value(GameListPathKey, "").toString();
		settings.endGroup();
		settings.endGroup();
	}
}

void Settings::StoreSettings() {
	if(!testingMode) {
		qDebug() << "Saving Settings to disk...";
		QSettings settings;
		settings.beginGroup("MUI");
		settings.beginGroup("Settings");
		settings.setValue(MamePathKey, mamePath);
		settings.setValue(RomsPathKey, romsPath);
		settings.setValue(GameListPathKey, gameListPath);
		settings.endGroup();
		settings.endGroup();
	}
}
