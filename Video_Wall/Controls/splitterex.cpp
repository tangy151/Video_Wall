#include "splitterex.h"
#include "../headfiledefine.h"


SplitterEx::SplitterEx(Qt::Orientation iOrientation, QWidget *parent)
	: QSplitter(iOrientation,parent)
{
}

SplitterEx::~SplitterEx()
{
}
 
void SplitterEx::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);
 

	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(0, 120, 255));
	painter.setPen(QColor(210, 210, 210));
}

void SplitterEx::resizeEvent(QResizeEvent* pEvent)
{
 	int iWidth = width();
	int iHeight = height();
 
	QWidget::resizeEvent(pEvent);
 }