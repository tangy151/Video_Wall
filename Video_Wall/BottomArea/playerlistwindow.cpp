#include "playerlistwindow.h"
#include "../headfiledefine.h"

#include "../Controls/buttonex.h"
#include "../Controls/flatuiex.h"

#include "../Controls/playlistwidgetex.h"
 
#include "playcontrolwindow.h"

PlayerListWindow::PlayerListWindow(QWidget *parent)
	: QWidget(parent)
{
	InitUI();
	InitTAB();
	InitConnects();
 }

PlayerListWindow::~PlayerListWindow()
{
}

void PlayerListWindow::InitTAB()
{
	m_ptrTabWidget.reset(new PlayListWidgetEx(this)); 	FlatUIEx::Instance()->SetTabWidgetQss(m_ptrTabWidget.get(), "rgb(30,30,30)", "rgb(230,230,230)");

	m_ptrTabWidget->hide();
 }

void PlayerListWindow::AddPlayListPageNotify(QString strPageName)
{
	m_ptrTabWidget->AddPage(strPageName);

	int iCount = m_ptrTabWidget->GetPageCount();

	if (iCount >0)
	{
		m_ptrTabWidget->show();
 	}
 }

void PlayerListWindow::DeletePlayListPageNotify(QString strPageName)
{
	m_ptrTabWidget->RemovePage(strPageName); 	int iCount = m_ptrTabWidget->GetPageCount();
 	if (iCount <= 0)
	{
		m_ptrTabWidget->hide();
 	} }

void PlayerListWindow::InitUI()
{
 	//--------------------------------------------
	m_ptrButton1.reset(new ButtonEx(this));

	m_ptrButton1->setPaddingLeft(0);
	m_ptrButton1->setShowLine(false);
	m_ptrButton1->setShowIcon(false);
	m_ptrButton1->setIconSpace(0);
  
	m_ptrButton1->setTextAlign(ButtonEx::TextAlign_Center);
	m_ptrButton1->setFont(QFont("Microsoft YaHei", 10, 75));
	m_ptrButton1->setText(QString::fromLocal8Bit("播放列表设置"));
	 
	m_ptrButton1->setHoverBgColor(QColor(50, 50, 50));
	m_ptrButton1->setCheckBgColor(QColor(50, 50, 50));

	m_ptrButton1->setNormalBgColor(QColor(50, 50, 50));
	m_ptrButton1->setNormalFrameColor(QColor(50, 50, 50));

	m_ptrButton1->setNormalTextColor(QColor(239, 98, 234));
	m_ptrButton1->setHoverTextColor(QColor(239, 98, 234));
	m_ptrButton1->setCheckTextColor(QColor(239, 98, 234));
}


void PlayerListWindow::InitConnects()
{

}

void PlayerListWindow::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(50, 50, 50));
	painter.setPen(QColor(210, 210, 210));
}

void PlayerListWindow::resizeEvent(QResizeEvent* pEvent)
 {
	int iWidth = width();
	int iHeight = height();

	int iPrev = iHeight / 10;
	
	int iHeight2 = iPrev / 2;

	if (m_ptrButton1)
	{
		m_ptrButton1->setGeometry(0, 0, iWidth, 35);
		m_ptrButton1->move(0, iHeight - 35);
	}
  
	if (m_ptrTabWidget)
	{
 		m_ptrTabWidget->setGeometry(0, 0, iWidth, iHeight);
 		m_ptrTabWidget->move(0, 0);
	}

	QWidget::resizeEvent(pEvent);
}

