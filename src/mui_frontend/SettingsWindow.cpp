#include "SettingsWindow.h"
#include "ui_SettingsWindow.h"

#include <QtGui>
#include <QtCore>

SettingsWindow::SettingsWindow(Settings* SettingsManager, QWidget* parent)
	: QDialog(parent)
	, ui(new Ui::SettingsWindow)
{
	ui->setupUi(this);
	settings = SettingsManager;
	ui->MameExecutable->setText(settings->GetMamePath());
	ui->RomsDirectory->setText(settings->GetRomsPath());
	ui->GameListFile->setText(settings->GetGameListPath());
}

SettingsWindow::~SettingsWindow() {
	delete(ui);
}

void SettingsWindow::on_buttonBox_accepted() {
	settings->SetMamePath(ui->MameExecutable->text());
	settings->SetRomsPath(ui->RomsDirectory->text());
	settings->SetGameListPath(ui->GameListFile->text());
	this->accept();
}

void SettingsWindow::on_buttonBox_rejected() {
	this->reject();
}
