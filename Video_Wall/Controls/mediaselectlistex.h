#ifndef			_MEDIA_SELECT_LIST_EX_H_
#define		_MEDIA_SELECT_LIST_EX_H_
 
#include <QListWidget>
#include <QListWidget>
#include <QList>
#include <QHash>
#include <QMenu>
#include <map>

#include <QListWidget>

class MediaSelectListViewChild;
class MediaSelectListItemEx;

class MediaSelectListEx 
	: public QListWidget
{
	Q_OBJECT

public:
	explicit	MediaSelectListEx(QWidget *parent = nullptr);

signals:
 	void OnSessionListNotify(MediaSelectListItemEx* pListItem);
 	void OnListSizeNotify(int iSize);
	 
public slots:
	void onChildSelected(MediaSelectListViewChild* pChild);
	 
public:
	void InitUI();
	 
public:
	void OnInsertUserItem(QString strTitle, QString strPath);
	void OnRemoveUserItem(MediaSelectListItemEx * pItem);
	void OnRemoveUserItem(QString strTitle, QString strPath);


	void OnUpLoad();

private:
	void OnSetBackGroundColor(int iIndex, QWidget* pWidget);
	void OnAddChildItem(MediaSelectListItemEx *pItem);

protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent* pEvent);
	 
public:
	void Layout(int iWidth,int iHeight);

private:

	QList<MediaSelectListItemEx *>		m_listItems;	 //所有的数据
  
 };


#endif//_MEDIA_SELECT_LIST_EX_H_
