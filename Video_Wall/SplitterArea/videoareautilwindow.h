#ifndef			_VIDEO_AREA_UTIL_WINDOW_H_
#define		_VIDEO_AREA_UTIL_WINDOW_H_
  
#include <QWidget>

#include "../globaldefine.h"

class QPushButton;
class LabelEx;
class ButtonEx;
class NavLabelEx;
class SliderEx;
class QSplitter;
class SplitterEx;

class PlayerListWindow;
class MediaSettingWindow;
class AudioSettingWindow;
 
class VideoAreaUtilWindow 
	: public QWidget
{
	Q_OBJECT

public:
	VideoAreaUtilWindow(QWidget *parent);
	~VideoAreaUtilWindow();
public:
	void InitUI();
	
	void InitMainChButtons();
	void InitPrevChButtons();
	  
	void InitMainEffectButtons();
	void InitPrevEffectButtons();
	 
	void InitMainSubtitlesButtons();
	void InitPrevSubtitlesButtons();
	 
	void LayoutChannelButtons();
	void LayoutEffectButtons();
	void LayoutSubtitlesButtons();

	void LayoutChannelButtons2();
	void LayoutEffectButtons2();
	void LayoutSubtitlesButtons2();


	void InitLabels();
	void InitConnect();
 

protected:
	void paintEvent(QPaintEvent* pEvent);
	void resizeEvent(QResizeEvent* pEvent);
	  

public slots:
	void  OnBtnMainCh1();
	void  OnBtnMainCh2();
	void  OnBtnMainCh3();
	void  OnBtnMainCh4();
	void  OnBtnMainCh5();
	void  OnBtnMainCh6();
	void  OnBtnMainCh7();
	void  OnBtnMainCh8();
	void  OnBtnMainCh9();

#if PIX_1080p
	void  OnBtnMainCh10();
	void  OnBtnMainCh11();
	void  OnBtnMainCh12();
#endif



	void OnBtnPrevCh1();
	void OnBtnPrevCh2();
	void OnBtnPrevCh3();
	void OnBtnPrevCh4();
	void OnBtnPrevCh5();
	void OnBtnPrevCh6();
	void OnBtnPrevCh7();
	void OnBtnPrevCh8();
	void OnBtnPrevCh9();

#if PIX_1080p
	void OnBtnPrevCh10();
	void OnBtnPrevCh11();
	void OnBtnPrevCh12();
 #endif
	 
	void OnBtnMainSubtitles1();
	void OnBtnMainSubtitles2();
	void OnBtnMainSubtitles3();

#if PIX_1080p
	void OnBtnMainSubtitles4();
 #endif

	void OnBtnPrevSubtitles1();
	void OnBtnPrevSubtitles2();
	void OnBtnPrevSubtitles3();

#if PIX_1080p
	void OnBtnPrevSubtitles4();
#endif

	void OnBtnMainBlackSite();
	void OnBtnMainColourBar();
	void OnBtnMainPicInPic1();
	void OnBtnMainPicInPic2();

	void OnBtnPrevBlackSite();
	void OnBtnPrevColourBar();
	void OnBtnPrevPicInPic1();
	void OnBtnPrevPicInPic2();
	 
private:
	std::unique_ptr<ButtonEx>			m_ptrBtnMainCh1;
	std::unique_ptr<ButtonEx>			m_ptrBtnMainCh2;
	std::unique_ptr<ButtonEx>			m_ptrBtnMainCh3;
	std::unique_ptr<ButtonEx>			m_ptrBtnMainCh4;
	std::unique_ptr<ButtonEx>			m_ptrBtnMainCh5;
 	std::unique_ptr<ButtonEx>			m_ptrBtnMainCh6;
	std::unique_ptr<ButtonEx>			m_ptrBtnMainCh7;
	std::unique_ptr<ButtonEx>			m_ptrBtnMainCh8;
	std::unique_ptr<ButtonEx>			m_ptrBtnMainCh9;
	std::unique_ptr<ButtonEx>			m_ptrBtnMainCh10;
	std::unique_ptr<ButtonEx>			m_ptrBtnMainCh11;
	std::unique_ptr<ButtonEx>			m_ptrBtnMainCh12;

	std::unique_ptr<ButtonEx>			m_ptrBtnPrevCh1;
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevCh2;
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevCh3;
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevCh4;
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevCh5;
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevCh6;
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevCh7;
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevCh8;
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevCh9;
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevCh10;
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevCh11;
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevCh12;


	std::unique_ptr<ButtonEx>			m_ptrBtnMainSubtitles1;
	std::unique_ptr<ButtonEx>			m_ptrBtnMainSubtitles2;
	std::unique_ptr<ButtonEx>			m_ptrBtnMainSubtitles3;
	std::unique_ptr<ButtonEx>			m_ptrBtnMainSubtitles4;
 
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevSubtitles1;
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevSubtitles2;
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevSubtitles3;
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevSubtitles4;
	 
	std::unique_ptr<ButtonEx>			m_ptrBtnMainBlackSite;
	std::unique_ptr<ButtonEx>			m_ptrBtnMainColourBar;
	std::unique_ptr<ButtonEx>			m_ptrBtnMainPicInPic1;
	std::unique_ptr<ButtonEx>			m_ptrBtnMainPicInPic2;
	 
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevBlackSite;
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevColourBar;
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevPicInPic1;
	std::unique_ptr<ButtonEx>			m_ptrBtnPrevPicInPic2;
	 
	std::unique_ptr<NavLabelEx>			m_ptrMainLabel;	//Ö÷¼à
	std::unique_ptr<NavLabelEx>			m_ptrPrevLabel;	//Ô¤¼à
	 
	QList<ButtonEx*>		m_listMainChanBtns;
	QList<ButtonEx*>		m_listPrevChanBtns;
	
	QList<ButtonEx*>		m_listMainSubtitlesBtns;
	QList<ButtonEx*>		m_listPrevSubtitlesBtns;

	QList<ButtonEx*>		m_listMainEffectBtns;
	QList<ButtonEx*>		m_listPrevEffectBtns;

	//std::unique_ptr<QSplitter>				m_ptrBottomSplitter;
	std::unique_ptr<SplitterEx>				m_ptrBottomSplitter;

	
	std::unique_ptr<PlayerListWindow>				m_ptrPlayerListWindow;
	std::unique_ptr<MediaSettingWindow>		m_ptrMediaSettingWindow;
	std::unique_ptr<AudioSettingWindow>			m_ptrAudioSettingWindow;
  

	QColor				m_iNormalFrameColor;
	QColor				m_iNormalBgColor;

	QColor				m_iHoverBgColor;
	QColor				m_iCheckBgColor;

	QColor				m_iNormalTextColor;
	QColor				m_iHoverTextColor;
	QColor				m_iCheckTextColor;

	QString			m_strExePath;
 };

#endif//_VIDEO_AREA_UTIL_WINDOW_H_
