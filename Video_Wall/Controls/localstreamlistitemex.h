#ifndef			_LOCAL_STREAM_LISTITEM_EX_H_
#define		    _LOCAL_STREAM_LISTITEM_EX_H_

 
#include <QString>
#include <QList>

#include "../globaldefine.h"

class LocalStreamListViewGroup;
class LocalStreamListViewChild;

class LocalStreamListItemEx  
{
 public:
	LocalStreamListItemEx( ) 
	{
		m_pGroup = nullptr;
		m_pChild = nullptr;
 	}
	

public:
 
 	QString			m_strItemName;
 	QString			m_strGroupName;	//����
	 
	ItemType			m_iItemType;
  

	LocalStreamListViewGroup*		m_pGroup;
	LocalStreamListViewChild*			m_pChild;

	QList<LocalStreamListItemEx*>			m_listChilds;


};

#endif//_LOCAL_STREAM_LISTITEM_EX_H_



