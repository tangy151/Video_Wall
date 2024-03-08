#include "volumecontrolwindow.h"
#include "../headfiledefine.h"
#include "../globaldefine.h"
#include "../Controls/flatuiex.h"
#include "../Controls/buttonex.h"
#include "../Controls/navlabelex.h"
#include "../Controls/sliderex.h"
#include "../Controls/progressbarex.h"
#include "../Controls/volumemeter.h"
#include "../Controls/rulerlineex.h"
#include "../Controls/sliderex.h"

VolumeControlWindow::VolumeControlWindow(QWidget *parent)
	: QWidget(parent)
	, m_iChannelIndex(0)
	, m_ptrLabelChannel(nullptr)
	, m_ptrBtnPlay(nullptr)
	, m_ptrBtnPause(nullptr)
	, m_ptrBtnStop(nullptr)
	, m_ptrBtnSpeaker(nullptr)
	, m_ptrRulerLineEx(nullptr)
	, m_ptrVSliderEx(nullptr)
{ 
	m_strExePath = QCoreApplication::applicationDirPath();

	InitSlider();
	InitButtons();
	InitLabels();
	 InitVolumeMeter();
	InitConnects();


	//初始化随机数种子
	QTime t = QTime::currentTime();
	qsrand(t.msec() + t.second() * 1000);

	QTimer *timer = new QTimer(this);
	timer->setInterval(2000);

	connect(timer, SIGNAL(timeout()), this, SLOT(updateValue()));
	timer->start();
	updateValue();
 }

VolumeControlWindow::~VolumeControlWindow()
{
}

void VolumeControlWindow::InitSlider()
{ 
	m_ptrVSliderEx.reset(new SliderEx(this));
	m_ptrVSliderEx->setStyle(Single_VerticalSlider, RectangleEx);
	m_ptrVSliderEx->setRange(-50, 50);
	m_ptrVSliderEx->setSingleStep(1);
	m_ptrVSliderEx->setSliderColor(QColor(40, 40, 40), QColor(40, 40, 40));		//设置槽底色,选中色
	m_ptrVSliderEx->setHandleColor(QColor(50, 50, 50), QColor(50, 50, 50));		//设置滑块选中色,未选中色
	m_ptrVSliderEx->setDrawVolume(true);
	 
	QString	 strIcon = m_strExePath + "/Images/sliderbar.png";
 
 	QPixmap iconNormal = QPixmap(strIcon);
 	m_ptrVSliderEx->setIconNormal(iconNormal);
  
	//----------------------------------------------

	m_ptrRulerLineEx.reset( new RulerLineEx(this));

	m_ptrRulerLineEx->setMaxValue(100);
	m_ptrRulerLineEx->setLongStep(20);
	m_ptrRulerLineEx->setShortStep(10);
 
	m_ptrRulerLineEx->setRange(-50, 50);
	m_ptrRulerLineEx->setBgColor(QColor(40, 40, 40));
	m_ptrRulerLineEx->setScaleStyle(RulerLineEx::ScaleStyle_Single);
  }

void VolumeControlWindow::InitButtons()
{
	m_ptrBtnPlay.reset(new ButtonEx(this));
	m_ptrBtnPause.reset(new ButtonEx(this));
	m_ptrBtnStop.reset(new ButtonEx(this));

	m_listButtons << m_ptrBtnPlay.get() << m_ptrBtnPause.get() << m_ptrBtnStop.get();

	for (int iIndex = 0; iIndex < m_listButtons.count(); iIndex++)
	{
		ButtonEx* pButtonEx = m_listButtons.at(iIndex);
		pButtonEx->setPaddingLeft(0);
		pButtonEx->setShowLine(false);
		pButtonEx->setShowIcon(false);
		pButtonEx->setShowPlayButtonState(true);
		pButtonEx->setBigStyle(false);
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
 		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);
		pButtonEx->setFont(QFont("Microsoft YaHei", 10, 75));

		pButtonEx->setHoverBgColor(QColor(239, 98, 234));
 		pButtonEx->setCheckBgColor(QColor(50, 50, 50));

		pButtonEx->setButtonStateColor(QColor(185, 185, 185));
		pButtonEx->setNormalBgColor(QColor(50,50,50));
		pButtonEx->setNormalFrameColor(QColor(50, 50, 50));
 	}

	//-------------------------------------------------------------------
	QString strIcon = "";
	strIcon = m_strExePath + "/Images/skpear.png";
	
	m_ptrBtnSpeaker.reset(new ButtonEx(this));
	m_ptrBtnSpeaker->setPaddingLeft(0);
	m_ptrBtnSpeaker->setPaddingTop(0);
	m_ptrBtnSpeaker->setShowLine(false);
	m_ptrBtnSpeaker->setShowIcon(true);
	m_ptrBtnSpeaker->setIconSpace(5);
	m_ptrBtnSpeaker->setIconSize(QSize(24, 24));
 
	m_ptrBtnSpeaker->setIconNormal(QPixmap(strIcon));
	m_ptrBtnSpeaker->setIconHover(QPixmap(strIcon));
	m_ptrBtnSpeaker->setIconCheck(QPixmap(strIcon));
 
	m_ptrBtnSpeaker->setHoverBgColor(QColor(239, 98, 234));
	m_ptrBtnSpeaker->setCheckBgColor(QColor(50, 50, 50));

	m_ptrBtnSpeaker->setButtonStateColor(QColor(185, 185, 185));
	m_ptrBtnSpeaker->setNormalBgColor(QColor(50, 50, 50));
	m_ptrBtnSpeaker->setNormalFrameColor(QColor(50, 50, 50));
	 
}
void VolumeControlWindow::InitVolumeMeter()
{
	m_ptrVolumeMeter.reset(new VolumeMeter(this));

}
void VolumeControlWindow::updateValue()
{
	if (m_ptrVolumeMeter)
	{
		m_ptrVolumeMeter->setLeftValue(qrand() % 100);
		m_ptrVolumeMeter->setRightValue(qrand() % 100);
	}
 }

void VolumeControlWindow::InitLabels()
{
	
	m_ptrLabelChannel.reset(new NavLabelEx(this));
	//-------------------------------------

#if PIX_1080p
	QFont font1("Microsoft YaHei", 10);
#else
	QFont font1("Microsoft YaHei", 8);
#endif

	m_ptrLabelChannel->setFont(font1);

	m_ptrLabelChannel->setTextAlign(NavLabelEx::TextAlign_Center);
	m_ptrLabelChannel->setShowIcon(false);
	m_ptrLabelChannel->setIconSize(QSize(0, 0));
	m_ptrLabelChannel->setText(QString::fromLocal8Bit("通道"));

	m_ptrLabelChannel->setNormalBgColor(QColor(50, 50, 50));
	m_ptrLabelChannel->setNormalTextColor(QColor(235, 235, 235));
}

void VolumeControlWindow::InitConnects()
{

}

void VolumeControlWindow::paintEvent(QPaintEvent* pEvent)
{
 	QPainter painter(this);

	int iWidth = width();
	int iHeight = height();

	painter.setClipRect(0, 0, width(), height());
 	painter.fillRect(QRectF(0, 0, width(), height()), QColor(50, 50, 50));

	//painter.setClipRect(1, 1, width() - 2, height() - 2);
	//painter.fillRect(QRectF(0, 0, width(), height()), QColor(50, 50, 50));
}

void VolumeControlWindow::resizeEvent(QResizeEvent* pEvent)
{
	int iWidth = width();
	int iHeight = height();

	int iPre = iWidth / 3;
	  
	if (m_ptrLabelChannel)
	{
		char szBuffer[200];
		memset(szBuffer, 0, sizeof(char));
		
		QString strTemp = "",   strText="";

#if  PIX_1080p
		if (m_iChannelIndex == 13)
#else
		if (m_iChannelIndex == 10)
#endif
 		{
			strText = QString::fromLocal8Bit("输出");
 			sprintf_s(szBuffer, "%s", strText.toStdString().c_str());
		}
		else
		{
			strTemp = QString::fromLocal8Bit("_通道");

			sprintf_s(szBuffer, "%02d", m_iChannelIndex);
			strText = szBuffer;
			strText += strTemp;
		}
		 
		m_ptrLabelChannel->setText(strText);
		m_ptrLabelChannel->setGeometry(0, 0, iWidth, 25);
		m_ptrLabelChannel->move(0, iHeight - 25);
 	}

#if PIX_1080p
	if (m_ptrBtnPlay)
	{
		m_ptrBtnPlay->setGeometry(0, 0, 24, 24);
		m_ptrBtnPlay->move(0, 1);
	}

	if (m_ptrBtnPause)
	{
		m_ptrBtnPause->setGeometry(0, 0, 24, 24);
		m_ptrBtnPause->move(0, 1);
	}

	if (m_ptrBtnStop)
	{
		m_ptrBtnStop->setGeometry(0, 0, 24, 24);
		m_ptrBtnStop->move(iPre, 1);
	}

	if (m_ptrBtnSpeaker)
	{
		m_ptrBtnSpeaker->setGeometry(0, 0, 24, 24);
		m_ptrBtnSpeaker->move(iPre * 2, 1);
	}


	if (m_ptrVolumeMeter)
	{
		m_ptrVolumeMeter->setGeometry(0, 0, 14, iHeight - 62);
		m_ptrVolumeMeter->move(5, 31);
	}

	if (m_ptrRulerLineEx)
	{
		m_ptrRulerLineEx->setGeometry(0, 0, 35, iHeight - 62);
		m_ptrRulerLineEx->move(iPre - 4, 31);
	}

	if (m_ptrVSliderEx)
	{
		m_ptrVSliderEx->setGeometry(0, 0, iPre - 4, iHeight - 62);
		m_ptrVSliderEx->move(iPre * 2 + 4, 31);
	}
#else
	if (m_ptrBtnPlay)
	{
		m_ptrBtnPlay->setGeometry(0, 0, 22, 22);
		m_ptrBtnPlay->move(0, 1);
	}

	if (m_ptrBtnPause)
	{
		m_ptrBtnPause->setGeometry(0, 0, 22, 22);
		m_ptrBtnPause->move(0, 1);
	}

	if (m_ptrBtnStop)
	{
		m_ptrBtnStop->setGeometry(0, 0, 22, 22);
		m_ptrBtnStop->move(iPre, 1);
	}

	if (m_ptrBtnSpeaker)
	{
		m_ptrBtnSpeaker->setGeometry(0, 0, 22, 22);
		m_ptrBtnSpeaker->move(iPre * 2, 1);
	}


	if (m_ptrVolumeMeter)
	{
		m_ptrVolumeMeter->setGeometry(0, 0, 12, iHeight - 58);
		m_ptrVolumeMeter->move(5, 31);
	}

	if (m_ptrRulerLineEx)
	{
		m_ptrRulerLineEx->setGeometry(0, 0, iPre+7, iHeight - 58);
		m_ptrRulerLineEx->move(iPre - 4, 31);
	}

	if (m_ptrVSliderEx)
	{
		int iWid = iPre - 4;
		m_ptrVSliderEx->setGeometry(0, 0, iPre - 4, iHeight - 58);
		m_ptrVSliderEx->move(iPre * 2 + 4, 31);
	}
#endif
	 
}


