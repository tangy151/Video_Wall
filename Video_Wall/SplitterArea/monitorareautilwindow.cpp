#include "monitorareautilwindow.h"

#include "../globaldefine.h"
#include "../headfiledefine.h"
#include "../Controls/labelex.h"
#include "../Controls/flatuiex.h"
#include "../Controls/buttonex.h"
#include "../Controls/navlabelex.h"
#include "../Controls/iconhelper.h"
#include "../Controls/sliderex.h"
#include "../ComputerInfo/computerinfo.h"
#include "../VideoChannel/previewmonitorwindow.h"
#include "../VideoChannel/mainmonitorwindow.h"


MonitorAreaUtilWindow::MonitorAreaUtilWindow(QWidget *parent)
	: QWidget(parent)
	, m_ptrPreviewMonitorWindow(nullptr)
	, m_ptrMainMonitorWindow(nullptr)
	, m_ptrButtonLOGO1(nullptr)
	, m_ptrButtonLOGO2(nullptr)
	, m_ptrButtonClock(nullptr)
	, m_ptrButtonRecord(nullptr)
	, m_ptrButtonStreamMedia(nullptr)
	, m_ptrButtonStartNDI(nullptr)
	, m_ptrLabelOutPut(nullptr)
	, m_ptrLabelLogo(nullptr)
	, m_ptrButtonScreen(nullptr)
	, m_ptrBtnToTheLeft(nullptr)
	, m_ptrBtnToTheRight(nullptr)
	, m_ptrBtnCirrusLeaf(nullptr)
	, m_ptrBtnDrawRight(nullptr)
	, m_ptrBtnFadeInFadeOut(nullptr)
	, m_ptrBtnPushLeft(nullptr)
	, m_ptrBtnRightRub(nullptr)
	, m_ptrBtnCircularRubIn(nullptr)
	, m_ptrBtnBurn(nullptr)
	, m_ptrBtnDipToBlack(nullptr)
	, m_ptrHSliderEx(nullptr)
	, m_ptrVSliderEx(nullptr)
	,m_ptrBtnHardSwitch(nullptr)
	, m_ptrBtnAutoSwitch(nullptr)
{  
	m_strExePath = QApplication::applicationDirPath();
	 
	m_iNormalBgColor = QColor(50, 50, 50);
	m_iNormalFrameColor = QColor(50, 50, 50);

	m_iHoverBgColor = QColor(255, 0, 0);
	m_iCheckBgColor = QColor(255, 0, 0);

	m_iNormalTextColor = QColor(200, 200, 200);
	m_iHoverTextColor = QColor(200, 200, 200);
	m_iCheckTextColor = QColor(0, 0, 0);

	InitUI();
	InitSliders();
	InitButtons();
	InitButtons2();
	InitLabels();
 	InitSystemInfo();
	InitConnect();
 }

MonitorAreaUtilWindow::~MonitorAreaUtilWindow()
{
	m_pServerRunState->stop();
}

void MonitorAreaUtilWindow::InitSystemInfo()
{
	m_pServerRunState = new QTimer(this);
	connect(m_pServerRunState, SIGNAL(timeout()), this, SLOT(OnGetServerRunState()));
	OnStart(1000);
}

void MonitorAreaUtilWindow::OnGetServerRunState()
{
	m_iComputerInfo.GetComputerInfo();

	QString  strText = GetRunTimeString();

	if (m_ptrLabelLogo)
		m_ptrLabelLogo->setText(strText);
}

void MonitorAreaUtilWindow::OnStart(int interval)
{
 	OnGetServerRunState();
 	m_pServerRunState->start(interval);
}

void MonitorAreaUtilWindow::OnStop()
{
	m_pServerRunState->stop();
}

void MonitorAreaUtilWindow::InitConnect()
{
	connect(m_ptrButtonLOGO1.get(), SIGNAL(clicked()), this, SLOT(OnButtonLOGO1()));
	connect(m_ptrButtonLOGO2.get(), SIGNAL(clicked()), this, SLOT(OnButtonLOGO2()));
	connect(m_ptrButtonStreamMedia.get(), SIGNAL(clicked()), this, SLOT(OnButtonStreamMedia()));
	connect(m_ptrButtonStartNDI.get(), SIGNAL(clicked()), this, SLOT(OnButtonStartNDI()));
	connect(m_ptrButtonClock.get(), SIGNAL(clicked()), this, SLOT(OnButtonClock()));
	connect(m_ptrButtonRecord.get(), SIGNAL(clicked()), this, SLOT(OnButtonRecord()));

	connect(m_ptrBtnToTheLeft.get(), SIGNAL(clicked()), this, SLOT(OnBtnToTheLeft()));
	connect(m_ptrBtnToTheRight.get(), SIGNAL(clicked()), this, SLOT(OnBtnToTheRight()));
	connect(m_ptrBtnCirrusLeaf.get(), SIGNAL(clicked()), this, SLOT(OnBtnCirrusLeaf()));
	connect(m_ptrBtnDrawRight.get(), SIGNAL(clicked()), this, SLOT(OnBtnDrawRight()));
	connect(m_ptrBtnFadeInFadeOut.get(), SIGNAL(clicked()), this, SLOT(OnBtnFadeInFadeOut()));
	 
	connect(m_ptrBtnPushLeft.get(), SIGNAL(clicked()), this, SLOT(OnBtnPushLeft()));
	connect(m_ptrBtnRightRub.get(), SIGNAL(clicked()), this, SLOT(OnBtnRightRub()));
	connect(m_ptrBtnCircularRubIn.get(), SIGNAL(clicked()), this, SLOT(OnBtnCircularRubIn()));
	connect(m_ptrBtnBurn.get(), SIGNAL(clicked()), this, SLOT(OnBtnBurn()));
	connect(m_ptrBtnDipToBlack.get(), SIGNAL(clicked()), this, SLOT(OnBtnDipToBlack()));
}

void MonitorAreaUtilWindow::InitUI()
{
	m_ptrPreviewMonitorWindow.reset(new PreviewMonitorWindow(this));
	m_ptrMainMonitorWindow.reset(new MainMonitorWindow(this));
}

void MonitorAreaUtilWindow::InitButtons()
{
	m_ptrButtonLOGO1.reset(new ButtonEx(this));
	m_ptrButtonLOGO2.reset(new ButtonEx(this));
	m_ptrButtonClock.reset(new ButtonEx(this));

	m_ptrButtonRecord.reset(new ButtonEx(this));
	m_ptrButtonStreamMedia.reset(new ButtonEx(this));
	m_ptrButtonStartNDI.reset(new ButtonEx(this));

	m_listButtons << m_ptrButtonLOGO1.get() << m_ptrButtonLOGO2.get() << m_ptrButtonClock.get()
		<< m_ptrButtonRecord.get() << m_ptrButtonStreamMedia.get() << m_ptrButtonStartNDI.get();

	bool bClock = false;

	for (int iIndex = 0; iIndex < m_listButtons.count(); iIndex++)
	{
		ButtonEx* pButtonEx = m_listButtons.at(iIndex);
		pButtonEx->setPaddingLeft(0);
		pButtonEx->setShowLine(false);
		pButtonEx->setShowIcon(false);
		pButtonEx->setIconSpace(0);

		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);
		pButtonEx->setFont(QFont("Microsoft YaHei", 10, 75));

		if (pButtonEx == m_ptrButtonLOGO1.get())
		{
			m_ptrButtonLOGO1->setText(QString::fromLocal8Bit("LOGO1"));
			bClock = false;
		}
		else if (pButtonEx == m_ptrButtonLOGO2.get())
		{
			bClock = false;

			m_ptrButtonLOGO2->setText(QString::fromLocal8Bit("LOGO2"));
		}
		else if (pButtonEx == m_ptrButtonClock.get())
		{
			m_ptrButtonClock->setText(QString::fromLocal8Bit("时钟"));

			bClock = true;
		}
		else	if (pButtonEx == m_ptrButtonRecord.get())
		{
			bClock = false;

			m_ptrButtonRecord->setText(QString::fromLocal8Bit("录制"));
		}
		else if (pButtonEx == m_ptrButtonStreamMedia.get())
		{
			bClock = false;

			m_ptrButtonStreamMedia->setText(QString::fromLocal8Bit("流媒体"));
		}
		else if (pButtonEx == m_ptrButtonStartNDI.get())
		{
			bClock = false;

			m_ptrButtonStartNDI->setText(QString::fromLocal8Bit("NDI\r\n开启"));
		}
		 
		if (bClock)
		{
			pButtonEx->setHoverBgColor(QColor(239, 98, 234));
			pButtonEx->setCheckBgColor(QColor(239, 98, 234));
		}
		else
		{
			pButtonEx->setHoverBgColor(/*m_iHoverBgColor*/QColor(247, 52, 115));
			pButtonEx->setCheckBgColor(/*m_iCheckBgColor*/QColor(247, 52, 115));
		}

 		pButtonEx->setNormalBgColor(m_iNormalBgColor);
		pButtonEx->setNormalFrameColor(m_iNormalFrameColor);
		pButtonEx->setNormalTextColor(m_iNormalTextColor);
		pButtonEx->setHoverTextColor(m_iHoverTextColor);
		pButtonEx->setCheckTextColor(m_iCheckTextColor);
	}
}

void MonitorAreaUtilWindow::InitButtons2()
{
	m_ptrBtnToTheLeft.reset(new ButtonEx(this));
	m_ptrBtnToTheRight.reset(new ButtonEx(this));
	m_ptrBtnCirrusLeaf.reset(new ButtonEx(this));
	m_ptrBtnDrawRight.reset(new ButtonEx(this));
	m_ptrBtnFadeInFadeOut.reset(new ButtonEx(this));

	m_ptrBtnPushLeft.reset(new ButtonEx(this));
	m_ptrBtnRightRub.reset(new ButtonEx(this));
	m_ptrBtnCircularRubIn.reset(new ButtonEx(this));
	m_ptrBtnBurn.reset(new ButtonEx(this));
	m_ptrBtnDipToBlack.reset(new ButtonEx(this));

	m_ptrBtnHardSwitch.reset(new ButtonEx(this));
	m_ptrBtnAutoSwitch.reset(new ButtonEx(this));
	  
	m_listButtons2 << m_ptrBtnToTheLeft.get() << m_ptrBtnToTheRight.get() << m_ptrBtnCirrusLeaf.get()
		<< m_ptrBtnDrawRight.get() << m_ptrBtnFadeInFadeOut.get() << m_ptrBtnPushLeft.get()
		<< m_ptrBtnRightRub.get() << m_ptrBtnCircularRubIn.get() << m_ptrBtnBurn.get()
		<< m_ptrBtnDipToBlack.get() << m_ptrBtnHardSwitch.get()<< m_ptrBtnAutoSwitch.get();
	 
	for (int iIndex = 0; iIndex < m_listButtons2.count(); iIndex++)
	{
		ButtonEx* pButtonEx = m_listButtons2.at(iIndex);
		pButtonEx->setPaddingLeft(0);
		pButtonEx->setShowLine(false);
		pButtonEx->setShowIcon(false);
		pButtonEx->setIconSpace(0);

		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);
		pButtonEx->setFont(QFont("Microsoft YaHei", 10, 75));

		if (pButtonEx == m_ptrBtnToTheLeft.get())
		{
			m_ptrBtnToTheLeft->setText(QString::fromLocal8Bit("划向\r\n左边"));
		}
		else if (pButtonEx == m_ptrBtnToTheRight.get())
		{
			m_ptrBtnToTheRight->setText(QString::fromLocal8Bit("划向\r\n右边"));
		}
		else if (pButtonEx == m_ptrBtnCirrusLeaf.get())
		{
			m_ptrBtnCirrusLeaf->setText(QString::fromLocal8Bit("卷叶"));
		}
		else if (pButtonEx == m_ptrBtnDrawRight.get())
		{
			m_ptrBtnDrawRight->setText(QString::fromLocal8Bit("右边\r\n划出"));
		}
		else if (pButtonEx == m_ptrBtnFadeInFadeOut.get())
		{
			m_ptrBtnFadeInFadeOut->setText(QString::fromLocal8Bit("淡入\r\n淡出"));
		} 
		else if (pButtonEx == m_ptrBtnPushLeft.get())
		{
			m_ptrBtnPushLeft->setText(QString::fromLocal8Bit("左推"));
		}
		else if (pButtonEx == m_ptrBtnRightRub.get())
		{
			m_ptrBtnRightRub->setText(QString::fromLocal8Bit("右擦"));
		}
		else if (pButtonEx == m_ptrBtnCircularRubIn.get())
		{
			m_ptrBtnCircularRubIn->setText(QString::fromLocal8Bit("圆形\r\n擦入"));
		}
		else if (pButtonEx == m_ptrBtnBurn.get())
		{
			m_ptrBtnBurn->setText(QString::fromLocal8Bit("燃烧"));
		}
		else if (pButtonEx == m_ptrBtnDipToBlack.get())
		{
			m_ptrBtnDipToBlack->setText(QString::fromLocal8Bit("黑色\r\n过度"));
		}
		else if (pButtonEx == m_ptrBtnHardSwitch.get())
		{
			m_ptrBtnHardSwitch->setText(QString::fromLocal8Bit("硬切"));
		}
		else if (pButtonEx == m_ptrBtnAutoSwitch.get())
		{
			m_ptrBtnAutoSwitch->setText(QString::fromLocal8Bit("自动"));
		} 

		pButtonEx->setHoverBgColor(QColor(239, 98, 234));
		pButtonEx->setCheckBgColor(QColor(239, 98, 234));

		pButtonEx->setNormalBgColor(m_iNormalBgColor);
		pButtonEx->setNormalFrameColor(m_iNormalFrameColor);
		pButtonEx->setNormalTextColor(m_iNormalTextColor);
		pButtonEx->setHoverTextColor(m_iHoverTextColor);
		pButtonEx->setCheckTextColor(m_iCheckTextColor);
	}
}

void MonitorAreaUtilWindow::InitLabels()
{
	QString strIcon = "";
	strIcon = m_strExePath + "/Images/screen.png";

	m_ptrButtonScreen.reset(new ButtonEx(this));
	m_ptrButtonScreen->setPaddingLeft(0);
	m_ptrButtonScreen->setPaddingTop(5);
	m_ptrButtonScreen->setShowLine(false);
	m_ptrButtonScreen->setShowIcon(true);
	m_ptrButtonScreen->setIconSpace(5);
	m_ptrButtonScreen->setIconSize(QSize(30, 30));
	m_ptrButtonScreen->setNormalBgColor(RGB(30, 30, 30));
	m_ptrButtonScreen->setNormalFrameColor(RGB(50, 50, 50));
	m_ptrButtonScreen->setIconNormal(QPixmap(strIcon));
	m_ptrButtonScreen->setIconHover(QPixmap(strIcon));
	m_ptrButtonScreen->setIconCheck(QPixmap(strIcon));

	//---------------------------------------------
	m_ptrLabelLogo.reset(new NavLabelEx(this));

	QColor normalBgColor = QColor(RGB(30, 30, 30));
	QColor normalTextColor = QColor(RGB(239, 98, 234));

#if	PIX_1080p

	QFont font("Microsoft YaHei", 19, 75);
	m_ptrLabelLogo->setFont(font);
#else
	QFont font("Microsoft YaHei", 15, 75);
	m_ptrLabelLogo->setFont(font);
#endif

	m_ptrLabelLogo->setPaddingLeft(5);
	m_ptrLabelLogo->setTextAlign(NavLabelEx::TextAlign_Left);
	m_ptrLabelLogo->setShowIcon(true);
	m_ptrLabelLogo->setIconTopSpace(5);
	  
#if	PIX_1080p

	m_ptrLabelLogo->setIconLeftSpace(30);
	m_ptrLabelLogo->setIconSize(QSize(65, 80));
	m_ptrLabelLogo->setText(QString::fromLocal8Bit("00:00:00"));
#else
	m_ptrLabelLogo->setIconLeftSpace(20);
	m_ptrLabelLogo->setIconSize(QSize(65, 80));
	m_ptrLabelLogo->setText(QString::fromLocal8Bit("00:00:00"));
#endif
	 
	strIcon = m_strExePath + "/Images/logo.png";

	QPixmap iconNormal = QPixmap(strIcon);

	m_ptrLabelLogo->setIconNormal(iconNormal);
	m_ptrLabelLogo->setNormalBgColor(normalBgColor);
	m_ptrLabelLogo->setNormalTextColor(normalTextColor);

	m_ptrLabelOutPut.reset(new NavLabelEx(this));

	//-------------------------------------
	QFont font1("Microsoft YaHei", 12, 75);
	m_ptrLabelOutPut->setFont(font1);

	m_ptrLabelOutPut->setTextAlign(NavLabelEx::TextAlign_Right);
	m_ptrLabelOutPut->setShowIcon(false);
	m_ptrLabelOutPut->setIconSize(QSize(65, 80));
	m_ptrLabelOutPut->setText(QString::fromLocal8Bit("屏幕2"));

	m_ptrLabelOutPut->setNormalBgColor(RGB(30, 30, 30));
	m_ptrLabelOutPut->setNormalTextColor(RGB(235, 235, 235));
}
void MonitorAreaUtilWindow::InitSliders()
{
	m_ptrHSliderEx.reset(new SliderEx(this));
	m_ptrHSliderEx->setStyle(Single_HorizontalSlider, RectangleEx);
	m_ptrHSliderEx->setRange(1, 10);
	m_ptrHSliderEx->setSingleStep(1);
	m_ptrHSliderEx->setSliderColor(RGB(40, 40, 40), RGB(40, 40, 40));		//设置槽底色,选中色
	m_ptrHSliderEx->setHandleColor(RGB(50, 50, 50), RGB(50, 50, 50));	//设置滑块选中色,未选中色
	m_ptrHSliderEx->setDrawVolume(true);

#if PIX_1080p
	QString	 strHIcon = m_strExePath + "/Images/sliderbar.png";
	QPixmap iconNormal = QPixmap(strHIcon);
#else
	QString	 strHIcon = m_strExePath + "/Images/sliderbar2.png";
	QPixmap iconNormal = QPixmap(strHIcon);
#endif
	 
	m_ptrHSliderEx->setIconNormal(iconNormal);

	m_ptrVSliderEx.reset(new SliderEx(this));
	m_ptrVSliderEx->setStyle(Single_VerticalSlider, RectangleEx);
	m_ptrVSliderEx->setRange(0, 10);
	m_ptrVSliderEx->setSingleStep(1);
	m_ptrVSliderEx->setSliderColor(QColor(40, 40, 40), QColor(40, 40, 40));		//设置槽底色,选中色
	m_ptrVSliderEx->setHandleColor(QColor(50, 50, 50), QColor(50, 50, 50));	//设置滑块选中色,未选中色
	m_ptrVSliderEx->setDrawVolume(true);
	 
	QString	 strVIcon = m_strExePath + "/Images/sliderbar.png";
	iconNormal = QPixmap(strVIcon);
	 
	m_ptrVSliderEx->setIconNormal(iconNormal);
}

void MonitorAreaUtilWindow::OnButtonLOGO1()
{
	bool bCheck = m_ptrButtonLOGO1->isChecked();
	m_ptrButtonLOGO1->setChecked(!bCheck);
}

void MonitorAreaUtilWindow::OnButtonLOGO2()
{
	bool bCheck = m_ptrButtonLOGO2->isChecked();
	m_ptrButtonLOGO2->setChecked(!bCheck);
}
void MonitorAreaUtilWindow::OnButtonClock()
{
	bool bCheck = m_ptrButtonClock->isChecked();
	m_ptrButtonClock->setChecked(!bCheck);
}

void MonitorAreaUtilWindow::OnButtonStreamMedia()
{
	bool bCheck = m_ptrButtonStreamMedia->isChecked();
	m_ptrButtonStreamMedia->setChecked(!bCheck);
}

void MonitorAreaUtilWindow::OnButtonRecord()
{
	bool bCheck = m_ptrButtonRecord->isChecked();
	m_ptrButtonRecord->setChecked(!bCheck);
}

void MonitorAreaUtilWindow::OnButtonStartNDI()
{
	bool bCheck = m_ptrButtonStartNDI->isChecked();
	m_ptrButtonStartNDI->setChecked(!bCheck);
}

void MonitorAreaUtilWindow::OnBtnToTheLeft()
{
	bool bCheck = m_ptrBtnToTheLeft->isChecked();
	m_ptrBtnToTheLeft->setChecked(!bCheck);
}
void MonitorAreaUtilWindow::OnBtnToTheRight()
{
	bool bCheck = m_ptrBtnToTheRight->isChecked();
	m_ptrBtnToTheRight->setChecked(!bCheck);
}
void MonitorAreaUtilWindow::OnBtnCirrusLeaf()
{
	bool bCheck = m_ptrBtnCirrusLeaf->isChecked();
	m_ptrBtnCirrusLeaf->setChecked(!bCheck);
}
void MonitorAreaUtilWindow::OnBtnDrawRight()
{
	bool bCheck = m_ptrBtnDrawRight->isChecked();
	m_ptrBtnDrawRight->setChecked(!bCheck);
}
void MonitorAreaUtilWindow::OnBtnFadeInFadeOut()
{
	bool bCheck = m_ptrBtnFadeInFadeOut->isChecked();
	m_ptrBtnFadeInFadeOut->setChecked(!bCheck);
}

void MonitorAreaUtilWindow::OnBtnPushLeft()
{
	bool bCheck = m_ptrBtnPushLeft->isChecked();
	m_ptrBtnPushLeft->setChecked(!bCheck);
}
void MonitorAreaUtilWindow::OnBtnRightRub()
{
	bool bCheck = m_ptrBtnRightRub->isChecked();
	m_ptrBtnRightRub->setChecked(!bCheck);
}
void MonitorAreaUtilWindow::OnBtnCircularRubIn()
{
	bool bCheck = m_ptrBtnCircularRubIn->isChecked();
	m_ptrBtnCircularRubIn->setChecked(!bCheck);
}
void MonitorAreaUtilWindow::OnBtnBurn()
{
	bool bCheck = m_ptrBtnBurn->isChecked();
	m_ptrBtnBurn->setChecked(!bCheck);
}

void MonitorAreaUtilWindow::OnBtnDipToBlack()
{
	bool bCheck = m_ptrBtnDipToBlack->isChecked();
	m_ptrBtnDipToBlack->setChecked(!bCheck);
}
 
void MonitorAreaUtilWindow::resizeEvent(QResizeEvent* pEvent)
{
	int iWidth = this->width();
	int iHeight = this->height();

	if (m_ptrPreviewMonitorWindow)
	{
		m_ptrPreviewMonitorWindow->setGeometry(0, 0, iWidth / 2 - 5, iHeight - 98);
		m_ptrPreviewMonitorWindow->move(0, 0);
	}

	if (m_ptrMainMonitorWindow)
	{
		m_ptrMainMonitorWindow->setGeometry(0, 0, iWidth / 2 - 5, iHeight - 98);
		m_ptrMainMonitorWindow->move(iWidth / 2, 0);
	}

 
	LayOut720p();
 


	QWidget::resizeEvent(pEvent);
}

 void  MonitorAreaUtilWindow::LayOut720p() 
{
	int iWidth = this->width();
	int iHeight = this->height();

	int iWidth1	= iWidth / 2;
	int iHeight1	= iHeight / 2;
	  

#if PIX_1080p
	if (m_ptrLabelLogo)
	{
		m_ptrLabelLogo->setGeometry(0, 0, 250, 40);
		m_ptrLabelLogo->move(0, iHeight - 90);
	}

	if (m_ptrLabelOutPut)
	{
		m_ptrLabelOutPut->setGeometry(0, 0, 55, 40);
		m_ptrLabelOutPut->move(iWidth1 - 100, iHeight - 90);
	}

#else
	if (m_ptrLabelLogo)
	{
		m_ptrLabelLogo->setGeometry(0, 0, 200, 40);
		m_ptrLabelLogo->move(0, iHeight - 90);
	}

	if (m_ptrLabelOutPut)
	{
		m_ptrLabelOutPut->setGeometry(0, 0, 50, 40);
		m_ptrLabelOutPut->move(iWidth1 - 95, iHeight - 90);
	}
#endif

	//-------------------------------------------------

 

	if (m_ptrButtonScreen)
	{
		m_ptrButtonScreen->setGeometry(0, 0, 40, 40);
		m_ptrButtonScreen->move(iWidth1- 45, iHeight - 90);
	}

	//-------------------------------------------------

	int iPrevWidth = (iWidth1 -10) / 6;

	if (m_ptrButtonLOGO1)
	{
		m_ptrButtonLOGO1->setGeometry(0, 0, iPrevWidth, 45);
		m_ptrButtonLOGO1->move(0, iHeight - 45);
	}

	if (m_ptrButtonLOGO2)
	{
		m_ptrButtonLOGO2->setGeometry(0, 0, iPrevWidth, 45);
		m_ptrButtonLOGO2->move(iPrevWidth+1, iHeight - 45);
	}

	if (m_ptrButtonClock)
	{
		m_ptrButtonClock->setGeometry(0, 0, iPrevWidth, 45);
		m_ptrButtonClock->move(iPrevWidth*2+2, iHeight - 45);
	} 

	//-------------------------------------------------
	if (m_ptrButtonRecord)
	{
		m_ptrButtonRecord->setGeometry(0, 0, iPrevWidth, 45);
		m_ptrButtonRecord->move(iPrevWidth*3 + 8, iHeight - 45);
	}
	 
	if (m_ptrButtonStreamMedia)
	{
		m_ptrButtonStreamMedia->setGeometry(0, 0, iPrevWidth, 45);
		m_ptrButtonStreamMedia->move(iPrevWidth*4 + 9, iHeight - 45);
	}

	if (m_ptrButtonStartNDI)
	{
		m_ptrButtonStartNDI->setGeometry(0, 0, iPrevWidth, 45);
		m_ptrButtonStartNDI->move(iPrevWidth*5+10, iHeight - 45);
	}
	int iPrev = 0;
	//-------------------------------------------------
#if PIX_1080p
	iPrev = iPrevWidth - 20;
	if (m_ptrBtnToTheLeft)
	{
		m_ptrBtnToTheLeft->setGeometry(0, 0, iPrev, 45);
		m_ptrBtnToTheLeft->move(iWidth1, iHeight - 91);
	}

	if (m_ptrBtnToTheRight)
	{
		m_ptrBtnToTheRight->setGeometry(0, 0, iPrev, 45);
		m_ptrBtnToTheRight->move(iWidth1 + iPrev + 1, iHeight - 91);
	}

	if (m_ptrBtnCirrusLeaf)
	{
		m_ptrBtnCirrusLeaf->setGeometry(0, 0, iPrev, 45);
		m_ptrBtnCirrusLeaf->move(iWidth1 + iPrev * 2 + 2, iHeight - 91);
	}

	if (m_ptrBtnDrawRight)
	{
		m_ptrBtnDrawRight->setGeometry(0, 0, iPrev, 45);
		m_ptrBtnDrawRight->move(iWidth1 + iPrev * 3 + 3, iHeight - 91);
	}

	if (m_ptrBtnFadeInFadeOut)
	{
		m_ptrBtnFadeInFadeOut->setGeometry(0, 0, iPrev, 45);
		m_ptrBtnFadeInFadeOut->move(iWidth1 + iPrev * 4 + 4, iHeight - 91);
	}

	//-------------------------------------------------

	if (m_ptrBtnPushLeft)
	{
		m_ptrBtnPushLeft->setGeometry(0, 0, iPrev, 45);
		m_ptrBtnPushLeft->move(iWidth1, iHeight - 45);
	}

	if (m_ptrBtnRightRub)
	{
		m_ptrBtnRightRub->setGeometry(0, 0, iPrev, 45);
		m_ptrBtnRightRub->move(iWidth1 + iPrev + 1, iHeight - 45);
	}

	if (m_ptrBtnCircularRubIn)
	{
		m_ptrBtnCircularRubIn->setGeometry(0, 0, iPrev, 45);
		m_ptrBtnCircularRubIn->move(iWidth1 + iPrev * 2 + 2, iHeight - 45);
	}

	if (m_ptrBtnBurn)
	{
		m_ptrBtnBurn->setGeometry(0, 0, iPrev, 45);
		m_ptrBtnBurn->move(iWidth1 + iPrev * 3 + 3, iHeight - 45);
	}

	if (m_ptrBtnDipToBlack)
	{
		m_ptrBtnDipToBlack->setGeometry(0, 0, iPrev, 45);
		m_ptrBtnDipToBlack->move(iWidth1 + iPrev * 4 + 4, iHeight - 45);
	}

	//-----------------------------------------------
 		if (m_ptrVSliderEx)
		{
			m_ptrVSliderEx->setGeometry(0, 0, 21, 91);
			m_ptrVSliderEx->move(iWidth1 + iPrev * 5 + 5, iHeight - 91);
		}

	if (m_ptrHSliderEx)
	{
		m_ptrHSliderEx->setGeometry(0, 0, iPrev * 3 - 10, 45);
		m_ptrHSliderEx->move(iWidth1 + iPrev * 5 + 27, iHeight - 91);
	}

	//-----------------------------------------------

 
	if (m_ptrVSliderEx)
	{
		m_ptrVSliderEx->setGeometry(0, 0, 21, 91);
		m_ptrVSliderEx->move(iWidth1 + iPrev * 5 + 5, iHeight - 91);
	}

	if (m_ptrHSliderEx)
	{
		m_ptrHSliderEx->setGeometry(0, 0, iPrev * 3 - 10, 45);
		m_ptrHSliderEx->move(iWidth1 + iPrev * 5 + 27, iHeight - 91);
	}

	//-----------------------------------------------

	int iWidth3 = (iPrev * 3) / 2 - 5;

	if (m_ptrBtnHardSwitch)
	{
		m_ptrBtnHardSwitch->setGeometry(0, 0, iWidth3, 45);
		m_ptrBtnHardSwitch->move(iWidth - iWidth3 * 2 - 6, iHeight - 45);
	}

	if (m_ptrBtnAutoSwitch)
	{
		m_ptrBtnAutoSwitch->setGeometry(0, 0, iWidth3, 45);
		m_ptrBtnAutoSwitch->move(iWidth - iWidth3 - 5, iHeight - 45);
	}


#else
	
	iPrev = 45;
	if (m_ptrBtnToTheLeft)
	{
		m_ptrBtnToTheLeft->setGeometry(0, 0, 45, 45);
		m_ptrBtnToTheLeft->move(iWidth1, iHeight - 91);
	}

	if (m_ptrBtnToTheRight)
	{
		m_ptrBtnToTheRight->setGeometry(0, 0, 45, 45);
		m_ptrBtnToTheRight->move(iWidth1 + iPrev + 1, iHeight - 91);
	}

	if (m_ptrBtnCirrusLeaf)
	{
		m_ptrBtnCirrusLeaf->setGeometry(0, 0, 45, 45);
		m_ptrBtnCirrusLeaf->move(iWidth1 + iPrev * 2 + 2, iHeight - 91);
	}

	if (m_ptrBtnDrawRight)
	{
		m_ptrBtnDrawRight->setGeometry(0, 0, 45, 45);
		m_ptrBtnDrawRight->move(iWidth1 + iPrev * 3 + 3, iHeight - 91);
	}

	if (m_ptrBtnFadeInFadeOut)
	{
		m_ptrBtnFadeInFadeOut->setGeometry(0, 0, 45, 45);
		m_ptrBtnFadeInFadeOut->move(iWidth1 + iPrev * 4 + 4, iHeight - 91);
	}

	//-------------------------------------------------

	if (m_ptrBtnPushLeft)
	{
		m_ptrBtnPushLeft->setGeometry(0, 0, 45, 45);
		m_ptrBtnPushLeft->move(iWidth1, iHeight - 45);
	}

	if (m_ptrBtnRightRub)
	{
		m_ptrBtnRightRub->setGeometry(0, 0, 45, 45);
		m_ptrBtnRightRub->move(iWidth1 + iPrev + 1, iHeight - 45);
	}

	if (m_ptrBtnCircularRubIn)
	{
		m_ptrBtnCircularRubIn->setGeometry(0, 0, 45, 45);
		m_ptrBtnCircularRubIn->move(iWidth1 + iPrev * 2 + 2, iHeight - 45);
	}

	if (m_ptrBtnBurn)
	{
		m_ptrBtnBurn->setGeometry(0, 0, 45, 45);
		m_ptrBtnBurn->move(iWidth1 + iPrev * 3 + 3, iHeight - 45);
	}

	if (m_ptrBtnDipToBlack)
	{
		m_ptrBtnDipToBlack->setGeometry(0, 0, 45, 45);
		m_ptrBtnDipToBlack->move(iWidth1 + iPrev * 4 + 4, iHeight - 45);
	}

	//-----------------------------------------------

	if (m_ptrBtnHardSwitch)
	{
		m_ptrBtnHardSwitch->setGeometry(0, 0, 45, 45);
		m_ptrBtnHardSwitch->move(iWidth - iPrev * 2 - 6, iHeight - 45);
	}

	if (m_ptrBtnAutoSwitch)
	{
		m_ptrBtnAutoSwitch->setGeometry(0, 0, 45, 45);
		m_ptrBtnAutoSwitch->move(iWidth - iPrev - 5, iHeight - 45);
	}


	//-----------------------------------------------

	if (m_ptrVSliderEx)
	{
		m_ptrVSliderEx->setGeometry(0, 0, 12, 91);
		m_ptrVSliderEx->move(iWidth - iPrev * 2 - 19, iHeight - 91);
	}

	if (m_ptrHSliderEx)
	{
		m_ptrHSliderEx->setGeometry(0, 0, iPrev * 2 + 1, 45);
		m_ptrHSliderEx->move(iWidth - iPrev * 2 - 6, iHeight - 91);
	}

#endif
	
	

}

void MonitorAreaUtilWindow::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(30, 30, 30));
	painter.setPen(QColor(210, 210, 210));
}

QString MonitorAreaUtilWindow::GetRunTimeString()
{
	char szBuffer[1024];
	memset(szBuffer, 0, 1024);

	std::string  strWeekDay = "";
	 

	sprintf(szBuffer, "% 02d:%02d:%02d", m_iComputerInfo.m_iCurSystemTime.GetHour(),
		m_iComputerInfo.m_iCurSystemTime.GetMinute(), m_iComputerInfo.m_iCurSystemTime.GetSecond());

	std::string strSystem = szBuffer;
	QString  strText = QString(QString::fromLocal8Bit(strSystem.c_str()));

	return strText;
}
