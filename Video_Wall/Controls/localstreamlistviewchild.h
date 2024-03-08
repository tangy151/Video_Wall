#ifndef			_LOCAL_MEDIA_LIST_VIEW_CHILD_H_
#define		_LOCAL_MEDIA_LIST_VIEW_CHILD_H_

#include <QWidget>
#include <QMouseEvent>

#include "localstreamlistitemex.h"

class LocalStreamListViewChild
	: public QWidget
{
	Q_OBJECT

public:
	explicit LocalStreamListViewChild(QWidget *parent = nullptr);
	~LocalStreamListViewChild();

protected:
	void mousePressEvent(QMouseEvent *pEvent);
 	void enterEvent(QEvent *pEvent);
	void leaveEvent(QEvent *pEvent);

	void paintEvent(QPaintEvent *pEvent);

public:
	void SetLeftBtnDown(bool b);

signals:
	void onChildSelected(LocalStreamListViewChild* pChild);

public:
	LocalStreamListItemEx*			m_pLocalStreamListItemEx;
	
	QString	m_strExePath;

	bool			m_bLeftBtnDown;
	QColor		m_iNormalTextColor;
	QColor		m_iCheckTextColor;

 private:
	bool			m_bEntered;
};


#endif//_LOCAL_MEDIA_LIST_VIEW_CHILD_H_
