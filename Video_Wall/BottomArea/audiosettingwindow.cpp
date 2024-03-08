#include "audiosettingwindow.h"
#include "../headfiledefine.h"
#include "../Controls/flatuiex.h"
#include "../Controls/buttonex.h"
#include "../Controls/tabwidgetex.h"
#include "../Controls/tabpageex.h"
#include "volumecontrolwindow.h"


AudioSettingWindow::AudioSettingWindow(QWidget *parent)
	: QWidget(parent)
	, m_ptrVolumeControlWindow(nullptr)
{
	m_vecVolumeControlWindow.clear();

	InitUI();
 	InitVolumeControlWindow();
	InitConnects();
}

AudioSettingWindow::~AudioSettingWindow()
{
}

void AudioSettingWindow::InitVolumeControlWindow()
{
	for (int iIndex = 0; iIndex < CHANNEL_COUNT + 1; iIndex++)
	{
		VolumeControlWindow*	ptrWindow = nullptr;
		ptrWindow = new VolumeControlWindow(this);
		ptrWindow->SetChannelIndex(iIndex + 1);
		ptrWindow->show();
		m_vecVolumeControlWindow.push_back(ptrWindow);
	}
}

void AudioSettingWindow::InitUI()
{
	m_ptrTabWidget.reset(new TabWidgetEx(this));
	 
	// 	m_ptrTabWidget->AddPage(QString::fromLocal8Bit("已使用"), );
	// 	m_ptrTabWidget->AddPage(QString::fromLocal8Bit("溶解"), );
	// 	m_ptrTabWidget->AddPage(QString::fromLocal8Bit("滑块"), );
	// 	m_ptrTabWidget->AddPage(QString::fromLocal8Bit("擦除"), );
	// 	m_ptrTabWidget->AddPage(QString::fromLocal8Bit("挤压"), );
	// 	m_ptrTabWidget->AddPage(QString(QString::fromLocal8Bit("特殊"), );


	m_ptrTabWidget->ShowAudioEditor(true);

	FlatUIEx::Instance()->SetTabWidgetQss(m_ptrTabWidget.get(), "rgb(30,30,30)", "rgb(230,230,230)");

	m_ptrTabWidget->hide();

	//---------------------------------------

	m_ptrButton1.reset(new ButtonEx(this));
	m_ptrButton2.reset(new ButtonEx(this));
	m_ptrButton3.reset(new ButtonEx(this));

	m_listButtons << m_ptrButton1.get() << m_ptrButton2.get() << m_ptrButton3.get();

	bool bLabel = false;

	for (int iIndex = 0; iIndex < m_listButtons.count(); iIndex++)
	{
		ButtonEx* pButtonEx = m_listButtons.at(iIndex);
		pButtonEx->setPaddingLeft(0);
		pButtonEx->setShowLine(false);
		pButtonEx->setShowIcon(false);
		pButtonEx->setIconSpace(0);
		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);

		if (pButtonEx == m_ptrButton1.get())
		{
			bLabel = false;
			m_ptrButton1->setText(QString::fromLocal8Bit("音频"));
		}
		else if (pButtonEx == m_ptrButton2.get())
		{
			m_ptrButton2->setText(QString::fromLocal8Bit(""));
			bLabel = true;
		}
		else if (pButtonEx == m_ptrButton3.get())
		{
			bLabel = false;
			m_ptrButton3->setText(QString::fromLocal8Bit("场景过渡"));
		}

		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);

#if PIX_1080p 
		pButtonEx->setFont(QFont("Microsoft YaHei", 10, 65));
#else
		pButtonEx->setFont(QFont("Microsoft YaHei", 8, 65));
#endif

		if (bLabel)
		{
			pButtonEx->setHoverBgColor(QColor(30, 30, 30));
			pButtonEx->setCheckBgColor(QColor(30, 30, 30));
			pButtonEx->setNormalBgColor(QColor(30, 30, 30));
			pButtonEx->setNormalFrameColor(QColor(30, 30, 30));
		}
		else
		{
			pButtonEx->setHoverBgColor(QColor(50, 50, 50));
			pButtonEx->setCheckBgColor(QColor(50, 50, 50));

			pButtonEx->setNormalBgColor(QColor(50, 50, 50));
			pButtonEx->setNormalFrameColor(QColor(50, 50, 50));

			pButtonEx->setNormalTextColor(QColor(230, 230, 230));
			pButtonEx->setHoverTextColor(QColor(255, 255, 255));
			pButtonEx->setCheckTextColor(QColor(239, 98, 234));
		}
	}

	m_ptrSwitchGroup.reset(new QButtonGroup(this));

	m_ptrSwitchGroup->addButton(m_ptrButton1.get());
	m_ptrSwitchGroup->addButton(m_ptrButton3.get());

	m_ptrButton1->setChecked(true);  // 为operatingModeGroup组设置初选项
}

void AudioSettingWindow::InitConnects()
{
	connect(m_ptrButton1.get(), SIGNAL(clicked()), this, SLOT(OnButton1()));
	connect(m_ptrButton3.get(), SIGNAL(clicked()), this, SLOT(OnButton3()));
}

void  AudioSettingWindow::OnButton1()
{
	bool bCheck = m_ptrButton1->isChecked();
	m_ptrButton1->setChecked(!bCheck);
	m_ptrTabWidget->hide();

	SetVolumeControlWindowState(true);
	m_ptrButton1->setCheckTextColor(QColor(239, 98, 234));
	m_ptrButton3->setNormalTextColor(QColor(250, 250, 250));
}

void  AudioSettingWindow::OnButton3()
{
	bool bCheck = m_ptrButton3->isChecked();
	m_ptrButton3->setChecked(!bCheck);
	m_ptrTabWidget->show();
	SetVolumeControlWindowState(false);

	m_ptrButton3->setCheckTextColor(QColor(239, 98, 234));
	m_ptrButton1->setNormalTextColor(QColor(250, 250, 250));
}

void AudioSettingWindow::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);

#if PIX_1080p
	painter.setClipRect(0, 0, width(), height());
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(50, 50, 50));
 	painter.setClipRect(0, 0, width(), height());
	painter.fillRect(QRectF(5, 30, width() - 10, height() - 65), QColor(30, 30, 30));
#else
	painter.setClipRect(0, 0, width(), height());
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(50, 50, 50));
 	painter.setClipRect(0, 0, width(), height());
	painter.fillRect(QRectF(5, 30, width() - 10, height() - 55), QColor(30, 30, 30));
#endif
	 
}

void AudioSettingWindow::resizeEvent(QResizeEvent* pEvent)
{
	QWidget::resizeEvent(pEvent);

	int iWidth = width();
	int iHeight = height();

	if (m_ptrTabWidget)
	{
		m_ptrTabWidget->setGeometry(0, 0, iWidth, iHeight - 25);
		m_ptrTabWidget->move(0, 0);
 	}

#if  PIX_1080p 
	if (m_ptrButton1)
	{
		m_ptrButton1->setGeometry(0, 0, iWidth / 2 - 1,35);
		m_ptrButton1->move(0, iHeight - 35);
 	}

	if (m_ptrButton2)
	{
		m_ptrButton2->setGeometry(0, 0, 2, 20);
		m_ptrButton2->move(iWidth / 2, iHeight - 30);
 	}

	if (m_ptrButton3)
	{
		m_ptrButton3->setGeometry(0, 0, iWidth / 2 - 4, 35);
		m_ptrButton3->move(iWidth / 2 + 4, iHeight - 35);
 	}
 #else
	if (m_ptrButton1)
	{
		m_ptrButton1->setGeometry(0, 0, iWidth / 2 - 1, 25);
		m_ptrButton1->move(0, iHeight - 25);
	}

	if (m_ptrButton2)
	{
		m_ptrButton2->setGeometry(0, 0, 2, 10);
		m_ptrButton2->move(iWidth / 2, iHeight - 20);
	}
	if (m_ptrButton3)
	{
		m_ptrButton3->setGeometry(0, 0, iWidth / 2 - 4, 25);
		m_ptrButton3->move(iWidth / 2 + 4, iHeight - 25);
	}
#endif


	//-------------------------------------

	int iGrap = 1;


#if PIX_1080p
	int iColWidth = (iWidth - 10) / 13;
#else
	int iColWidth = (iWidth - 8) / 10;
#endif

	int iSize = m_vecVolumeControlWindow.size();

	for (int iIndex = 0; iIndex < iSize; iIndex++)
	{
		VolumeControlWindow*	 pCtrlWnd = nullptr;

		pCtrlWnd = m_vecVolumeControlWindow[iIndex];
		if (pCtrlWnd)
		{
#if  PIX_1080p 
			pCtrlWnd->setGeometry(0, 0, iColWidth, iHeight - 71);
			pCtrlWnd->move(8 + iIndex * iColWidth, 33);
#else
			pCtrlWnd->setGeometry(0, 0, iColWidth, iHeight - 61);
			pCtrlWnd->move(8 + iIndex * iColWidth, 33);
#endif
		}
	}

	this->update();
}
 
void AudioSettingWindow::SetVolumeControlWindowState(bool bShow)
{
	int iSize = m_vecVolumeControlWindow.size();

	for (int iIndex = 0; iIndex < iSize; iIndex++)
	{
		VolumeControlWindow*	 pCtrlWnd = nullptr;

		pCtrlWnd = m_vecVolumeControlWindow[iIndex];
		if (pCtrlWnd)
		{
			if (bShow)
			{
				pCtrlWnd->show();
			}
			else
			{
				pCtrlWnd->hide();
			}
		}
	}
}
