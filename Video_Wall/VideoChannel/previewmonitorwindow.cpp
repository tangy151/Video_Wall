#include "previewmonitorwindow.h"
#include "../headfiledefine.h"
#include "../Controls/flatuiex.h"
#include "../Controls/volumemeter.h"

#include "pvwwindow.h"

PreviewMonitorWindow::PreviewMonitorWindow(QWidget *parent)
	: QWidget(parent)
	, m_ptrPvwWindow(nullptr)
	, m_ptrTitleLabel(nullptr)
	, m_ptrVolumeMeter(nullptr)
	, m_ptrActPic1(nullptr)
	, m_ptrActPic2(nullptr)
	, m_ptrActLogo1(nullptr)
	, m_ptrActLogo2(nullptr)
	, m_ptrActTimer(nullptr)
	, m_ptrActSubtitles1(nullptr)
	, m_ptrActSubtitles2(nullptr)
	, m_ptrActSubtitles3(nullptr)
	, m_ptrActSubtitles4(nullptr)

 { 
	InitActions();
 	InitUI();
 	InitMenu();
	 
	InitConnects();

	//³õÊ¼»¯Ëæ»úÊýÖÖ×Ó
	QTime t = QTime::currentTime();
	qsrand(t.msec() + t.second() * 1000);

	QTimer *timer = new QTimer(this);
	timer->setInterval(2000);

	connect(timer, SIGNAL(timeout()), this, SLOT(updateValue()));
	timer->start();
	updateValue();
}

PreviewMonitorWindow::~PreviewMonitorWindow()
{
}

void PreviewMonitorWindow::updateValue()
{
	m_ptrVolumeMeter->setLeftValue(qrand() % 100);
	m_ptrVolumeMeter->setRightValue(qrand() % 100);
}

void PreviewMonitorWindow::InitUI()
{
	m_ptrPvwWindow.reset(new PvwWindow(this));
	m_ptrTitleLabel.reset(new QLabel(this));

	QString strTitle = QString::fromLocal8Bit("Ô¤¼à:");
	m_ptrTitleLabel->setText(strTitle);

  	FlatUIEx::Instance()->SetLabelQss(m_ptrTitleLabel.get(), "rgb(50,50,50)", "rgb(0,255,0)");

	QFont font("Microsoft YaHei", 10, 75);  
	m_ptrTitleLabel->setFont(font);

	//----------------------------------------
	m_ptrVolumeMeter.reset(new VolumeMeter(this));
 }
 
void PreviewMonitorWindow::InitMenu()
{
	m_ptrPopMenu.reset(new QMenu(this));

	m_ptrSubtitlesMenu.reset(new QMenu(QString::fromLocal8Bit("×Ö Ä»")));

 	m_ptrChildMenu.reset(new QMenu(QString::fromLocal8Bit("±à¼­²ã")));
 
	m_ptrChildMenu->addAction(m_ptrActPic1.get());
	m_ptrChildMenu->addAction(m_ptrActPic2.get());
	m_ptrChildMenu->addSeparator();

	m_ptrChildMenu->addAction(m_ptrActLogo1.get());
	m_ptrChildMenu->addAction(m_ptrActLogo2.get());
	m_ptrChildMenu->addAction(m_ptrActTimer.get());
	m_ptrChildMenu->addSeparator();

	m_ptrChildMenu->addMenu(m_ptrSubtitlesMenu.get());
 	m_ptrPopMenu->addMenu(m_ptrChildMenu.get());

	m_ptrSubtitlesMenu->addAction(m_ptrActSubtitles1.get());
	m_ptrSubtitlesMenu->addAction(m_ptrActSubtitles2.get());
	m_ptrSubtitlesMenu->addAction(m_ptrActSubtitles3.get());
	m_ptrSubtitlesMenu->addAction(m_ptrActSubtitles4.get());
	 
	FlatUIEx::Instance()->SetMenuQss(m_ptrPopMenu.get());
	FlatUIEx::Instance()->SetMenuQss(m_ptrChildMenu.get());
	FlatUIEx::Instance()->SetMenuQss(m_ptrSubtitlesMenu.get());
  }

void PreviewMonitorWindow::InitActions()
{
	m_ptrActPic1.reset(new QAction(QString::fromLocal8Bit("»­ÖÐ»­1"), this));
	m_ptrActPic2.reset(new QAction(QString::fromLocal8Bit("»­ÖÐ»­2"), this));
	m_ptrActLogo1.reset(new QAction(QString::fromLocal8Bit("LOGO1"), this));
	m_ptrActLogo2.reset(new QAction(QString::fromLocal8Bit("LOGO2"), this));
	m_ptrActTimer.reset(new QAction(QString::fromLocal8Bit("Ê± ÖÓ"), this));
	
	m_ptrActSubtitles1.reset(new QAction(QString::fromLocal8Bit("×ÖÄ»1"), this));
	m_ptrActSubtitles2.reset(new QAction(QString::fromLocal8Bit("×ÖÄ»2"), this));
	m_ptrActSubtitles3.reset(new QAction(QString::fromLocal8Bit("×ÖÄ»3"), this));
	m_ptrActSubtitles4.reset(new QAction(QString::fromLocal8Bit("×ÖÄ»4"), this));
   
}
void PreviewMonitorWindow::InitConnects()
{
	connect(m_ptrActPic1.get(), SIGNAL(triggered()), this, SLOT(OnActPic1()));
	connect(m_ptrActPic2.get(), SIGNAL(triggered()), this, SLOT(OnActPic2()));
	connect(m_ptrActLogo1.get(), SIGNAL(triggered()), this, SLOT(OnActLogo1()));
	connect(m_ptrActLogo2.get(), SIGNAL(triggered()), this, SLOT(OnActLogo2()));
	connect(m_ptrActTimer.get(), SIGNAL(triggered()), this, SLOT(OnActTimer()));

	connect(m_ptrActSubtitles1.get(), SIGNAL(triggered()), this, SLOT(OnActSubtitles1()));
	connect(m_ptrActSubtitles2.get(), SIGNAL(triggered()), this, SLOT(OnActSubtitles2()));
	connect(m_ptrActSubtitles3.get(), SIGNAL(triggered()), this, SLOT(OnActSubtitles3()));
	connect(m_ptrActSubtitles4.get(), SIGNAL(triggered()), this, SLOT(OnActSubtitles4()));
}

void	PreviewMonitorWindow::OnActPic1() {
	int i = 0;
}
void	PreviewMonitorWindow::OnActPic2() {
	int i = 0;
}
void	PreviewMonitorWindow::OnActLogo1() {
	int i = 0;
}
void	PreviewMonitorWindow::OnActLogo2() {
	int i = 0;
}
void	PreviewMonitorWindow::OnActTimer() {
	int i = 0;
}
void	PreviewMonitorWindow::OnActSubtitles1() {
	int i = 0;
}
void	PreviewMonitorWindow::OnActSubtitles2() {
	int i = 0;
}
void	PreviewMonitorWindow::OnActSubtitles3() {
	int i = 0;
}
void	PreviewMonitorWindow::OnActSubtitles4() {
	int i = 0;
}


void PreviewMonitorWindow::mousePressEvent(QMouseEvent *pEvent)      //µ¥»÷
{
	 if (pEvent->button() == Qt::RightButton)
	{
		QPoint pos; //»ñÈ¡°´¼ü²Ëµ¥µÄ×ø±ê

		int y = pos.y();
 		pos.setY(y + this->geometry().height());
 		 
		m_ptrPopMenu->exec(QCursor::pos());
	}
 }


void PreviewMonitorWindow::resizeEvent(QResizeEvent* pEvent)
{
	int iWidth = this->width();
	int iHeight = this->height();

	if (m_ptrTitleLabel)
	{
		m_ptrTitleLabel->setGeometry(0, 0, iWidth - 80, 30);
		m_ptrTitleLabel->move(5, 0);
	}

	if (m_ptrPvwWindow)
	{
		m_ptrPvwWindow->setGeometry(0, 0, iWidth - 31, iHeight - 50);
		m_ptrPvwWindow->move(5, 30);
	}
  
	if (m_ptrVolumeMeter)
	{
		m_ptrVolumeMeter->setGeometry(0, 0, 16, iHeight - 50);
		m_ptrVolumeMeter->move(iWidth - 21, 30);
	}


	QWidget::resizeEvent(pEvent);
}

void PreviewMonitorWindow::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(50, 50, 50));
	painter.setPen(QColor(210, 210, 210));
}