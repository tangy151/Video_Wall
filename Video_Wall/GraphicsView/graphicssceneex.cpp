#include "graphicssceneex.h"

#include "../headfiledefine.h"

#include<QGraphicsSceneMouseEvent>
#include<QGraphicsRectItem>
#include <QDebug>
#include <QKeyEvent>
 #include <vector>
#include <QPainter>



GraphicsSceneEx::GraphicsSceneEx(QObject *parent)
	: QGraphicsScene(parent)
{
	m_view = NULL;
	m_dx = m_dy = 0;
 
	//QGraphicsItem * item = addRect(QRectF(0, 0,0, 0));
	//item->setAcceptHoverEvents(true);
}

GraphicsSceneEx::~GraphicsSceneEx()
{
}
void GraphicsSceneEx::drawBackground(QPainter *painter, const QRectF &rect) 
{
	QGraphicsScene::drawBackground(painter, rect);
	painter->fillRect(sceneRect(), QColor(0,0,255));
 
}


void GraphicsSceneEx::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) 
{

}


void GraphicsSceneEx::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) 
{

}


void GraphicsSceneEx::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) 
{

}


void GraphicsSceneEx::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvet)
{

}


void GraphicsSceneEx::keyPressEvent(QKeyEvent *e) 
{

}


void GraphicsSceneEx::keyReleaseEvent(QKeyEvent *e) 
{

}




void GraphicsSceneEx::mouseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	switch (mouseEvent->type()) 
	{
	case QEvent::GraphicsSceneMousePress:
		QGraphicsScene::mousePressEvent(mouseEvent);
		break;
	case QEvent::GraphicsSceneMouseMove:
		QGraphicsScene::mouseMoveEvent(mouseEvent);
		break;
	case QEvent::GraphicsSceneMouseRelease:
		QGraphicsScene::mouseReleaseEvent(mouseEvent);
		break;
	}
}



void GraphicsSceneEx::destroyGroup(QGraphicsItemGroup *group)
{

}

