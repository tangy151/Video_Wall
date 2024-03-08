#ifndef		_TAB_BAR_EX_H_
#define _TAB_BAR_EX_H_

 

#include <QTabBar>

class TabBarEx : public QTabBar
{
	Q_OBJECT

public:
	TabBarEx(QWidget *parent);
	~TabBarEx();

public:
	int OnAddTab(QWidget *widget, const QString & strTitle);


protected:
 
	//void paintEvent(QPaintEvent* pEvent);
 

};
#endif//_TAB_BAR_EX_H_
