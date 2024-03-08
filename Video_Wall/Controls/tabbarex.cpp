#include "tabbarex.h"
#include "../headfiledefine.h"

TabBarEx::TabBarEx(QWidget *parent)
	: QTabBar(parent)
{
}

TabBarEx::~TabBarEx()
{
}
 
int TabBarEx::OnAddTab(QWidget *widget, const QString & strTitle)
{
 return	addTab(strTitle);
}
 