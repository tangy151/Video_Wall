#include "pvwwindow.h"
#include "../headfiledefine.h"

PvwWindow::PvwWindow(QWidget *parent)
	: QWidget(parent)
{
}

PvwWindow::~PvwWindow()
{
}

void PvwWindow::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(0, 0, 0));
	painter.setPen(QColor(210, 210, 210));
}

