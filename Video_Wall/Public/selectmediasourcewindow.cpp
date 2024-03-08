#include "selectmediasourcewindow.h"

#include "../headfiledefine.h"
#include "../globaldefine.h"
#include "../Controls/flatuiex.h"
#include "../Controls/buttonex.h"
#include "../Controls/navlabelex.h"
#include "../Controls/tabwidgetex.h"

#include "../BottomArea/playerlistwindow.h"
#include "../BottomArea/mediasettingwindow.h"

#include "../runtimedata.h"
 
SelectMediaSourceWindow::SelectMediaSourceWindow(QWidget *parent)
	: QDialog(parent)
{
#if PIX_1080p
	this->resize(500, 400);
 #else
	this->resize(450, 350);
 #endif

	Qt::WindowFlags m_flags = windowFlags();

	setWindowFlags(m_flags | Qt::WindowStaysOnTopHint);

	m_iNormalBgColor = QColor(50, 50, 50);
	m_iHoverBgColor = QColor(50, 50, 50);
	m_iCheckBgColor = QColor(50, 50, 50);
	m_iNormalFrameColor = QColor(30, 30, 30);

	m_iNormalTextColor = QColor(255, 255, 255);
	m_iHoverTextColor = QColor(255, 255, 255);
	m_iCheckTextColor = QColor(255, 255, 255);
	 
	//设置标题栏隐藏
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

	InitUI();
	InitConnect();
}

SelectMediaSourceWindow::~SelectMediaSourceWindow()
{
}
 
void SelectMediaSourceWindow::InitConnect()
{
	connect(m_ptrOK.get(), SIGNAL(clicked()), this, SLOT(OnButtonOK()));
	connect(m_ptrCancel.get(), SIGNAL(clicked()), this, SLOT(OnButtonCancel()));
	connect(m_ptrCloseBtn.get(), SIGNAL(clicked()), this, SLOT(OnButtonClose()));
	
	connect(m_ptrTabWidget.get(), SIGNAL(AddPlayListPage(QString)), this, SLOT(AddPlayListPage(QString)), Qt::QueuedConnection);
	connect(m_ptrTabWidget.get(), SIGNAL(DeletePlayListPage(QString)), this, SLOT(DeletePlayListPage(QString)), Qt::QueuedConnection);

	connect(m_ptrTabWidget.get(), SIGNAL(AddPageDataNotify(QString, QString)), this, SLOT(AddPageDataNotify(QString, QString)), Qt::QueuedConnection);
	connect(m_ptrTabWidget.get(), SIGNAL(DeletePageDataNotify(  QString, QString)), this, SLOT(DeletePageDataNotify( QString, QString)), Qt::QueuedConnection);
 }

void SelectMediaSourceWindow::InitUI()
{
 	InitButtons();
	InitLabels();
 	InitTab();
}

void SelectMediaSourceWindow::InitTab()
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

void SelectMediaSourceWindow::InitButtons()
 {
	m_ptrOK.reset(new ButtonEx(this));
	m_ptrCancel.reset(new ButtonEx(this));
	m_ptrCloseBtn.reset(new ButtonEx(this));

	m_listButtons << m_ptrOK.get() << m_ptrCancel.get() << m_ptrCloseBtn.get();

	bool bClose = false;

	for (int iIndex = 0; iIndex < m_listButtons.count(); iIndex++)
	{
		ButtonEx* pButtonEx = m_listButtons.at(iIndex);
		pButtonEx->setPaddingLeft(0);
		pButtonEx->setShowLine(false);
		pButtonEx->setShowIcon(false);
		pButtonEx->setIconSpace(0);
		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);

		if (pButtonEx == m_ptrOK.get())
		{
			bClose = false;
			m_ptrOK->setText(QString::fromLocal8Bit("确 定"));
		}
		else 	if (pButtonEx == m_ptrCancel.get())
		{
			bClose = false;

			m_ptrCancel->setText(QString::fromLocal8Bit("取 消"));
		}
		if (pButtonEx == m_ptrCloseBtn.get())
		{
			bClose = true;
			m_ptrCloseBtn->setText(QString::fromLocal8Bit("X"));
		}

		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);
		pButtonEx->setFont(QFont("Microsoft YaHei", 10, 75));


		if (bClose)
		{
			pButtonEx->setHoverBgColor(QColor(50, 50, 50));
			pButtonEx->setCheckBgColor(QColor(50, 50, 50));
			pButtonEx->setNormalBgColor(QColor(50, 50, 50));
			pButtonEx->setHoverTextColor(QColor(239, 98, 234));
			pButtonEx->setNormalFrameColor(QColor(50, 50, 50));
		}
		else
		{
			pButtonEx->setHoverBgColor(QColor(239, 98, 234));
			pButtonEx->setCheckBgColor(QColor(239, 98, 234));
			pButtonEx->setNormalBgColor(/*m_iNormalBgColor*/QColor(30, 30, 30));

			pButtonEx->setHoverTextColor(m_iHoverTextColor);
			pButtonEx->setNormalFrameColor(/*m_iNormalFrameColor*/QColor(50, 50, 50));
		}

		pButtonEx->setNormalTextColor(QColor(200, 200, 200));
		pButtonEx->setCheckTextColor(m_iCheckTextColor);
	}
}

void SelectMediaSourceWindow::InitLabels()
{
	m_ptrTitle.reset(new NavLabelEx(this));

	QFont font1("Microsoft YaHei", 10, 75);
	m_ptrTitle->setFont(font1);

	m_ptrTitle->setTextAlign(NavLabelEx::TextAlign_Left);
	m_ptrTitle->setShowIcon(false);
	m_ptrTitle->setIconSize(QSize(0, 0));
	m_ptrTitle->setText(QString::fromLocal8Bit("选择媒体源"));
 	m_ptrTitle->setNormalBgColor(QColor(50, 50, 50));
	m_ptrTitle->setNormalTextColor(QColor(220, 220, 220));
 }
 
void SelectMediaSourceWindow::AddPlayListPage(QString strPageName)
{
 	 OnGetRuntimeData().OnGetPlayerListWindow()->AddPlayListPageNotify(strPageName);
}

void SelectMediaSourceWindow::DeletePlayListPage(QString strPageName)
{
	OnGetRuntimeData().OnGetPlayerListWindow()->DeletePlayListPageNotify(strPageName);
}

void SelectMediaSourceWindow::AddPageDataNotify(  QString strName, QString strPath)
{
	MEDIA_SELECT_TYPE iType = m_ptrTabWidget->OnGetMediaSelectType();
 	OnGetRuntimeData().OnGetMediaSettingWindow()->AddPageData(iType, strName, strPath);
  }

void SelectMediaSourceWindow::DeletePageDataNotify( QString strName, QString strPath)
{
	MEDIA_SELECT_TYPE iType = m_ptrTabWidget->OnGetMediaSelectType();
 	OnGetRuntimeData().OnGetMediaSettingWindow()->DeletePageData(iType, strName, strPath);
 }
 
void SelectMediaSourceWindow::AddPageData(MEDIA_SELECT_TYPE iMediaType, QString strName, QString strPath)
{
	if (m_ptrTabWidget)
		m_ptrTabWidget->AddPageData(iMediaType, strName, strPath);
}

void SelectMediaSourceWindow::DeletePageData(MEDIA_SELECT_TYPE iMediaType, QString strName, QString strPath)
{
	if (m_ptrTabWidget)
		m_ptrTabWidget->DeletePageData(iMediaType, strName, strPath);
}

void SelectMediaSourceWindow::OnButtonOK()
{
	close();
 }

void SelectMediaSourceWindow::OnButtonCancel()
{
	close();
}

void SelectMediaSourceWindow::OnButtonClose()
{
	close();
}
 
void SelectMediaSourceWindow::resizeEvent(QResizeEvent *pEvent)
{
	int iWidth = this->width();
	int iHeight = this->height();

	if (m_ptrTitle)
	{
		m_ptrTitle->setGeometry(0, 0, 150, 25);
		m_ptrTitle->move(1, 0);
	}

	if (m_ptrCloseBtn)
	{
		m_ptrCloseBtn->setGeometry(0, 0, 25, 25);
		m_ptrCloseBtn->move(iWidth - 27, 0);
	}


	if (m_ptrOK)
	{
		m_ptrOK->setGeometry(0, 0, 75, 25);
		m_ptrOK->move(iWidth / 2 - 75, iHeight - 30);
	}

	if (m_ptrCancel)
	{
		m_ptrCancel->setGeometry(0, 0, 75, 25);
		m_ptrCancel->move(iWidth / 2 + 50, iHeight - 30);
	}
 
	if (m_ptrTabWidget)
	{
		m_ptrTabWidget->setGeometry(0, 0, iWidth, iHeight - 60);
		m_ptrTabWidget->move(0, 25);
	}
 }

void SelectMediaSourceWindow::paintEvent(QPaintEvent* pEvent)
 {
	QPainter painter(this);
 
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(50, 50, 50));
	painter.setPen(QColor(210, 210, 210));

	painter.setClipRect(0, 0, width(), height());
	painter.fillRect(QRectF(6, 25, width() - 12, height() - 58), QColor(30, 30, 30));
}

void SelectMediaSourceWindow::mousePressEvent(QMouseEvent * pEvent)
 {
	//只能是鼠标左键移动和改变大小
	if (pEvent->button() == Qt::LeftButton)
		m_bMousePress = true;

	//窗口移动距离
	m_iMovePoint = pEvent->globalPos() - pos();
}

void SelectMediaSourceWindow::mouseReleaseEvent(QMouseEvent*pEvent)
{
	m_bMousePress = false;
}
 
void SelectMediaSourceWindow::mouseMoveEvent(QMouseEvent *pEvent)
{
	//移动窗口
	if (m_bMousePress)
	{
		QPoint move_pos = pEvent->globalPos();
		move(move_pos - m_iMovePoint);
	}
}



