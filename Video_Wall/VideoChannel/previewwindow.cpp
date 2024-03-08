#include "previewwindow.h"
#include "../headfiledefine.h"
#include "../Controls/flatuiex.h"

#include "../Public/selectmediasourcewindow.h"

#include "../runtimedata.h"

#include <QMenu>

PreviewWindow::PreviewWindow(QWidget *parent)
	: QWidget(parent)
	, m_ptrPopMenu(nullptr)
	, m_ptrActInputMainMonitor(nullptr)
	, m_ptrActInputPrevMonitor(nullptr)
	, m_ptrASelMediaSource(nullptr)
	, m_ptrActEditorMedia(nullptr)
	, m_ptrActReloadMedia(nullptr)
	, m_ptrActClearMedia(nullptr)
	, m_iMediaType(MEDIA_TYPE_NULL)
{ 
	InitActions();
	InitPopMenu();
	InitConnects();
}

PreviewWindow::~PreviewWindow()
{
}

void PreviewWindow::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(35, 35, 35));
	painter.setPen(QColor(210, 210, 210));
 }

void PreviewWindow::resizeEvent(QResizeEvent* pEvent)
{
	int iWidth = width();
	int iHeight = height();
}

void PreviewWindow::InitActions()
{
	m_ptrActInputMainMonitor.reset(new QAction(QString::fromLocal8Bit("输出到主窗口"), this));
	m_ptrActInputPrevMonitor.reset(new QAction(QString::fromLocal8Bit("输出到预览窗口"), this));
	m_ptrASelMediaSource.reset(new QAction(QString::fromLocal8Bit("选择媒体源"), this));
	m_ptrActEditorMedia.reset(new QAction(QString::fromLocal8Bit("编辑媒体源"), this));
	m_ptrActReloadMedia.reset(new QAction(QString::fromLocal8Bit("重新加载媒体"), this));
	m_ptrActClearMedia.reset(new QAction(QString::fromLocal8Bit("清理输入通道"), this));
 }


void PreviewWindow::InitConnects()
{
	connect(m_ptrActInputMainMonitor.get(), SIGNAL(triggered()), this, SLOT(OnInputMainMonitor()));
	connect(m_ptrActInputPrevMonitor.get(), SIGNAL(triggered()), this, SLOT(OnInputPrevMonitor()));
	connect(m_ptrASelMediaSource.get(), SIGNAL(triggered()), this, SLOT(OnSelMediaSource()));
	connect(m_ptrActEditorMedia.get(), SIGNAL(triggered()), this, SLOT(OnEditorMedia()));
	connect(m_ptrActReloadMedia.get(), SIGNAL(triggered()), this, SLOT(OnReloadMedia()));
	connect(m_ptrActClearMedia.get(), SIGNAL(triggered()), this, SLOT(OnClearMedia()));
}

void PreviewWindow::InitPopMenu()
{
	m_ptrPopMenu.reset( new QMenu(this));

	m_ptrPopMenu->addAction(m_ptrActInputMainMonitor.get());
	m_ptrPopMenu->addAction(m_ptrActInputPrevMonitor.get());
	m_ptrPopMenu->addSeparator();

	m_ptrPopMenu->addAction(m_ptrASelMediaSource.get());
	m_ptrPopMenu->addSeparator();

	m_ptrPopMenu->addAction(m_ptrActEditorMedia.get());
	m_ptrPopMenu->addAction(m_ptrActReloadMedia.get());
	m_ptrPopMenu->addSeparator();

	m_ptrPopMenu->addAction(m_ptrActClearMedia.get());
  
	
	FlatUIEx::Instance()->SetMenuQss(m_ptrPopMenu.get());

}
void  PreviewWindow::OnInputMainMonitor() 
{
	int i = 0;
}

void  PreviewWindow::OnInputPrevMonitor()
{

}

void  PreviewWindow::OnSelMediaSource() 
{
// 	SelectMediaSourceWindow  dlg(QApplication::activeWindow());
// 	 
// 	if (dlg.exec() != QDialog::Accepted)
// 		return;

	SelectMediaSourceWindow* pWindow = OnGetRuntimeData().OnGetSelectMediaSourceWindow();
	if (pWindow->exec() != QDialog::Accepted)
	{
		return;
 	}
 
}

void  PreviewWindow::OnEditorMedia()
{

}

void  PreviewWindow::OnReloadMedia()
{

}

void  PreviewWindow::OnClearMedia()
{

}



void PreviewWindow::mousePressEvent(QMouseEvent *pEvent)      //单击
{
	// 如果是鼠标左键按下   改变指针形状，并且存储当前指针位置与窗口位置的差值。
	if (pEvent->button() == Qt::LeftButton) 
	{

 	}
 	else if (pEvent->button() == Qt::RightButton) 
	{
		QPoint pos; //获取按键菜单的坐标
		 
		int y = pos.y();
 
		pos.setY(y + this->geometry().height());

 		//m_ptrPopMenu->exec(this->mapToGlobal(pos));
		//exec(QCursor::pos());  当前光标的坐标
		m_ptrPopMenu->exec(QCursor::pos());
 	}


 
}



