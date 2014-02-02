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

	arguments.append("-rp " + settings.GetRomsPath());
	arguments.append(mameGameName);

	gameProcess = new QProcess(this);

	connect(gameProcess, SIGNAL(finished(int)), this, SLOT(GameExited(int)));

	qDebug() << "Starting Process:" << settings.GetMamePath();
	gameProcess->start(settings.GetMamePath(), arguments);

}

void MainWindow::on_Btn_LoadGames_clicked() {
	ui->GameList->clear();
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
