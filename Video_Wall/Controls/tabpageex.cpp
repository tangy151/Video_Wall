#include "tabpageex.h"
#include "../headfiledefine.h"
 
#include "flatuiex.h"

#include "mediaselectlistex.h"
#include "mediaselectlistitemex.h"
#include "tabwidgetex.h"

TabPageEx::TabPageEx(QWidget *parent, const QString& pageTitle, MEDIA_SELECT_TYPE iMediaType)
	: QWidget(parent )
	, m_strPageTitle(pageTitle) 
 	, m_iMediaType(iMediaType)
{
	m_pRibbon = (TabWidgetEx*)this->parentWidget();

 	InitUI();
	InitConnects();
}

TabPageEx::~TabPageEx()
{
}

void TabPageEx::InitUI()
{
 	m_ptrMediaSelectListEx.reset(new MediaSelectListEx(this));
 	m_ptrMediaSelectListEx->setStyleSheet("QListWidget{border:1 px; color:rgb(30,30,30); background:rgb(30,30,30); }");
  }
  
void TabPageEx::InsertData(QString strTitle, QString strPath)
{
	if (m_ptrMediaSelectListEx)
   		m_ptrMediaSelectListEx->OnInsertUserItem(strTitle, strPath);
}

void TabPageEx::DeleteData(MediaSelectListItemEx* pSelectListItem)
{
	if (m_ptrMediaSelectListEx)
 		m_ptrMediaSelectListEx->OnRemoveUserItem(pSelectListItem);
}

void TabPageEx::DeleteData(QString strTitle, QString strPath)
{
	if (m_ptrMediaSelectListEx)
		m_ptrMediaSelectListEx->OnRemoveUserItem(strTitle, strPath);
}
 
void TabPageEx::InitConnects()
{
	connect(m_ptrMediaSelectListEx.get(), SIGNAL(OnSessionListNotify(MediaSelectListItemEx*)), this, SLOT(OnSessionListNotify(MediaSelectListItemEx*)), Qt::QueuedConnection);
 	connect(m_ptrMediaSelectListEx.get(), SIGNAL(OnListSizeNotify(int)), this, SLOT(OnListSizeNotify(int)), Qt::QueuedConnection);
 }

void TabPageEx::OnSessionListNotify(MediaSelectListItemEx* pListItem)
{
	QString strName = pListItem->m_strFileName;

	if (m_pRibbon)
	{
		m_pRibbon->SetMediaButtonEnable(true);
		m_pRibbon->SetCurrentSelectItem(pListItem);
	}
 }

void TabPageEx::OnListSizeNotify(int iSize)
{
	if (m_pRibbon)
		m_pRibbon->MediaListHasData(iSize);
 }

void TabPageEx::paintEvent(QPaintEvent* pEvent)
{
 	QPainter painter(this);
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(50, 50, 50));
	painter.setPen(QColor(210, 210, 210));
}

void TabPageEx::resizeEvent(QResizeEvent* pEvent)
{
	int iWidth = width();
	int iHeight = height();
	 
	if (m_ptrMediaSelectListEx)
	{
		m_ptrMediaSelectListEx->setGeometry(0, 0, iWidth-14 , iHeight);
		m_ptrMediaSelectListEx->move(7, 0);
	} 

 	QWidget::resizeEvent(pEvent);
}
 
void TabPageEx::SetPageTitle(const QString& title)
{
	m_strPageTitle = title;
 }

void TabPageEx::SetActive(bool state)
{
	m_bActive = state;
	emit ActiveChanged(this);
}



