#include "application.h"
#include "mainwindow.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QSplashScreen>
#include <QtCore/QSize>

#include "headfiledefine.h"
  
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setAttribute(Qt::AA_NativeWindows);//设置QT 每个控件都有一个独立得句柄
	QString strExePath = QCoreApplication::applicationDirPath();
	   
	g_ptrMainWindow = new MainWindow();
	g_ptrMainWindow->show();

	g_ptrMainWindow->repaint();

	int retval = a.exec();
	  
	return a.exec();
 }



