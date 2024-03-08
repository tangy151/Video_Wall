#include "playlistpageex.h"
#include "../headfiledefine.h"
#include "playlistex.h"
#include "playlistitemex.h"
#include "../globaldefine.h"
#include "../BottomArea/playcontrolwindow.h"
 
PlayListPageEx::PlayListPageEx(QWidget *parent, const QString& pageTitle)
	: QWidget(parent)
	, m_strPageTitle(pageTitle)
	, m_ptrPlayListEx(nullptr)
{
	InitUI();
	InitConnects();
}

PlayListPageEx::~PlayListPageEx()
{
}
 
void PlayListPageEx::InitUI()
{ 
	m_ptrPlayListEx.reset(new PlayListEx(this));
	m_ptrPlayListEx->setStyleSheet("QListWidget{border:1 px; color:rgb(230,230,230); }");
	 
	m_ptrPlayControlWindow.reset(new PlayControlWindow(this));
 }

void PlayListPageEx::InitConnects()
{
	connect(m_ptrPlayListEx.get(), SIGNAL(OnPlayListNotify(PlayListItemEx*)), this, SLOT(OnPlayListNotify(PlayListItemEx*)), Qt::QueuedConnection);
 }
 
void PlayListPageEx::OnPlayListNotify(PlayListItemEx* pListItem)
{
	int i = 0;
}

void PlayListPageEx::InsertData(QString strTitle, QString strPath, QString strTime)
{
	int i = 0;
}

void PlayListPageEx::DeleteData(PlayListItemEx* pSelectListItem)
{
	int i = 0;
 }

void PlayListPageEx::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(50, 50, 50));
	painter.setPen(QColor(210, 210, 210));
}

void PlayListPageEx::resizeEvent(QResizeEvent* pEvent)
{
	int iWidth = width();
	int iHeight = height();
  
#if   PIX_1080p
	if (m_ptrPlayListEx)
	{
		m_ptrPlayListEx->setGeometry(0, 0, iWidth - 14, iHeight - 75);
		m_ptrPlayListEx->move(7, 0);
	}

	if (m_ptrPlayControlWindow)
	{
		m_ptrPlayControlWindow->setGeometry(0, 0, iWidth - 14, 40);
		m_ptrPlayControlWindow->move(7, iHeight - 75);
	}
#else
	if (m_ptrPlayListEx)
	{
		m_ptrPlayListEx->setGeometry(0, 0, iWidth - 14, iHeight - 55);
		m_ptrPlayListEx->move(7, 0);
	}

	if (m_ptrPlayControlWindow)
	{
		m_ptrPlayControlWindow->setGeometry(0, 0, iWidth - 14, 30);
		m_ptrPlayControlWindow->move(7, iHeight - 55);
	}
#endif
	 
	QWidget::resizeEvent(pEvent);
}
  
void PlayListPageEx::SetPageTitle(const QString& title)
{
	m_strPageTitle = title;
 }
 
void PlayListPageEx::SetActive(bool state)
{
	m_bActive = state;
	emit ActiveChanged(this);
}








