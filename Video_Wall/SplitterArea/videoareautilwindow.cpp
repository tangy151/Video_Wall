#include "videoareautilwindow.h"
#include "../headfiledefine.h"
#include "../globaldefine.h"
 
#include "../Controls/flatuiex.h"
#include "../Controls/navlabelex.h"
#include "../Controls/buttonex.h"
#include "../Controls/splitterex.h"
 
#include "../BottomArea/audiosettingwindow.h"
#include "../BottomArea/mediasettingwindow.h"
#include "../BottomArea/playerlistwindow.h"
 
#include "../runtimedata.h"

VideoAreaUtilWindow::VideoAreaUtilWindow(QWidget *parent)
	: QWidget(parent)
	, m_ptrBtnMainCh1(nullptr)
	, m_ptrBtnMainCh2(nullptr)
	, m_ptrBtnMainCh3(nullptr)
	, m_ptrBtnMainCh4(nullptr)
	, m_ptrBtnMainCh5(nullptr)
	, m_ptrBtnMainCh6(nullptr)
	, m_ptrBtnMainCh7(nullptr)
	, m_ptrBtnMainCh8(nullptr)
	, m_ptrBtnMainCh9(nullptr)
	, m_ptrBtnMainCh10(nullptr)
	, m_ptrBtnMainCh11(nullptr)
	, m_ptrBtnMainCh12(nullptr)

	, m_ptrBtnPrevCh1(nullptr)
	, m_ptrBtnPrevCh2(nullptr)
	, m_ptrBtnPrevCh3(nullptr)
	, m_ptrBtnPrevCh4(nullptr)
	, m_ptrBtnPrevCh5(nullptr)
	, m_ptrBtnPrevCh6(nullptr)
	, m_ptrBtnPrevCh7(nullptr)
	, m_ptrBtnPrevCh8(nullptr)
	, m_ptrBtnPrevCh9(nullptr)
	, m_ptrBtnPrevCh10(nullptr)
	, m_ptrBtnPrevCh11(nullptr)
	, m_ptrBtnPrevCh12(nullptr)

	, m_ptrBtnMainSubtitles1(nullptr)
	, m_ptrBtnMainSubtitles2(nullptr)
	, m_ptrBtnMainSubtitles3(nullptr)
	, m_ptrBtnMainSubtitles4(nullptr)
	, m_ptrBtnPrevSubtitles1(nullptr)
	, m_ptrBtnPrevSubtitles2(nullptr)
	, m_ptrBtnPrevSubtitles3(nullptr)
	, m_ptrBtnPrevSubtitles4(nullptr)
	, m_ptrBtnMainBlackSite(nullptr)
	, m_ptrBtnMainColourBar(nullptr)
	, m_ptrBtnMainPicInPic1(nullptr)
	, m_ptrBtnMainPicInPic2(nullptr)

	, m_ptrBtnPrevBlackSite(nullptr)
	, m_ptrBtnPrevColourBar(nullptr)
	, m_ptrBtnPrevPicInPic1(nullptr)
	, m_ptrBtnPrevPicInPic2(nullptr)

	, m_ptrMainLabel(nullptr)
	, m_ptrPrevLabel(nullptr)

	, m_ptrPlayerListWindow(nullptr)
	, m_ptrMediaSettingWindow(nullptr)
	, m_ptrAudioSettingWindow(nullptr)
 {  
	m_strExePath = QCoreApplication::applicationDirPath();

	m_iNormalBgColor = QColor(50, 50, 50);
	m_iNormalFrameColor = QColor(50, 50, 50);

	m_iHoverBgColor = QColor(255, 0, 0);
	m_iCheckBgColor = QColor(255, 0, 0);

	m_iNormalTextColor = QColor(200, 200, 200);
	m_iHoverTextColor = QColor(200, 200, 200);
	m_iCheckTextColor = QColor(0, 0, 0);

	InitUI();

	InitMainChButtons();
	InitPrevChButtons();

	InitMainEffectButtons();
	InitPrevEffectButtons();

	InitMainSubtitlesButtons();
	InitPrevSubtitlesButtons();

	InitLabels();
	InitConnect();
 }

VideoAreaUtilWindow::~VideoAreaUtilWindow()
{
}

void VideoAreaUtilWindow::InitUI()
{
	m_ptrMediaSettingWindow.reset(new MediaSettingWindow(this/*m_ptrBottomSplitter.get()*/));
	m_ptrPlayerListWindow.reset(new PlayerListWindow(this/*m_ptrBottomSplitter.get()*/));
	m_ptrAudioSettingWindow.reset(new AudioSettingWindow(this/*m_ptrBottomSplitter.get()*/));
	 
	OnGetRuntimeData().OnSetMediaSettingWindow(m_ptrMediaSettingWindow.get());
	OnGetRuntimeData().OnSetPlayerListWindow(m_ptrPlayerListWindow.get());
	OnGetRuntimeData().OnSetAudioSettingWindow(m_ptrAudioSettingWindow.get());
 }

#if PIX_1080p

void VideoAreaUtilWindow::InitMainSubtitlesButtons()
{
	m_ptrBtnMainSubtitles1.reset(new ButtonEx(this));
	m_ptrBtnMainSubtitles2.reset(new ButtonEx(this));
	m_ptrBtnMainSubtitles3.reset(new ButtonEx(this));
	m_ptrBtnMainSubtitles4.reset(new ButtonEx(this));

	m_listMainSubtitlesBtns << m_ptrBtnMainSubtitles1.get() << m_ptrBtnMainSubtitles2.get() << m_ptrBtnMainSubtitles3.get()
		<< m_ptrBtnMainSubtitles4.get();

	for (int iIndex = 0; iIndex < m_listMainSubtitlesBtns.count(); iIndex++)
	{
		ButtonEx* pButtonEx = m_listMainSubtitlesBtns.at(iIndex);
		pButtonEx->setPaddingLeft(0);
		pButtonEx->setShowLine(false);
		pButtonEx->setShowIcon(false);
		pButtonEx->setIconSpace(0);

		if (pButtonEx == m_ptrBtnMainSubtitles1.get())
		{
			m_ptrBtnMainSubtitles1->setText(QString::fromLocal8Bit("×ÖÄ»1"));
		}
		else if (pButtonEx == m_ptrBtnMainSubtitles2.get())
		{
			m_ptrBtnMainSubtitles2->setText(QString::fromLocal8Bit("×ÖÄ»2"));
		}
		else if (pButtonEx == m_ptrBtnMainSubtitles3.get())
		{
			m_ptrBtnMainSubtitles3->setText(QString::fromLocal8Bit("×ÖÄ»3"));
		}
		else if (pButtonEx == m_ptrBtnMainSubtitles4.get())
		{
			m_ptrBtnMainSubtitles4->setText(QString::fromLocal8Bit("×ÖÄ»4"));
		}

		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);
		pButtonEx->setFont(QFont("Microsoft YaHei", 10, 75));

		pButtonEx->setHoverBgColor(QColor(247, 52, 115));
		pButtonEx->setCheckBgColor(QColor(247, 52, 115));

		pButtonEx->setNormalBgColor(m_iNormalBgColor);
		pButtonEx->setNormalFrameColor(m_iNormalFrameColor);
		pButtonEx->setNormalTextColor(m_iNormalTextColor);
		pButtonEx->setHoverTextColor(m_iHoverTextColor);
		pButtonEx->setCheckTextColor(m_iCheckTextColor);
	}
}

void VideoAreaUtilWindow::InitPrevSubtitlesButtons()
{
	m_ptrBtnPrevSubtitles1.reset(new ButtonEx(this));
	m_ptrBtnPrevSubtitles2.reset(new ButtonEx(this));
	m_ptrBtnPrevSubtitles3.reset(new ButtonEx(this));
	m_ptrBtnPrevSubtitles4.reset(new ButtonEx(this));

	m_listPrevSubtitlesBtns << m_ptrBtnPrevSubtitles1.get() << m_ptrBtnPrevSubtitles2.get() << m_ptrBtnPrevSubtitles3.get()
		<< m_ptrBtnPrevSubtitles4.get();

	for (int iIndex = 0; iIndex < m_listPrevSubtitlesBtns.count(); iIndex++)
	{
		ButtonEx* pButtonEx = m_listPrevSubtitlesBtns.at(iIndex);
		pButtonEx->setPaddingLeft(0);
		pButtonEx->setShowLine(false);
		pButtonEx->setShowIcon(false);
		pButtonEx->setIconSpace(0);

		if (pButtonEx == m_ptrBtnPrevSubtitles1.get())
		{
			m_ptrBtnPrevSubtitles1->setText(QString::fromLocal8Bit("×ÖÄ»1"));
		}
		else if (pButtonEx == m_ptrBtnPrevSubtitles2.get())
		{
			m_ptrBtnPrevSubtitles2->setText(QString::fromLocal8Bit("×ÖÄ»2"));
		}
		else if (pButtonEx == m_ptrBtnPrevSubtitles3.get())
		{
			m_ptrBtnPrevSubtitles3->setText(QString::fromLocal8Bit("×ÖÄ»3"));
		}
		else if (pButtonEx == m_ptrBtnPrevSubtitles4.get())
		{
			m_ptrBtnPrevSubtitles4->setText(QString::fromLocal8Bit("×ÖÄ»4"));
		}

		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);
		pButtonEx->setFont(QFont("Microsoft YaHei", 10, 75));

		pButtonEx->setHoverBgColor(QColor(45, 127, 16));
		pButtonEx->setCheckBgColor(QColor(45, 127, 16));

		pButtonEx->setNormalBgColor(m_iNormalBgColor);
		pButtonEx->setNormalFrameColor(m_iNormalFrameColor);
		pButtonEx->setNormalTextColor(m_iNormalTextColor);
		pButtonEx->setHoverTextColor(m_iHoverTextColor);
		pButtonEx->setCheckTextColor(m_iCheckTextColor);
	}
}
void VideoAreaUtilWindow::InitMainChButtons()
{
	m_ptrBtnMainCh1.reset(new ButtonEx(this));
	m_ptrBtnMainCh2.reset(new ButtonEx(this));
	m_ptrBtnMainCh3.reset(new ButtonEx(this));
	m_ptrBtnMainCh4.reset(new ButtonEx(this));
	m_ptrBtnMainCh5.reset(new ButtonEx(this));
	m_ptrBtnMainCh6.reset(new ButtonEx(this));
	m_ptrBtnMainCh7.reset(new ButtonEx(this));
	m_ptrBtnMainCh8.reset(new ButtonEx(this));
	m_ptrBtnMainCh9.reset(new ButtonEx(this));
	m_ptrBtnMainCh10.reset(new ButtonEx(this));
	m_ptrBtnMainCh11.reset(new ButtonEx(this));
	m_ptrBtnMainCh12.reset(new ButtonEx(this));

	m_listMainChanBtns << m_ptrBtnMainCh1.get() << m_ptrBtnMainCh2.get() << m_ptrBtnMainCh3.get()
		<< m_ptrBtnMainCh4.get() << m_ptrBtnMainCh5.get() << m_ptrBtnMainCh6.get()
		<< m_ptrBtnMainCh7.get() << m_ptrBtnMainCh8.get() << m_ptrBtnMainCh9.get()
		<< m_ptrBtnMainCh10.get() << m_ptrBtnMainCh11.get() << m_ptrBtnMainCh12.get();

	for (int iIndex = 0; iIndex < m_listMainChanBtns.count(); iIndex++)
	{
		ButtonEx* pButtonEx = m_listMainChanBtns.at(iIndex);
		pButtonEx->setPaddingLeft(0);
		pButtonEx->setShowLine(false);
		pButtonEx->setShowIcon(false);
		pButtonEx->setIconSpace(0);

		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);
		pButtonEx->setFont(QFont("Microsoft YaHei", 10, 75));


		if (pButtonEx == m_ptrBtnMainCh1.get())
		{
			m_ptrBtnMainCh1->setText(QString::fromLocal8Bit("1"));
		}
		else if (pButtonEx == m_ptrBtnMainCh2.get())
		{
			m_ptrBtnMainCh2->setText(QString::fromLocal8Bit("2"));
		}
		else if (pButtonEx == m_ptrBtnMainCh3.get())
		{
			m_ptrBtnMainCh3->setText(QString::fromLocal8Bit("3"));
		}

		else if (pButtonEx == m_ptrBtnMainCh4.get())
		{
			m_ptrBtnMainCh4->setText(QString::fromLocal8Bit("4"));
		}
		else if (pButtonEx == m_ptrBtnMainCh5.get())
		{
			m_ptrBtnMainCh5->setText(QString::fromLocal8Bit("5"));
		}
		else if (pButtonEx == m_ptrBtnMainCh6.get())
		{
			m_ptrBtnMainCh6->setText(QString::fromLocal8Bit("6"));
		}

		else if (pButtonEx == m_ptrBtnMainCh7.get())
		{
			m_ptrBtnMainCh7->setText(QString::fromLocal8Bit("7"));
		}
		else if (pButtonEx == m_ptrBtnMainCh8.get())
		{
			m_ptrBtnMainCh8->setText(QString::fromLocal8Bit("8"));
		}
		else if (pButtonEx == m_ptrBtnMainCh9.get())
		{
			m_ptrBtnMainCh9->setText(QString::fromLocal8Bit("9"));
		}
		else if (pButtonEx == m_ptrBtnMainCh10.get())
		{
			m_ptrBtnMainCh10->setText(QString::fromLocal8Bit("10"));
		}
		else if (pButtonEx == m_ptrBtnMainCh11.get())
		{
			m_ptrBtnMainCh11->setText(QString::fromLocal8Bit("11"));
		}
		else if (pButtonEx == m_ptrBtnMainCh12.get())
		{
			m_ptrBtnMainCh12->setText(QString::fromLocal8Bit("12"));
		}

		pButtonEx->setHoverBgColor(QColor(247, 52, 115));
		pButtonEx->setCheckBgColor(QColor(247, 52, 115));

		pButtonEx->setNormalBgColor(m_iNormalBgColor);
		pButtonEx->setNormalFrameColor(m_iNormalFrameColor);
		pButtonEx->setNormalTextColor(m_iNormalTextColor);
		pButtonEx->setHoverTextColor(m_iHoverTextColor);
		pButtonEx->setCheckTextColor(m_iCheckTextColor);
	}
}

void VideoAreaUtilWindow::InitPrevChButtons()
{
	m_ptrBtnPrevCh1.reset(new ButtonEx(this));
	m_ptrBtnPrevCh2.reset(new ButtonEx(this));
	m_ptrBtnPrevCh3.reset(new ButtonEx(this));
	m_ptrBtnPrevCh4.reset(new ButtonEx(this));
	m_ptrBtnPrevCh5.reset(new ButtonEx(this));
	m_ptrBtnPrevCh6.reset(new ButtonEx(this));
	m_ptrBtnPrevCh7.reset(new ButtonEx(this));
	m_ptrBtnPrevCh8.reset(new ButtonEx(this));
	m_ptrBtnPrevCh9.reset(new ButtonEx(this));
	m_ptrBtnPrevCh10.reset(new ButtonEx(this));
	m_ptrBtnPrevCh11.reset(new ButtonEx(this));
	m_ptrBtnPrevCh12.reset(new ButtonEx(this));

	m_listPrevChanBtns << m_ptrBtnPrevCh1.get() << m_ptrBtnPrevCh2.get() << m_ptrBtnPrevCh3.get()
		<< m_ptrBtnPrevCh4.get() << m_ptrBtnPrevCh5.get() << m_ptrBtnPrevCh6.get()
		<< m_ptrBtnPrevCh7.get() << m_ptrBtnPrevCh8.get() << m_ptrBtnPrevCh9.get()
		<< m_ptrBtnPrevCh10.get() << m_ptrBtnPrevCh11.get() << m_ptrBtnPrevCh12.get();

	for (int iIndex = 0; iIndex < m_listPrevChanBtns.count(); iIndex++)
	{
		ButtonEx* pButtonEx = m_listPrevChanBtns.at(iIndex);
		pButtonEx->setPaddingLeft(0);
		pButtonEx->setShowLine(false);
		pButtonEx->setShowIcon(false);
		pButtonEx->setIconSpace(0);

		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);
		pButtonEx->setFont(QFont("Microsoft YaHei", 10, 75));

		if (pButtonEx == m_ptrBtnPrevCh1.get())
		{
			m_ptrBtnPrevCh1->setText(QString::fromLocal8Bit("1"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh2.get())
		{
			m_ptrBtnPrevCh2->setText(QString::fromLocal8Bit("2"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh3.get())
		{
			m_ptrBtnPrevCh3->setText(QString::fromLocal8Bit("3"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh4.get())
		{
			m_ptrBtnPrevCh4->setText(QString::fromLocal8Bit("4"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh5.get())
		{
			m_ptrBtnPrevCh5->setText(QString::fromLocal8Bit("5"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh6.get())
		{
			m_ptrBtnPrevCh6->setText(QString::fromLocal8Bit("6"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh7.get())
		{
			m_ptrBtnPrevCh7->setText(QString::fromLocal8Bit("7"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh8.get())
		{
			m_ptrBtnPrevCh8->setText(QString::fromLocal8Bit("8"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh9.get())
		{
			m_ptrBtnPrevCh9->setText(QString::fromLocal8Bit("9"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh10.get())
		{
			m_ptrBtnPrevCh10->setText(QString::fromLocal8Bit("10"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh11.get())
		{
			m_ptrBtnPrevCh11->setText(QString::fromLocal8Bit("11"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh12.get())
		{
			m_ptrBtnPrevCh12->setText(QString::fromLocal8Bit("12"));
		}

		pButtonEx->setHoverBgColor(QColor(45, 127, 16));
		pButtonEx->setCheckBgColor(QColor(45, 127, 16));

		pButtonEx->setNormalBgColor(m_iNormalBgColor);
		pButtonEx->setNormalFrameColor(m_iNormalFrameColor);
		pButtonEx->setNormalTextColor(m_iNormalTextColor);
		pButtonEx->setHoverTextColor(m_iHoverTextColor);
		pButtonEx->setCheckTextColor(m_iCheckTextColor);
	}
}
#else
void VideoAreaUtilWindow::InitMainChButtons()
{
	m_ptrBtnMainCh1.reset(new ButtonEx(this));
	m_ptrBtnMainCh2.reset(new ButtonEx(this));
	m_ptrBtnMainCh3.reset(new ButtonEx(this));
	m_ptrBtnMainCh4.reset(new ButtonEx(this));
	m_ptrBtnMainCh5.reset(new ButtonEx(this));
	m_ptrBtnMainCh6.reset(new ButtonEx(this));
	m_ptrBtnMainCh7.reset(new ButtonEx(this));
	m_ptrBtnMainCh8.reset(new ButtonEx(this));
	m_ptrBtnMainCh9.reset(new ButtonEx(this));
 

	m_listMainChanBtns << m_ptrBtnMainCh1.get() << m_ptrBtnMainCh2.get() << m_ptrBtnMainCh3.get()
		<< m_ptrBtnMainCh4.get() << m_ptrBtnMainCh5.get() << m_ptrBtnMainCh6.get()
		<< m_ptrBtnMainCh7.get() << m_ptrBtnMainCh8.get() << m_ptrBtnMainCh9.get() ;

	for (int iIndex = 0; iIndex < m_listMainChanBtns.count(); iIndex++)
	{
		ButtonEx* pButtonEx = m_listMainChanBtns.at(iIndex);
		pButtonEx->setPaddingLeft(0);
		pButtonEx->setShowLine(false);
		pButtonEx->setShowIcon(false);
		pButtonEx->setIconSpace(0);

		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);
		pButtonEx->setFont(QFont("Microsoft YaHei", 10, 75));


		if (pButtonEx == m_ptrBtnMainCh1.get())
		{
			m_ptrBtnMainCh1->setText(QString::fromLocal8Bit("1"));
		}
		else if (pButtonEx == m_ptrBtnMainCh2.get())
		{
			m_ptrBtnMainCh2->setText(QString::fromLocal8Bit("2"));
		}
		else if (pButtonEx == m_ptrBtnMainCh3.get())
		{
			m_ptrBtnMainCh3->setText(QString::fromLocal8Bit("3"));
		}

		else if (pButtonEx == m_ptrBtnMainCh4.get())
		{
			m_ptrBtnMainCh4->setText(QString::fromLocal8Bit("4"));
		}
		else if (pButtonEx == m_ptrBtnMainCh5.get())
		{
			m_ptrBtnMainCh5->setText(QString::fromLocal8Bit("5"));
		}
		else if (pButtonEx == m_ptrBtnMainCh6.get())
		{
			m_ptrBtnMainCh6->setText(QString::fromLocal8Bit("6"));
		}

		else if (pButtonEx == m_ptrBtnMainCh7.get())
		{
			m_ptrBtnMainCh7->setText(QString::fromLocal8Bit("7"));
		}
		else if (pButtonEx == m_ptrBtnMainCh8.get())
		{
			m_ptrBtnMainCh8->setText(QString::fromLocal8Bit("8"));
		}
		else if (pButtonEx == m_ptrBtnMainCh9.get())
		{
			m_ptrBtnMainCh9->setText(QString::fromLocal8Bit("9"));
		}
	 

		pButtonEx->setHoverBgColor(QColor(247, 52, 115));
		pButtonEx->setCheckBgColor(QColor(247, 52, 115));

		pButtonEx->setNormalBgColor(m_iNormalBgColor);
		pButtonEx->setNormalFrameColor(m_iNormalFrameColor);
		pButtonEx->setNormalTextColor(m_iNormalTextColor);
		pButtonEx->setHoverTextColor(m_iHoverTextColor);
		pButtonEx->setCheckTextColor(m_iCheckTextColor);
	}
}

void VideoAreaUtilWindow::InitPrevChButtons()
{
	m_ptrBtnPrevCh1.reset(new ButtonEx(this));
	m_ptrBtnPrevCh2.reset(new ButtonEx(this));
	m_ptrBtnPrevCh3.reset(new ButtonEx(this));
	m_ptrBtnPrevCh4.reset(new ButtonEx(this));
	m_ptrBtnPrevCh5.reset(new ButtonEx(this));
	m_ptrBtnPrevCh6.reset(new ButtonEx(this));
	m_ptrBtnPrevCh7.reset(new ButtonEx(this));
	m_ptrBtnPrevCh8.reset(new ButtonEx(this));
	m_ptrBtnPrevCh9.reset(new ButtonEx(this));
 

	m_listPrevChanBtns << m_ptrBtnPrevCh1.get() << m_ptrBtnPrevCh2.get() << m_ptrBtnPrevCh3.get()
		<< m_ptrBtnPrevCh4.get() << m_ptrBtnPrevCh5.get() << m_ptrBtnPrevCh6.get()
		<< m_ptrBtnPrevCh7.get() << m_ptrBtnPrevCh8.get() << m_ptrBtnPrevCh9.get() ;

	for (int iIndex = 0; iIndex < m_listPrevChanBtns.count(); iIndex++)
	{
		ButtonEx* pButtonEx = m_listPrevChanBtns.at(iIndex);
		pButtonEx->setPaddingLeft(0);
		pButtonEx->setShowLine(false);
		pButtonEx->setShowIcon(false);
		pButtonEx->setIconSpace(0);

		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);
		pButtonEx->setFont(QFont("Microsoft YaHei", 10, 75));

		if (pButtonEx == m_ptrBtnPrevCh1.get())
		{
			m_ptrBtnPrevCh1->setText(QString::fromLocal8Bit("1"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh2.get())
		{
			m_ptrBtnPrevCh2->setText(QString::fromLocal8Bit("2"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh3.get())
		{
			m_ptrBtnPrevCh3->setText(QString::fromLocal8Bit("3"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh4.get())
		{
			m_ptrBtnPrevCh4->setText(QString::fromLocal8Bit("4"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh5.get())
		{
			m_ptrBtnPrevCh5->setText(QString::fromLocal8Bit("5"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh6.get())
		{
			m_ptrBtnPrevCh6->setText(QString::fromLocal8Bit("6"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh7.get())
		{
			m_ptrBtnPrevCh7->setText(QString::fromLocal8Bit("7"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh8.get())
		{
			m_ptrBtnPrevCh8->setText(QString::fromLocal8Bit("8"));
		}
		else if (pButtonEx == m_ptrBtnPrevCh9.get())
		{
			m_ptrBtnPrevCh9->setText(QString::fromLocal8Bit("9"));
		}
	 

		pButtonEx->setHoverBgColor(QColor(45, 127, 16));
		pButtonEx->setCheckBgColor(QColor(45, 127, 16));

		pButtonEx->setNormalBgColor(m_iNormalBgColor);
		pButtonEx->setNormalFrameColor(m_iNormalFrameColor);
		pButtonEx->setNormalTextColor(m_iNormalTextColor);
		pButtonEx->setHoverTextColor(m_iHoverTextColor);
		pButtonEx->setCheckTextColor(m_iCheckTextColor);
	}
}

void VideoAreaUtilWindow::InitMainSubtitlesButtons()
{
	m_ptrBtnMainSubtitles1.reset(new ButtonEx(this));
	m_ptrBtnMainSubtitles2.reset(new ButtonEx(this));
	m_ptrBtnMainSubtitles3.reset(new ButtonEx(this));
 
	m_listMainSubtitlesBtns << m_ptrBtnMainSubtitles1.get() << m_ptrBtnMainSubtitles2.get() << m_ptrBtnMainSubtitles3.get();

	for (int iIndex = 0; iIndex < m_listMainSubtitlesBtns.count(); iIndex++)
	{
		ButtonEx* pButtonEx = m_listMainSubtitlesBtns.at(iIndex);
		pButtonEx->setPaddingLeft(0);
		pButtonEx->setShowLine(false);
		pButtonEx->setShowIcon(false);
		pButtonEx->setIconSpace(0);

		if (pButtonEx == m_ptrBtnMainSubtitles1.get())
		{
			m_ptrBtnMainSubtitles1->setText(QString::fromLocal8Bit("×ÖÄ»1"));
		}
		else if (pButtonEx == m_ptrBtnMainSubtitles2.get())
		{
			m_ptrBtnMainSubtitles2->setText(QString::fromLocal8Bit("×ÖÄ»2"));
		}
		else if (pButtonEx == m_ptrBtnMainSubtitles3.get())
		{
			m_ptrBtnMainSubtitles3->setText(QString::fromLocal8Bit("×ÖÄ»3"));
		}
	 
		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);
		pButtonEx->setFont(QFont("Microsoft YaHei", 10, 75));

		pButtonEx->setHoverBgColor(QColor(247, 52, 115));
		pButtonEx->setCheckBgColor(QColor(247, 52, 115));

		pButtonEx->setNormalBgColor(m_iNormalBgColor);
		pButtonEx->setNormalFrameColor(m_iNormalFrameColor);
		pButtonEx->setNormalTextColor(m_iNormalTextColor);
		pButtonEx->setHoverTextColor(m_iHoverTextColor);
		pButtonEx->setCheckTextColor(m_iCheckTextColor);
	}
}

void VideoAreaUtilWindow::InitPrevSubtitlesButtons()
{
	m_ptrBtnPrevSubtitles1.reset(new ButtonEx(this));
	m_ptrBtnPrevSubtitles2.reset(new ButtonEx(this));
	m_ptrBtnPrevSubtitles3.reset(new ButtonEx(this));
 
	m_listPrevSubtitlesBtns << m_ptrBtnPrevSubtitles1.get() << m_ptrBtnPrevSubtitles2.get() << m_ptrBtnPrevSubtitles3.get();

	for (int iIndex = 0; iIndex < m_listPrevSubtitlesBtns.count(); iIndex++)
	{
		ButtonEx* pButtonEx = m_listPrevSubtitlesBtns.at(iIndex);
		pButtonEx->setPaddingLeft(0);
		pButtonEx->setShowLine(false);
		pButtonEx->setShowIcon(false);
		pButtonEx->setIconSpace(0);

		if (pButtonEx == m_ptrBtnPrevSubtitles1.get())
		{
			m_ptrBtnPrevSubtitles1->setText(QString::fromLocal8Bit("×ÖÄ»1"));
		}
		else if (pButtonEx == m_ptrBtnPrevSubtitles2.get())
		{
			m_ptrBtnPrevSubtitles2->setText(QString::fromLocal8Bit("×ÖÄ»2"));
		}
		else if (pButtonEx == m_ptrBtnPrevSubtitles3.get())
		{
			m_ptrBtnPrevSubtitles3->setText(QString::fromLocal8Bit("×ÖÄ»3"));
		}
  
		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);
		pButtonEx->setFont(QFont("Microsoft YaHei", 10, 75));

		pButtonEx->setHoverBgColor(QColor(45, 127, 16));
		pButtonEx->setCheckBgColor(QColor(45, 127, 16));

		pButtonEx->setNormalBgColor(m_iNormalBgColor);
		pButtonEx->setNormalFrameColor(m_iNormalFrameColor);
		pButtonEx->setNormalTextColor(m_iNormalTextColor);
		pButtonEx->setHoverTextColor(m_iHoverTextColor);
		pButtonEx->setCheckTextColor(m_iCheckTextColor);
	}
}

#endif



void VideoAreaUtilWindow::InitMainEffectButtons()
{
	m_ptrBtnMainBlackSite.reset(new ButtonEx(this));
	m_ptrBtnMainColourBar.reset(new ButtonEx(this));
	m_ptrBtnMainPicInPic1.reset(new ButtonEx(this));
	m_ptrBtnMainPicInPic2.reset(new ButtonEx(this));

	m_listMainEffectBtns << m_ptrBtnMainBlackSite.get() << m_ptrBtnMainColourBar.get() << m_ptrBtnMainPicInPic1.get()
		<< m_ptrBtnMainPicInPic2.get();


	for (int iIndex = 0; iIndex < m_listMainEffectBtns.count(); iIndex++)
	{
		ButtonEx* pButtonEx = m_listMainEffectBtns.at(iIndex);
		pButtonEx->setPaddingLeft(0);
		pButtonEx->setShowLine(false);
		pButtonEx->setShowIcon(false);
		pButtonEx->setIconSpace(0);

		if (pButtonEx == m_ptrBtnMainBlackSite.get())
		{
			m_ptrBtnMainBlackSite->setText(QString::fromLocal8Bit("ºÚ³¡"));
		}
		else if (pButtonEx == m_ptrBtnMainColourBar.get())
		{
			m_ptrBtnMainColourBar->setText(QString::fromLocal8Bit("²ÊÌõ"));
		}
		else if (pButtonEx == m_ptrBtnMainPicInPic1.get())
		{
			m_ptrBtnMainPicInPic1->setText(QString::fromLocal8Bit("»­ÖÐ»­1"));
		}
		else if (pButtonEx == m_ptrBtnMainPicInPic2.get())
		{
			m_ptrBtnMainPicInPic2->setText(QString::fromLocal8Bit("»­ÖÐ»­2"));
		}

		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);
		pButtonEx->setFont(QFont("Microsoft YaHei", 10, 75));

		pButtonEx->setHoverBgColor(QColor(247, 52, 115));
		pButtonEx->setCheckBgColor(QColor(247, 52, 115));

		pButtonEx->setNormalBgColor(m_iNormalBgColor);
		pButtonEx->setNormalFrameColor(m_iNormalFrameColor);
		pButtonEx->setNormalTextColor(m_iNormalTextColor);
		pButtonEx->setHoverTextColor(m_iHoverTextColor);
		pButtonEx->setCheckTextColor(m_iCheckTextColor);
	}
}
 
void VideoAreaUtilWindow::InitPrevEffectButtons()
{
	m_ptrBtnPrevBlackSite.reset(new ButtonEx(this));
	m_ptrBtnPrevColourBar.reset(new ButtonEx(this));
	m_ptrBtnPrevPicInPic1.reset(new ButtonEx(this));
	m_ptrBtnPrevPicInPic2.reset(new ButtonEx(this));

	m_listPrevEffectBtns << m_ptrBtnPrevBlackSite.get() << m_ptrBtnPrevColourBar.get() << m_ptrBtnPrevPicInPic1.get()
		<< m_ptrBtnPrevPicInPic2.get();
	 
	for (int iIndex = 0; iIndex < m_listPrevEffectBtns.count(); iIndex++)
	{
		ButtonEx* pButtonEx = m_listPrevEffectBtns.at(iIndex);
		pButtonEx->setPaddingLeft(0);
		pButtonEx->setShowLine(false);
		pButtonEx->setShowIcon(false);
		pButtonEx->setIconSpace(0);
		 
		if (pButtonEx == m_ptrBtnPrevBlackSite.get())
		{
			m_ptrBtnPrevBlackSite->setText(QString::fromLocal8Bit("ºÚ³¡"));
		}
		else if (pButtonEx == m_ptrBtnPrevColourBar.get())
		{
			m_ptrBtnPrevColourBar->setText(QString::fromLocal8Bit("²ÊÌõ"));
		}
		else if (pButtonEx == m_ptrBtnPrevPicInPic1.get())
		{
			m_ptrBtnPrevPicInPic1->setText(QString::fromLocal8Bit("»­ÖÐ»­1"));
		}
		else if (pButtonEx == m_ptrBtnPrevPicInPic2.get())
		{
			m_ptrBtnPrevPicInPic2->setText(QString::fromLocal8Bit("»­ÖÐ»­2"));
		}

		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);
		pButtonEx->setFont(QFont("Microsoft YaHei", 10, 75));

		pButtonEx->setHoverBgColor(QColor(45, 127, 16));
		pButtonEx->setCheckBgColor(QColor(45, 127, 16));

		pButtonEx->setNormalBgColor(m_iNormalBgColor);
		pButtonEx->setNormalFrameColor(m_iNormalFrameColor);
		pButtonEx->setNormalTextColor(m_iNormalTextColor);
		pButtonEx->setHoverTextColor(m_iHoverTextColor);
		pButtonEx->setCheckTextColor(m_iCheckTextColor);
	}
}
 
void VideoAreaUtilWindow::InitLabels()
{
#if PIX_1080p
	QFont font1("Microsoft YaHei", 12, 75);
 #else
	QFont font1("Microsoft YaHei", 10, 75);
 #endif

	//-------------------------------------

	m_ptrMainLabel.reset(new NavLabelEx(this));
	m_ptrMainLabel->setFont(font1);

	m_ptrMainLabel->setTextAlign(NavLabelEx::TextAlign_Center);
	m_ptrMainLabel->setShowIcon(false);
	m_ptrMainLabel->setIconSize(QSize(20, 80));
	m_ptrMainLabel->setText(QString::fromLocal8Bit("Ö÷¼à:"));

	m_ptrMainLabel->setNormalBgColor(QColor(30, 30, 30));
	m_ptrMainLabel->setNormalTextColor(QColor(235, 235, 235));

	//-------------------------------------
	m_ptrPrevLabel.reset(new NavLabelEx(this));
 	m_ptrPrevLabel->setFont(font1);
 	m_ptrPrevLabel->setTextAlign(NavLabelEx::TextAlign_Center);
	m_ptrPrevLabel->setShowIcon(false);
	m_ptrPrevLabel->setIconSize(QSize(20, 80));
	m_ptrPrevLabel->setText(QString::fromLocal8Bit("Ô¤¼à:"));

	m_ptrPrevLabel->setNormalBgColor(QColor(30, 30, 30));
	m_ptrPrevLabel->setNormalTextColor(QColor(235, 235, 235));
}

void VideoAreaUtilWindow::InitConnect()
{
	connect(m_ptrBtnMainCh1.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainCh1()));
	connect(m_ptrBtnMainCh2.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainCh2()));
	connect(m_ptrBtnMainCh3.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainCh3()));
	connect(m_ptrBtnMainCh4.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainCh4()));
	connect(m_ptrBtnMainCh5.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainCh5()));
	connect(m_ptrBtnMainCh6.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainCh6()));
	connect(m_ptrBtnMainCh7.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainCh7()));
	connect(m_ptrBtnMainCh8.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainCh8()));
	connect(m_ptrBtnMainCh9.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainCh9()));

#if PIX_1080p
	connect(m_ptrBtnMainCh10.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainCh10()));
	connect(m_ptrBtnMainCh11.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainCh11()));
	connect(m_ptrBtnMainCh12.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainCh12()));
 #endif
	 
	connect(m_ptrBtnPrevCh1.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevCh1()));
	connect(m_ptrBtnPrevCh2.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevCh2()));
	connect(m_ptrBtnPrevCh3.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevCh3()));
	connect(m_ptrBtnPrevCh4.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevCh4()));
	connect(m_ptrBtnPrevCh5.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevCh5()));
	connect(m_ptrBtnPrevCh6.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevCh6()));
	connect(m_ptrBtnPrevCh7.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevCh7()));
	connect(m_ptrBtnPrevCh8.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevCh8()));
	connect(m_ptrBtnPrevCh9.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevCh9()));

#if PIX_1080p
	connect(m_ptrBtnPrevCh10.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevCh10()));
	connect(m_ptrBtnPrevCh11.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevCh11()));
	connect(m_ptrBtnPrevCh12.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevCh12()));
#endif
	 

	connect(m_ptrBtnMainSubtitles1.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainSubtitles1()));
	connect(m_ptrBtnMainSubtitles2.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainSubtitles2()));
	connect(m_ptrBtnMainSubtitles3.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainSubtitles3()));

#if PIX_1080p
	connect(m_ptrBtnMainSubtitles4.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainSubtitles4()));
#endif
	 
	connect(m_ptrBtnPrevSubtitles1.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevSubtitles1()));
	connect(m_ptrBtnPrevSubtitles2.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevSubtitles2()));
	connect(m_ptrBtnPrevSubtitles3.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevSubtitles3()));

#if PIX_1080p
	connect(m_ptrBtnPrevSubtitles4.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevSubtitles4()));
#endif

	connect(m_ptrBtnMainBlackSite.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainBlackSite()));
	connect(m_ptrBtnMainColourBar.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainColourBar()));
	connect(m_ptrBtnMainPicInPic1.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainPicInPic1()));
	connect(m_ptrBtnMainPicInPic2.get(), SIGNAL(clicked()), this, SLOT(OnBtnMainPicInPic2()));

	connect(m_ptrBtnPrevBlackSite.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevBlackSite()));
	connect(m_ptrBtnPrevColourBar.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevColourBar()));
	connect(m_ptrBtnPrevPicInPic1.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevPicInPic1()));
	connect(m_ptrBtnPrevPicInPic2.get(), SIGNAL(clicked()), this, SLOT(OnBtnPrevPicInPic2()));
  }
 
void VideoAreaUtilWindow::resizeEvent(QResizeEvent* pEvent)
{
	int iWidth = width();
	int iHeight = height();
	 
 	if (m_ptrMainLabel)
	{
		m_ptrMainLabel->setGeometry(0, 0, 40, BUTTON_HEIGHT);
		m_ptrMainLabel->move(0, 0);
	}

	if (m_ptrPrevLabel)
	{
		m_ptrPrevLabel->setGeometry(0, 0, 40, BUTTON_HEIGHT);
		m_ptrPrevLabel->move(0, 55);
	}

	LayoutChannelButtons();
	LayoutEffectButtons();
	LayoutSubtitlesButtons();

	LayoutChannelButtons2();
	LayoutEffectButtons2();
	LayoutSubtitlesButtons2();

// 	if (m_ptrBottomSplitter)
// 	{
// 		m_ptrBottomSplitter->setGeometry(0, 0, iWidth, iHeight - 110);
// 		m_ptrBottomSplitter->move(0, 110);
// 		m_ptrBottomSplitter->updateGeometry();
// 	}

	if (m_ptrMediaSettingWindow)
	{
		m_ptrMediaSettingWindow->setGeometry(0, 0, iWidth / 4-5,iHeight - 140);
		m_ptrMediaSettingWindow->move(0, 110);
 	}

	if (m_ptrPlayerListWindow)
	{
		m_ptrPlayerListWindow->setGeometry(0, 0, iWidth / 4-2, iHeight - 140);
		m_ptrPlayerListWindow->move(iWidth / 4, 110);
 	}

	if (m_ptrAudioSettingWindow)
	{
		m_ptrAudioSettingWindow->setGeometry(0, 0, iWidth / 2-2, iHeight - 140);
		m_ptrAudioSettingWindow->move(iWidth -  iWidth / 2+2, 110);
	}
	 
	QWidget::resizeEvent(pEvent);
}
#if PIX_1080p
void VideoAreaUtilWindow::LayoutChannelButtons()
{
	if (m_ptrBtnMainCh1)
	{
		m_ptrBtnMainCh1->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh1->move(LEFT_GAP, 0);

	}
	if (m_ptrBtnMainCh2)
	{
		m_ptrBtnMainCh2->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh2->move(LEFT_GAP + 1 * BUTTON_WIDTH + 1, 0);
	}

	if (m_ptrBtnMainCh3)
	{
		m_ptrBtnMainCh3->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh3->move(LEFT_GAP + 2 * BUTTON_WIDTH + 2, 0);
	}

	if (m_ptrBtnMainCh4)
	{
		m_ptrBtnMainCh4->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh4->move(LEFT_GAP + 3 * BUTTON_WIDTH + 3, 0);
	}

	if (m_ptrBtnMainCh5)
	{
		m_ptrBtnMainCh5->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh5->move(LEFT_GAP + 4 * BUTTON_WIDTH + 8, 0);
	}



	if (m_ptrBtnMainCh6)
	{
		m_ptrBtnMainCh6->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh6->move(LEFT_GAP + 5 * BUTTON_WIDTH + 9, 0);
	}


	if (m_ptrBtnMainCh7)
	{
		m_ptrBtnMainCh7->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh7->move(LEFT_GAP + 6 * BUTTON_WIDTH + 10, 0);
	}

	if (m_ptrBtnMainCh8)
	{
		m_ptrBtnMainCh8->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh8->move(LEFT_GAP + 7 * BUTTON_WIDTH + 11, 0);
	}

	if (m_ptrBtnMainCh9)
	{
		m_ptrBtnMainCh9->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh9->move(LEFT_GAP + 8 * BUTTON_WIDTH + 16, 0);
	}

	if (m_ptrBtnMainCh10)
	{
		m_ptrBtnMainCh10->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh10->move(LEFT_GAP + 9 * BUTTON_WIDTH + 17, 0);
	}
	if (m_ptrBtnMainCh11)
	{
		m_ptrBtnMainCh11->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh11->move(LEFT_GAP + 10 * BUTTON_WIDTH + 18, 0);
	}

	if (m_ptrBtnMainCh12)
	{
		m_ptrBtnMainCh12->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh12->move(LEFT_GAP + 11 * BUTTON_WIDTH + 19, 0);
	}
}

void VideoAreaUtilWindow::LayoutChannelButtons2()
{
	if (m_ptrBtnPrevCh1)
	{
		m_ptrBtnPrevCh1->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh1->move(LEFT_GAP, HEIGHT_GAP);

	}
	if (m_ptrBtnPrevCh2)
	{
		m_ptrBtnPrevCh2->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh2->move(LEFT_GAP + 1 * BUTTON_WIDTH + 1, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevCh3)
	{
		m_ptrBtnPrevCh3->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh3->move(LEFT_GAP + 2 * BUTTON_WIDTH + 2, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevCh4)
	{
		m_ptrBtnPrevCh4->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh4->move(LEFT_GAP + 3 * BUTTON_WIDTH + 3, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevCh5)
	{
		m_ptrBtnPrevCh5->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh5->move(LEFT_GAP + 4 * BUTTON_WIDTH + 8, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevCh6)
	{
		m_ptrBtnPrevCh6->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh6->move(LEFT_GAP + 5 * BUTTON_WIDTH + 9, HEIGHT_GAP);
	}


	if (m_ptrBtnPrevCh7)
	{
		m_ptrBtnPrevCh7->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh7->move(LEFT_GAP + 6 * BUTTON_WIDTH + 10, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevCh8)
	{
		m_ptrBtnPrevCh8->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh8->move(LEFT_GAP + 7 * BUTTON_WIDTH + 11, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevCh9)
	{
		m_ptrBtnPrevCh9->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh9->move(LEFT_GAP + 8 * BUTTON_WIDTH + 16, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevCh10)
	{
		m_ptrBtnPrevCh10->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh10->move(LEFT_GAP + 9 * BUTTON_WIDTH + 17, HEIGHT_GAP);
	}
	if (m_ptrBtnPrevCh11)
	{
		m_ptrBtnPrevCh11->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh11->move(LEFT_GAP + 10 * BUTTON_WIDTH + 18, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevCh12)
	{
		m_ptrBtnPrevCh12->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh12->move(LEFT_GAP + 11 * BUTTON_WIDTH + 19, HEIGHT_GAP);
	}
}

void VideoAreaUtilWindow::LayoutEffectButtons()
{
	if (m_ptrBtnMainBlackSite)
	{
		m_ptrBtnMainBlackSite->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainBlackSite->move(LEFT_GAP + 12 * BUTTON_WIDTH + 24, 0);
	}

	if (m_ptrBtnMainColourBar)
	{
		m_ptrBtnMainColourBar->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainColourBar->move(LEFT_GAP + 13 * BUTTON_WIDTH + 25, 0);
	}

	if (m_ptrBtnMainPicInPic1)
	{
		m_ptrBtnMainPicInPic1->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainPicInPic1->move(LEFT_GAP + 14 * BUTTON_WIDTH + 26, 0);
	}

	if (m_ptrBtnMainPicInPic2)
	{
		m_ptrBtnMainPicInPic2->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainPicInPic2->move(LEFT_GAP + 15 * BUTTON_WIDTH + 27, 0);
	}

}

void VideoAreaUtilWindow::LayoutEffectButtons2()
{
	if (m_ptrBtnPrevBlackSite)
	{
		m_ptrBtnPrevBlackSite->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevBlackSite->move(LEFT_GAP + 12 * BUTTON_WIDTH + 24, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevColourBar)
	{
		m_ptrBtnPrevColourBar->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevColourBar->move(LEFT_GAP + 13 * BUTTON_WIDTH + 25, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevPicInPic1)
	{
		m_ptrBtnPrevPicInPic1->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevPicInPic1->move(LEFT_GAP + 14 * BUTTON_WIDTH + 26, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevPicInPic2)
	{
		m_ptrBtnPrevPicInPic2->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevPicInPic2->move(LEFT_GAP + 15 * BUTTON_WIDTH + 27, HEIGHT_GAP);
	}

}

void VideoAreaUtilWindow::LayoutSubtitlesButtons()
{
	if (m_ptrBtnMainSubtitles1)
	{
		m_ptrBtnMainSubtitles1->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainSubtitles1->move(LEFT_GAP + 16 * BUTTON_WIDTH + 32, 0);
	}

	if (m_ptrBtnMainSubtitles2)
	{
		m_ptrBtnMainSubtitles2->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainSubtitles2->move(LEFT_GAP + 17 * BUTTON_WIDTH + 33, 0);
	}

	if (m_ptrBtnMainSubtitles3)
	{
		m_ptrBtnMainSubtitles3->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainSubtitles3->move(LEFT_GAP + 18 * BUTTON_WIDTH + 34, 0);
	}

	if (m_ptrBtnMainSubtitles4)
	{
		m_ptrBtnMainSubtitles4->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainSubtitles4->move(LEFT_GAP + 19 * BUTTON_WIDTH + 35, 0);
	}
}

void VideoAreaUtilWindow::LayoutSubtitlesButtons2()
{
	if (m_ptrBtnPrevSubtitles1)
	{
		m_ptrBtnPrevSubtitles1->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevSubtitles1->move(LEFT_GAP + 16 * BUTTON_WIDTH + 32, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevSubtitles2)
	{
		m_ptrBtnPrevSubtitles2->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevSubtitles2->move(LEFT_GAP + 17 * BUTTON_WIDTH + 33, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevSubtitles3)
	{
		m_ptrBtnPrevSubtitles3->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevSubtitles3->move(LEFT_GAP + 18 * BUTTON_WIDTH + 34, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevSubtitles4)
	{
		m_ptrBtnPrevSubtitles4->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevSubtitles4->move(LEFT_GAP + 19 * BUTTON_WIDTH + 35, HEIGHT_GAP);
	}
}

#else

void VideoAreaUtilWindow::LayoutChannelButtons()
{
	if (m_ptrBtnMainCh1)
	{
		m_ptrBtnMainCh1->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh1->move(LEFT_GAP, 0);

	}
	if (m_ptrBtnMainCh2)
	{
		m_ptrBtnMainCh2->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh2->move(LEFT_GAP + 1 * BUTTON_WIDTH + 1, 0);
	}

	if (m_ptrBtnMainCh3)
	{
		m_ptrBtnMainCh3->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh3->move(LEFT_GAP + 2 * BUTTON_WIDTH + 2, 0);
	}

	if (m_ptrBtnMainCh4)
	{
		m_ptrBtnMainCh4->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh4->move(LEFT_GAP + 3 * BUTTON_WIDTH + 8, 0);
	}

	if (m_ptrBtnMainCh5)
	{
		m_ptrBtnMainCh5->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh5->move(LEFT_GAP + 4 * BUTTON_WIDTH + 9, 0);
	}
	 

	if (m_ptrBtnMainCh6)
	{
		m_ptrBtnMainCh6->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh6->move(LEFT_GAP + 5 * BUTTON_WIDTH + 10, 0);
	}


	if (m_ptrBtnMainCh7)
	{
		m_ptrBtnMainCh7->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh7->move(LEFT_GAP + 6 * BUTTON_WIDTH + 15, 0);
	}

	if (m_ptrBtnMainCh8)
	{
		m_ptrBtnMainCh8->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh8->move(LEFT_GAP + 7 * BUTTON_WIDTH + 16, 0);
	}

	if (m_ptrBtnMainCh9)
	{
		m_ptrBtnMainCh9->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainCh9->move(LEFT_GAP + 8 * BUTTON_WIDTH + 17, 0);
	}
 }

void VideoAreaUtilWindow::LayoutChannelButtons2()
{
	if (m_ptrBtnPrevCh1)
	{
		m_ptrBtnPrevCh1->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh1->move(LEFT_GAP, HEIGHT_GAP);

	}
	if (m_ptrBtnPrevCh2)
	{
		m_ptrBtnPrevCh2->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh2->move(LEFT_GAP + 1 * BUTTON_WIDTH + 1, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevCh3)
	{
		m_ptrBtnPrevCh3->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh3->move(LEFT_GAP + 2 * BUTTON_WIDTH + 2, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevCh4)
	{
		m_ptrBtnPrevCh4->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh4->move(LEFT_GAP + 3 * BUTTON_WIDTH + 8, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevCh5)
	{
		m_ptrBtnPrevCh5->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh5->move(LEFT_GAP + 4 * BUTTON_WIDTH + 9, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevCh6)
	{
		m_ptrBtnPrevCh6->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh6->move(LEFT_GAP + 5 * BUTTON_WIDTH + 10, HEIGHT_GAP);
	}
	 
	if (m_ptrBtnPrevCh7)
	{
		m_ptrBtnPrevCh7->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh7->move(LEFT_GAP + 6 * BUTTON_WIDTH + 15, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevCh8)
	{
		m_ptrBtnPrevCh8->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh8->move(LEFT_GAP + 7 * BUTTON_WIDTH + 16, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevCh9)
	{
		m_ptrBtnPrevCh9->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevCh9->move(LEFT_GAP + 8 * BUTTON_WIDTH + 17, HEIGHT_GAP);
	}
 }
 
void VideoAreaUtilWindow::LayoutEffectButtons()
{
	if (m_ptrBtnMainBlackSite)
	{
		m_ptrBtnMainBlackSite->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainBlackSite->move(LEFT_GAP + 9 * BUTTON_WIDTH + 22, 0);
	}

	if (m_ptrBtnMainColourBar)
	{
		m_ptrBtnMainColourBar->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainColourBar->move(LEFT_GAP + 10 * BUTTON_WIDTH + 23, 0);
	}

	if (m_ptrBtnMainPicInPic1)
	{
		m_ptrBtnMainPicInPic1->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainPicInPic1->move(LEFT_GAP + 11 * BUTTON_WIDTH + 24, 0);
	}

	if (m_ptrBtnMainPicInPic2)
	{
		m_ptrBtnMainPicInPic2->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainPicInPic2->move(LEFT_GAP + 12 * BUTTON_WIDTH + 25, 0);
	}
 }

void VideoAreaUtilWindow::LayoutEffectButtons2()
{
	if (m_ptrBtnPrevBlackSite)
	{
		m_ptrBtnPrevBlackSite->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevBlackSite->move(LEFT_GAP + 9 * BUTTON_WIDTH + 22, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevColourBar)
	{
		m_ptrBtnPrevColourBar->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevColourBar->move(LEFT_GAP + 10 * BUTTON_WIDTH + 23, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevPicInPic1)
	{
		m_ptrBtnPrevPicInPic1->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevPicInPic1->move(LEFT_GAP + 11 * BUTTON_WIDTH + 24, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevPicInPic2)
	{
		m_ptrBtnPrevPicInPic2->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevPicInPic2->move(LEFT_GAP + 12 * BUTTON_WIDTH + 25, HEIGHT_GAP);
	}
 }

void VideoAreaUtilWindow::LayoutSubtitlesButtons()
{
	if (m_ptrBtnMainSubtitles1)
	{
		m_ptrBtnMainSubtitles1->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainSubtitles1->move(LEFT_GAP + 13 * BUTTON_WIDTH + 30, 0);
	}

	if (m_ptrBtnMainSubtitles2)
	{
		m_ptrBtnMainSubtitles2->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainSubtitles2->move(LEFT_GAP + 14 * BUTTON_WIDTH + 31, 0);
	}

	if (m_ptrBtnMainSubtitles3)
	{
		m_ptrBtnMainSubtitles3->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainSubtitles3->move(LEFT_GAP + 15 * BUTTON_WIDTH + 32, 0);
	}

	if (m_ptrBtnMainSubtitles4)
	{
		m_ptrBtnMainSubtitles4->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnMainSubtitles4->move(LEFT_GAP + 16 * BUTTON_WIDTH + 33, 0);
	}
}

void VideoAreaUtilWindow::LayoutSubtitlesButtons2()
{
	if (m_ptrBtnPrevSubtitles1)
	{
		m_ptrBtnPrevSubtitles1->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevSubtitles1->move(LEFT_GAP + 13 * BUTTON_WIDTH + 30, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevSubtitles2)
	{
		m_ptrBtnPrevSubtitles2->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevSubtitles2->move(LEFT_GAP + 14 * BUTTON_WIDTH + 31, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevSubtitles3)
	{
		m_ptrBtnPrevSubtitles3->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevSubtitles3->move(LEFT_GAP + 15 * BUTTON_WIDTH + 32, HEIGHT_GAP);
	}

	if (m_ptrBtnPrevSubtitles4)
	{
		m_ptrBtnPrevSubtitles4->setGeometry(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
		m_ptrBtnPrevSubtitles4->move(LEFT_GAP + 16 * BUTTON_WIDTH + 33, HEIGHT_GAP);
	}
}
 
#endif
  
void  VideoAreaUtilWindow::OnBtnMainCh1()
{
	bool bCheck = m_ptrBtnMainCh1->isChecked();
	m_ptrBtnMainCh1->setChecked(!bCheck);
}

void  VideoAreaUtilWindow::OnBtnMainCh2()
{
	bool bCheck = m_ptrBtnMainCh2->isChecked();
	m_ptrBtnMainCh2->setChecked(!bCheck);
}

void  VideoAreaUtilWindow::OnBtnMainCh3()
{
	bool bCheck = m_ptrBtnMainCh3->isChecked();
	m_ptrBtnMainCh3->setChecked(!bCheck);
}
void  VideoAreaUtilWindow::OnBtnMainCh4()
{
	bool bCheck = m_ptrBtnMainCh4->isChecked();
	m_ptrBtnMainCh4->setChecked(!bCheck);
}
void  VideoAreaUtilWindow::OnBtnMainCh5()
{
	bool bCheck = m_ptrBtnMainCh5->isChecked();
	m_ptrBtnMainCh5->setChecked(!bCheck);
}
void  VideoAreaUtilWindow::OnBtnMainCh6() {
	bool bCheck = m_ptrBtnMainCh6->isChecked();
	m_ptrBtnMainCh6->setChecked(!bCheck);
}
void  VideoAreaUtilWindow::OnBtnMainCh7()
{
	bool bCheck = m_ptrBtnMainCh7->isChecked();
	m_ptrBtnMainCh7->setChecked(!bCheck);
}
void  VideoAreaUtilWindow::OnBtnMainCh8()
{
	bool bCheck = m_ptrBtnMainCh8->isChecked();
	m_ptrBtnMainCh8->setChecked(!bCheck);
}

void  VideoAreaUtilWindow::OnBtnMainCh9()
{
	bool bCheck = m_ptrBtnMainCh9->isChecked();
	m_ptrBtnMainCh9->setChecked(!bCheck);
}

#if PIX_1080p
void  VideoAreaUtilWindow::OnBtnMainCh10()
{
	bool bCheck = m_ptrBtnMainCh10->isChecked();
	m_ptrBtnMainCh10->setChecked(!bCheck);
}

void  VideoAreaUtilWindow::OnBtnMainCh11()
{
	bool bCheck = m_ptrBtnMainCh11->isChecked();
	m_ptrBtnMainCh11->setChecked(!bCheck);
}

void  VideoAreaUtilWindow::OnBtnMainCh12()
{
	bool bCheck = m_ptrBtnMainCh12->isChecked();
	m_ptrBtnMainCh12->setChecked(!bCheck);
}
#endif


void VideoAreaUtilWindow::OnBtnPrevCh1()
{
	bool bCheck = m_ptrBtnPrevCh1->isChecked();
	m_ptrBtnPrevCh1->setChecked(!bCheck);
}

void VideoAreaUtilWindow::OnBtnPrevCh2()
{
	bool bCheck = m_ptrBtnPrevCh2->isChecked();
	m_ptrBtnPrevCh2->setChecked(!bCheck);
}

void VideoAreaUtilWindow::OnBtnPrevCh3()
{
	bool bCheck = m_ptrBtnPrevCh3->isChecked();
	m_ptrBtnPrevCh3->setChecked(!bCheck);
}

void VideoAreaUtilWindow::OnBtnPrevCh4()
{
	bool bCheck = m_ptrBtnPrevCh4->isChecked();
	m_ptrBtnPrevCh4->setChecked(!bCheck);
}

void VideoAreaUtilWindow::OnBtnPrevCh5()
{
	bool bCheck = m_ptrBtnPrevCh5->isChecked();
	m_ptrBtnPrevCh5->setChecked(!bCheck);
}

void VideoAreaUtilWindow::OnBtnPrevCh6()
{
	bool bCheck = m_ptrBtnPrevCh6->isChecked();
	m_ptrBtnPrevCh6->setChecked(!bCheck);
}

void VideoAreaUtilWindow::OnBtnPrevCh7()
{
	bool bCheck = m_ptrBtnPrevCh7->isChecked();
	m_ptrBtnPrevCh7->setChecked(!bCheck);
}

void VideoAreaUtilWindow::OnBtnPrevCh8()
{
	bool bCheck = m_ptrBtnPrevCh8->isChecked();
	m_ptrBtnPrevCh8->setChecked(!bCheck);
}

void VideoAreaUtilWindow::OnBtnPrevCh9()
{
	bool bCheck = m_ptrBtnPrevCh9->isChecked();
	m_ptrBtnPrevCh9->setChecked(!bCheck);
}

#if PIX_1080p
void VideoAreaUtilWindow::OnBtnPrevCh10()
{
	bool bCheck = m_ptrBtnPrevCh10->isChecked();
	m_ptrBtnPrevCh10->setChecked(!bCheck);
}

void VideoAreaUtilWindow::OnBtnPrevCh11()
{
	bool bCheck = m_ptrBtnPrevCh11->isChecked();
	m_ptrBtnPrevCh11->setChecked(!bCheck);
}

void VideoAreaUtilWindow::OnBtnPrevCh12()
{
	bool bCheck = m_ptrBtnPrevCh12->isChecked();
	m_ptrBtnPrevCh12->setChecked(!bCheck);
}
#endif


void VideoAreaUtilWindow::OnBtnMainSubtitles1() 
{
	bool bCheck = m_ptrBtnMainSubtitles1->isChecked();
	m_ptrBtnMainSubtitles1->setChecked(!bCheck);
}

void VideoAreaUtilWindow::OnBtnMainSubtitles2() 
{
	bool bCheck = m_ptrBtnMainSubtitles2->isChecked();
	m_ptrBtnMainSubtitles2->setChecked(!bCheck);
}
void VideoAreaUtilWindow::OnBtnMainSubtitles3() 
{
	bool bCheck = m_ptrBtnMainSubtitles3->isChecked();
	m_ptrBtnMainSubtitles3->setChecked(!bCheck);
}

#if   PIX_1080p
void VideoAreaUtilWindow::OnBtnMainSubtitles4()
{
	bool bCheck = m_ptrBtnMainSubtitles4->isChecked();
	m_ptrBtnMainSubtitles4->setChecked(!bCheck);
}
#endif

void VideoAreaUtilWindow::OnBtnPrevSubtitles1() 
{
	bool bCheck = m_ptrBtnPrevSubtitles1->isChecked();
	m_ptrBtnPrevSubtitles1->setChecked(!bCheck);
}

void VideoAreaUtilWindow::OnBtnPrevSubtitles2() 
{
	bool bCheck = m_ptrBtnPrevSubtitles2->isChecked();
	m_ptrBtnPrevSubtitles2->setChecked(!bCheck);
}

void VideoAreaUtilWindow::OnBtnPrevSubtitles3() 
{
	bool bCheck = m_ptrBtnPrevSubtitles3->isChecked();
	m_ptrBtnPrevSubtitles3->setChecked(!bCheck);
}

#if PIX_1080p
 
void VideoAreaUtilWindow::OnBtnPrevSubtitles4()
{
	bool bCheck = m_ptrBtnPrevSubtitles4->isChecked();
	m_ptrBtnPrevSubtitles4->setChecked(!bCheck);
}
#endif


void VideoAreaUtilWindow::OnBtnMainBlackSite() 
{
	bool bCheck = m_ptrBtnMainBlackSite->isChecked();
	m_ptrBtnMainBlackSite->setChecked(!bCheck);
}
void VideoAreaUtilWindow::OnBtnMainColourBar() 
{
	bool bCheck = m_ptrBtnMainColourBar->isChecked();
	m_ptrBtnMainColourBar->setChecked(!bCheck);
}
void VideoAreaUtilWindow::OnBtnMainPicInPic1()
{
	bool bCheck = m_ptrBtnMainPicInPic1->isChecked();
	m_ptrBtnMainPicInPic1->setChecked(!bCheck);
}
void VideoAreaUtilWindow::OnBtnMainPicInPic2() 
{
	bool bCheck = m_ptrBtnMainPicInPic2->isChecked();
	m_ptrBtnMainPicInPic2->setChecked(!bCheck);
}
 
void VideoAreaUtilWindow::OnBtnPrevBlackSite() 
{
	bool bCheck = m_ptrBtnPrevBlackSite->isChecked();
	m_ptrBtnPrevBlackSite->setChecked(!bCheck);
}
void VideoAreaUtilWindow::OnBtnPrevColourBar() 
{
	bool bCheck = m_ptrBtnPrevColourBar->isChecked();
	m_ptrBtnPrevColourBar->setChecked(!bCheck);
}
void VideoAreaUtilWindow::OnBtnPrevPicInPic1()
{
	bool bCheck = m_ptrBtnPrevPicInPic1->isChecked();
	m_ptrBtnPrevPicInPic1->setChecked(!bCheck);
}
void VideoAreaUtilWindow::OnBtnPrevPicInPic2() 
{
	bool bCheck = m_ptrBtnPrevPicInPic2->isChecked();
	m_ptrBtnPrevPicInPic2->setChecked(!bCheck);
} 

void VideoAreaUtilWindow::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(30, 30, 30));
	painter.setPen(QColor(210, 210, 210));
 }

