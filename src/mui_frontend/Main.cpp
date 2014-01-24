#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	QCoreApplication::setOrganizationName("MUI");
	QCoreApplication::setApplicationName("MameUI");

	MainWindow w;
	w.show();
	
	return a.exec();
}
