#ifndef		_ADD_PLAY_LIST_WINDOW_H_
#define	 _ADD_PLAY_LIST_WINDOW_H_
 
#include <QDialog>
#include <QLineEdit>

class ButtonEx;
class LabelEx;
class NavLabelEx;

class AddPlayListWindow 
	: public QDialog
{
	Q_OBJECT

public:
	explicit	AddPlayListWindow(QWidget *parent = nullptr);
	~AddPlayListWindow();

  signals:
	void OnAddPlayListNotify(QString);

public slots:
	void OnButtonOK();
	void OnButtonCancel();
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
	void InitLineEdit();

public:
	QString GetPlayListName()
	{
		return 	m_strPlayListName;
	}

public:
	QString		m_strPlayListName;


private:
	std::unique_ptr<ButtonEx>			m_ptrOK;
	std::unique_ptr<ButtonEx>			m_ptrCancel;

	std::unique_ptr<ButtonEx>			m_ptrCloseBtn;


	std::unique_ptr<NavLabelEx>				m_ptrTitle;
	std::unique_ptr<NavLabelEx>				m_ptrName;

 

	std::unique_ptr<QLineEdit>			m_ptrListNameEdit;
 
	QList<ButtonEx*>		m_listButtons;

	QString						m_strExePath;


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


#endif//_ADD_PLAY_LIST_WINDOW_H_


