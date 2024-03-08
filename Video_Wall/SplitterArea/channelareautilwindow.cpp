#include "channelareautilwindow.h"
#include "../headfiledefine.h"
#include "../VideoChannel/channelwindow.h"
#include "../globaldefine.h"
 
#include "../runtimedata.h"

ChannelAreaUtilWindow::ChannelAreaUtilWindow(QWidget *parent)
	: QWidget(parent)
	, m_ptrSelectMediaSourceWindow(nullptr)
{
	InitUI();
}

ChannelAreaUtilWindow::~ChannelAreaUtilWindow()
{
}

void ChannelAreaUtilWindow::InitUI()
{ 
	m_ptrSelectMediaSourceWindow.reset(new SelectMediaSourceWindow(QApplication::activeWindow()));
	m_ptrSelectMediaSourceWindow->hide();
	OnGetRuntimeData().OnSetSelectMediaSourceWindow(m_ptrSelectMediaSourceWindow.get());
	  
	for (int iIndex = 0; iIndex < CHANNEL_COUNT; iIndex++)
	{
		ChannelWindow*	 pChanMgrWnd = new ChannelWindow(this);
		pChanMgrWnd->SetChannelIndex(iIndex + 1);
		m_vecChannelWindows.push_back(pChanMgrWnd);
	}

 }

void ChannelAreaUtilWindow::SetChannelIndex(int iChannelIndex)
{
}

void ChannelAreaUtilWindow::resizeEvent(QResizeEvent *pEvent)
{
	int iWidth		= width();
	int iHeight	= height();

#if PIX_1080p 
	int iColWidth = (iWidth - CHAN_GAP * 5) / COL;
	int iRowHeight = (iHeight - CHAN_GAP) / ROW;
 #else


	int iColWidth = (iWidth - CHAN_GAP * 4) / COL;
	int iRowHeight = (iHeight - CHAN_GAP) / ROW;
 #endif

	int iCount = 0;
 
	int iSize = m_vecChannelWindows.size();
	if (iSize > 0)
	{
		for (int iCol = 1; iCol <= ROW; iCol++)
		{
			for (int iRow = 1; iRow <= COL; iRow++)
			{
				ChannelWindow*	 pChanMgrWnd1 = m_vecChannelWindows[iCount++];
				pChanMgrWnd1->setGeometry(0, 0, iColWidth, iRowHeight);
				pChanMgrWnd1->move((iRow - 1)*iColWidth + CHAN_GAP * iRow, (iCol - 1)*iRowHeight);
			}
		}
 	}
	 
	this->update();
 }

void ChannelAreaUtilWindow::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(50, 50, 50));
	painter.setPen(QColor(210, 210, 210));
}




