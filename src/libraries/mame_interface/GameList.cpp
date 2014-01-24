#include "GameList.h"

#include <QFile>
#include <QtGui>

GameList::GameList()
{
}

bool GameList::GetGameListFromFile(QString FilePath, QMap<QString, QString>& Games) {
	QString rawGames;
	bool readFileSuccessfully = ReadFileContents(FilePath, rawGames);

	if(!readFileSuccessfully) {
		return(false);
	}

	bool parsedGameListSuccessfully = ParseGameListFromString(rawGames, Games);

	if(!parsedGameListSuccessfully) {
		return(false);
	}

	return(true);
}

bool GameList::ReadFileContents(QString FilePath, QString& FileContents) {
	QFile file(FilePath);

	if(!file.exists()) {
		return(false);
	}

	bool openedFile = file.open(QIODevice::ReadOnly);

	if(!openedFile) {
		return(false);
	}

	while(!file.atEnd()) {
		FileContents += file.readLine();
	}

	file.close();

	return(true);
}

bool GameList::ParseGameListFromString(QString RawGamesList, QMap<QString, QString>& Games) {
	QStringList gameList = RawGamesList.split('\n');
	QRegExp sep("\\s{3,}");

	for(QStringList::Iterator iter = gameList.begin(); iter != gameList.end(); ++iter) {
		if(iter->isEmpty())
			continue;

		QString shortName = iter->section(sep, 0, 0);
		QString longName = iter->section(sep, 1, 1);

		//The normal output from MAME titles the colums and we don't want these titles in the game list
		if(shortName == "Name:" && longName == "Description:")
			continue;

		Games.insert(longName, shortName);
	}

	return(true);
}
