#include "localmediastreamwindow.h"
#include "../globaldefine.h"

#include "../headfiledefine.h"
#include "../Controls/flatuiex.h"
#include "../Controls/buttonex.h"
#include "../Controls/navlabelex.h"
#include "../Controls/localstreamlistex.h"
 #include "../Controls/localstreamlistitemex.h"
 
LocalMediaStreamWindow::LocalMediaStreamWindow(QWidget *parent)
	: QDialog(parent)
	, m_strDevceName("")
{
#if PIX_1080p
	this->resize(450, 400);
 #else
	this->resize(450, 350);
 #endif

 
	m_strExePath = QCoreApplication::applicationDirPath();

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

LocalMediaStreamWindow::~LocalMediaStreamWindow()
{
}

void 	LocalMediaStreamWindow::InitConnect()
{
	connect(m_ptrOK.get(), SIGNAL(clicked()), this, SLOT(OnButtonOK()));
	connect(m_ptrCancel.get(), SIGNAL(clicked()), this, SLOT(OnButtonCancel()));
	connect(m_ptrCloseBtn.get(), SIGNAL(clicked()), this, SLOT(OnButtonClose()));
	connect(m_ptrCloseBtn.get(), SIGNAL(clicked()), this, SLOT(OnButtonClose()));
 
	connect(m_ptrLocalStreamListEx.get(), SIGNAL(OnLocalStreamListNotify(LocalStreamListItemEx*)), this, SLOT(OnLocalStreamListNotify(LocalStreamListItemEx*)), Qt::QueuedConnection);
 }

void LocalMediaStreamWindow::OnLocalStreamListNotify(LocalStreamListItemEx* pListItem)
{
	m_strDevceName = pListItem->m_strItemName;
 }
 
void LocalMediaStreamWindow::InitUI()
{
	InitButtons();
	InitLabels();
	InitListEx();
	InitData();
 }

void LocalMediaStreamWindow::InitData()
{
 	//------------------------------------------------	
	
	LocalStreamListItemEx* pUserListItem1 = new LocalStreamListItemEx;
	pUserListItem1->m_strGroupName = QString(QString::fromLocal8Bit("系统视频源"));
 
	pUserListItem1->m_iItemType = ItemType_Group;
	pUserListItem1->m_strItemName = QString(QString::fromLocal8Bit("xx"));
 	m_ptrLocalStreamListEx->OnInsertUserItem(pUserListItem1);
	
	//---------------------
	LocalStreamListItemEx*  pVideo1 = new LocalStreamListItemEx;

	pVideo1->m_strGroupName = QString(QString::fromLocal8Bit("系统视频源"));
	pVideo1->m_iItemType = ItemType_Child;
	pVideo1->m_strItemName = QString::fromLocal8Bit("USB2.0 PC CAMERA");
	m_ptrLocalStreamListEx->OnInsertUserItem(pVideo1);
  
	//------------------------------------------------	

	LocalStreamListItemEx* pUserListItem2 = new LocalStreamListItemEx;
	pUserListItem2->m_strGroupName = QString(QString::fromLocal8Bit("系统音频源"));

	pUserListItem2->m_iItemType = ItemType_Group;
	pUserListItem2->m_strItemName = QString(QString::fromLocal8Bit(" "));
	m_ptrLocalStreamListEx->OnInsertUserItem(pUserListItem2);


	//---------------------
	LocalStreamListItemEx*  pAudio1 = new LocalStreamListItemEx;

	pAudio1->m_strGroupName = QString(QString::fromLocal8Bit("系统音频源"));
	pAudio1->m_iItemType = ItemType_Child;
	pAudio1->m_strItemName = QString::fromLocal8Bit("麦克风(Realtek High Definition Audio)");
	m_ptrLocalStreamListEx->OnInsertUserItem(pAudio1);

	//---------------------
	LocalStreamListItemEx*  pAudio2 = new LocalStreamListItemEx;

	pAudio2->m_strGroupName = QString(QString::fromLocal8Bit("系统音频源"));
	pAudio2->m_iItemType = ItemType_Child;
	pAudio2->m_strItemName = QString::fromLocal8Bit("麦克风(2-USB2.0 MIC)");
	m_ptrLocalStreamListEx->OnInsertUserItem(pAudio2);
	 
	//------------------------------------------------	

	LocalStreamListItemEx* pUserListItem3 = new LocalStreamListItemEx;
	pUserListItem3->m_strGroupName = QString(QString::fromLocal8Bit("DirectShow视频源"));

	pUserListItem3->m_iItemType = ItemType_Group;
	pUserListItem3->m_strItemName = QString(QString::fromLocal8Bit("xx"));
	m_ptrLocalStreamListEx->OnInsertUserItem(pUserListItem3);
 
	//---------------------
	LocalStreamListItemEx*  pVideo2 = new LocalStreamListItemEx;

	pVideo2->m_strGroupName = QString(QString::fromLocal8Bit("DirectShow视频源"));
	pVideo2->m_iItemType = ItemType_Child;
	pVideo2->m_strItemName = QString::fromLocal8Bit("USB2.0 PC CAMERA");
	m_ptrLocalStreamListEx->OnInsertUserItem(pVideo2);
	 
	//------------------------------------------------	

	LocalStreamListItemEx* pUserListItem4 = new LocalStreamListItemEx;
	pUserListItem4->m_strGroupName = QString(QString::fromLocal8Bit("DirectShow音频源"));

	pUserListItem4->m_iItemType = ItemType_Group;
	pUserListItem4->m_strItemName = QString(QString::fromLocal8Bit("xx"));
	m_ptrLocalStreamListEx->OnInsertUserItem(pUserListItem4);
	 
	//---------------------
	LocalStreamListItemEx*  pAudio3 = new LocalStreamListItemEx;

	pAudio3->m_strGroupName = QString(QString::fromLocal8Bit("DirectShow音频源"));
	pAudio3->m_iItemType = ItemType_Child;
	pAudio3->m_strItemName = QString::fromLocal8Bit("麦克风(Realtek High Definition Audio)");
	m_ptrLocalStreamListEx->OnInsertUserItem(pAudio3);

	//---------------------
	LocalStreamListItemEx*  pAudio4 = new LocalStreamListItemEx;

	pAudio4->m_strGroupName = QString(QString::fromLocal8Bit("DirectShow音频源"));
	pAudio4->m_iItemType = ItemType_Child;
	pAudio4->m_strItemName = QString::fromLocal8Bit("麦克风(2-USB2.0 MIC)");
	m_ptrLocalStreamListEx->OnInsertUserItem(pAudio4);
	 
}

void LocalMediaStreamWindow::InitListEx()
{
	m_ptrLocalStreamListEx.reset(new LocalStreamListEx(this));
 	m_ptrLocalStreamListEx->setStyleSheet("QListWidget{border:1 px; color:rgb(30,30,30); background:rgb(30,30,30); }");  
}

void LocalMediaStreamWindow::InitButtons()
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

		else	if (pButtonEx == m_ptrCloseBtn.get())
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
			pButtonEx->setNormalBgColor(/*m_iNormalBgColor*/QColor(50, 50, 50));

			pButtonEx->setHoverTextColor(m_iHoverTextColor);
			pButtonEx->setNormalFrameColor(/*m_iNormalFrameColor*/QColor(30, 30, 30));
		}

		pButtonEx->setNormalTextColor(QColor(200, 200, 200));
		pButtonEx->setCheckTextColor(m_iCheckTextColor);
	}
}

void LocalMediaStreamWindow::InitLabels()
{
	m_ptrTitle.reset(new NavLabelEx(this));

	QFont font1("Microsoft YaHei", 10, 75);
	m_ptrTitle->setFont(font1);

	m_ptrTitle->setTextAlign(NavLabelEx::TextAlign_Left);
	m_ptrTitle->setShowIcon(false);
	m_ptrTitle->setIconSize(QSize(0, 0));
	m_ptrTitle->setText(QString::fromLocal8Bit("实时输入"));

	m_ptrTitle->setNormalBgColor(QColor(50, 50, 50));
	m_ptrTitle->setNormalTextColor(QColor(220, 220, 220));
}

void LocalMediaStreamWindow::OnButtonOK()
{
 //	emit OnDeviceNameNotify(m_strDevceName);
	//this->hide();

 	 close();
 }

void LocalMediaStreamWindow::OnButtonCancel()
{
//	emit OnDeviceNameNotify(m_strDevceName);
	//this->hide();
	close();
}

void LocalMediaStreamWindow::OnButtonClose()
{
	//this->hide();
 	close();
}

void LocalMediaStreamWindow::resizeEvent(QResizeEvent *pEvent)
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

	if (m_ptrLocalStreamListEx)
	{
		m_ptrLocalStreamListEx->setGeometry(0, 0,iWidth - 12,iHeight - 60);
		m_ptrLocalStreamListEx->move(6, 25);
	}
 }

void LocalMediaStreamWindow::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);

	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(50, 50, 50));
	painter.setPen(QColor(210, 210, 210));

	painter.setClipRect(0, 0, width(), height());
	painter.fillRect(QRectF(6, 25, width() - 12, height() - 58), QColor(30, 30, 30));
}

void LocalMediaStreamWindow::mousePressEvent(QMouseEvent * pEvent)
{
	//只能是鼠标左键移动和改变大小
	if (pEvent->button() == Qt::LeftButton)
		m_bMousePress = true;

	//窗口移动距离
	m_iMovePoint = pEvent->globalPos() - pos();
}

void LocalMediaStreamWindow::mouseReleaseEvent(QMouseEvent*pEvent)
{
	m_bMousePress = false;
 }

void LocalMediaStreamWindow::mouseMoveEvent(QMouseEvent *pEvent)
{
	//移动窗口
	if (m_bMousePress)
	{
		QPoint move_pos = pEvent->globalPos();
		move(move_pos - m_iMovePoint);
	}
}


