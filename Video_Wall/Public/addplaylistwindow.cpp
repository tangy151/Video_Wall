#include "addplaylistwindow.h"
#include "../headfiledefine.h"

#include "../Controls/flatuiex.h"
#include "../Controls/buttonex.h"
#include "../Controls/navlabelex.h"

AddPlayListWindow::AddPlayListWindow(QWidget *parent)
	: QDialog(parent)
{
	m_strPlayListName = "";
	this->resize(300, 125);

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

AddPlayListWindow::~AddPlayListWindow()
{
}
  
void AddPlayListWindow::InitConnect()
{
	connect(m_ptrOK.get(), SIGNAL(clicked()), this, SLOT(OnButtonOK()));
	connect(m_ptrCancel.get(), SIGNAL(clicked()), this, SLOT(OnButtonCancel()));
	connect(m_ptrCloseBtn.get(), SIGNAL(clicked()), this, SLOT(OnButtonClose()));
 }

void AddPlayListWindow::InitUI()
{
	InitButtons();
	InitLabels();
	InitLineEdit();
 }

void AddPlayListWindow::InitButtons()
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

		 
		if (bClose )
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
 			pButtonEx->setNormalBgColor(/*m_iNormalBgColor*/QColor(30,30,30));

			pButtonEx->setHoverTextColor(m_iHoverTextColor);
			pButtonEx->setNormalFrameColor(/*m_iNormalFrameColor*/QColor(50,50,50));

 		}
	 
 		pButtonEx->setNormalTextColor(QColor(200,200,200));
 		pButtonEx->setCheckTextColor(m_iCheckTextColor);
 	}
 }

void AddPlayListWindow::InitLabels()
{
	//---------------------------------------------
	m_ptrTitle.reset(new NavLabelEx(this));

 
 	QFont font1("Microsoft YaHei", 10, 75);
	m_ptrTitle->setFont(font1);

	m_ptrTitle->setTextAlign(NavLabelEx::TextAlign_Left);
	m_ptrTitle->setShowIcon(false);
	m_ptrTitle->setIconSize(QSize(0, 0));
	m_ptrTitle->setText(QString::fromLocal8Bit("增加播出列表"));

	m_ptrTitle->setNormalBgColor(QColor(50, 50, 50));
	m_ptrTitle->setNormalTextColor(QColor(220, 220, 220));

	//---------------------------------------------
	m_ptrName.reset(new NavLabelEx(this));
	 
	QFont font2("Microsoft YaHei", 10, 75);
	m_ptrName->setFont(font2);

	m_ptrName->setTextAlign(NavLabelEx::TextAlign_Left);
	m_ptrName->setShowIcon(false);
	m_ptrName->setIconSize(QSize(0, 0));
	m_ptrName->setText(QString::fromLocal8Bit("列表名称"));

	m_ptrName->setNormalBgColor(QColor(30, 30, 30));
	m_ptrName->setNormalTextColor(QColor(220, 220, 220));
}

void AddPlayListWindow::InitLineEdit()
{
 	m_ptrListNameEdit.reset(new QLineEdit(this));

	m_ptrListNameEdit->setGeometry(QRect(0, 0, 200, 30));
	m_ptrListNameEdit->setFixedSize(QSize(200, 30));
	m_ptrListNameEdit->setFont(QFont("Microsoft Yahei", 10));
	FlatUIEx::Instance()->setLineEditQss(m_ptrListNameEdit.get());
}

void AddPlayListWindow::OnButtonOK()
{
	//this->hide();
 	QString strText = m_ptrListNameEdit->text();
	emit OnAddPlayListNotify(strText);

	m_strPlayListName = strText;
	m_ptrListNameEdit->setText("");
	close();
 }

void AddPlayListWindow::OnButtonCancel()
{
	//this->hide();
 	m_ptrListNameEdit->setText("");
	close();
 }

void AddPlayListWindow::OnButtonClose()
{
	//this->hide();
	m_ptrListNameEdit->setText("");
	close(); 
}

void AddPlayListWindow::resizeEvent(QResizeEvent *pEvent)
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

	if (m_ptrName)
	{
		m_ptrName->setGeometry(0, 0, 100, 30);
		m_ptrName->move(6, 45);
	}

	if (m_ptrListNameEdit)
	{
		//m_ptrListNameEdit->setGeometry(0, 0, iWidth/2+30, 25);
		m_ptrListNameEdit->move(iWidth /4 , 45);
	}
	 
	if (m_ptrOK)
	{
		m_ptrOK->setGeometry(0, 0, 75, 25);
		m_ptrOK->move(iWidth / 2- 75, iHeight - 35);
	}

	if (m_ptrCancel)
	{
		m_ptrCancel->setGeometry(0, 0, 75, 25);
		m_ptrCancel->move(iWidth / 2+50, iHeight - 35);
	}
 }

void AddPlayListWindow::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);
	 
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(50, 50, 50));
	painter.setPen(QColor(210, 210, 210));

	painter.setClipRect(0, 0, width(), height());
	painter.fillRect(QRectF(6, 25, width()-12, height()- 30),   QColor(30, 30, 30)  );
 }

void AddPlayListWindow::mousePressEvent(QMouseEvent * pEvent)
{
	//只能是鼠标左键移动和改变大小
	if (pEvent->button() == Qt::LeftButton)
		m_bMousePress = true;

	//窗口移动距离
	m_iMovePoint = pEvent->globalPos() - pos();
}
void AddPlayListWindow::mouseReleaseEvent(QMouseEvent*pEvent)
{
	m_bMousePress = false;
 }

void AddPlayListWindow::mouseMoveEvent(QMouseEvent *pEvent)
{
	if (m_bMousePress)
	{
		QPoint move_pos = pEvent->globalPos();
		move(move_pos - m_iMovePoint);
	}
}


