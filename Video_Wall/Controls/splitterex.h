#ifndef		_SPLITTER_EX_H_
#define _SPLITTER_EX_H_

 

#include <QSplitter>

class SplitterEx : public QSplitter
{
	Q_OBJECT

public:
	SplitterEx(Qt::Orientation iOrientation,  QWidget *parent);
	~SplitterEx();

protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent* pEvent);

};
#endif//_SPLITTER_EX_H_
