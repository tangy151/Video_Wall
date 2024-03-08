#ifndef		_LOCAL_STREAM_EDITOR_WINDOW_H_
#define		_LOCAL_STREAM_EDITOR_WINDOW_H_

#include <QDialog>
#include "../globaldefine.h"

class ButtonEx;
class NavLabelEx;
class TabWidgetEx;


class LocalStreamEditorWindow 
	: public QDialog

{
	Q_OBJECT

public:
	explicit  	LocalStreamEditorWindow(QWidget *parent = nullptr);
	~LocalStreamEditorWindow();


public slots:

	void OnButtonClose();

protected:
	void resizeEvent(QResizeEvent *pEvent);
	void paintEvent(QPaintEvent* pEvent);
	void mousePressEvent(QMouseEvent * pEvent);
	void mouseReleaseEvent(QMouseEvent*pEvent);
	void mouseMoveEvent(QMouseEvent *pEvent);



private:
	void 	InitConnect();
	void InitUI();
	void InitButtons();

	void InitLabels();



private:

	std::unique_ptr<ButtonEx>			m_ptrCloseBtn;
	std::unique_ptr<NavLabelEx>		m_ptrTitle;

	QColor				m_iNormalBgColor;
	QColor				m_iHoverBgColor;
	QColor				m_iCheckBgColor;

	QColor				m_iNormalFrameColor;

	QColor				m_iNormalTextColor;
	QColor				m_iHoverTextColor;
	QColor				m_iCheckTextColor;


	QPoint		m_iMovePoint;
	bool			m_bMousePress;
};

#endif//_LOCAL_STREAM_EDITOR_WINDOW_H_


