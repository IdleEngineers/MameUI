#include <QString>
#include <QPair>
#include <QMap>

#ifndef GAMELIST_H
#define GAMELIST_H

class GameList
{
	public:
		GameList();

		/**
		 * @brief Reads the file in the provided path and parses it into a pair of names that MAME uses and human readable names.
		 * @param [in] FilePath Fully qualified path to the file containing the game names. This file should be generated from MAME using <pre>mame -listfull</pre>
		 * @param [out] Games A list of roms <short name, full name>. The short name is used by MAME to launch the game.
		 * @returns pass/fail. QMap will be empty on a failure.
		 */
		bool GetGameListFromFile(QString FilePath, QMap<QString, QString>& Games);

	private:
		/**
		 * @brief Opens the a file and reads all the contents.
		 * @param [in] FilePath Full qualified path to a file
		 * @param [out] FileContents The contents of the file will be returned as a string
		 * @returns pass/fail. FileContents will be empty if it fails.
		 */
		bool ReadFileContents(QString FilePath, QString& FileContents);

		/**
		 * @brief Parses the game list out of the raw text from MAME
		 * @param [in] RawGamesList Raw text from <pre>mame -listfull</pre>
		 * @param Games A list of roms <short name, full name>.
		 * @returns pass/fail. Games will be empty on a failure
		 */
		bool ParseGameListFromString(QString RawGamesList, QMap<QString, QString>& Games);
};

#endif // GAMELIST_H
