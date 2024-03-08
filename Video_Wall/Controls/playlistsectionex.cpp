#include "playlistsectionex.h"
#include "../headfiledefine.h"
#include "playlistex.h"
#include "flatuiex.h"
#include "playlistitemex.h"

PlayListSectionEx::PlayListSectionEx(QWidget *parent, QString  strTitleName)
	: QWidget(parent)
	, m_strTitleName(strTitleName)
{
	InitUI();
	InitConnects();
}

PlayListSectionEx::~PlayListSectionEx()
{
}


void PlayListSectionEx::InitUI()
{
 	m_ptrPlayListEx.reset(new PlayListEx(this));
	  
	InitData();
 
 	  
	m_ptrPlayListEx->setStyleSheet("QListWidget{border:1 px; color:rgb(230,230,230); }");
	 
 }

void PlayListSectionEx::InitData()
{
	for (int iIndex = 0; iIndex < 8; iIndex++)
	{ 
 		PlayListItemEx*  pItem = new PlayListItemEx();

 		pItem->m_iItemType = ItemType_Child;

		pItem->m_strFileName		= QString::fromLocal8Bit("测试_%1").arg(iIndex + 1);
 		pItem->m_strTotalName	= QString(QString::fromLocal8Bit("0:00:00"));

		pItem->m_iUserID = iIndex + 1;
 
		m_ptrPlayListEx->OnInsertUserItem(pItem);
 	}
}

void PlayListSectionEx::InitConnects()
{
	connect(m_ptrPlayListEx.get(), SIGNAL(OnSessionListNotify(PlayListItemEx*)), this, SLOT(OnSessionListNotify(PlayListItemEx*)), Qt::QueuedConnection);
}

void PlayListSectionEx::OnSessionListNotify(PlayListItemEx* pListItem)
{
	QString strName = pListItem->m_strFileName;
	int i = 0;
}

void PlayListSectionEx::paintEvent(QPaintEvent* pEvent)
{
 	int iWidth = width();
	int iHeight = height();

	QPainter painter(this);
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(30, 30, 30));
	painter.setPen(QColor(210, 210, 210));
	painter.save();
	painter.setBrush(Qt::NoBrush);

// 	//根据当前状态选择对应颜色
// 	QColor textColor(239, 98, 234);
 

	painter.restore();
}

void PlayListSectionEx::resizeEvent(QResizeEvent* pEvent)
{
	int iWidth = width();
	int iHeight = height();
	 
	if (m_ptrPlayListEx)
	{
		m_ptrPlayListEx->setGeometry(1, 1, iWidth-2, iHeight-2);
		m_ptrPlayListEx->move(1, 1);
	}


 	QWidget::resizeEvent(pEvent);
}



