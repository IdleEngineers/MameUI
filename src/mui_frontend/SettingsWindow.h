#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>
#include <mame_interface/Settings.h>

namespace Ui {
	class SettingsWindow;
}

class SettingsWindow : public QDialog {
	Q_OBJECT

	public:
		explicit SettingsWindow(Settings* SettingsManager, QWidget* parent = 0);
		~SettingsWindow();

	public slots:


	private slots:
		//UI Events

		void on_buttonBox_accepted();

		void on_buttonBox_rejected();

	signals:


	private:
		Ui::SettingsWindow *ui;

		Settings* settings;
};

#endif
