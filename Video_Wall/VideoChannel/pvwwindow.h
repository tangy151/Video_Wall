#ifndef		_PVW_WINDOW_H_
#define	_PVW_WINDOW_H_


#include <QWidget>

class PvwWindow : public QWidget
{
	Q_OBJECT

public:
	PvwWindow(QWidget *parent);
	~PvwWindow();

protected:
	void paintEvent(QPaintEvent* pEvent);

};


#endif//_PVW_WINDOW_H_
