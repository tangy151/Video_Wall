#ifndef		_PLAY_LISTITEM_EX_H_
#define _PLAY_LISTITEM_EX_H_


#include <QString>
#include <QList>

#include "../globaldefine.h"

class PlayListViewChild;
class PlayListItemEx  
{ 
 public:
	 PlayListItemEx()
	 {
		 m_bIsOpen = false;
	 }

public:

	QString			m_strFileName;
	QString			m_strTotalName;
  

	ItemType			m_iItemType;

	bool					m_bIsOpen;
	int					m_iUserID;	//QQ�ţ���Ϊ��ʶ

	PlayListViewChild*		pChild;
};



#endif//_PLAY_LISTITEM_EX_H_
