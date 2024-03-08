#ifndef		_MEDIA_SELECT_LIST_ITEM_EX_H_
#define	    _MEDIA_SELECT_LIST_ITEM_EX_H_

#include <QString>
#include <QList>

#include "../globaldefine.h"




class MediaSelectListViewChild;
class MediaSelectListItemEx  
{
 
public:
	MediaSelectListItemEx() 
	{
		m_bIsOpen = false;
	}

public:

	QString			m_strFileName;
	QString			m_strTotalName;


	ItemType			m_iItemType;

	bool					m_bIsOpen;
	int					m_iUserID;	//QQ号，作为标识

	MediaSelectListViewChild*		pChild;


};


#endif//_MEDIA_SELECT_LIST_ITEM_EX_H_


