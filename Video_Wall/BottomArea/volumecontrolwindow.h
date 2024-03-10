#ifndef		_VOLUME_CONTROL_WINDOW_H_
#define	    _VOLUME_CONTROL_WINDOW_H_


#include <QWidget>
#include <memory>
 
class ButtonEx;
class SliderEx;
class NavLabelEx;
class VolumeMeter;
class RulerLineEx;

class VolumeControlWindow 
	: public QWidget
{
	Q_OBJECT

public:
	VolumeControlWindow(QWidget *parent = nullptr);
	~VolumeControlWindow();
	 

public:
	void InitSlider();
	void InitVolumeMeter();
	void InitButtons();
	void InitLabels();
	void InitConnects();

private slots:
	void updateValue();
public:
	void	SetChannelIndex(int iIndex)
	{
		m_iChannelIndex = iIndex;
	}

protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent* pEvent);

private:
	int m_iChannelIndex;


protected:
	std::unique_ptr<ButtonEx>			m_ptrBtnPlay;
	std::unique_ptr<ButtonEx>			m_ptrBtnPause;
	std::unique_ptr<ButtonEx>			m_ptrBtnStop;
	std::unique_ptr<ButtonEx>			m_ptrBtnSpeaker;

	std::unique_ptr<SliderEx>			m_ptrVSliderEx;		//��ֱ


 	QList<ButtonEx*>		m_listButtons;

	std::unique_ptr<VolumeMeter>			m_ptrVolumeMeter;
	std::unique_ptr<NavLabelEx>				m_ptrLabelChannel;

	std::unique_ptr<RulerLineEx>				m_ptrRulerLineEx;

	

	QString		m_strExePath;

};
#endif//_VOLUME_CONTROL_WINDOW_H_
