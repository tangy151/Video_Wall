#include "channelwindow.h"
#include "../headfiledefine.h"
#include "previewwindow.h"

#include "../Controls/flatuiex.h"

ChannelWindow::ChannelWindow(QWidget *parent)
	: QWidget(parent)
	, m_ptPreviewWindow(nullptr)
	, m_ptrTitleLabel(nullptr)
	, m_iChannelIndex(0)
{
	InitUI();
}

ChannelWindow::~ChannelWindow()
{
}

void ChannelWindow::InitUI()
{
	m_ptPreviewWindow.reset(new PreviewWindow(this));
	m_ptrTitleLabel.reset(new QLabel(this));
	 
	FlatUIEx::Instance()->SetLabelQss(m_ptrTitleLabel.get(), "rgb(50,50,50)", "rgb(235,235,235)");
}

void ChannelWindow::SetChannelIndex(int iChannelIndex)
{
	m_iChannelIndex = iChannelIndex;

	char szBuffer[20];
	memset(szBuffer, 0, 20);

	sprintf_s(szBuffer, "%d", iChannelIndex);

	QString strTitle = szBuffer;

	strTitle += QString::fromLocal8Bit(":<¿ÕµÄ>");

	if (m_ptrTitleLabel)
	{
		m_ptrTitleLabel->setText(strTitle);
 	}
 }

void ChannelWindow::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(255, 50, 150));
	painter.setPen(QColor(210, 210, 210));

}

void ChannelWindow::resizeEvent(QResizeEvent* pEvent)
{
	int iWidth = width();
	int iHeight = height();
	 
	if (m_ptrTitleLabel)
	{
		m_ptrTitleLabel->setGeometry(0, 0, iWidth, iHeight / 5);
		m_ptrTitleLabel->move(0, 0);
	}

	if (m_ptPreviewWindow)
	{
		m_ptPreviewWindow->setGeometry(0, 0, iWidth, iHeight - (iHeight / 5));
		m_ptPreviewWindow->move(0, iHeight / 5 );
	}
}






