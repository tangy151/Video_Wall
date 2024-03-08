#include "playlistex.h"
#include "../headfiledefine.h"
#include "flatuiex.h"
#include "playlistviewchild.h"
#include "playlistitemex.h"

PlayListEx::PlayListEx(QWidget *parent)
	: QListWidget(parent)
{
	InitUI();
}


void PlayListEx::InitUI()
{
}

void PlayListEx::onChildSelected(PlayListViewChild* pChild)
{
	PlayListItemEx* pItem = pChild->m_pPlayListItemEx;
	emit OnPlayListNotify(pItem);

	foreach(PlayListItemEx* pItem2, m_listItems)
	{
		if (pItem !=pItem2)
		{
			pItem2->pChild->SetLeftBtnDown(false);
		}
 	}
  }
 
void PlayListEx::OnInsertUserItem(PlayListItemEx * pItem)
{
	m_listItems.append(pItem);
	OnUpLoad();
}

void PlayListEx::OnRemoveUserItem(PlayListItemEx * pItem)
{
}

void PlayListEx::OnUpLoad()
{
	this->clear();

	// Ë¢ÐÂÁÐ±í
	for (PlayListItemEx * pItem : m_listItems)
	{
		OnAddChildItem(pItem);
 	}
 }

void PlayListEx::OnSetBackGroundColor(int iIndex, QWidget* pWidget)
{

}
void PlayListEx::OnAddChildItem(PlayListItemEx *pItem)
{ 
	int iWidth = width();
	PlayListViewChild* pChild = new PlayListViewChild();

	pChild->setGeometry(0, 0, 470, 25);
	pChild->m_pPlayListItemEx = pItem;
	pChild->m_pPlayListItemEx->pChild = pChild;
 
	connect(pChild, SIGNAL(onChildSelected(PlayListViewChild*)), this, SLOT(onChildSelected(PlayListViewChild*)));

	QListWidgetItem * item = new QListWidgetItem("");

	this->addItem(item);
	this->setItemWidget(item, pChild);
	item->setSizeHint(pChild->geometry().size());
}

void PlayListEx::paintEvent(QPaintEvent* pEvent)
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

void PlayListEx::resizeEvent(QResizeEvent* pEvent)
{
	int iWidth = width();
	int iHeight = height();

	QWidget::resizeEvent(pEvent);
 }


