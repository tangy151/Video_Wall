#include "ribbon.h"

#include <QPushButton>
#include <QTabBar>
#include <QToolButton>
#include <QtCore/QCoreApplication>
#include <QHBoxLayout>

//#include "applicationcore.h"
#include "ribbonpage.h"

Ribbon::Ribbon(QWidget* parent)
	: QTabWidget(parent)
{
	setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
	setMovable(false);
	setTabsClosable(false);
	setContentsMargins(0, 0, 0, 0);
	setDocumentMode(false);
	connect(this, &QTabWidget::tabBarClicked, this, &Ribbon::TabClicked);

	QString  strExePath = QCoreApplication::applicationDirPath();

	QString strIcon = "";

	// Top Right section for toggle/settings
	{
// 		QToolButton* settingsBtn = new QToolButton();
// 
// 		strIcon = strExePath + "/Images/godot/icon_tools.png";
// 
// 		settingsBtn->setIcon(QIcon(strIcon));
		
// 		settingsBtn->setToolTip(Localizer::Translate(QString::fromLocal8Bit("ÉèÖÃ")));
// 		connect(settingsBtn, &QToolButton::clicked, [](bool)
// 		{
// 			ConfigWindow::Show(Settings::GetInstance());
// 		});


// 		settingsBtn->setIconSize(QSize(24, 24));
// 
// 		strIcon = strExePath + "/Images/up_arrow.png";
// 
// 		m_pToggleRibbon = new QToolButton();
// 		m_pToggleRibbon->setIcon(QIcon(strIcon));
// 		//m_pToggleRibbon->setToolTip(Localizer::Translate(QString::fromLocal8Bit("Toggle ribbon expansion")));
// 		m_pToggleRibbon->setCheckable(true);
// 		m_pToggleRibbon->setChecked(true);

// 		QWidget* widget = new QWidget();
// 		QHBoxLayout* layout = new QHBoxLayout(widget);
// 		layout->setMargin(0);
// 		layout->setSpacing(0);
// 		layout->addWidget(settingsBtn);
// 		layout->addWidget(m_pToggleRibbon);
// 
// 		setCornerWidget(widget);
// 
// 		connect(m_pToggleRibbon, &QToolButton::toggled, this, &Ribbon::SetRibbonDisplayed);
// 		connect(m_pToggleRibbon, &QToolButton::toggled, [=](bool state)
// 		{
// 			if (state)
// 			{
// 				m_pToggleRibbon->setIcon(QIcon(strExePath + "/Images/up_arrow.png"));
//  			}
// 			else
// 			{
// 				m_pToggleRibbon->setIcon(QIcon(strExePath + "/Images/down_arrow.png"));
//  			}
// 		});
	}

	// Create the application button
	{
// 		QWidget* appButton = new QWidget();
// 		QHBoxLayout* layout = new QHBoxLayout(appButton);
// 		layout->setContentsMargins(3, 0, 7, 0);

// 		m_pApplicationButton = new QPushButton(QString::fromLocal8Bit("ÎÄ¼þ"));
// 		m_pApplicationButton->setObjectName("application_button");
// 		layout->addWidget(m_pApplicationButton);

// 		m_pDocumentButton = new OpenDocumentsButton();
// 		m_pDocumentButton->setObjectName("document_button");
// 		layout->addWidget(m_pDocumentButton);

		//setCornerWidget(appButton, Qt::Corner::TopLeftCorner);

		//connect(actualButton, &QPushButton::clicked, this, &Ribbon::HandleApplicationButton);
	}
}

Ribbon::~Ribbon()
{

}

void Ribbon::AddPage(RibbonPage* page)
{
	if (page->IsActive())
		addTab(page, page->GetPageTitle());

	connect(page, &RibbonPage::ActiveChanged, this, &Ribbon::PageActivityChanged);
	m_vecAllPages.push_back(page);

	emit PageAdded(page);

}

void Ribbon::RemovePage(RibbonPage* page)
{
	int index = indexOf(page);
	
	if (index != -1)
		removeTab(index);
	
	disconnect(page, &RibbonPage::ActiveChanged, this, &Ribbon::PageActivityChanged);
	auto found = std::find(m_vecAllPages.begin(), m_vecAllPages.end(), page);

	if (found != m_vecAllPages.end())
		m_vecAllPages.erase(found);

	emit PageRemoved(page);
}

void Ribbon::SetAutoHide(bool state)
{
	m_bAutoHide = state;
	SetRibbonDisplayed(state);
// 	Settings::GetInstance()->GetValue("Secret GUI State/Ribbon Collapsed")->m_iValue = m_bAutoHide;
}

void Ribbon::PageActivityChanged(RibbonPage* page)
{
	// Set the enabled/disabled state for the tab bar
	if (page->IsActive() && indexOf(page) == -1)
	{
		int lastActivePage = 0;
		const int numPages = count();
		for (int i = 0; i < m_vecAllPages.size(); ++i)
		{
			if (m_vecAllPages[i]->IsActive() && m_vecAllPages[i] != page)
			{
				++lastActivePage;
 			}
			else if (m_vecAllPages[i] == page)
			{
				insertTab(lastActivePage, page, page->GetPageTitle());
				break;
			}
		}
	}
	else if (!page->IsActive())
	{
		removeTab(indexOf(page));
 	}
}

void Ribbon::TabClicked(int index)
{
	if (m_bAutoHide)
	{
		if (QWidget* showTab = widget(index))
		{
			if (((RibbonPage*)showTab)->IsActive())
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

void Ribbon::SetRibbonDisplayed(bool showRibbon)
{
	m_bAutoHide = !showRibbon;
	
/*	if (!showRibbon)
	{
		for (int i = 0; i < count(); ++i)
		{
			widget(i)->setVisible(false);
 		}
		m_bOldHeight = height();
		setFixedHeight(tabBar()->height());
		updateGeometry();
	}
	else
	{
		for (int i = 0; i < count(); ++i)
		{
			widget(i)->setVisible(GetPage(i)->IsActive() && currentIndex() == i);
 		}

		setFixedHeight(m_bOldHeight);
		updateGeometry();
	}

	*/
}

void Ribbon::HandleApplicationButton(bool)
{
	emit ApplicationButtonClicked();
}

