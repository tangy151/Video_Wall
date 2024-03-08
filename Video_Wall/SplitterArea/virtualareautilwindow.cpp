#include "virtualareautilwindow.h"
#include "../headfiledefine.h"
#include "../Controls/flatuiex.h"


VirtualAreaUtilWindow::VirtualAreaUtilWindow(QWidget *parent)
	: QWidget(parent)
{
}

VirtualAreaUtilWindow::~VirtualAreaUtilWindow()
{
}
void VirtualAreaUtilWindow::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(50, 50, 50));
	painter.setPen(QColor(210, 210, 210));
	
}
void VirtualAreaUtilWindow::resizeEvent(QResizeEvent* pEvent)
{

	
}

