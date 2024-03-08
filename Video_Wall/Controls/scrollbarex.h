#ifndef		_SCROLL_BAR_EX_H_
#define _SCROLL_BAR_EX_H_


#include <QScrollBar>

class ScrollBarEx : public QScrollBar
{
	Q_OBJECT

public:
	ScrollBarEx(QWidget *parent = nullptr);
	~ScrollBarEx();
};

#endif//_SCROLL_BAR_EX_H_


