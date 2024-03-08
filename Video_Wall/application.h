#ifndef			_APPLICATION_H_
#define		_APPLICATION_H_

#include <QApplication>
#include <iostream>


class Application
	: public QApplication
{
	Q_OBJECT

public:
	Application(int &argc, char *argv[]);
	virtual bool notify(QObject *receiver, QEvent *e);
};

#endif//_APPLICATION_H_

