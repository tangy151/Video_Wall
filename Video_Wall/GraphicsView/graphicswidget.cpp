#include "graphicswidget.h"

#include "../headfiledefine.h"
#include "../Controls/flatuiex.h"
#include "../Controls/buttonex.h"
#include "../Controls/navlabelex.h"
#include "../runtimedata.h"
 
#include "graphicsviewex.h"
#include "graphicssceneex.h"
#include "graphicswindow.h"

#include "../Controls/flatuiex.h"
 
GraphicsWidget::GraphicsWidget(QWidget *parent)
	:   QWidget (parent)
	, m_pViewEx(nullptr)
{
	InitUI();
	InitConnect();
}

GraphicsWidget::~GraphicsWidget()
{

}

void GraphicsWidget::InitUI()
{ 
 	m_pViewEx = CreateGraphicsViewEx();
	m_pViewEx->hide();
	QBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(m_pViewEx);
	layout->setContentsMargins(0, 0,0,0);
	setLayout(layout);
 }

GraphicsViewEx* GraphicsWidget::CreateGraphicsViewEx()
{
	GraphicsSceneEx* pScene = new GraphicsSceneEx(this);
 	QRectF rc = QRectF(0, 0, 1000, 1000);

	pScene->setSceneRect(rc);
	 
	GraphicsViewEx* pViewEx = new GraphicsViewEx(pScene);
	pScene->setView(pViewEx);


	pViewEx->setRenderHint(QPainter::Antialiasing);
	pViewEx->setCacheMode(QGraphicsView::CacheBackground);
	pViewEx->setOptimizationFlags(QGraphicsView::DontSavePainterState);
	pViewEx->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
	pViewEx->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

	// pViewEx->setTransform(pViewEx->transform().scale(1, -1));
//	pViewEx->setBackgroundBrush(QColor(50, 50, 50)/*Qt::darkGray*/);
 
	FlatUIEx::Instance()->SetGraphicsViewQss(pViewEx);

 
	return pViewEx;
}


void 	GraphicsWidget::InitConnect()
{

}


void GraphicsWidget::resizeEvent(QResizeEvent *pEvent)
{

	int iWidth = width();
	int iHeight = height();

	if (m_pViewEx)
	{
		m_pViewEx->setGeometry(0, 0, iWidth-1, iHeight-1);
		m_pViewEx->move(0, 0);
		m_pViewEx->show();
	}

	QWidget::resizeEvent(pEvent);

}
void GraphicsWidget::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);

	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(30, 30, 30));
	painter.setPen(QColor(210, 210, 210));
}

