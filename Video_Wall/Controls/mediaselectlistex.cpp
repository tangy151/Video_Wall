#include "mediaselectlistex.h"

#include "mediaselectlistitemex.h"
#include "mediaselectlistviewchild.h"

#include "../headfiledefine.h"
#include "../globaldefine.h"

MediaSelectListEx::MediaSelectListEx(QWidget *parent)
	: QListWidget(parent)
{
	InitUI();
}


void MediaSelectListEx::onChildSelected(MediaSelectListViewChild* pChild)
{
	MediaSelectListItemEx* pItem = pChild->m_pPlayListItemEx;
	emit OnSessionListNotify(pItem);

	foreach(MediaSelectListItemEx* pItem2, m_listItems)
	{
		if (pItem != pItem2)
		{
			pItem2->pChild->SetLeftBtnDown(false);
		}
	}
}
 
void MediaSelectListEx::InitUI()
{
}
 
void MediaSelectListEx::OnInsertUserItem(QString strTitle, QString strPath)
{
	int iSize = m_listItems.size();

	if (iSize > 0)
	{
		foreach(MediaSelectListItemEx* pItem2, m_listItems)
		{
			if (pItem2->m_strTotalName == strPath)
				return;
		}
	}
	 
	MediaSelectListItemEx*  pItem = new MediaSelectListItemEx();

	pItem->m_iItemType = ItemType_Child;

	pItem->m_strFileName = strTitle;
	pItem->m_strTotalName = strPath;
	 
	m_listItems.append(pItem);

	OnUpLoad();
}

void MediaSelectListEx::OnRemoveUserItem(QString strTitle, QString strPath)
{
	int iSize = m_listItems.size();
   
	if (iSize > 0)
	{
		foreach(MediaSelectListItemEx* pItem, m_listItems)
		{
			if (pItem->m_strTotalName == strPath)
			{
				m_listItems.removeOne(pItem);
				OnUpLoad();
				return;
 			}
		}
	}
	else
	{
		emit OnListSizeNotify(iSize);
	}
 }

void MediaSelectListEx::OnRemoveUserItem(MediaSelectListItemEx * pItem)
{
	int iSize = m_listItems.size();

	if (iSize > 0)
	{
 		m_listItems.removeOne(pItem);
		OnUpLoad();
 	}
	else
	{
		emit OnListSizeNotify(iSize);
 	}
 }

void MediaSelectListEx::OnUpLoad()
{
	this->clear();

	// Ë¢ÐÂÁÐ±í
	for (MediaSelectListItemEx * pItem : m_listItems)
	{
		OnAddChildItem(pItem);
	}
}

void MediaSelectListEx::OnSetBackGroundColor(int iIndex, QWidget* pWidget)
{

}

void MediaSelectListEx::OnAddChildItem(MediaSelectListItemEx *pItem)
{
	int iWidth = width();
	MediaSelectListViewChild* pChild = new MediaSelectListViewChild();
	
#if PIX_1080p
	pChild->setGeometry(0, 0, 450, 25);
 #else
	pChild->setGeometry(0, 0, 300, 15);
 #endif


	pChild->m_pPlayListItemEx = pItem;
	pChild->m_pPlayListItemEx->pChild = pChild;

	connect(pChild, SIGNAL(onChildSelected(MediaSelectListViewChild*)), this, SLOT(onChildSelected(MediaSelectListViewChild*)));
	  
	QListWidgetItem * item = new QListWidgetItem("");

	this->addItem(item);
	this->setItemWidget(item, pChild);
	item->setSizeHint(pChild->geometry().size());
}
 
void MediaSelectListEx::Layout(int iWidth, int iHeight)
{
	int iSize = m_listItems.size();

	if (iSize > 0)
	{
		foreach(MediaSelectListItemEx* pItem2, m_listItems)
		{
			if (pItem2)
			{
				pItem2->pChild->setGeometry(0, 0, iWidth, 25);
				pItem2->pChild->SetLeftBtnDown(false);
			}
		}
	}
}

void MediaSelectListEx::resizeEvent(QResizeEvent* pEvent)
{
	int iWidth = width();
	int iHeight = height();

	  
	QWidget::resizeEvent(pEvent);
}

void MediaSelectListEx::paintEvent(QPaintEvent* pEvent)
{
	int iWidth = width();
	int iHeight = height();

	QPainter painter(this);
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(0, 255, 0));
	painter.setPen(QColor(210, 210, 210));
	painter.save();
	painter.setBrush(Qt::NoBrush);
}




