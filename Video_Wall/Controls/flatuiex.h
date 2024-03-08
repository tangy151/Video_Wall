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
	//���ð�ť��ʽ
	static QString setPushButtonQss(QPushButton* pBtn,                               //��ť����
	 
		const QString& strNormalColor ,         //������ɫ
		const QString& strNormalTextColor ,     //������ɫ
		const QString& strHoverColor ,          //��ͣ��ɫ
		const QString& strHoverTextColor,      //��ͣ������ɫ
		const QString& strPressedColor ,        //������ɫ
		const QString& strPressedTextColor );   //����������ɫ


		//���ô�����ʽ
	static  QString setQWidgetWndQss(QWidget* pWnd =nullptr	,const QString& strBKColor = "#202020" );   //����������ɫ

	static  QString setMenuBarQss(QMenuBar* pWnd  = nullptr,
		const QString& strBKColor = "#202020",
		const QString& strItemColor = "#202020", 
		const QString& strItemSelectColor = "#202020",
		const QString& strItemPressedColor = "#202020");   //����������ɫ

	static QString SetMenuQss(QMenu* pMenu=nullptr, const QString& strBKColor = "#202020");

	static QString SetLabelQss(QLabel* pLabel, const QString& strBKColor,const QString& strFontColor);

	static QString SetTabWidgetQss(QTabWidget* pTabWidget, const QString& strBKColor, const QString& strFontColor);

	static QString SetTabBarQss(QTabBar* pTabBar, const QString& strBKColor, const QString& strFontColor);
	 
	static QString SetListWidgetQss(QListWidget* pTabBar, const QString& strBKColor, const QString& strFontColor);

	static QString SetGraphicsViewQss(QGraphicsView* pView );

	static QString SetTreeWidgetQss(QTreeWidget* pTreeWidget);
	 


	

	//�����ı�����ʽ
	static QString setLineEditQss(QLineEdit* pLineEdit,                                   //�ı������
		int iRadius = 3,                                   //Բ�ǰ뾶
		int iBorderWidth = 2,                              //�߿��С
		const QString& strNormalColor = "#DCE4EC",           //������ɫ
		const QString& strFocusColor = "#34495E");           //ѡ����ɫ

	//���ý�������ʽ
	static QString setProgressBarQss(QProgressBar *pBar,
		int iBarHeight = 8,                             //�������߶�
		int iBarRadius = 5,                             //�������뾶
		int iFontSize = 9,                              //�����ֺ�
		const QString& strNormalColor = "#E8EDF2",        //������ɫ
		const QString& strChunkColor = "#E74C3C");        //������ɫ

	//���û�������ʽ
	static QString setSliderQss(QSlider* pSlider,                                    //����������
		int sliderHeight = 8,                               //�������߶�
		const QString & strNormalColor = "#E8EDF2",             //������ɫ
		const QString & strGrooveColor = "#1ABC9C",             //������ɫ
		const QString & strHandleBorderColor = "#1ABC9C",       //ָʾ���߿���ɫ
		const QString & strHandleColor = "#FFFFFF");            //ָʾ����ɫ

	//���õ�ѡ����ʽ
	static QString setRadioButtonQss(QRadioButton* pRbtn,                            //��ѡ�����
		int iIndicatorRadius = 8,                       //ָʾ��Բ�ǽǶ�
		const QString& strNormalColor = "#D7DBDE",        //������ɫ
		const QString& strCheckColor = "#34495E");        //ѡ����ɫ

	//���ù�������ʽ
	static QString setScrollBarQss(QWidget* pScroll,                                 //����������
		int iRadius = 6,                                  //Բ�ǽǶ�
		int iMin = 120,                                   //ָʾ����С����
		int iMax = 12,                                    //��������󳤶�
		const QString & strBgColor = "#606060",              //����ɫ
		const QString & strHandleNormalColor = "#34495E",    //ָʾ��������ɫ
		const QString & strHandleHoverColor = "#1ABC9C",     //ָʾ����ͣ��ɫ
		const QString & strHandlePressedColor = "#E74C3C");  //ָʾ��������ɫ



	//���ô�����ʽ
	

};

#endif		//_FLATUI_EX_H_
