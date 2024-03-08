#include "graphicswindow.h"
#include "../headfiledefine.h"

GraphicsWindow::GraphicsWindow(QGraphicsItem * parent )
	: QGraphicsObject(parent)
{
	setFlag(ItemIsFocusable); //receive key events
 
}

GraphicsWindow::~GraphicsWindow()
{
}
 
QRectF GraphicsWindow::boundingRect() const
{
	return QRectF(0, 0, 800, 600);
 }

void GraphicsWindow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	int i = 0;


// 	painter->setClipRect(0, 0, width(), height());
	painter->setBrush(QBrush(QColor(255, 0, 0)));
	painter->fillRect(QRectF(0, 0, 200, 200), QColor(150, 80, 250));
	painter->setPen(QColor(210, 210, 210));
}
