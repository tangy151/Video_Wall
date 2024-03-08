#ifndef		_ADD_IP_STREAM_WINDOW_H_
#define		_ADD_IP_STREAM_WINDOW_H_

#include <QDialog>
#include <QLineEdit>

class ButtonEx;
class LabelEx;
class NavLabelEx;

class AddIPStreamWindow 
	: public QDialog
{
	Q_OBJECT

public:
	explicit	AddIPStreamWindow(QWidget *parent = nullptr) ;
	~AddIPStreamWindow();

signals:
	void OnAddIPStreamNotify(QString,QString);


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
	void GetNameAndAddr(QString& strName, QString& strAddr)
	{
		strName	= m_strName;
		strAddr	= m_strAddr;
	}


private:
	std::unique_ptr<ButtonEx>			m_ptrOK;
	std::unique_ptr<ButtonEx>			m_ptrCancel;

	std::unique_ptr<ButtonEx>			m_ptrCloseBtn;


	std::unique_ptr<NavLabelEx>				m_ptrTitle;

	std::unique_ptr<NavLabelEx>				m_ptrStreamName;
 	std::unique_ptr<NavLabelEx>				m_ptrStreamAddr;


	std::unique_ptr<QLineEdit>			m_ptrStreamNameEdit;
	std::unique_ptr<QLineEdit>			m_ptrStreamAddrEdit;


	QList<ButtonEx*>		m_listButtons;

	QString						m_strExePath;

	QString						m_strName;
	QString						m_strAddr;

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


#endif//_ADD_IP_STREAM_WINDOW_H_
