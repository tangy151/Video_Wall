#include "pictureeditorwindow.h"
#include "../globaldefine.h"
 #include "../headfiledefine.h"
#include "../Controls/flatuiex.h"
#include "../Controls/buttonex.h"
#include "../Controls/navlabelex.h"
#include "../runtimedata.h"


PictureEditorWindow::PictureEditorWindow(QWidget *parent)
	: QDialog(parent)
{
#if PIX_1080p
	this->resize(1190, 690);
#else
	this->resize(1000, 600);
#endif


	Qt::WindowFlags m_flags = windowFlags();
	m_iNormalBgColor = QColor(50, 50, 50);
	m_iHoverBgColor = QColor(50, 50, 50);
	m_iCheckBgColor = QColor(50, 50, 50);
	m_iNormalFrameColor = QColor(30, 30, 30);

	m_iNormalTextColor = QColor(255, 255, 255);
	m_iHoverTextColor = QColor(255, 255, 255);
	m_iCheckTextColor = QColor(255, 255, 255);
	setWindowFlags(m_flags | Qt::WindowStaysOnTopHint);


	//设置标题栏隐藏
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

	InitUI();
	InitConnect();
}

PictureEditorWindow::~PictureEditorWindow()
{
}
void	PictureEditorWindow::InitConnect()
{
	connect(m_ptrCloseBtn.get(), SIGNAL(clicked()), this, SLOT(OnButtonClose()));
 }

void PictureEditorWindow::InitUI()
{
	InitButtons();
	InitLabels();
}

void PictureEditorWindow::InitButtons()

{
	m_ptrCloseBtn.reset(new ButtonEx(this));

	m_ptrCloseBtn->setPaddingLeft(0);
	m_ptrCloseBtn->setShowLine(false);
	m_ptrCloseBtn->setShowIcon(false);
	m_ptrCloseBtn->setIconSpace(0);
	m_ptrCloseBtn->setTextAlign(ButtonEx::TextAlign_Center);

	m_ptrCloseBtn->setText(QString::fromLocal8Bit("X"));

	m_ptrCloseBtn->setTextAlign(ButtonEx::TextAlign_Center);
	m_ptrCloseBtn->setFont(QFont("Microsoft YaHei", 10, 75));

	m_ptrCloseBtn->setHoverBgColor(QColor(50, 50, 50));
	m_ptrCloseBtn->setCheckBgColor(QColor(50, 50, 50));
	m_ptrCloseBtn->setNormalBgColor(QColor(50, 50, 50));
	m_ptrCloseBtn->setHoverTextColor(QColor(239, 98, 234));
	m_ptrCloseBtn->setNormalFrameColor(QColor(50, 50, 50));

	m_ptrCloseBtn->setNormalTextColor(QColor(200, 200, 200));
	m_ptrCloseBtn->setCheckTextColor(m_iCheckTextColor);
}


void PictureEditorWindow::InitLabels()
{
	m_ptrTitle.reset(new NavLabelEx(this));

	QFont font1("Microsoft YaHei", 10, 75);
	m_ptrTitle->setFont(font1);

	m_ptrTitle->setTextAlign(NavLabelEx::TextAlign_Left);
	m_ptrTitle->setShowIcon(false);
	m_ptrTitle->setIconSize(QSize(0, 0));
	m_ptrTitle->setText(QString::fromLocal8Bit("图片编辑器"));
	m_ptrTitle->setNormalBgColor(QColor(50, 50, 50));
	m_ptrTitle->setNormalTextColor(QColor(220, 220, 220));
}


void PictureEditorWindow::OnButtonClose()
{
	close();
}
 
void PictureEditorWindow::resizeEvent(QResizeEvent *pEvent)
 {
	int iWidth = this->width();
	int iHeight = this->height();

	if (m_ptrTitle)
	{
		m_ptrTitle->setGeometry(0, 0, 150, 30);
		m_ptrTitle->move(1, 0);
	}

	if (m_ptrCloseBtn)
	{
		m_ptrCloseBtn->setGeometry(0, 0, 25, 25);
		m_ptrCloseBtn->move(iWidth - 27, 0);
	}
}

void PictureEditorWindow::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);

	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(50, 50, 50));
	painter.setPen(QColor(210, 210, 210));

	painter.setClipRect(0, 0, width(), height());
	painter.fillRect(QRectF(8, 30, width() - 380, height() - 38), QColor(30, 30, 30));

	painter.setClipRect(0, 0, width(), height());
	painter.fillRect(QRectF(width() - 365, 30, 358, height() - 250), QColor(30, 30, 30));

	painter.setClipRect(0, 0, width(), height());
	painter.fillRect(QRectF(width() - 365, height() - 212, 358, height() / 4 + 32), QColor(30, 30, 30));
}

void PictureEditorWindow::mousePressEvent(QMouseEvent * pEvent)
 {
	//只能是鼠标左键移动和改变大小
	if (pEvent->button() == Qt::LeftButton)
		m_bMousePress = true;

	//窗口移动距离
	m_iMovePoint = pEvent->globalPos() - pos();
}

void PictureEditorWindow::mouseReleaseEvent(QMouseEvent*pEvent)
{
	m_bMousePress = false;
 }

void PictureEditorWindow::mouseMoveEvent(QMouseEvent *pEvent)
{
	//移动窗口
	if (m_bMousePress)
	{
		QPoint move_pos = pEvent->globalPos();
		move(move_pos - m_iMovePoint);
	}
}
