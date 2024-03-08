#include "graphicsviewex.h" 
#include "../headfiledefine.h"

#include "graphicsviewex.h"
#include "../Controls/scrollbarex.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

#include "../Controls/flatuiex.h"

GraphicsViewEx::GraphicsViewEx(QGraphicsScene* pScene)
	: QGraphicsView(pScene)
{
	setViewport(new QWidget);

 	//setAttribute(Qt::WA_DeleteOnClose);
 
	InitScrollBarEx();
 }



GraphicsViewEx::~GraphicsViewEx()
{


}

 
void GraphicsViewEx::InitScrollBarEx()
{
	m_ptrVScrollBarEx.reset(new  ScrollBarEx(this));
	m_ptrHScrollBarEx.reset(new  ScrollBarEx(this));


	this->setHorizontalScrollBar(m_ptrHScrollBarEx.get());
	this->setVerticalScrollBar(m_ptrVScrollBarEx.get());

	FlatUIEx::Instance()->setScrollBarQss(m_ptrVScrollBarEx.get());
	FlatUIEx::Instance()->setScrollBarQss(m_ptrHScrollBarEx.get());

}


void GraphicsViewEx::wheelEvent(QWheelEvent* pEvent)
{
	QGraphicsView::wheelEvent(pEvent);
}

void GraphicsViewEx::closeEvent(QCloseEvent *pEvent)
{
	pEvent->accept();
}

void GraphicsViewEx::mouseMoveEvent(QMouseEvent * pEvent)
{
	QGraphicsView::mouseMoveEvent(pEvent);
 }

void GraphicsViewEx::resizeEvent(QResizeEvent *pEvent)
{
	int iWidth = width();
	int iHeight = height();

	
	QGraphicsView::resizeEvent(pEvent);
 this->setViewportMargins(iWidth - 1, iHeight - 1, 0, 0); 
//
}

void GraphicsViewEx::scrollContentsBy(int dx, int dy)
{
	QGraphicsView::scrollContentsBy(dx, dy);
 }


void GraphicsViewEx::zoomIn()
{
	scale(1.2, 1.2);
}

void GraphicsViewEx::zoomOut()
{
	scale(1 / 1.2, 1 / 1.2);
}
