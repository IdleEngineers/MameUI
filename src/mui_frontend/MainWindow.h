#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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


	signals:


	private:
		Ui::MainWindow *ui;

		/**
		 * @brief Makes the connections for any custom slots and signals.
		 *			Called during class construction
		 */
		void SetupCustomSlotsAndSignals();

		void LoadSettings();
		void SaveSettings();
};

#endif
