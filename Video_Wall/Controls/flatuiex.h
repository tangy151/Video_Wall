#ifndef			_FLATUI_EX_H_
#define			_FLATUI_EX_H_

#include <QtCore/QObject>


class QPushButton;
class QLineEdit;
class QProgressBar;
class QSlider;
class QRadioButton;
class QCheckBox;
class QScrollBar;
class QMenu;
class QMenuBar;
class QLabel;
class QTabWidget;
class QTabBar;
class QGraphicsView;
class QListWidget;
class QTreeWidget;


class FlatUIEx
	: public QObject
{
	Q_OBJECT

public:
	explicit	FlatUIEx(QObject *parent = nullptr);

	static FlatUIEx *Instance();


private:
	static QScopedPointer<FlatUIEx >  m_ptrSelf;

public:
	//设置按钮样式
	static QString setPushButtonQss(QPushButton* pBtn,                               //按钮对象
	 
		const QString& strNormalColor ,         //正常颜色
		const QString& strNormalTextColor ,     //文字颜色
		const QString& strHoverColor ,          //悬停颜色
		const QString& strHoverTextColor,      //悬停文字颜色
		const QString& strPressedColor ,        //按下颜色
		const QString& strPressedTextColor );   //按下文字颜色


		//设置窗口样式
	static  QString setQWidgetWndQss(QWidget* pWnd =nullptr	,const QString& strBKColor = "#202020" );   //按下文字颜色

	static  QString setMenuBarQss(QMenuBar* pWnd  = nullptr,
		const QString& strBKColor = "#202020",
		const QString& strItemColor = "#202020", 
		const QString& strItemSelectColor = "#202020",
		const QString& strItemPressedColor = "#202020");   //按下文字颜色

	static QString SetMenuQss(QMenu* pMenu=nullptr, const QString& strBKColor = "#202020");

	static QString SetLabelQss(QLabel* pLabel, const QString& strBKColor,const QString& strFontColor);

	static QString SetTabWidgetQss(QTabWidget* pTabWidget, const QString& strBKColor, const QString& strFontColor);

	static QString SetTabBarQss(QTabBar* pTabBar, const QString& strBKColor, const QString& strFontColor);
	 
	static QString SetListWidgetQss(QListWidget* pTabBar, const QString& strBKColor, const QString& strFontColor);

	static QString SetGraphicsViewQss(QGraphicsView* pView );

	static QString SetTreeWidgetQss(QTreeWidget* pTreeWidget);
	 


	

	//设置文本框样式
	static QString setLineEditQss(QLineEdit* pLineEdit,                                   //文本框对象
		int iRadius = 3,                                   //圆角半径
		int iBorderWidth = 2,                              //边框大小
		const QString& strNormalColor = "#DCE4EC",           //正常颜色
		const QString& strFocusColor = "#34495E");           //选中颜色

	//设置进度条样式
	static QString setProgressBarQss(QProgressBar *pBar,
		int iBarHeight = 8,                             //进度条高度
		int iBarRadius = 5,                             //进度条半径
		int iFontSize = 9,                              //文字字号
		const QString& strNormalColor = "#E8EDF2",        //正常颜色
		const QString& strChunkColor = "#E74C3C");        //进度颜色

	//设置滑块条样式
	static QString setSliderQss(QSlider* pSlider,                                    //滑动条对象
		int sliderHeight = 8,                               //滑动条高度
		const QString & strNormalColor = "#E8EDF2",             //正常颜色
		const QString & strGrooveColor = "#1ABC9C",             //滑块颜色
		const QString & strHandleBorderColor = "#1ABC9C",       //指示器边框颜色
		const QString & strHandleColor = "#FFFFFF");            //指示器颜色

	//设置单选框样式
	static QString setRadioButtonQss(QRadioButton* pRbtn,                            //单选框对象
		int iIndicatorRadius = 8,                       //指示器圆角角度
		const QString& strNormalColor = "#D7DBDE",        //正常颜色
		const QString& strCheckColor = "#34495E");        //选中颜色

	//设置滚动条样式
	static QString setScrollBarQss(QWidget* pScroll,                                 //滚动条对象
		int iRadius = 6,                                  //圆角角度
		int iMin = 120,                                   //指示器最小长度
		int iMax = 12,                                    //滚动条最大长度
		const QString & strBgColor = "#606060",              //背景色
		const QString & strHandleNormalColor = "#34495E",    //指示器正常颜色
		const QString & strHandleHoverColor = "#1ABC9C",     //指示器悬停颜色
		const QString & strHandlePressedColor = "#E74C3C");  //指示器按下颜色



	//设置窗口样式
	

};

#endif		//_FLATUI_EX_H_
