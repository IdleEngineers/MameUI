#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SettingsWindow.h"

#include <QtGui>
#include <QtCore>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
	, gameProcess(0)
{
	ui->setupUi(this);
	SetupCustomSlotsAndSignals();
	ReloadGameList();
}

MainWindow::~MainWindow() {
	delete(ui);

	if(gameProcess != 0) {
		gameProcess->terminate();
		gameProcess->waitForFinished(10000);
	}

	delete gameProcess;
}

void MainWindow::SetupCustomSlotsAndSignals() {
}

void MainWindow::LaunchGame(QString FullGameName) {
	QStringList arguments;
	QString mameGameName = games[FullGameName];

	if(mameGameName == QString::null || mameGameName.isEmpty()) {
		qDebug() << "Error: Game not found";
		return;
	}

	QString cmd = settings.GetMamePath() + " -rp " + settings.GetRomsPath() + " " + mameGameName;

	arguments.append("-rp " + settings.GetRomsPath());
	arguments.append(mameGameName);

	gameProcess = new QProcess(this);

	connect(gameProcess, SIGNAL(finished(int)), this, SLOT(GameExited(int)));

	qDebug() << "Command:" << settings.GetMamePath() << " " << arguments.at(0) << " " << arguments.at(1);

	gameProcess->start(settings.GetMamePath(), arguments);
//	gameProcess->start(cmd.toStdString().c_str());
	//		system(cmd.toStdString().c_str());
}

void MainWindow::ReloadGameList() {
	ui->GameList->clear();
	ui->gameFilter->clear();
	games.clear();

	bool loadedGameList = gameListManger.GetGameListFromFile(settings.GetGameListPath(), games);

	if(!loadedGameList) {
		return;
	}

	ui->GameList->addItems(games.keys());
}


void MainWindow::on_actionSettings_triggered() {
	SettingsWindow settingsDialog(&settings);
	settingsDialog.exec();
}

void MainWindow::on_GameList_doubleClicked(const QModelIndex &index) {
	LaunchGame(index.data().toString());
}

void MainWindow::GameExited(int ExitCode) {
	qDebug() << "Process Finished with code:" << ExitCode;

}


void MainWindow::on_GameList_activated(const QModelIndex &index) {
	LaunchGame(index.data().toString());
}

void MainWindow::on_gameFilter_textChanged(const QString &arg1) {
	ui->GameList->clear();

	QList<QString> gameKeys = games.keys();

	if(ui->gameFilter->text().isEmpty()) {
		ui->GameList->addItems(gameKeys);
	} else {
		for(int i(0); i < gameKeys.count(); ++i) {
			if(gameKeys[i].contains(ui->gameFilter->text(), Qt::CaseInsensitive)) {
				ui->GameList->addItem(gameKeys[i]);
			}
		}
	}
}

void MainWindow::on_action_Reload_Game_List_triggered() {
	ReloadGameList();
}
