#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidgetItem>
#include <QMainWindow>
#include <QModelIndex>
#include <QProcess>

#include <mame_interface/GameList.h>
#include <mame_interface/Settings.h>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT

	public:
		explicit MainWindow(QWidget* parent = 0);
		~MainWindow();

	public slots:


	private slots:
		//UI Events

		void on_actionSettings_triggered();
		void on_GameList_doubleClicked(const QModelIndex &index);

		void GameExited(int ExitCode);

		void on_GameList_activated(const QModelIndex &index);

		void on_gameFilter_textChanged(const QString &arg1);

		void on_action_Reload_Game_List_triggered();

	signals:


	private:
		Ui::MainWindow *ui;

		GameList gameListManger;
		Settings settings;
		QMap<QString, QString> games;

		QProcess* gameProcess; ///< Reference to the running game process

		/**
		 * @brief Makes the connections for any custom slots and signals.
		 *			Called during class construction
		 */
		void SetupCustomSlotsAndSignals();

		void LaunchGame(QString FullGameName);

		void ReloadGameList();

		void LoadSettings();
		void SaveSettings();
};

#endif
