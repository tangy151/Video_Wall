#include "playcontrolwindow.h"
#include "../globaldefine.h"
#include "../headfiledefine.h"
#include "../Controls/flatuiex.h"
#include "../Controls/buttonex.h"
#include "../Controls/navlabelex.h"
#include "../Controls/sliderex.h"
#include "../Controls/progressbarex.h"
 
PlayControlWindow::PlayControlWindow(QWidget *parent)
	: QWidget(parent)
	, m_ptrBtnPlay(nullptr)
	, m_ptrBtnPause(nullptr)
	, m_ptrBtnNext(nullptr)
	, m_ptrBtnPrev(nullptr)
	, m_ptrPlayProgress(nullptr)
	, m_ptrTotalTime(nullptr)
	, m_ptrCurTime(nullptr)
	, m_ptrBtnStop(nullptr)
{ 
	m_strExePath = QCoreApplication::applicationDirPath();
	 
	m_iNormalBgColor = QColor(50, 50, 50);
	m_iNormalFrameColor = QColor(50, 50, 50);

	m_iHoverBgColor = QColor(255, 0, 0);
	m_iCheckBgColor = QColor(255, 0, 0);

	m_iNormalTextColor = QColor(200, 200, 200);
	m_iHoverTextColor = QColor(200, 200, 200);
	m_iCheckTextColor = QColor(0, 0, 0);

	InitSlider();
	InitLabels();
 	InitButtons();
	InitConnects();
 }

PlayControlWindow::~PlayControlWindow()
{
}

void PlayControlWindow::InitLabels()
{
	m_ptrTotalTime.reset(new NavLabelEx(this));
 	//-------------------------------------
	QFont font1("Microsoft YaHei", 9);
	m_ptrTotalTime->setFont(font1);

	m_ptrTotalTime->setTextAlign(NavLabelEx::TextAlign_Right);
	m_ptrTotalTime->setShowIcon(false);
	m_ptrTotalTime->setIconSize(QSize(0, 0));
	m_ptrTotalTime->setText(QString::fromLocal8Bit("0:00:00"));

	m_ptrTotalTime->setNormalBgColor(QColor(50, 50, 50));
	m_ptrTotalTime->setNormalTextColor(QColor(235, 235, 235));

	//-------------------------------------
	QFont font2("Microsoft YaHei", 9);
	m_ptrCurTime.reset(new NavLabelEx(this));

	m_ptrCurTime->setFont(font2);

	m_ptrCurTime->setTextAlign(NavLabelEx::TextAlign_Right);
	m_ptrCurTime->setShowIcon(false);
	m_ptrCurTime->setIconSize(QSize(0, 0));
	m_ptrCurTime->setText(QString::fromLocal8Bit("0:10:00"));

	m_ptrCurTime->setNormalBgColor(QColor(50, 50, 50));
	m_ptrCurTime->setNormalTextColor(QColor(235, 235, 235));
 }

void PlayControlWindow::InitSlider()
{
	m_ptrPlayProgress.reset(new ProgressBarEx(this));

	m_ptrPlayProgress->setBgColorStart(QColor(50, 50, 50));
	m_ptrPlayProgress->setBgColorEnd(QColor(50, 50, 50));
 
	m_ptrPlayProgress->setBarFrameColor(QColor(30, 30, 30));
	m_ptrPlayProgress->setBarColor(QColor(239, 98, 234));
	m_ptrPlayProgress->setBarBgColor(QColor(50, 50, 50));
	 
}

void PlayControlWindow::InitConnects()
{
	connect(m_ptrBtnPlay.get(), SIGNAL(clicked()), this, SLOT(OnButtonPlay()));
	connect(m_ptrBtnPause.get(), SIGNAL(clicked()), this, SLOT(OnButtonPause()));
	connect(m_ptrBtnStop.get(), SIGNAL(clicked()), this, SLOT(OnButtonStop()));
	connect(m_ptrBtnNext.get(), SIGNAL(clicked()), this, SLOT(OnButtonNext()));
	connect(m_ptrBtnPrev.get(), SIGNAL(clicked()), this, SLOT(OnButtonPrev()));
 }

void  PlayControlWindow::OnButtonPlay()
{
	bool bCheck = m_ptrBtnPlay->isChecked();
	m_ptrBtnPlay->setChecked(!bCheck);
	 
	m_ptrBtnPause->show();
	m_ptrBtnPlay->hide();
  }

void  PlayControlWindow::OnButtonPause() 
{
	bool bCheck = m_ptrBtnPause->isChecked();
	m_ptrBtnPause->setChecked(!bCheck);


 	m_ptrBtnPause->hide();
	m_ptrBtnPlay->show();
 
}
 
void  PlayControlWindow::OnButtonStop()
{
	bool bCheck = m_ptrBtnStop->isChecked();
	m_ptrBtnStop->setChecked(!bCheck);
}

void  PlayControlWindow::OnButtonNext()
{
	bool bCheck = m_ptrBtnNext->isChecked();
	m_ptrBtnNext->setChecked(!bCheck);
}

void  PlayControlWindow::OnButtonPrev()
{
	bool bCheck = m_ptrBtnPrev->isChecked();
	m_ptrBtnPrev->setChecked(!bCheck);
}
  
void PlayControlWindow::InitButtons()
{
	m_ptrBtnPlay.reset(new ButtonEx(this));
	m_ptrBtnPause.reset(new ButtonEx(this));
	m_ptrBtnStop.reset(new ButtonEx(this));
	m_ptrBtnNext.reset(new ButtonEx(this));
	m_ptrBtnPrev.reset(new ButtonEx(this));

	m_listButtons << m_ptrBtnPlay.get() << m_ptrBtnPause.get() << m_ptrBtnStop.get()
		<< m_ptrBtnNext.get() << m_ptrBtnPrev.get();

	for (int iIndex = 0; iIndex < m_listButtons.count(); iIndex++)
	{
		ButtonEx* pButtonEx = m_listButtons.at(iIndex);
		pButtonEx->setPaddingLeft(0);
		pButtonEx->setShowLine(false);
		pButtonEx->setShowIcon(false);
		pButtonEx->setShowPlayButtonState(true);

#if PIX_1080p 
		pButtonEx->setBigStyle(true);
#else
		pButtonEx->setBigStyle(false);
 #endif

		pButtonEx->setIconSpace(0);
		  
		if (pButtonEx == m_ptrBtnPlay.get())
		{
			m_ptrBtnPlay->setShowPlayButtonState(ButtonEx::Button_Play);
		}
		else if (pButtonEx == m_ptrBtnPause.get())
		{
			m_ptrBtnPause->setShowPlayButtonState(ButtonEx::Button_Pause);
			m_ptrBtnPause->hide();
 		}
		else if (pButtonEx == m_ptrBtnStop.get())
		{
			m_ptrBtnStop->setShowPlayButtonState(ButtonEx::Button_Stop);
		}
		else if (pButtonEx == m_ptrBtnPrev.get())
		{
			m_ptrBtnPrev->setShowPlayButtonState(ButtonEx::Button_Prev);
		}
		else if (pButtonEx == m_ptrBtnNext.get())
		{
			m_ptrBtnNext->setShowPlayButtonState(ButtonEx::Button_Next);
		}

		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);
		pButtonEx->setFont(QFont("Microsoft YaHei", 10, 75));

 		pButtonEx->setHoverBgColor(QColor(239, 98, 234));
	//	pButtonEx->setHoverBgColor(QColor(50, 50, 50));

		pButtonEx->setCheckBgColor(QColor(50, 50, 50));

		pButtonEx->setButtonStateColor(QColor(185, 185, 185));
		pButtonEx->setNormalBgColor(m_iNormalBgColor);
		pButtonEx->setNormalFrameColor(m_iNormalFrameColor);
 	}
 }
 
void PlayControlWindow::paintEvent(QPaintEvent* pEvent)
{
 	QPainter painter(this);
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(30, 30, 30));
	painter.setPen(QColor(210, 210, 210));
}

void PlayControlWindow::resizeEvent(QResizeEvent* pEvent)
{
	int iWidth = width();
	int iHeight = height();
	 
#if PIX_1080p
	if (m_ptrBtnPlay)
	{
		m_ptrBtnPlay->setGeometry(0, 0, 35, 35);
		m_ptrBtnPlay->move(3, 3);
	}

	if (m_ptrBtnPause)
	{
		m_ptrBtnPause->setGeometry(0, 0, 35, 35);
		m_ptrBtnPause->move(3, 3);
	}

	if (m_ptrBtnStop)
	{
		m_ptrBtnStop->setGeometry(0, 0, 35, 35);
		m_ptrBtnStop->move(38, 3);
	}

	if (m_ptrBtnPrev)
	{
		m_ptrBtnPrev->setGeometry(0, 0, 35, 35);
		m_ptrBtnPrev->move(73, 3);
	}
	if (m_ptrBtnNext)
	{
		m_ptrBtnNext->setGeometry(0, 0, 35, 35);
		m_ptrBtnNext->move(108, 3);
	}

	if (m_ptrCurTime)
	{
		m_ptrCurTime->setGeometry(0, 0, 50, 35);
		m_ptrCurTime->move(143, 3);
	}

	if (m_ptrPlayProgress)
	{
		m_ptrPlayProgress->setGeometry(0, 0, 220, 35);
		m_ptrPlayProgress->move(190, 3);
	}

	if (m_ptrTotalTime)
	{
		m_ptrTotalTime->setGeometry(0, 0, 50, 35);
		m_ptrTotalTime->move(iWidth - 53, 3);
	}
#else
	if (m_ptrBtnPlay)
	{
		m_ptrBtnPlay->setGeometry(0, 0, 24, 24);
		m_ptrBtnPlay->move(3, 3);
	}

	if (m_ptrBtnPause)
	{
		m_ptrBtnPause->setGeometry(0, 0, 24, 24);
		m_ptrBtnPause->move(3, 3);
	}

	if (m_ptrBtnStop)
	{
		m_ptrBtnStop->setGeometry(0, 0, 24, 24);
		m_ptrBtnStop->move(27, 3);
	}

	if (m_ptrBtnPrev)
	{
		m_ptrBtnPrev->setGeometry(0, 0, 24, 24);
		m_ptrBtnPrev->move(51, 3);
	}
	if (m_ptrBtnNext)
	{
		m_ptrBtnNext->setGeometry(0, 0, 24, 24);
		m_ptrBtnNext->move(75, 3);
	}

	if (m_ptrCurTime)
	{
		m_ptrCurTime->setGeometry(0, 0, 50, 24);
		m_ptrCurTime->move(99, 3);
	}

	if (m_ptrPlayProgress)
	{
 		m_ptrPlayProgress->setGeometry(0, 0, 121, 24);
		m_ptrPlayProgress->move(149, 3);
	}

	if (m_ptrTotalTime)
	{
		m_ptrTotalTime->setGeometry(0, 0, 50, 24);
		m_ptrTotalTime->move(iWidth - 53, 3);
	}
#endif
	 
	QWidget::resizeEvent(pEvent);
 }
