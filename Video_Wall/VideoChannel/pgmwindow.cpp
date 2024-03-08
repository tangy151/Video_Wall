#include "pgmwindow.h"

#include "../headfiledefine.h"

PgmWindow::PgmWindow(QWidget *parent)
	: QWidget(parent)
{
}

PgmWindow::~PgmWindow()
{
}
void PgmWindow::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(0, 0, 0));
	painter.setPen(QColor(210, 210, 210));
}