#ifndef			_PLAY_CONTROL_WINDOW_H_
#define		    _PLAY_CONTROL_WINDOW_H_

#include <memory>
#include <QWidget>

class ButtonEx;
class SliderEx;
class NavLabelEx;
class ProgressBarEx;


 class PlayControlWindow 
	 : public QWidget
{
	Q_OBJECT

public:
	PlayControlWindow(QWidget *parent);
	~PlayControlWindow();


public:
	void InitSlider();
	void InitButtons();
	void InitLabels();
	void InitConnects();

protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent* pEvent);

public slots:
	void  OnButtonPlay();
	void  OnButtonPause();
	void  OnButtonStop();
	void  OnButtonNext();
	void  OnButtonPrev();
 
	  

protected:
	std::unique_ptr<ButtonEx>			m_ptrBtnPlay;
	std::unique_ptr<ButtonEx>			m_ptrBtnPause;
	std::unique_ptr<ButtonEx>			m_ptrBtnStop;

	std::unique_ptr<ButtonEx>			m_ptrBtnNext;
	std::unique_ptr<ButtonEx>			m_ptrBtnPrev;

	QList<ButtonEx*>		m_listButtons;
	 
	std::unique_ptr<ProgressBarEx>			m_ptrPlayProgress;

	std::unique_ptr<NavLabelEx>			m_ptrTotalTime;
	std::unique_ptr<NavLabelEx>			m_ptrCurTime;

	QColor				m_iNormalFrameColor;
	QColor				m_iNormalBgColor;

	QColor				m_iHoverBgColor;
	QColor				m_iCheckBgColor;

	QColor				m_iNormalTextColor;
	QColor				m_iHoverTextColor;
	QColor				m_iCheckTextColor;

	QString			m_strExePath;

};


#endif//_PLAY_CONTROL_WINDOW_H_
