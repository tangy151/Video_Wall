#ifndef		_virtual_area_util_window_h_
#define _virtual_area_util_window_h_

 

#include <QWidget>

class VirtualAreaUtilWindow : public QWidget
{
	Q_OBJECT

public:
	VirtualAreaUtilWindow(QWidget *parent);
	~VirtualAreaUtilWindow();

protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent* pEvent);
};
#endif//_virtual_area_util_window_h_
