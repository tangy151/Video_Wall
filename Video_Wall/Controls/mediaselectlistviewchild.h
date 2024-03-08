#ifndef		_MEDIA_SELECT_LIST_VIEW_CHILD_H_
#define _MEDIA_SELECT_LIST_VIEW_CHILD_H_

#include <QWidget>
#include <QMouseEvent>

#include "mediaselectlistitemex.h"

class MediaSelectListViewChild 
	: public QWidget
{
	Q_OBJECT

public:
	explicit MediaSelectListViewChild(QWidget *parent = nullptr);
	 
public:
	void SetLeftBtnDown(bool b);

protected:
	void mousePressEvent(QMouseEvent *pEvent);
 	void enterEvent(QEvent *pEvent);
	void leaveEvent(QEvent *pEvent);

	void paintEvent(QPaintEvent *pEvent);

signals:
	void onChildSelected(MediaSelectListViewChild* pChild);

public:
	MediaSelectListItemEx*		m_pPlayListItemEx;
	QString								m_strExePath;

	
	bool								m_bLeftBtnDown;
	QColor							m_iNormalTextColor;
	QColor							m_iCheckTextColor;


private:
	bool m_bEntered;


};
#endif//_MEDIA_SELECT_LIST_VIEW_CHILD_H_
 


