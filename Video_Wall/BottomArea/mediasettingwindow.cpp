#include "mediasettingwindow.h"
#include "../headfiledefine.h"
#include "../Controls/flatuiex.h"
#include "../Controls/buttonex.h"
#include "../Controls/tabwidgetex.h"
#include "../Controls/tabpageex.h"
#include "../Controls/tabbarex.h"
#include "../runtimedata.h"
#include "../Public/selectmediasourcewindow.h"  
#include "../globaldefine.h"
#include "playerlistwindow.h"
 
MediaSettingWindow::MediaSettingWindow(QWidget *parent)
	: QWidget(parent)
	, m_ptrButton1(nullptr)
	, m_ptrButton2(nullptr)
	, m_ptrButton3(nullptr)
	, m_ptrTabBarEx(nullptr)
	, m_ptrTabWidget(nullptr)
{
	InitTAB();
	InitButtons();
	InitConnects();
}

void MediaSettingWindow::resizeEvent(QResizeEvent* pEvent)
{
	int iWidth = width();
	int iHeight = height();
	 
#if PIX_1080p 
	if (m_ptrTabWidget)
	{
		m_ptrTabWidget->setGeometry(0, 0, iWidth, iHeight - 35);
		m_ptrTabWidget->move(0, 0);
	}

	if (m_ptrButton1)
	{
		m_ptrButton1->setGeometry(0, 0, iWidth / 2 - 1, 35);
		m_ptrButton1->move(0, iHeight - 35);
	}

	if (m_ptrButton2)
	{
		m_ptrButton2->setGeometry(0, 0, 3, 20);
		m_ptrButton2->move(iWidth / 2, iHeight - 30);
	}

	if (m_ptrButton3)
	{
		m_ptrButton3->setGeometry(0, 0, iWidth / 2 - 4, 35);
		m_ptrButton3->move(iWidth / 2 + 4, iHeight - 35);
	}

#else
	if (m_ptrTabWidget)
	{
		m_ptrTabWidget->setGeometry(0, 0, iWidth, iHeight - 25);
		m_ptrTabWidget->move(0, 0);
	}

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

	QWidget::resizeEvent(pEvent);
}

MediaSettingWindow::~MediaSettingWindow()
{
}

void MediaSettingWindow::InitButtons()
{
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
			m_ptrButton1->setText(QString::fromLocal8Bit("字幕唱词"));
		}
		else if (pButtonEx == m_ptrButton2.get())
		{
			m_ptrButton2->setText(QString::fromLocal8Bit(""));
			bLabel = true;
		}
		else if (pButtonEx == m_ptrButton3.get())
		{
			bLabel = false;
			m_ptrButton3->setText(QString::fromLocal8Bit("所以媒体源设置"));
		}
		 
		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);

#if PIX_1080p 
		pButtonEx->setFont(QFont("Microsoft YaHei", 10, 75));
 #else
		pButtonEx->setFont(QFont("Microsoft YaHei", 8, 75));
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

	m_ptrButton3->setChecked(true);  // 为operatingModeGroup组设置初选项

 }

void MediaSettingWindow::InitConnects()
{
	connect(m_ptrButton1.get(), SIGNAL(clicked()), this, SLOT(OnButton1()));
	connect(m_ptrButton3.get(), SIGNAL(clicked()), this, SLOT(OnButton3()));

	connect(m_ptrTabWidget.get(), SIGNAL(AddPlayListPage(QString)), this, SLOT(AddPlayListPage(QString)), Qt::QueuedConnection);
	connect(m_ptrTabWidget.get(), SIGNAL(DeletePlayListPage(QString)), this, SLOT(DeletePlayListPage(QString)), Qt::QueuedConnection);
	 
	connect(m_ptrTabWidget.get(), SIGNAL(AddPageDataNotify(QString, QString)), this, SLOT(AddPageDataNotify(QString, QString)), Qt::QueuedConnection);
	connect(m_ptrTabWidget.get(), SIGNAL(DeletePageDataNotify(QString, QString)), this, SLOT(DeletePageDataNotify(QString, QString)), Qt::QueuedConnection);
 }
  
void MediaSettingWindow::InitTAB()
{ 
	m_ptrTabWidget.reset(new TabWidgetEx(this));
	m_ptrTabWidget->AddPage(QString::fromLocal8Bit("视频"), VOIDE);
	m_ptrTabWidget->AddPage(QString::fromLocal8Bit("图片"), PICTURE);
	m_ptrTabWidget->AddPage(QString::fromLocal8Bit("实时源"), LOCAL_STREAM);
	m_ptrTabWidget->AddPage(QString::fromLocal8Bit("IP网络流"), IP_STREAM);
	m_ptrTabWidget->AddPage(QString::fromLocal8Bit("播放列表"), PLAY_LIST);

	m_ptrTabWidget->ShowAudioEditor(false);
	FlatUIEx::Instance()->SetTabWidgetQss(m_ptrTabWidget.get(), "rgb(30,30,30)", "rgb(230,230,230)");
 }

void MediaSettingWindow::AddPlayListPage(QString strPageName)
{
	OnGetRuntimeData().OnGetPlayerListWindow()->AddPlayListPageNotify(strPageName);
}

void MediaSettingWindow::DeletePlayListPage(QString strPageName)
{
	OnGetRuntimeData().OnGetPlayerListWindow()->DeletePlayListPageNotify(strPageName);
}

void MediaSettingWindow::AddPageDataNotify(QString strName, QString strPath)
{
	MEDIA_SELECT_TYPE iType = m_ptrTabWidget->OnGetMediaSelectType();
	OnGetRuntimeData().OnGetSelectMediaSourceWindow()->AddPageData(iType, strName, strPath);
}

void MediaSettingWindow::DeletePageDataNotify(QString strName, QString strPath)
{
	MEDIA_SELECT_TYPE iType = m_ptrTabWidget->OnGetMediaSelectType();
	OnGetRuntimeData().OnGetSelectMediaSourceWindow()->DeletePageData(iType, strName, strPath);
 }

void MediaSettingWindow::AddPageData(MEDIA_SELECT_TYPE iMediaType, QString strName, QString strPath)
{
	if (m_ptrTabWidget)
		m_ptrTabWidget->AddPageData(iMediaType, strName, strPath);
}

void MediaSettingWindow::DeletePageData(MEDIA_SELECT_TYPE iMediaType, QString strName, QString strPath)
{
	if (m_ptrTabWidget)
		m_ptrTabWidget->DeletePageData(iMediaType, strName, strPath);
}
 
void  MediaSettingWindow::OnButton1()
{
	bool bCheck = m_ptrButton1->isChecked();
	m_ptrButton1->setChecked(!bCheck);
	m_ptrTabWidget->hide();

	m_ptrButton1->setCheckTextColor(QColor(239, 98, 234));
	m_ptrButton3->setNormalTextColor(QColor(250, 250, 250));
 }

void  MediaSettingWindow::OnButton3()
{
	bool bCheck = m_ptrButton3->isChecked();
	m_ptrButton3->setChecked(!bCheck);

	m_ptrTabWidget->show();


	m_ptrButton3->setCheckTextColor(QColor(239, 98, 234));
	m_ptrButton1->setNormalTextColor(QColor(250, 250, 250));
}
 

void MediaSettingWindow::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(50, 50, 50));
	painter.setPen(QColor(210, 210, 210));
}


