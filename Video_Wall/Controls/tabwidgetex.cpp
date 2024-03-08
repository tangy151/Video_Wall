#include "tabwidgetex.h"
#include "../headfiledefine.h"
#include "flatuiex.h"
#include "buttonex.h"

 #include "tabpageex.h"
#include "tabbarex.h"

#include "../Public/addplaylistwindow.h"
#include "../Public/addipstreamwindow.h"
#include "../Public/localmediastreamwindow.h"

#include "mediaselectlistitemex.h"

#include "../EditorWindow/ipstreameditorwindow.h"
#include "../EditorWindow/localstreameditorwindow.h"
#include "../EditorWindow/pictureeditorwindow.h"
#include "../EditorWindow/playlisteditorwindow.h"
#include "../EditorWindow/videosourceeditrowindow.h"


#include "../runtimedata.h"

TabWidgetEx::TabWidgetEx(QWidget *parent)
	: QTabWidget(parent)
	, m_ptrBtnAdd(nullptr)
	, m_ptrBtnEdit(nullptr)
	, m_ptrBtnReName(nullptr)
	, m_ptrBtnDelete(nullptr)
	, m_ptrBtnclone(nullptr)
	, m_ptrBtnReName2(nullptr)
	, m_ptrBtnDelete2(nullptr)
	, m_ptrTabBarEx(nullptr)
	, m_iMediaType(VOIDE)
	, m_ptrCurrentPageEx(nullptr)
	, m_strCurPictureDir("")
	, m_strCurVideoDir("")
	, m_pSelectListItem(nullptr)
{  
	QString  strExePath = QCoreApplication::applicationDirPath();

	setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
	setMovable(true);
	setTabsClosable(false);

	m_vecAllPages.clear();

	InitUI();
	InitWindow();
	InitButtons();
	InitConnects();
	SetMediaButtonEnable(false);
 }

TabWidgetEx::~TabWidgetEx()
{
}

void TabWidgetEx::InitUI()
{
	m_ptrTabBarEx.reset(new TabBarEx(this));
	this->setTabBar(m_ptrTabBarEx.get());
	 
#if PIX_1080p
	m_ptrTabBarEx->setFixedHeight(30);
	m_ptrTabBarEx->setMaximumHeight(30);
	m_ptrTabBarEx->setFixedWidth(300);
	m_ptrTabBarEx->setFont(QFont("Microsoft YaHei", 9, 75));
 #else
	m_ptrTabBarEx->setFixedHeight(30);
	m_ptrTabBarEx->setMaximumHeight(30);
	m_ptrTabBarEx->setFixedWidth(235);
	m_ptrTabBarEx->setFont(QFont("Microsoft YaHei", 8, 75));
 #endif
	 
 	FlatUIEx::Instance()->SetTabBarQss(m_ptrTabBarEx.get(), "rgb(30,30,30)", "rgb(230,230,230)");
}

void TabWidgetEx::InitWindow()
{
// 	m_ptrLocalMediaStreamWindow.reset(new LocalMediaStreamWindow(QApplication::activeWindow()));
// 	m_ptrLocalMediaStreamWindow->hide();

// 	m_ptrAddIPStreamWindow.reset(new AddIPStreamWindow(QApplication::activeWindow()));
// 	m_ptrAddIPStreamWindow->hide();
// 
// 	m_ptrAddPlayListWindow.reset(new AddPlayListWindow(QApplication::activeWindow()));
// 	m_ptrAddPlayListWindow->hide();
}

void TabWidgetEx::ShowAudioEditor(bool bShow)
{
	if (bShow)
	{
		m_ptrBtnAdd->hide();
		m_ptrBtnEdit->hide();
		//m_ptrBtnReName->hide();
		m_ptrBtnDelete->hide();

		m_ptrBtnclone->show();
		m_ptrBtnReName2->show();
		m_ptrBtnDelete2->show();

	}
	else
	{
		m_ptrBtnAdd->show();
		m_ptrBtnEdit->show();
		//m_ptrBtnReName->show();
		m_ptrBtnDelete->show();

		m_ptrBtnclone->hide();
		m_ptrBtnReName2->hide();
		m_ptrBtnDelete2->hide();
	}
}

void TabWidgetEx::SetMediaButtonEnable(bool bEnable)
{
	m_ptrBtnDelete->setEnabled(bEnable);
	m_ptrBtnEdit->setEnabled(bEnable);
 }

void TabWidgetEx::SetCurrentSelectItem(MediaSelectListItemEx*  pSelectListItem)
{
	m_pSelectListItem = pSelectListItem;
}

void TabWidgetEx::MediaListHasData(int iSize)
{
	if (iSize == 0)
		m_pSelectListItem = nullptr;
}
 
void TabWidgetEx::InitButtons()
{
	m_ptrBtnAdd.reset(new ButtonEx(this));
	m_ptrBtnEdit.reset(new ButtonEx(this));
 	m_ptrBtnDelete.reset(new ButtonEx(this));

	m_ptrBtnclone.reset(new ButtonEx(this));
	m_ptrBtnReName2.reset(new ButtonEx(this));
	m_ptrBtnDelete2.reset(new ButtonEx(this));

	m_listButtons << m_ptrBtnAdd.get() << m_ptrBtnEdit.get() << m_ptrBtnDelete.get()

		<< m_ptrBtnclone.get() << m_ptrBtnReName2.get() << m_ptrBtnDelete2.get();

	for (int iIndex = 0; iIndex < m_listButtons.count(); iIndex++)
	{
		ButtonEx* pButtonEx = m_listButtons.at(iIndex);
		pButtonEx->setPaddingLeft(0);
		pButtonEx->setShowLine(false);
		pButtonEx->setShowIcon(false);
		pButtonEx->setIconSpace(0);
		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);

		if (pButtonEx == m_ptrBtnAdd.get())
		{
			m_ptrBtnAdd->setText(QString::fromLocal8Bit("添加"));
			m_ptrBtnAdd->setToolTip(QString::fromLocal8Bit("添加"));

		}
		else if (pButtonEx == m_ptrBtnEdit.get())
		{
			m_ptrBtnEdit->setText(QString::fromLocal8Bit("编辑"));
			m_ptrBtnEdit->setToolTip(QString::fromLocal8Bit("编辑"));
		}
		else if (pButtonEx == m_ptrBtnReName.get())
		{
			m_ptrBtnReName->setText(QString::fromLocal8Bit("重命名"));
			m_ptrBtnReName->setToolTip(QString::fromLocal8Bit("重命名"));
		}
		else if (pButtonEx == m_ptrBtnDelete.get())
		{
			m_ptrBtnDelete->setText(QString::fromLocal8Bit("删除"));
			m_ptrBtnDelete->setToolTip(QString::fromLocal8Bit("删除"));
		}

		else if (pButtonEx == m_ptrBtnclone.get())
		{
			m_ptrBtnclone->setText(QString::fromLocal8Bit("克隆"));
			m_ptrBtnclone->setToolTip(QString::fromLocal8Bit("克隆"));
		}

		else if (pButtonEx == m_ptrBtnReName2.get())
		{
			m_ptrBtnReName2->setText(QString::fromLocal8Bit("重命名"));
			m_ptrBtnReName2->setToolTip(QString::fromLocal8Bit("重命名"));
		}

		else if (pButtonEx == m_ptrBtnDelete2.get())
		{
			m_ptrBtnDelete2->setText(QString::fromLocal8Bit("删除"));
			m_ptrBtnDelete2->setToolTip(QString::fromLocal8Bit("删除"));
		}

		pButtonEx->setTextAlign(ButtonEx::TextAlign_Center);

#if PIX_1080p
		pButtonEx->setFont(QFont("Microsoft YaHei", 10, 75));

#else
		pButtonEx->setFont(QFont("Microsoft YaHei", 8, 75));

#endif
	}
}

void TabWidgetEx::InitConnects()
{
	connect(this, &QTabWidget::tabBarClicked, this, &TabWidgetEx::TabClicked);
  	connect(m_ptrBtnAdd.get(), SIGNAL(clicked()), this, SLOT(OnBtnAdd()));
	connect(m_ptrBtnEdit.get(), SIGNAL(clicked()), this, SLOT(OnBtnEdit()));
 	connect(m_ptrBtnDelete.get(), SIGNAL(clicked()), this, SLOT(OnBtnDelete()));
 }

void TabWidgetEx::OnBtnAdd()
{
	ButtonAddEvent();
}

void TabWidgetEx::OnBtnEdit() 
{
	ButtonEditEvent();
 }

void TabWidgetEx::OnBtnReName(){}

void TabWidgetEx::OnBtnDelete()
{
	ButtonDeleteEvent();
}
 
void TabWidgetEx::ButtonEditEvent()
{ 
	switch (m_iMediaType)
	{
	case VOIDE:
	{ 
		VideoSourceEditroWindow* pWindow = OnGetRuntimeData().OnGetVideoSourceEditroWindow();
		if (pWindow->exec() != QDialog::Accepted)
		{
			return;
		}

	}
	break;
	case PICTURE:
	{
		PictureEditorWindow* pWindow = OnGetRuntimeData().OnGetPictureEditorWindow();
		if (pWindow->exec() != QDialog::Accepted)
		{
			return;
		}
	}
	break;
	case  PLAY_LIST:
	{
		PlayListEditorWindow* pWindow = OnGetRuntimeData().OnGetPlayListEditorWindow();
		if (pWindow->exec() != QDialog::Accepted)
		{
			return;
		}
	}
	break;
	case  LOCAL_STREAM:
	{
		LocalStreamEditorWindow* pWindow = OnGetRuntimeData().OnGetLocalStreamEditorWindow();
		if (pWindow->exec() != QDialog::Accepted)
		{
			int i = 0;
			return;
		}
	}
	break;
	case IP_STREAM:
	{
		IPStreamEditorWindow* pWindow = OnGetRuntimeData().OnGetIPStreamEditorWindow();
		if (pWindow->exec() != QDialog::Accepted)
		{
			int i = 0;
			return;
		}
	}
	break;
	default:
		break;
	}
}

void TabWidgetEx::ButtonDeleteEvent()
{
 	switch (m_iMediaType)
	{
	case VOIDE:
 	case PICTURE:
	{
		if (m_pSelectListItem&&m_ptrCurrentPageEx)
		{
			m_ptrCurrentPageEx->DeleteData(m_pSelectListItem);

			QString strName = m_pSelectListItem->m_strFileName;
			QString strPath = m_pSelectListItem->m_strTotalName;

			emit DeletePageDataNotify(strName,	 strPath);
 		}
	}
	break;
	case  PLAY_LIST:
	{
		if (m_pSelectListItem&&m_ptrCurrentPageEx)
		{
			QString strPageName = m_pSelectListItem->m_strFileName;
			
			if (!strPageName.isEmpty())
			{
				emit DeletePlayListPage(strPageName);
 				emit DeletePageDataNotify(strPageName, strPageName);
			}
   
			m_ptrCurrentPageEx->DeleteData(m_pSelectListItem);
		}
	}
	break;
	case  LOCAL_STREAM:
	{
		if (m_pSelectListItem&&m_ptrCurrentPageEx)
		{
			m_ptrCurrentPageEx->DeleteData(m_pSelectListItem);

			QString strName		= m_pSelectListItem->m_strFileName;
			QString strPath		= m_pSelectListItem->m_strTotalName;

			emit DeletePageDataNotify(strName, strPath);
 		}
	}
	break;
	case IP_STREAM:
	{
		if (m_pSelectListItem&&m_ptrCurrentPageEx)
		{
			QString strName = m_pSelectListItem->m_strFileName;
			QString strPath = m_pSelectListItem->m_strTotalName;

			emit DeletePageDataNotify(strName, strPath);

			m_ptrCurrentPageEx->DeleteData(m_pSelectListItem);
 		}
	}
	break;
	default:
		break;
	}
}

void TabWidgetEx::ButtonAddEvent()
{
	switch (m_iMediaType)
	{
	case VOIDE:
	{ 
		m_strCurVideoDir = m_strExePath;

		QString strFilePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("视频文件"), m_strCurVideoDir,QString::fromLocal8Bit("视频格式(*.rmvb *.mpeg *.3gp  *.avi *.mp4 *.flv *.mkv)"));
 		std::string strTempPath = strFilePath.toStdString();
 		int ilength = strTempPath.length();
		int iPos = strTempPath.find_last_of('/');

		if (strTempPath.empty())
			return;

		std::string strFileName=	strTempPath.substr(iPos +1, ilength);
		QString strTempTitle	= strFileName.c_str();

		std::string  strVideoDir = strTempPath.substr(0, iPos);
		m_strCurVideoDir = strVideoDir.c_str();
		 
		m_ptrCurrentPageEx->InsertData(strTempTitle, strFilePath);
		 
		emit AddPageDataNotify(strTempTitle, strFilePath);
  	}
		break;
	case PICTURE:
	{ 
		QString strFilePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("图片文件"), m_strCurPictureDir, QString::fromLocal8Bit("图片格式(*.png *.jpg *.bmp)"));
		std::string strTempPath = strFilePath.toStdString();
		int ilength = strTempPath.length();
		int iPos = strTempPath.find_last_of('/');
		
		std::string strFileName	= strTempPath.substr(iPos + 1, ilength);
		std::string  strPictureDir	= strTempPath.substr(0, iPos);
		m_strCurPictureDir = strPictureDir.c_str();

		if (strTempPath.empty())
			return;

		  strFileName = strTempPath.substr(iPos + 1, ilength);
		QString strTempTitle = strFileName.c_str();

		m_ptrCurrentPageEx->InsertData(strTempTitle, strFilePath);
		emit AddPageDataNotify(strTempTitle, strFilePath);
 	}
		break;
	case  PLAY_LIST:
	{
		AddPlayListWindow  dlg(QApplication::activeWindow());

 		if (dlg.exec() != QDialog::Accepted)
		{
 			QString strName = 	dlg.GetPlayListName();
 			OnAddPlayListNotify(strName);
			return;
 		}
  	}
	break;
	case  LOCAL_STREAM:
	{ 
		LocalMediaStreamWindow  dlg(QApplication::activeWindow());
		if (dlg.exec() != QDialog::Accepted)
		{
			QString strName = dlg.OnGetDeviceName();
			OnDeviceNameNotify(strName);
			return;
 		}
   	}
		break;
	case IP_STREAM:
	{
		AddIPStreamWindow  dlg(QApplication::activeWindow());

		if (dlg.exec() != QDialog::Accepted)
		{
			QString strName = "", strAddr = "";
			dlg.GetNameAndAddr(strName, strAddr);
			
			OnAddIPStreamNotify(strName,strAddr);

			return;
 		}
  	}
		break;

	default:
		break;
	}
}

void TabWidgetEx::DeletePageData(MEDIA_SELECT_TYPE iMediaType, QString strName, QString strPath)
{ 
	int iSize = m_vecAllPages.size();

	for (int iIndex = 0; iIndex < iSize; iIndex++)
	{
		TabPageEx* 	ptrTabPageEx = nullptr;
		ptrTabPageEx = m_vecAllPages[iIndex];

		MEDIA_SELECT_TYPE iType;

		iType = ptrTabPageEx->GetMediaType();

		if (iType == iMediaType)
		{
			if (ptrTabPageEx)
				ptrTabPageEx->DeleteData(strName, strPath);
			 
			break;
		}
	}
}
 
void TabWidgetEx::AddPageData(MEDIA_SELECT_TYPE iMediaType, QString strName, QString strPath)
{
	int iSize = m_vecAllPages.size();
	for (int iIndex = 0; iIndex < iSize; iIndex++)
	{
		TabPageEx* 	ptrTabPageEx = nullptr;
		ptrTabPageEx = m_vecAllPages[iIndex];

		MEDIA_SELECT_TYPE iType;

		iType = ptrTabPageEx->GetMediaType();

		if (iType == iMediaType)
		{
			ptrTabPageEx->InsertData(strName, strPath);
			break;
		} 
	} 
 }
 
void TabWidgetEx::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(50, 50, 50));
	painter.setPen(QColor(210, 210, 210));
}

void TabWidgetEx::resizeEvent(QResizeEvent* pEvent)
{
	QWidget::resizeEvent(pEvent);

	int iWidth = width();
	int iHeight = height();
	 
#if PIX_1080p
	if (m_ptrBtnAdd)
	{
		m_ptrBtnAdd->setGeometry(0, 0, 50, 30);
		m_ptrBtnAdd->move(iWidth - 157, 0);
	}

	if (m_ptrBtnEdit)
	{
		m_ptrBtnEdit->setGeometry(0, 0, 50, 30);
		m_ptrBtnEdit->move(iWidth - 107, 0);
	}

	if (m_ptrBtnDelete)
	{
		m_ptrBtnDelete->setGeometry(0, 0, 50, 30);
		m_ptrBtnDelete->move(iWidth - 56, 0);
	}

	if (m_ptrBtnclone)
	{
		m_ptrBtnclone->setGeometry(0, 0, 50, 30);
		m_ptrBtnclone->move(iWidth - 157, 0);
	}

	if (m_ptrBtnReName2)
	{
		m_ptrBtnReName2->setGeometry(0, 0, 50, 30);
		m_ptrBtnReName2->move(iWidth - 107, 0);
	}

	if (m_ptrBtnDelete2)
	{
		m_ptrBtnDelete2->setGeometry(0, 0, 50, 30);
		m_ptrBtnDelete2->move(iWidth - 56, 0);
	}

	int iSize = m_vecAllPages.size();
	for (int iIndex = 0; iIndex < iSize; iIndex++)
	{
		TabPageEx* 	ptrTabPageEx = nullptr;
		ptrTabPageEx = m_vecAllPages[iIndex];

		ptrTabPageEx->setGeometry(0, 0, iWidth, iHeight);
		ptrTabPageEx->move(0, 0);
		ptrTabPageEx->update();
	}

#else
	if (m_ptrBtnAdd)
	{
		m_ptrBtnAdd->setGeometry(0, 0, 30, 30);
		m_ptrBtnAdd->move(iWidth - 98, 0);
	}

	if (m_ptrBtnEdit)
	{
		m_ptrBtnEdit->setGeometry(0, 0, 30, 30);
		m_ptrBtnEdit->move(iWidth -67, 0);
	}

	if (m_ptrBtnDelete)
	{
		m_ptrBtnDelete->setGeometry(0, 0, 30, 30);
		m_ptrBtnDelete->move(iWidth - 36, 0);
	}

	if (m_ptrBtnclone)
	{
		m_ptrBtnclone->setGeometry(0, 0, 30, 30);
		m_ptrBtnclone->move(iWidth - 147, 0);
	}

	if (m_ptrBtnReName2)
	{
		m_ptrBtnReName2->setGeometry(0, 0, 30, 30);
		m_ptrBtnReName2->move(iWidth - 97, 0);
	}

	if (m_ptrBtnDelete2)
	{
		m_ptrBtnDelete2->setGeometry(0, 0, 30, 30);
		m_ptrBtnDelete2->move(iWidth - 46, 0);
	}

	int iSize = m_vecAllPages.size();
	for (int iIndex = 0; iIndex < iSize; iIndex++)
	{
		TabPageEx* 	ptrTabPageEx = nullptr;
		ptrTabPageEx = m_vecAllPages[iIndex];

		ptrTabPageEx->setGeometry(0, 0, iWidth, iHeight);
		ptrTabPageEx->move(0, 0);
		ptrTabPageEx->update();
	}

#endif
 }

void TabWidgetEx::AddPage(QString strName, MEDIA_SELECT_TYPE  iMediaType)
{
	TabPageEx* 	ptrTabPageEx = nullptr;
	ptrTabPageEx = new TabPageEx(this, strName, iMediaType);

	if (iMediaType == VOIDE)
 		m_ptrCurrentPageEx = ptrTabPageEx;
 
	if (ptrTabPageEx->IsActive())
	{

		setTabShape(QTabWidget::Rounded);
		addTab(ptrTabPageEx, ptrTabPageEx->GetPageTitle());

  	}

	connect(ptrTabPageEx, &TabPageEx::ActiveChanged, this, &TabWidgetEx::PageActivityChanged);

	m_vecAllPages.push_back(ptrTabPageEx);
	emit PageAdded(ptrTabPageEx);
 }

TabPageEx* TabWidgetEx::GetPage(unsigned index)
{
	return (TabPageEx*)widget(index);
}

void TabWidgetEx::RemovePage(TabPageEx* pPage)
{
	int index = indexOf(pPage);

	if (index != -1)
		removeTab(index);

	disconnect(pPage, &TabPageEx::ActiveChanged, this, &TabWidgetEx::PageActivityChanged);
	auto found = std::find(m_vecAllPages.begin(), m_vecAllPages.end(), pPage);

	if (found != m_vecAllPages.end())
		m_vecAllPages.erase(found);

	emit PageRemoved(pPage);
}

void TabWidgetEx::OnDeviceNameNotify(QString strDeviceName)
{
	if (!strDeviceName.isEmpty() && m_ptrCurrentPageEx)
	{
		m_ptrCurrentPageEx->InsertData(strDeviceName, strDeviceName);

		//外部添加
		emit AddPageDataNotify(strDeviceName, strDeviceName);
 	}
 }

void TabWidgetEx::OnAddPlayListNotify(QString strListName)
{
	if (!strListName.isEmpty() && m_ptrCurrentPageEx)
	{
		m_ptrCurrentPageEx->InsertData(strListName, strListName);

		//外部添加
		emit AddPageDataNotify( strListName, strListName);
		 
		if (!strListName.isEmpty())
			emit AddPlayListPage(strListName);
 	}
}

void TabWidgetEx::OnAddIPStreamNotify(QString strName, QString strAddr)
{
	if (!strAddr.isEmpty() && !strName.isEmpty() && m_ptrCurrentPageEx)
	{
		m_ptrCurrentPageEx->InsertData(strName, strAddr);

		//外部添加
		emit AddPageDataNotify(  strName, strAddr);
	}
}
 
bool TabWidgetEx::IsAutoHide()
{
	return m_bAutoHide;
}

void TabWidgetEx::SetAutoHide(bool state)
{
	m_bAutoHide = state;
}

void TabWidgetEx::PageActivityChanged(TabPageEx* pPage)
{
 	if (pPage->IsActive() && indexOf(pPage) == -1)
	{
		int lastActivePage = 0;
		const int numPages = count();
		for (int i = 0; i < m_vecAllPages.size(); ++i)
		{
			if (m_vecAllPages[i]->IsActive() && m_vecAllPages[i] != pPage)
			{
				++lastActivePage;
			}
			else if (m_vecAllPages[i] == pPage)
			{
				insertTab(lastActivePage, pPage, pPage->GetPageTitle());
				break;
			}
		}
	}
	else if (!pPage->IsActive())
	{
		removeTab(indexOf(pPage));
	}
}

void TabWidgetEx::TabClicked(int index)
{
	if (QWidget* showTab = widget(index))
	{
		TabPageEx* pTabPageEx = ((TabPageEx*)showTab);
		if (pTabPageEx)
		{
			m_iMediaType = pTabPageEx->GetMediaType();
			m_ptrCurrentPageEx = pTabPageEx;
		}
	}
 }

void TabWidgetEx::HandleApplicationButton(bool)
{
	emit ApplicationButtonClicked();
}


