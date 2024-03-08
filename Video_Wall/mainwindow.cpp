#include "mainwindow.h"
 
#include <memory>

#include "headfiledefine.h"
#include "Controls/flatuiex.h"
  
#include "SplitterArea/videoareautilwindow.h"
#include "SplitterArea/virtualareautilwindow.h"
#include "SplitterArea/channelareautilwindow.h"
#include "SplitterArea/monitorareautilwindow.h"

#include "EditorWindow/ipstreameditorwindow.h"
#include "EditorWindow/localstreameditorwindow.h"
#include "EditorWindow/pictureeditorwindow.h"
#include "EditorWindow/playlisteditorwindow.h"
#include "EditorWindow/videosourceeditrowindow.h"

#include "runtimedata.h"

 MainWindow*	g_ptrMainWindow = nullptr;
 

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, m_ptrTopToolBar(nullptr)
	, m_ptrActNew(nullptr)
	, m_ptrActOpen(nullptr)
	, m_ptrActSave(nullptr)
	, m_ptrActSaveAs(nullptr)
	, m_ptrActQuit(nullptr)
	, m_ptrMenuBar(nullptr)
	, m_ptrMainSplitter(nullptr)
	, m_ptrTopSplitter(nullptr)

	, m_ptrActPic1(nullptr)
	, m_ptrActPic2(nullptr)
	, m_ptrActLogo1(nullptr)
	, m_ptrActLogo2(nullptr)
	, m_ptrActTimer(nullptr)
	, m_ptrActSubtitles(nullptr)
	, m_ptrActFullScreen(nullptr)
	, m_ptrActMedia(nullptr)
	, m_ptrActSetting(nullptr)
	, m_ptrActInputData(nullptr)
	, m_ptrActAbout(nullptr)
	, m_ptrVirtualAreaUtilWindow(nullptr)
	, m_ptrVideoAreaUtilWindow(nullptr)
	, m_ptrVideoSourceEditroWindow(nullptr)
	, m_ptrPlayListEditorWindow(nullptr)
	, m_ptrPictureEditorWindow(nullptr)
	, m_ptrLocalStreamEditorWindow(nullptr)
	, m_ptrIPStreamEditorWindow(nullptr)
{  


 	g_ptrMainWindow = this;
	m_strExePath = QCoreApplication::applicationDirPath();

	QScreen *screen = QGuiApplication::primaryScreen();
	QRect mm = screen->availableGeometry();

	int screen_width = 0;
	int screen_height = 0;

#if  PIX_1080p
	  screen_width = mm.width();
	  screen_height = mm.height();
#else
	screen_width = 1366;
	screen_height = 728;
#endif

 
	
	qDebug() << screen_width << screen_height;
   
	setWindowTitle(QString::fromLocal8Bit("AllDemo"));

	setMinimumSize(screen_width, screen_height - 30);
	setMaximumSize(screen_width, screen_height - 30);
	QString strIcon =QString( ":/res/logo.png");
	QIcon icon;
	icon.addPixmap(QPixmap(strIcon), QIcon::Normal, QIcon::Off);

	setWindowIcon(icon);
	//--------------------------------------

	m_ptrMainSplitter.reset(new QSplitter(Qt::Vertical, this));
	m_ptrMainSplitter->setHandleWidth(5);
	m_ptrMainSplitter->setStyleSheet("QSplitter::handle{background:#202020}");
	m_ptrMainSplitter->setChildrenCollapsible(false);


	//--------------------------------------
	m_ptrTopSplitter.reset(new QSplitter(Qt::Horizontal, m_ptrMainSplitter.get()));
	m_ptrTopSplitter->setHandleWidth(5);

	m_ptrTopSplitter->setStyleSheet("QSplitter::handle{background:#202020}");
	m_ptrTopSplitter->setMinimumHeight(400);
 	m_ptrTopSplitter->setMaximumHeight(800);
	m_ptrTopSplitter->setChildrenCollapsible(false);
	//--------------------------------------

	CreateActions();
	CreateMenuBar();

	FlatUIEx::Instance()->setQWidgetWndQss(this);
	
	CreateEditroWindow();

	CreatePreviewWindows();

	InitConnects();
}


void MainWindow::CreateMenuBar()
{
	m_ptrMenuFile.reset(new QMenu(QString::fromLocal8Bit("文件")));

	m_ptrMenuFile->addAction(m_ptrActNew.get());
	m_ptrMenuFile->addSeparator();
	m_ptrMenuFile->addAction(m_ptrActOpen.get());
	m_ptrMenuFile->addAction(m_ptrActSave.get());
	m_ptrMenuFile->addSeparator();
	m_ptrMenuFile->addAction(m_ptrActQuit.get());

	FlatUIEx::Instance()->SetMenuQss(m_ptrMenuFile.get());


	m_ptrMenuEidt.reset(new QMenu(QString::fromLocal8Bit("编辑")));

	m_ptrMenuEidt->addAction(m_ptrActPic1.get());
	m_ptrMenuEidt->addAction(m_ptrActPic2.get());
	m_ptrMenuEidt->addSeparator();

	m_ptrMenuEidt->addAction(m_ptrActLogo1.get());
	m_ptrMenuEidt->addAction(m_ptrActLogo2.get());
	m_ptrMenuEidt->addAction(m_ptrActTimer.get());
	m_ptrMenuEidt->addSeparator();

	m_ptrMenuEidt->addAction(m_ptrActSubtitles.get());
	FlatUIEx::Instance()->SetMenuQss(m_ptrMenuEidt.get());

	m_ptrMenuLook.reset(new QMenu(QString::fromLocal8Bit("查看")));
	m_ptrMenuLook->addAction(m_ptrActFullScreen.get());
	FlatUIEx::Instance()->SetMenuQss(m_ptrMenuLook.get());


	m_ptrMenuTool.reset(new QMenu(QString::fromLocal8Bit("工具")));
	m_ptrMenuTool->addAction(m_ptrActMedia.get());
	m_ptrMenuTool->addSeparator();
	m_ptrMenuTool->addAction(m_ptrActSetting.get());
	m_ptrMenuTool->addAction(m_ptrActInputData.get());
	FlatUIEx::Instance()->SetMenuQss(m_ptrMenuTool.get());

	m_ptrMenuHelp.reset(new QMenu(QString::fromLocal8Bit("帮助")));
	m_ptrMenuHelp->addAction(m_ptrActAbout.get());
	FlatUIEx::Instance()->SetMenuQss(m_ptrMenuHelp.get());

	m_ptrMenuBar.reset(new QMenuBar(this));
	m_ptrMenuBar->addMenu(m_ptrMenuFile.get());
	m_ptrMenuBar->addMenu(m_ptrMenuEidt.get());
	m_ptrMenuBar->addMenu(m_ptrMenuLook.get());
	m_ptrMenuBar->addMenu(m_ptrMenuTool.get());
	m_ptrMenuBar->addMenu(m_ptrMenuHelp.get());

	FlatUIEx::Instance()->setMenuBarQss(m_ptrMenuBar.get());
}

void MainWindow::CreateActions()
{
	m_ptrActNew.reset(new QAction(QString::fromLocal8Bit("新建"), this));
	m_ptrActOpen.reset(new QAction(QString::fromLocal8Bit("打开"), this));
	m_ptrActSave.reset(new QAction(QString::fromLocal8Bit("保存"), this));
	m_ptrActSaveAs.reset(new QAction(QString::fromLocal8Bit("另存为"), this));
	m_ptrActQuit.reset(new QAction(QString::fromLocal8Bit("退出"), this));

	m_ptrActPic1.reset(new QAction(QString::fromLocal8Bit("画中画1"), this));
	m_ptrActPic2.reset(new QAction(QString::fromLocal8Bit("画中画2"), this));
	m_ptrActLogo1.reset(new QAction(QString::fromLocal8Bit("LOGO1"), this));
	m_ptrActLogo2.reset(new QAction(QString::fromLocal8Bit("LOGO2"), this));
	m_ptrActTimer.reset(new QAction(QString::fromLocal8Bit("时钟"), this));
	m_ptrActSubtitles.reset(new QAction(QString::fromLocal8Bit("字幕"), this));

	m_ptrActFullScreen.reset(new QAction(QString::fromLocal8Bit("全屏"), this));

	m_ptrActMedia.reset(new QAction(QString::fromLocal8Bit("媒体"), this));
	m_ptrActSetting.reset(new QAction(QString::fromLocal8Bit("设置"), this));
	m_ptrActInputData.reset(new QAction(QString::fromLocal8Bit("输出参数"), this));

	m_ptrActAbout.reset(new QAction(QString::fromLocal8Bit("关于"), this));
}

void MainWindow::InitConnects()
{
	connect(m_ptrActNew.get(), SIGNAL(triggered()), this, SLOT(OnActNew()));
	connect(m_ptrActOpen.get(), SIGNAL(triggered()), this, SLOT(OnActOpen()));
	connect(m_ptrActSave.get(), SIGNAL(triggered()), this, SLOT(OnActSave()));
	connect(m_ptrActSaveAs.get(), SIGNAL(triggered()), this, SLOT(OnActSaveAs()));
	connect(m_ptrActQuit.get(), SIGNAL(triggered()), this, SLOT(OnActQuit()));

	connect(m_ptrActPic1.get(), SIGNAL(triggered()), this, SLOT(OnActPic1()));
	connect(m_ptrActPic2.get(), SIGNAL(triggered()), this, SLOT(OnActPic2()));
	connect(m_ptrActLogo1.get(), SIGNAL(triggered()), this, SLOT(OnActLogo1()));
	connect(m_ptrActLogo2.get(), SIGNAL(triggered()), this, SLOT(OnActLogo2()));
	connect(m_ptrActTimer.get(), SIGNAL(triggered()), this, SLOT(OnActTimer()));
	connect(m_ptrActSubtitles.get(), SIGNAL(triggered()), this, SLOT(OnActSubtitles()));

	connect(m_ptrActFullScreen.get(), SIGNAL(triggered()), this, SLOT(OnActFullScreen()));

	connect(m_ptrActMedia.get(), SIGNAL(triggered()), this, SLOT(OnActMedia()));
	connect(m_ptrActSetting.get(), SIGNAL(triggered()), this, SLOT(OnActSetting()));
	connect(m_ptrActInputData.get(), SIGNAL(triggered()), this, SLOT(OnActInputData()));

	connect(m_ptrActAbout.get(), SIGNAL(triggered()), this, SLOT(OnActAbout()));
}

void	MainWindow::OnActNew()
{
	int i = 0;
}

void	MainWindow::OnActOpen()
{

}

void	MainWindow::OnActSave()
{

}

void	MainWindow::OnActSaveAs() {

}

void	MainWindow::OnActQuit()
{

}


void	MainWindow::OnActPic1()
{

}

void	MainWindow::OnActPic2()
{

}

void	MainWindow::OnActLogo1()
{

}

void	MainWindow::OnActLogo2()
{

}

void	MainWindow::OnActTimer()
{

}

void	MainWindow::OnActSubtitles()
{

}


void	MainWindow::OnActFullScreen()
{

}


void	MainWindow::OnActMedia()
{

}

void	MainWindow::OnActSetting()
{

}

void	MainWindow::OnActInputData()
{

}


void	MainWindow::OnActAbout()
{

}


void MainWindow::SetApplicationObject(QObject* pObject)
{
	pObject->installEventFilter(this);
}

MainWindow::~MainWindow()
{
}

void  MainWindow::CreateEditroWindow()
{ 
	m_ptrVideoSourceEditroWindow.reset(new VideoSourceEditroWindow(QApplication::activeWindow()));
	m_ptrVideoSourceEditroWindow->hide();

	OnGetRuntimeData().OnSetVideoSourceEditroWindow(m_ptrVideoSourceEditroWindow.get());

	m_ptrPlayListEditorWindow.reset(new PlayListEditorWindow(QApplication::activeWindow()));
	m_ptrPlayListEditorWindow->hide();

	OnGetRuntimeData().OnSetPlayListEditorWindow(m_ptrPlayListEditorWindow.get());

	m_ptrPictureEditorWindow.reset(new PictureEditorWindow(QApplication::activeWindow()));
	m_ptrPictureEditorWindow->hide();
	
	OnGetRuntimeData().OnSetPictureEditorWindow(m_ptrPictureEditorWindow.get());

	m_ptrLocalStreamEditorWindow.reset(new LocalStreamEditorWindow(QApplication::activeWindow()));
	m_ptrLocalStreamEditorWindow->hide();

	OnGetRuntimeData().OnSetLocalStreamEditorWindow(m_ptrLocalStreamEditorWindow.get());

	m_ptrIPStreamEditorWindow.reset(new IPStreamEditorWindow(QApplication::activeWindow()));
	m_ptrIPStreamEditorWindow->hide();

	OnGetRuntimeData().OnSetIPStreamEditorWindow(m_ptrIPStreamEditorWindow.get());
 }

void MainWindow::CreatePreviewWindows()
{
 	m_ptrChannelManagerWindow.reset(new ChannelAreaUtilWindow(this/*m_ptrTopSplitter.get()*/));
	//m_ptrTopSplitter->setMinimumWidth(300);
	//m_ptrTopSplitter->setMaximumWidth(1000);

	m_ptrMonitorManagerWindow.reset(new MonitorAreaUtilWindow(this/*m_ptrTopSplitter.get()*/));
	//m_ptrTopSplitter->setMinimumWidth(300);
	//m_ptrTopSplitter->setMaximumWidth(1600);

	//m_ptrTopSplitter->setStretchFactor(0, 5);
	//m_ptrTopSplitter->setStretchFactor(1, 5);
	 
	//------------------------------------------

	m_ptrVirtualAreaUtilWindow.reset(new VirtualAreaUtilWindow(this/*m_ptrMainSplitter.get()*/));
	//m_ptrVirtualAreaUtilWindow->setMinimumHeight(50);
	//m_ptrVirtualAreaUtilWindow->setMaximumHeight(100);
	m_ptrVirtualAreaUtilWindow->hide();
	m_ptrVideoAreaUtilWindow.reset(new VideoAreaUtilWindow(this/*m_ptrMainSplitter.get()*/));
	//m_ptrVideoAreaUtilWindow->setMinimumHeight(360);
	//m_ptrVideoAreaUtilWindow->setMaximumHeight(1000);
 }


void MainWindow::resizeEvent(QResizeEvent* pEvent)
{
	int iWidth = this->width();
	int iHeight = this->height();

// 	if (m_ptrMainSplitter)
// 	{
// 		m_ptrMainSplitter->setGeometry(0, 0, iWidth - 20, iHeight - 40);
// 		m_ptrMainSplitter->move(10, 26);
// 
	if (m_ptrMenuBar)
	{
		m_ptrMenuBar->setGeometry(0, 0, 300, 25);
		m_ptrMenuBar->move(10, 0);
		m_ptrMenuBar->show();
	}

	if (m_ptrChannelManagerWindow)
	{
		m_ptrChannelManagerWindow->setGeometry(0, 0, iWidth / 2 - 5, iHeight / 2 - 35);
		m_ptrChannelManagerWindow->move(5, 25);
	}
 
	if (m_ptrMonitorManagerWindow)
	{
		m_ptrMonitorManagerWindow->setGeometry(0, 0, iWidth / 2 - 5, iHeight / 2 - 35);
		m_ptrMonitorManagerWindow->move(iWidth/2 + 5, 25);
	}

	if (m_ptrVideoAreaUtilWindow)
	{
		m_ptrVideoAreaUtilWindow->setGeometry(0, 0, iWidth - 10, iHeight / 2+ 30  );
		m_ptrVideoAreaUtilWindow->move( 5, iHeight/2-5);
	}
	  

	QWidget::resizeEvent(pEvent);
}

// void MainWindow::closeEvent(QCloseEvent *pEvent)
// {
// 	pEvent->setAccepted(true);
// 	QMainWindow::closeEvent(pEvent);
// }
















