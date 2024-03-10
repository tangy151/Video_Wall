#include "application.h"
#include "mainwindow.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QSplashScreen>
#include <QtCore/QSize>
#include <QApplication>
#include <QTextCodec>
#include <QSettings>
#include <QIcon>
#include <QFont>
#include <QDir>
#include <QLockFile>
#include <QTextCodec>
#include <QFontDatabase>
#include <QApplication>


//#include <consoleapi.h>
//#include <dbghelp.h>
#include <string>
#include <iostream>
#include <fstream>
//#include <tlhelp32.h>
#include <thread>

#include "headfiledefine.h"
  
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

    a.setAttribute(Qt::AA_NativeWindows);//设置QT 每个控件都有一个独立得句柄


#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
    #if _MSC_VER
	QTextCodec *codec = QTextCodec::codecForName("GBK");
#else
	QTextCodec *codec = QTextCodec::codecForName("utf-8");
#endif
	QTextCodec::setCodecForLocale(codec);
	QTextCodec::setCodecForCStrings(codec);
	QTextCodec::setCodecForTr(codec);
#else
    QTextCodec *codec = QTextCodec::codecForName("GBK");
    QTextCodec::setCodecForLocale(codec);
#endif

	   
	g_ptrMainWindow = new MainWindow();
	g_ptrMainWindow->show();

	g_ptrMainWindow->repaint();

	int retval = a.exec();
	  
	return a.exec();
 }



