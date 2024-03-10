#ifndef			_PLAY_LIST_EX_H_
#define		    _PLAY_LIST_EX_H_
 
#include <QListWidget>
#include <QListWidget>
#include <QList>
#include <QHash>
#include <QMenu>
#include <map>

#include <QListWidget>

class PlayListItemEx;
class PlayListViewChild;

class PlayListEx 
	: public QListWidget
{
	Q_OBJECT

public:
	explicit	PlayListEx(QWidget *parent = nullptr);
 

signals:
 
	void OnPlayListNotify(PlayListItemEx* pListItem);

public slots:
 	void onChildSelected(PlayListViewChild* pChild);


public:
	void InitUI();
 
 
public:
	void OnInsertUserItem(PlayListItemEx * pItem);
	void OnRemoveUserItem(PlayListItemEx * pItem);
	void OnUpLoad();

private:
	void OnSetBackGroundColor(int iIndex, QWidget* pWidget);
	void OnAddChildItem(PlayListItemEx *pItem);

protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent* pEvent);

private:

	QList<PlayListItemEx *>		    m_listItems;	 //所有的数据
	PlayListItemEx *					m_pRightClickItem;

};


#endif//_PLAY_LIST_EX_H_
