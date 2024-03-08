#include "flatuiex.h"

#include <QtCore/QMutex>
 #include "../headfiledefine.h"


QScopedPointer<FlatUIEx> FlatUIEx::m_ptrSelf;

FlatUIEx *FlatUIEx::Instance()
{
	if (m_ptrSelf.isNull())
	{
		QMutex mutex;
		QMutexLocker locker(&mutex);
		if (m_ptrSelf.isNull())
		{
			m_ptrSelf.reset(new FlatUIEx);
		}
	}

	return m_ptrSelf.data();
}

FlatUIEx::FlatUIEx(QObject *parent)
	: QObject(parent)
{
}

QString FlatUIEx::setPushButtonQss(QPushButton* pBtn,const QString& strNormalColor, const QString& strNormalTextColor,
	const QString& strHoverColor, const QString& strHoverTextColor, const QString& strPressedColor, const QString& strPressedTextColor)
{
	QStringList list;
// 	list.append(QString("QPushButton{border-style:none;color:%1;background:%2;}").arg(strNormalTextColor).arg(strNormalColor));
// 	
// 	list.append(QString("QPushButton:hover{color:%1;background:%2;}").arg(strHoverTextColor).arg(strHoverColor));
// 
// 	list.append(QString("QPushButton:pressed{color:%1;background:%2;}").arg(strPressedColor).arg(strPressedColor));


	list.append(QString("QPushButton{color:rgb(200,200,200);background-color:rgb(50,50,50); border-style:solid; border-width:1px;border-color:rgb(50,50,50);padding:1px; }"));

	list.append(QString("QPushButton:hover{color:rgb(200,200,200);background-color:rgb(50,50,50); border-style:solid; border-width:1px;border-color:rgb(255,0,0);padding:1px;}"));

	list.append(QString("QPushButton:pressed{color:rgb(0,0,0);background-color:rgb(255,0,0); border-style:solid; border-width:1px;border-color:rgb(0,0,0);padding:1px;}"));

	list.append(QString("QPushButton:checked{color:rgb(0,0,0);background-color:rgb(255,0,0); border-style:solid; border-width:1px;border-color:rgb(0,0,0);padding:1px;}"));


	QString qss = list.join("");
	pBtn->setStyleSheet(qss);
	return qss;
}

QString FlatUIEx::setQWidgetWndQss(QWidget* pWnd, const QString& strBKColor)
{
	QStringList list;
	list.append(QString("QWidget{background:%4}").arg(strBKColor));
 
  	QString qss = list.join("");
	pWnd->setStyleSheet(qss);

	return qss;
}


   QString FlatUIEx::setMenuBarQss(QMenuBar* pWnd,const QString& strBKColor,const QString& strItemColor,
	const QString& strItemSelectColor,
	const QString& strItemPressedColor)
{
 	   QStringList list;
	   list.append(QString("QMenuBar{color:rgba(180,180,180,255);background-color:%4;}")
		   .arg(strBKColor));
 	    
	  
	    list.append(QString("QMenuBar:item{background:transparent;}"));
	  
	   list.append(QString("QMenuBar:item:selected{background: transparent;border: 0 px solid #76797C;}"));
	   list.append(QString("QMenuBar:item:pressed{border: 0 px  ;background-color: #202020;color:rgba(255,255,255,255);}"));

	   QString qss = list.join("");
	   pWnd->setStyleSheet(qss);
	   return qss;

}
   QString FlatUIEx::SetMenuQss(QMenu* pMenu, const QString& strBKColor)
   {
	   QStringList list;
	   list.append(QString("QMenu{ color: rgba(255,255,255,255);background-color: rgba(70,70,70,255);margin: 1px;}"));
 	   list.append(QString("QMenu:icon{margin: 1px;}"));
 	   list.append(QString("QMenu:separator{height: 1px;background: rgba(235,235,236,255);margin-left: 1px;margin-right: 1px;}"));

	   list.append(QString("QMenu:item{padding: 2px 20px 2px 20px;margin-left: 2px;border: 1px solid transparent;}"));

	   list.append(QString("QMenu:item:selected{background-color : rgb(70,70,70); color: rgba(180,8,191,255);}"));


	   QString qss = list.join("");
	   pMenu->setStyleSheet(qss);
	   return qss;
	 }


   QString FlatUIEx::SetLabelQss(QLabel* pLabel, const QString& strBKColor, const QString& strFontColor)
    {
	   QStringList list;
	  
	   list.append(QString("QLabel{background-color:%1;color:%2;}").arg(strBKColor).arg(strFontColor));
   
	   QString qss = list.join("");
	   pLabel->setStyleSheet(qss);
	   return qss;
    }

   QString FlatUIEx::SetTabWidgetQss(QTabWidget* pTabWidget, const QString& strBKColor, const QString& strFontColor)
   {
	   QStringList list;

	   list.append(QString("QTabWidget{background-color:%1;color:%2;}").arg(strBKColor).arg(strFontColor));
  	   list.append(QString("QTabWidget::pane{background-color:rgb(30,30,30);}"));
	    
	   //------------------------------------------------

	   list.append(QString("QScrollBar::horizontal{padding:1px; height: 20px;margin: 2px 0px 0px 0px; border: 0px transparent rgb(30,30,30);border-radius: 0px;background-color: rgb(30,30,30); }"));

	   list.append(QString("QScrollBar::handle:horizontal{ background-color: rgb(50,50,50);min-width: 5px;border-radius: 0px;margin: 0px 0px 0px 0px;}"));

	   list.append(QString("QScrollBar::add-line:horizontal{ background:none;}"));
	   list.append(QString("QScrollBar::sub-line:horizontal{background:none;}"));

	   list.append(QString("QScrollBar::add-line:horizontal:hover{ background:none;}"));
	   list.append(QString("QScrollBar::add-line:horizontal:on{background:none;}"));

	   list.append(QString("QScrollBar::sub-line:horizontal:hover{ background:none;}"));
	   list.append(QString("QScrollBar::sub-line:horizontal:on{background:none;}"));

	   list.append(QString("QScrollBar::up-arrow:horizontal{background:none;}"));
	   list.append(QString("QScrollBar::down-arrow:horizontal{background:none;}"));

	   list.append(QString("QScrollBar::add-page:horizontal{ background:none;}"));
	   list.append(QString("QScrollBar::sub-page:horizontal{background:none;}"));

	   //--------------------------------------------------------------------

	   list.append(QString("QScrollBar:vertical{padding:1px;background-color: rgb(30,30,30);width: 20px; margin: 0px 0px 0px 2px;border: 0px transparent rgb(30,30,30);border-radius: 0px;}"));
	   list.append(QString("QScrollBar::handle:vertical{background-color: rgb(50,50,50);min-height: 5px;  border-radius: 0px; margin: 1px 1px 1px 1px;}"));

	   list.append(QString("QScrollBar::sub-line:vertical{ background:none;}"));
	   list.append(QString("QScrollBar::add-line:vertical{background:none;}"));

	   list.append(QString("QScrollBar::sub-line:vertical:hover{ background:none;}"));
	   list.append(QString("QScrollBar::sub-line:vertical:on{background:none;}"));

	   list.append(QString("QScrollBar::add-line:vertical:hover{ background:none;}"));
	   list.append(QString("QScrollBar::add-line:vertical:on{background:none;}"));

	   list.append(QString("QScrollBar::up-arrow:vertical{ background:none;}"));
	   list.append(QString("QScrollBar::down-arrow:vertical{background:none;}"));

	   list.append(QString("QScrollBar::add-page:vertical{ background:none;}"));
	   list.append(QString("QScrollBar::sub-page:vertical{background:none;}"));

	   QString qss = list.join("");
	   pTabWidget->setStyleSheet(qss);
	   return qss;
	
   }
   QString FlatUIEx::SetTabBarQss(QTabBar* pTabBar, const QString& strBKColor, const QString& strFontColor)
   {
	   QStringList list;
	    
	   list.append(QString("QTabBar::tab{color:rgb(230,230,230);background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 rgb(50,50,50),stop:1 rgb(50,50,50) );}"));
	    
	   list.append(QString("QTabBar::tab:top{padding:7px 7px 7px 7px;}"));
	   list.append(QString("QTabBar::tab:bottom{padding:7px 7px 7px 7px;}"));
	   list.append(QString("QTabBar::tab:left{padding:3 px 3px 3px 3px;}"));
	   list.append(QString("QTabBar::tab:right{padding:3 px 3px 3px 3px;}"));
	    
  	   list.append(QString("QTabBar::tab:selected{color:rgb(239, 98, 234) ;border-style:solid;border-color:#00BB9E;background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 rgb(50, 50, 50) ,stop:1 rgb(50, 50, 50) );}"));
	   list.append(QString("QTabBar::tab:hover{color:rgb(239, 98, 234) ;border-style:solid;border-color:rgb(120,100,0);background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 rgb(50, 50, 50) ,stop:1 rgb(50, 50, 50) );}"));
 
	    
	   QString qss = list.join("");
	   pTabBar->setStyleSheet(qss);
	   return qss;
 	 }

   QString FlatUIEx::SetListWidgetQss(QListWidget* pListWidget, const QString& strBKColor, const QString& strFontColor)
   {
	   QStringList list;
	    
	   //主背景颜色
	   list.append(QString("QListWidget{padding:5px %1px 10px %2px;border:none;outline:10px;color:rgb(10,255,230);background:rgb(50,50,50);}"));
	
	   //产生按下凹凸感
	   list.append(QString("QListWidget::item{margin-top:2px;}"));

	   //节点鼠标经过
	   list.append(QString("QListWidget::item:hover{color:%1;background:%2;}") );

	   //节点鼠标选中
	   list.append(QString("QListWidget::item:selected{color:rgb(12,155,89);background:rgb(211,100,198);}") );
	    
	   QString qss = list.join("");
	   pListWidget->setStyleSheet(qss);
	   return qss;
   }

   QString FlatUIEx::SetGraphicsViewQss(QGraphicsView* pView)
   {
	   QStringList list;

	   //主背景颜色
	   list.append(QString("QGraphicsView{background:rgb(30, 30,30); border: 0px;}"));
	    

	   QString qss = list.join("");
	   pView->setStyleSheet(qss);
	   return qss;
	 }

	QString FlatUIEx::SetTreeWidgetQss(QTreeWidget* pTreeWidget)
   {
		QStringList list;
		list.append(QString("QTreeWidget{border:1px; color:rgb(30,30,30); background:rgb(30,30,30); }"));

		list.append(QString("QTreeView::item:hover{background-color:rgb(0,255,0,50)}"));

		list.append(QString("QTreeWidget:hover{border: 1px solid rgb(239, 98, 234);}"));


		QString qss = list.join("");
		pTreeWidget->setStyleSheet(qss);


		return qss;
   }

//设置文本框样式
QString FlatUIEx::setLineEditQss(QLineEdit* pLineEdit, int iRadius, int iBorderWidth, const QString& strNormalColor,
	const QString& strFocusColor)
{
	QStringList list;
	list.append(QString("QLineEdit{border-style:none;border: 1px solid rgb(50, 50, 50);background:rgb(30,30,30);font-size: 14px;color:rgb(200,200,200);}"));

	list.append(QString("QLineEdit:focus{border: 1px solid rgb(239, 98, 234);}") );

	list.append(QString("QLineEdit:hover{border: 1px solid rgb(239, 98, 234);}"));
	 

	QString qss = list.join("");
	pLineEdit->setStyleSheet(qss);
	return qss;
}


//设置进度条样式
QString FlatUIEx::setProgressBarQss(QProgressBar *pBar, int iBarHeight, int iBarRadius, int iFontSize,
	const QString& strNormalColor, const QString& strChunkColor)
{

	QStringList list;
	list.append(QString("QProgressBar{font:%1pt;background:%2;max-height:%3px;border-radius:%4px;text-align:center;border:1px solid %2;}")
		.arg(iFontSize).arg(strNormalColor).arg(iBarHeight).arg(iBarRadius));
	
	list.append(QString("QProgressBar:chunk{border-radius:%2px;background-color:%1;}")
		.arg(strChunkColor).arg(iBarRadius));

	QString qss = list.join("");
	pBar->setStyleSheet(qss);
	return qss;
}



//设置滑块条样式
QString FlatUIEx::setSliderQss(QSlider* pSlider, int sliderHeight, const QString & strNormalColor, const QString & strGrooveColor,
	const QString & strHandleBorderColor, const QString & strHandleColor)
{
	int sliderRadius = sliderHeight / 2;
	int handleWidth = (sliderHeight * 3) / 2 + (sliderHeight / 5);
	int handleRadius = handleWidth / 2;
	int handleOffset = handleRadius / 2;

	QStringList list;
	list.append(QString("QSlider::horizontal{min-height:%1px;}").arg(sliderHeight * 2));
	
	list.append(QString("QSlider::groove:horizontal{background:%1;height:%2px;border-radius:%3px;}")
		.arg(strNormalColor).arg(sliderHeight).arg(sliderRadius));
	
	list.append(QString("QSlider::add-page:horizontal{background:%1;height:%2px;border-radius:%3px;}")
		.arg(strNormalColor).arg(sliderHeight).arg(sliderRadius));
	
	list.append(QString("QSlider::sub-page:horizontal{background:%1;height:%2px;border-radius:%3px;}")
		.arg(strGrooveColor).arg(sliderHeight).arg(sliderRadius));
	
	list.append(QString("QSlider::handle:horizontal{width:%3px;margin-top:-%4px;margin-bottom:-%4px;border-radius:%5px;"
		"background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 %1,stop:0.8 %2);}")
		.arg(strHandleColor).arg(strHandleBorderColor).arg(handleWidth).arg(handleOffset).arg(handleRadius));

	//偏移一个像素
	handleWidth = handleWidth + 1;
	list.append(QString("QSlider::vertical{min-width:%1px;}").arg(sliderHeight * 2));
	list.append(QString("QSlider::groove:vertical{background:%1;width:%2px;border-radius:%3px;}")
		.arg(strNormalColor).arg(sliderHeight).arg(sliderRadius));
	list.append(QString("QSlider::add-page:vertical{background:%1;width:%2px;border-radius:%3px;}")
		.arg(strGrooveColor).arg(sliderHeight).arg(sliderRadius));
	list.append(QString("QSlider::sub-page:vertical{background:%1;width:%2px;border-radius:%3px;}")
		.arg(strNormalColor).arg(sliderHeight).arg(sliderRadius));
	list.append(QString("QSlider::handle:vertical{height:%3px;margin-left:-%4px;margin-right:-%4px;border-radius:%5px;"
		"background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 %1,stop:0.8 %2);}")
		.arg(strHandleColor).arg(strHandleBorderColor).arg(handleWidth).arg(handleOffset).arg(handleRadius));

	QString qss = list.join("");
	pSlider->setStyleSheet(qss);
	return qss;
}

//设置单选框样式
QString FlatUIEx::setRadioButtonQss(QRadioButton* pRbtn, int iIndicatorRadius, const QString& strNormalColor, const QString& strCheckColor)
{
	int indicatorWidth = iIndicatorRadius * 2;

	QStringList list;
	list.append(QString("QRadioButton::indicator{border-radius:%1px;width:%2px;height:%2px;}")
		.arg(iIndicatorRadius).arg(indicatorWidth));
	list.append(QString("QRadioButton::indicator::unchecked{background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,"
		"stop:0.6 #FFFFFF,stop:0.7 %1);}").arg(strNormalColor));
	list.append(QString("QRadioButton::indicator::checked{background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,"
		"stop:0 %1,stop:0.3 %1,stop:0.4 #FFFFFF,stop:0.6 #FFFFFF,stop:0.7 %1);}").arg(strCheckColor));

	QString qss = list.join("");
	pRbtn->setStyleSheet(qss);
	return qss;
}

//设置滚动条样式
QString FlatUIEx::setScrollBarQss(QWidget *pScroll, int iRadius, int iMin, int iMax, const QString & strBgColor,
	const QString & strHandleNormalColor, const QString & strHandleHoverColor, const QString & strHandlePressedColor)
{
	//滚动条离背景间隔
	int padding = 0;

	QStringList list;

	//handle:指示器,滚动条拉动部分 add-page:滚动条拉动时增加的部分 sub-page:滚动条拉动时减少的部分 add-line:递增按钮 sub-line:递减按钮

	//横向滚动条部分
	list.append(QString("QScrollBar:horizontal{height: 25px;margin: 3px 1px 3px 3px;border: 1px transparent rgb(30,30,30);border-radius: 0px;background-color: rgb(30,30,30); }"));
 	list.append(QString("QScrollBar::handle:horizontal{ background-color: rgb(50,50,50);min-width: 5px;border-radius: 0px;margin: 2px 2px 2px 2px;}"));

	list.append(QString("QScrollBar::handle:horizontal:hover{background:none;}") );
 	list.append(QString("QScrollBar::handle:horizontal:pressed{background:none;}"));
	 
	list.append(QString("QScrollBar::add-page:horizontal{background:none;}"));
	list.append(QString("QScrollBar::sub-page:horizontal{background:none;}"));

	list.append(QString("QScrollBar::add-line:horizontal{background:none;}"));
	list.append(QString("QScrollBar::sub-line:horizontal{background:none;}"));

	//纵向滚动条部分
	list.append(QString("QScrollBar:vertical{background:%1;padding:%2px;border-radius:%3px;min-width:%4px;max-width:%4px;}")
		.arg(strBgColor).arg(padding).arg(iRadius).arg(iMax));

	list.append(QString("QScrollBar::handle:vertical{background:%1;min-height:%2px;border-radius:%3px;}")
		.arg(strHandleNormalColor).arg(iMin).arg(iRadius));

	list.append(QString("QScrollBar::handle:vertical:hover{background:%1;}")
		.arg(strHandleHoverColor));

	list.append(QString("QScrollBar::handle:vertical:pressed{background:%1;}")
		.arg(strHandlePressedColor));

	list.append(QString("QScrollBar::add-page:vertical{background:none;}"));
	list.append(QString("QScrollBar::sub-page:vertical{background:none;}"));
	list.append(QString("QScrollBar::add-line:vertical{background:none;}"));
	list.append(QString("QScrollBar::sub-line:vertical{background:none;}"));

	QString qss = list.join("");
	pScroll->setStyleSheet(qss);
	return qss;
}





