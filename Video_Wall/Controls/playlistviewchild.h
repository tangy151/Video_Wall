#ifndef			_PLAY_LIST_VIEW_CHILD_H_
#define		_PLAY_LIST_VIEW_CHILD_H_

#include <QWidget>
#include <QMouseEvent>
#include "playlistitemex.h"

class PlayListViewChild 
	: public QWidget
{
	Q_OBJECT

public:
	explicit	PlayListViewChild(QWidget *parent = nullptr);
	~PlayListViewChild();

public:
	void SetLeftBtnDown(bool b);

protected:
	void mousePressEvent(QMouseEvent *pEvent);
// 	void mouseDoubleClickEvent(QMouseEvent * pEvent);
	void enterEvent(QEvent *pEvent);
	void leaveEvent(QEvent *pEvent);

	void paintEvent(QPaintEvent *pEvent);

signals:
	void onChildSelected(PlayListViewChild* pChild);

public:
	PlayListItemEx*			m_pPlayListItemEx;
	QString						m_strExePath;

	bool								m_bLeftBtnDown;
	QColor							m_iNormalTextColor;
	QColor							m_iCheckTextColor;


private:
	bool m_bEntered;

};


#endif//_PLAY_LIST_VIEW_CHILD_H_
