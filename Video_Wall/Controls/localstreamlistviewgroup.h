#ifndef		_LOCAL_MEDIA_LIST_VIEW_GROUP_H_
#define	_LOCAL_MEDIA_LIST_VIEW_GROUP_H_
 
#include <QWidget>
#include <QMenu>
#include <QMouseEvent>

 
#include <memory>

 class NavLabelEx;

class LocalStreamListItemEx;

class LocalStreamListViewGroup : public QWidget
{
	Q_OBJECT

public:
	explicit	LocalStreamListViewGroup(QWidget *parent = nullptr);
	~LocalStreamListViewGroup();

public:
 	void InitLabelEx();
	void InitConnect();

public:
	void  OnSetLocalStreamListItemEx(LocalStreamListItemEx* pItem);


protected:
	void mousePressEvent(QMouseEvent *pEvent);
	void resizeEvent(QResizeEvent *pEvent);
	void paintEvent(QPaintEvent* pEvent);

private:
	LocalStreamListItemEx*		m_pLocalStreamListItemEx;

 
	QString						m_strExePath;


public:
	std::unique_ptr<NavLabelEx>				m_ptrGroupName;
  
};
#endif//_LOCAL_MEDIA_LIST_VIEW_GROUP_H_
