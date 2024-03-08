#include "ribbonbutton.h"
 #include <QMenu>


RibbonButton::RibbonButton()
{
	//setFocusPolicy(Qt::FocusPolicy::ClickFocus);
	setObjectName("ribbon_button");
	InitLarge();
	setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
}

RibbonButton::RibbonButton(QAction* action)
{
	//setFocusPolicy(Qt::FocusPolicy::ClickFocus);
	setObjectName("ribbon_button");
	InitLarge();
	setDefaultAction(action);
	setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
}

void RibbonButton::InitLarge()
{
	m_iButtonType = 0;
	MakeLarge();
}

void RibbonButton::InitMedium()
{
	m_iButtonType = 1;
	MakeMedium();
}

void RibbonButton::InitSmall(bool wide)
{
	m_iButtonType = 2;
	m_bIsWide = wide;
	MakeSmall(wide);
}



void RibbonButton::MakeLarge()
{
	setMinimumSize(96, 96);
	setMaximumSize(96, 96);
	setIconSize(QSize(64, 64));
	setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
}

void RibbonButton::MakeMedium()
{
	setMinimumSize(48, 48);
	setMaximumSize(48, 48);
	setIconSize(QSize(32, 32));
	setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
}

void RibbonButton::MakeSmall(bool wide)
{
	setIconSize(QSize(16, 16));
	setMinimumSize(32, 32);
	setMaximumSize(5000, 32);

	m_bIsWide = wide;
	if (wide)
	{
		setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
 	}
	else
	{	
		setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
 	}
}

void RibbonButton::MakeRegular()
{
	setIconSize(QSize(32, 32));
	setMinimumSize(48, 48);
	setMaximumSize(5000, 48);
	m_bIsWide = true;
	setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
}

QSize RibbonButton::GetSizeForType(int btnType) const
{
	switch (btnType)
	{
	case 0:
		return QSize(96, 96);
	case 1:
		return QSize(64, 64);
	case 2:
	{
		if (m_bIsWide)
			return QSize(width(), 32);

		return QSize(32, 32);
	}
	}
	return QSize(64, 64);
}


