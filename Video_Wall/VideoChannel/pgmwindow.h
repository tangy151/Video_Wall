#ifndef		_PGM_WINDOW_H_
#define _PGM_WINDOW_H_

 

#include <QWidget>

class PgmWindow : public QWidget
{
	Q_OBJECT

public:
	PgmWindow(QWidget *parent);
	~PgmWindow();

protected:
	void paintEvent(QPaintEvent* pEvent);


};


#endif//_PGM_WINDOW_H_
