#ifndef			_LOCAL_MEDIA_STREAM_WINDOW_H_
#define		_LOCAL_MEDIA_STREAM_WINDOW_H_
 
#include <QDialog>
#include <QLineEdit>

class ButtonEx;
class NavLabelEx;
class LocalStreamListEx;
class LocalStreamListItemEx;

class LocalMediaStreamWindow 
	: public QDialog
{
	Q_OBJECT

public:
	explicit	LocalMediaStreamWindow(QWidget *parent = nullptr);
	~LocalMediaStreamWindow();
	 
signals:
	void OnDeviceNameNotify(QString strDeviceName);


public slots:
	void OnLocalStreamListNotify(LocalStreamListItemEx* pListItem);


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
	void InitListEx();

	void InitData();

public:
	QString OnGetDeviceName()
	{
		return m_strDevceName;
	}


private:
	std::unique_ptr<ButtonEx>			m_ptrOK;
	std::unique_ptr<ButtonEx>			m_ptrCancel;

	std::unique_ptr<ButtonEx>			m_ptrCloseBtn;

	std::unique_ptr<NavLabelEx>				m_ptrTitle;

	std::unique_ptr<LocalStreamListEx>				m_ptrLocalStreamListEx;
 
	 

	QList<ButtonEx*>		m_listButtons;

	QString						m_strExePath;
	QString						m_strDevceName;

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


#endif//_LOCAL_MEDIA_STREAM_WINDOW_H_
