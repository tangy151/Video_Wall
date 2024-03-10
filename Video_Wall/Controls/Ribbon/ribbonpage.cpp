#include "ribbonpage.h"
#include "ribbonsection.h"
#include <QFrame>
#include "ribbon.h"

RibbonPage::RibbonPage(const QString& pageTitle) 
	: QWidget()
	, m_strPageTitle(pageTitle)
{
	setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	m_pSectionsLayout = new QHBoxLayout(this);
	m_pSectionsLayout->setAlignment(Qt::AlignLeft);
	m_pSectionsLayout->setMargin(0);
	m_pSectionsLayout->setSpacing(0);
	m_pSectionsLayout->addItem(new QSpacerItem(1, 1, QSizePolicy::Expanding));
}

RibbonPage::~RibbonPage()
{
	for (auto section : m_vecSections)
	{
		delete section;
 	}

	delete m_pSectionsLayout;
}

void RibbonPage::AddSection(RibbonSection* section)
{
	if (m_vecSections.size() > 0)
	{
		QFrame* line = new QFrame();
		line->setFixedWidth(1);
		line->setFrameShape(QFrame::VLine);
		line->setFrameShadow(QFrame::Plain);
		m_pSectionsLayout->insertWidget(m_pSectionsLayout->count() - 1, line, 0, Qt::AlignLeft);
		//m_pSectionsLayout->addWidget(line);
	}

	m_vecSections.push_back(section);
	m_pSectionsLayout->insertWidget(m_pSectionsLayout->count() - 1, section, 0, Qt::AlignLeft);
	//m_pSectionsLayout->addWidget(section);
}

RibbonSection* RibbonPage::GetSection(unsigned index)
{
	if (index < m_vecSections.size())
		return m_vecSections[index];

	return 0x0;
}

RibbonSection* RibbonPage::RemoveSection(unsigned index)
{
	if (index < m_vecSections.size())
	{
		auto ret = m_vecSections[index];
		m_pSectionsLayout->removeWidget(m_vecSections[index]);
		m_vecSections.erase(m_vecSections.begin() + index);
	
		return ret;
	}
	return 0x0;
}

RibbonSection* RibbonPage::RemoveSection(RibbonSection* section)
{
	auto found = std::find(m_vecSections.begin(), m_vecSections.end(), section);
	if (found != m_vecSections.end())
	{
		m_pSectionsLayout->removeWidget(*found);
		m_vecSections.erase(found);
	
		return section;
	}
	return nullptr;
}

void RibbonPage::SetPageTitle(const QString& title)
{
	m_strPageTitle = title;
	//TODO send event
}

void RibbonPage::SetActive(bool state)
{
	m_bActive = state;
	emit ActiveChanged(this);
}


