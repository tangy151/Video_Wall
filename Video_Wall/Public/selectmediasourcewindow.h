#ifndef		_SELECT_MEDIA_SOURCE_WINDOW_H_
#define	_SELECT_MEDIA_SOURCE_WINDOW_H_

#include <QDialog>
#include <QLineEdit>
#include "../globaldefine.h"

class ButtonEx;
class LabelEx;
class NavLabelEx;
class TabWidgetEx;

class SelectMediaSourceWindow
	: public QDialog
{
	Q_OBJECT

public:
	explicit SelectMediaSourceWindow(QWidget *parent = nullptr);
	~SelectMediaSourceWindow();

public slots:
	void OnButtonOK();
	void OnButtonCancel();
	void OnButtonClose();


public slots:

	void AddPlayListPage(QString strPageName);
	void DeletePlayListPage(QString strPageName);
	 
	void AddPageDataNotify( QString strName, QString strPath);
	void DeletePageDataNotify(QString strName, QString strPath);
	 
public://外部添加删除数据
	void AddPageData(MEDIA_SELECT_TYPE iMediaType, QString strName, QString strPath);
	void DeletePageData(MEDIA_SELECT_TYPE iMediaType, QString strName, QString strPath);


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
	void InitTab();

	void InitLabels();
 


private:
	std::unique_ptr<ButtonEx>			m_ptrOK;
	std::unique_ptr<ButtonEx>			m_ptrCancel;
 	std::unique_ptr<ButtonEx>			m_ptrCloseBtn;
	 
	std::unique_ptr<NavLabelEx>				m_ptrTitle;
  
	QList<ButtonEx*>		m_listButtons;

	std::unique_ptr<TabWidgetEx>			m_ptrTabWidget;
 
	MEDIA_SELECT_TYPE			m_iMediaType;


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


#endif//_SELECT_MEDIA_SOURCE_WINDOW_H_
