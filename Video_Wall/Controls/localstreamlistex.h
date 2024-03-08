#ifndef		_LOCAL_STREAM_LIST_EX_H_
#define	_LOCAL_STREAM_LIST_EX_H_


#include <QList>
#include <QHash>
#include <QMenu>
#include <map>

#include <QListWidget>

class LocalStreamListItemEx;
class LocalStreamListViewChild;
class LocalStreamListViewGroup;

class LocalStreamListEx
	: public QListWidget
{
	Q_OBJECT

public:
	explicit	LocalStreamListEx(QWidget *parent = nullptr);
	~LocalStreamListEx();
	  
signals:
 	void OnLocalStreamListNotify(LocalStreamListItemEx* pListItem);
	  
public slots:
	void onChildSelected(LocalStreamListViewChild* pChild);
	 
public:
	void OnInsertUserItem(LocalStreamListItemEx * pItem);
	void OnRemoveUserItem(LocalStreamListItemEx * pItem);
	void OnUpLoad();

private:
	void OnSetBackGroundColor(int iIndex, QWidget* pWidget);
	void OnAddChildItem(LocalStreamListViewGroup* pGroup, LocalStreamListItemEx *pItem);

protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent* pEvent);

private:

	QList<LocalStreamListItemEx *>		m_listItems;	 //所有的数据
	LocalStreamListItemEx *					m_pRightClickItem;


};
#endif//_LOCAL_STREAM_LIST_EX_H_
