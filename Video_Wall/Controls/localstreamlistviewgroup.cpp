#include "localstreamlistviewgroup.h"
#include "../headfiledefine.h"
#include "../Controls/navlabelex.h"
#include "localstreamlistitemex.h"

LocalStreamListViewGroup::LocalStreamListViewGroup(QWidget *parent)
	: QWidget(parent)
	, m_pLocalStreamListItemEx(nullptr)
{
	this->setFixedHeight(25);
	m_strExePath = QCoreApplication::applicationDirPath();

//	InitLabelEx();
	InitConnect();
 }

LocalStreamListViewGroup::~LocalStreamListViewGroup()
{
}

void LocalStreamListViewGroup::InitLabelEx()
{ 
// 	m_ptrGroupName.reset(new NavLabelEx(this));
// 
// 	QFont font1("Microsoft YaHei", 10, 75);
// 	m_ptrGroupName->setFont(font1);
// 
// 	m_ptrGroupName->setTextAlign(NavLabelEx::TextAlign_Left);
// 	m_ptrGroupName->setShowIcon(false);
// 	m_ptrGroupName->setIconSize(QSize(0, 0));
// 	m_ptrGroupName->setText(QString::fromLocal8Bit("Ìí¼ÓÍøÂçÁ÷"));
// 
// 	m_ptrGroupName->setNormalBgColor(QColor(50, 50, 50));
// 	m_ptrGroupName->setNormalTextColor(QColor(220, 220, 220));
 }

void LocalStreamListViewGroup::InitConnect()
{

}
 
void  LocalStreamListViewGroup::OnSetLocalStreamListItemEx(LocalStreamListItemEx* pItem)
{
	m_pLocalStreamListItemEx = pItem;
}
 
void LocalStreamListViewGroup::mousePressEvent(QMouseEvent *pEvent)
{
}

void LocalStreamListViewGroup::resizeEvent(QResizeEvent *pEvent)
{
	int iWidth = width();
	int iHeight = height();

// 	if (m_ptrGroupName)
// 	{
// 		m_ptrGroupName->setGeometry(0, 0, 420, iHeight);
// 		m_ptrGroupName->move(0, 0);
// 	}
}

void LocalStreamListViewGroup::paintEvent(QPaintEvent* pEvent) 
 {
	QPainter painter(this);
	//   	painter.setRenderHint(QPainter::Antialiasing, true);
	//   	painter.fillRect(this->rect(), m_bEntered ? QColor(120,0,0) : QColor("transparent"));

  
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(30, 30, 30));
	painter.setPen(QColor(210, 210, 210));
	painter.save();
	painter.setBrush(Qt::NoBrush);


	int w = this->rect().width();
	int h = this->rect().height();

	QFont font("Î¢ÈíÑÅºÚ", 12, 75);
	QPen pen;
	 
	// »æÖÆÃû×Ö
  	pen.setColor(QColor(150, 100, 120));
	font.setPixelSize(12);
	painter.setPen(pen);
	painter.setFont(font);
	painter.drawText(10, 4, w / 2, h - 2, Qt::AlignLeft, m_pLocalStreamListItemEx->m_strGroupName);
 }



