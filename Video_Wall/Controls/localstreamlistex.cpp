#include "localstreamlistex.h"

#include "localstreamlistitemex.h"
#include "localstreamlistviewchild.h"
#include "localstreamlistviewgroup.h"

#include "../headfiledefine.h"

LocalStreamListEx::LocalStreamListEx(QWidget *parent)
	: QListWidget(parent)
{
}

LocalStreamListEx::~LocalStreamListEx()
{
}

void LocalStreamListEx::onChildSelected(LocalStreamListViewChild* pChild)
{
 	LocalStreamListItemEx* pItem = pChild->m_pLocalStreamListItemEx;

	emit OnLocalStreamListNotify(pItem);

	foreach(LocalStreamListItemEx* pItem2, m_listItems)
	{
		if (pItem2->m_iItemType == ItemType_Group)
		{
			foreach(LocalStreamListItemEx* pItem3, pItem2->m_listChilds)
			{
				if (pItem != pItem3)
				{
					pItem3->m_pChild->SetLeftBtnDown(false);
				}
			}
  		}  
	}
 }

void LocalStreamListEx::OnInsertUserItem(LocalStreamListItemEx * pItem)
{
	if (pItem->m_iItemType == ItemType_Group)
	{
		m_listItems.append(pItem);
	}
	else
	{
		foreach(LocalStreamListItemEx*pGroup, m_listItems)
		{
			if (!pGroup->m_strGroupName.compare(pItem->m_strGroupName))
			{
				pGroup->m_listChilds.append(pItem);

				break;
			}
		}
	}

	OnUpLoad();
}

void LocalStreamListEx::OnRemoveUserItem(LocalStreamListItemEx * pItem)
{

}

void LocalStreamListEx::OnUpLoad()
{
	this->clear();

	// 刷新列表
	for (LocalStreamListItemEx * pItem : m_listItems)
	{
		if (pItem->m_iItemType == ItemType_Group)
		{
			LocalStreamListViewGroup* pGroup = new LocalStreamListViewGroup();
			pGroup->setGeometry(0, 0, 420, 30);

			pGroup->OnSetLocalStreamListItemEx(pItem);

			QListWidgetItem *pWItem = new QListWidgetItem("");

			this->addItem(pWItem);
			this->setItemWidget(pWItem, pGroup);
			pWItem->setSizeHint(pGroup->geometry().size());

			// 再加载离线好友
			for (LocalStreamListItemEx* pUserList : pItem->m_listChilds)
			{
				OnAddChildItem(pGroup, pUserList);
			}
		}
	}
}

void LocalStreamListEx::OnSetBackGroundColor(int iIndex, QWidget* pWidget)
{
 }

void LocalStreamListEx::OnAddChildItem(LocalStreamListViewGroup* pGroup,  LocalStreamListItemEx *pItem)
{
 	LocalStreamListViewChild* pChild = new LocalStreamListViewChild();
	pChild->setGeometry(0, 0, 420, 30);

	pChild->m_pLocalStreamListItemEx = pItem;
	pChild->m_pLocalStreamListItemEx->m_pChild	= pChild;
	pChild->m_pLocalStreamListItemEx->m_pGroup	= pGroup;
	  
	connect(pChild, SIGNAL(onChildSelected(LocalStreamListViewChild*)), this, SLOT(onChildSelected(LocalStreamListViewChild*)));
  
	QListWidgetItem * item = new QListWidgetItem("");

	this->addItem(item);
	this->setItemWidget(item, pChild);
	item->setSizeHint(pChild->geometry().size());
 }
 
void LocalStreamListEx::paintEvent(QPaintEvent* pEvent)
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

void LocalStreamListEx::resizeEvent(QResizeEvent* pEvent)
{
	int iWidth = width();
	int iHeight = height();

	QWidget::resizeEvent(pEvent);
}

