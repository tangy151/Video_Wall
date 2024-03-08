#include "ribbonsection.h"

RibbonSection::RibbonSection(const QString& title)
{
	setObjectName("RibbonSection");
	m_pMainLayout = new QVBoxLayout();
	m_pMainLayout->setAlignment(Qt::AlignLeft);
	m_pMainLayout->setContentsMargins(3, 0, 3, 0);
	m_pMainLayout->setSpacing(0);

	setLayout(m_pMainLayout);
	m_pContentLayout = new QHBoxLayout();
	m_pContentLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	m_pContentLayout->setMargin(0);
	m_pContentLayout->setSpacing(0);
	m_pMainLayout->addLayout(m_pContentLayout);

	m_pMainLayout->addItem(new QSpacerItem(0, 1));

	m_pTitleLabel = new QLabel(title);
	m_pTitleLabel->setObjectName("ribbon_label");
	m_pTitleLabel->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	m_pMainLayout->addWidget(m_pTitleLabel);
}

RibbonSection::~RibbonSection()
{
	delete m_pMainLayout;
}
 
void RibbonSection::AddWidgets(QWidget* a, QWidget* b, QWidget* c)
{
	if (b == 0x0 && c == 0x0)
	{
		GetContentLayout()->addWidget(a);
		return;
	}
	else
	{
		QVBoxLayout* layout = new QVBoxLayout();
		//layout->setMargin(0);
		//??layout->setAlignment(Qt::AlignTop);
		GetContentLayout()->addLayout(layout, 1);
		if (a)
		{
			layout->addWidget(a, 1);
			layout->addItem(new QSpacerItem(1, 1, QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Expanding));
		}
		if (b)
		{
			layout->addWidget(b, 1);
			layout->addItem(new QSpacerItem(1, 1, QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Expanding));
		}
		if (c)
			layout->addWidget(c, 1);
	}
}

void RibbonSection::AddQuad(QWidget* topLeft, QWidget* bottomLeft, QWidget* topRight, QWidget* bottomRight)
{
	QHBoxLayout* baseLayout = new QHBoxLayout();
	baseLayout->setMargin(0);

	QVBoxLayout* topLayout = new QVBoxLayout();
	topLayout->setMargin(0);
	topLayout->addWidget(topLeft);
	topLayout->addWidget(bottomLeft);

	QVBoxLayout* bottomLayout = new QVBoxLayout();
	bottomLayout->setMargin(0);
	bottomLayout->addWidget(topRight);
	bottomLayout->addWidget(bottomRight);

	baseLayout->addLayout(topLayout);
	baseLayout->addLayout(bottomLayout);
}










