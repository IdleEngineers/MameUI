#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QtGui>
#include <QtCore>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	LoadSettings();

	SetupCustomSlotsAndSignals();
}

/**
 * @brief MainWindow::LoadSettings
 * Loads application settings from persistent storage
 * @note Has an ugly hack to assume the path of VLC on Linux vs. Windows... :(
 */
void MainWindow::LoadSettings() {

	QSettings settings;
//	settings.beginGroup("MainWindow");
//	restoreGeometry(settings.value("Geometry", saveGeometry()).toByteArray());
//	settings.beginGroup("Settings");
//	ui->baseUri->setText(settings.value("ServerBaseUri", "http://kirk.tenclay.myvwan.com/shiny").toString());
//	ui->downloadPath->setText(settings.value("DownloadPath", QDir::tempPath()).toString());
//	ui->playerCommand->setText(settings.value("PlayerCommand", defaultPlayerPath).toString());
}

void MainWindow::SaveSettings() {
	QSettings settings;
//	settings.beginGroup("MainWindow");
//	settings.setValue("Geometry", saveGeometry());
//	settings.beginGroup("Settings");
//	settings.setValue("ServerBaseUri", ui->baseUri->text());
//	settings.setValue("DownloadPath", ui->downloadPath->text());
//	settings.setValue("PlayerCommand", ui->playerCommand->text());
}

MainWindow::~MainWindow() {
	SaveSettings();
	delete(ui);
}

void MainWindow::SetupCustomSlotsAndSignals() {
}
