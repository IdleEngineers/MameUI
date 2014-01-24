#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>

class Settings
{
	public:
		Settings(bool TestingMode = false);
		~Settings();

		/****************************************
		 * Getters
		 ****************************************/

		QString GetMamePath();
		QString GetRomsPath();
		QString GetGameListPath();


		/****************************************
		 * Setters
		 ****************************************/

		void SetMamePath(QString MamePath);
		void SetRomsPath(QString RomsPath);
		void SetGameListPath(QString GameListPath);

	private:
		QString mamePath;
		QString romsPath;
		QString gameListPath;
		bool testingMode;

		void LoadSettings();
		void StoreSettings();

		static const QString MamePathKey;
		static const QString RomsPathKey;
		static const QString GameListPathKey;
};

#endif
