#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SettingsWindow.h"

#include <QtGui>
#include <QtCore>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	SetupCustomSlotsAndSignals();
}

MainWindow::~MainWindow() {
	delete(ui);
}

void MainWindow::SetupCustomSlotsAndSignals() {
}

void MainWindow::on_Btn_LoadGames_clicked() {
	ui->GameList->clear();
	games.clear();

	bool loadedGameList = gameListManger.GetGameListFromFile(ui->GameListFile->text(), games);

	if(!loadedGameList) {
		return;
	}

//	QList<QString> newGames = games.values();
	ui->GameList->addItems(games.keys());


}

void MainWindow::on_actionSettings_triggered() {
	SettingsWindow settingsDialog(&settings);
	settingsDialog.exec();
}

void MainWindow::on_GameList_doubleClicked(const QModelIndex &index) {
	//Launch game!
}
