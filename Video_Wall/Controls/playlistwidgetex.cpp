#include "playlistwidgetex.h"

#include "../headfiledefine.h"
#include "playlistpageex.h"
#include "playlistsectionex.h"
#include "tabbarex.h"
#include "flatuiex.h"
 
PlayListWidgetEx::PlayListWidgetEx(QWidget *parent)
	: QTabWidget(parent)
{
	setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
	setMovable(true);
	setTabsClosable(false);
	QString  strExePath = QCoreApplication::applicationDirPath();

	m_vecAllPages.clear();

	InitUI();
	InitConnects();
}

PlayListWidgetEx::~PlayListWidgetEx()
{
}

void PlayListWidgetEx::InitUI()
{
	m_ptrTabBarEx.reset(new TabBarEx(this));
	this->setTabBar(m_ptrTabBarEx.get());

	m_ptrTabBarEx->setFixedHeight(30);
	m_ptrTabBarEx->setMaximumHeight(30);
	m_ptrTabBarEx->setFont(QFont("Microsoft YaHei", 9, 75));

	FlatUIEx::Instance()->SetTabBarQss(m_ptrTabBarEx.get(), "rgb(30,30,30)", "rgb(230,230,230)");
}

void PlayListWidgetEx::InitConnects()
{
	connect(this, &QTabWidget::tabBarClicked, this, &PlayListWidgetEx::TabClicked);
}

void PlayListWidgetEx::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);
	painter.setClipRect(0, 0, width(), height());
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	painter.fillRect(QRectF(0, 0, width(), height()), QColor(50, 50, 50));
	painter.setPen(QColor(210, 210, 210));
}

void PlayListWidgetEx::resizeEvent(QResizeEvent* pEvent)
{
	int iWidth = width();
	int iHeight = height();

	int iSize = m_vecAllPages.size();

	for (int iIndex = 0; iIndex < iSize; iIndex++)
	{
		PlayListPageEx* 	ptrTabPageEx = nullptr;
		ptrTabPageEx = m_vecAllPages[iIndex];

		ptrTabPageEx->setGeometry(0, 0, iWidth, iHeight);
		ptrTabPageEx->move(0, 0);
		ptrTabPageEx->update();
	}

	QWidget::resizeEvent(pEvent);
}

void PlayListWidgetEx::AddPage(QString strPageName)
{
	PlayListPageEx* 	ptrTabPageEx = nullptr;
	ptrTabPageEx = new PlayListPageEx(this, strPageName);

	if (ptrTabPageEx->IsActive())
		addTab(ptrTabPageEx, ptrTabPageEx->GetPageTitle());

	connect(ptrTabPageEx, &PlayListPageEx::ActiveChanged, this, &PlayListWidgetEx::PageActivityChanged);

	m_vecAllPages.push_back(ptrTabPageEx);
	emit PageAdded(ptrTabPageEx);
}
 
int PlayListWidgetEx::GetPageCount()
{
	int iCount = m_vecAllPages.size();
	return iCount;
 }
void PlayListWidgetEx::RemovePage(QString strPageName)
{
 	std::vector<PlayListPageEx*>::iterator itVec = m_vecAllPages.begin();

	for (;itVec != m_vecAllPages.end();++itVec)
	{
		PlayListPageEx* pPage = (*itVec);

		if (pPage->GetPageTitle() == strPageName)
		{
			int index = indexOf(pPage);

			if (index != -1)
				removeTab(index);

			m_vecAllPages.erase(itVec);

			break;;
		}
 	}
}

void PlayListWidgetEx::RemovePage(PlayListPageEx* pPage)
{
	int index = indexOf(pPage);

	if (index != -1)
		removeTab(index);

	disconnect(pPage, &PlayListPageEx::ActiveChanged, this, &PlayListWidgetEx::PageActivityChanged);
	auto found = std::find(m_vecAllPages.begin(), m_vecAllPages.end(), pPage);

	if (found != m_vecAllPages.end())
		m_vecAllPages.erase(found);

	emit PageRemoved(pPage);
}

bool PlayListWidgetEx::IsAutoHide()
{
	return m_bAutoHide;
}
PlayListPageEx* PlayListWidgetEx::GetPage(unsigned index)
{
	return (PlayListPageEx*)widget(index);
}

void PlayListWidgetEx::SetAutoHide(bool state)
{
	m_bAutoHide = state;
}

void PlayListWidgetEx::PageActivityChanged(PlayListPageEx* pPage)
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

void PlayListWidgetEx::TabClicked(int index)
{
	if (m_bAutoHide)
	{
		if (QWidget* showTab = widget(index))
		{
			if (((PlayListPageEx*)showTab)->IsActive())
			{
				if (showTab->isVisible())
				{
					showTab->setVisible(false);
					setFixedHeight(tabBar()->height());
					updateGeometry();
				}
				else
				{
					showTab->setVisible(true);
					setFixedHeight(m_bOldHeight);
					updateGeometry();
				}
			}
		}
	}
}

void PlayListWidgetEx::HandleApplicationButton(bool bHide)
{
	emit ApplicationButtonClicked();
}
