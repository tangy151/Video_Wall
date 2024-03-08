#ifndef		_NAV_LABEL_EX_H_
#define _NAV_LABEL_EX_H_


#include <QLabel>

class NavLabelEx : public QLabel
{
 
		Q_OBJECT
		Q_ENUMS(TextAlign)
 		Q_ENUMS(IconPosition)

			Q_PROPERTY(int paddingLeft READ getPaddingLeft WRITE setPaddingLeft)
			Q_PROPERTY(int paddingRight READ getPaddingRight WRITE setPaddingRight)
			Q_PROPERTY(int paddingTop READ getPaddingTop WRITE setPaddingTop)
			Q_PROPERTY(int paddingBottom READ getPaddingBottom WRITE setPaddingBottom)
			Q_PROPERTY(TextAlign textAlign READ getTextAlign WRITE setTextAlign)

			Q_PROPERTY(bool showIcon READ getShowIcon WRITE setShowIcon)
			
			Q_PROPERTY(int m_iIconLeftSpace READ getIconLeftSpace WRITE setIconLeftSpace)
			Q_PROPERTY(int m_iIconTopSpace READ getIconTopSpace WRITE setIconTopSpace)
			  
			Q_PROPERTY(QSize iconSize READ getIconSize WRITE setIconSize)

			Q_PROPERTY(QPixmap iconNormal READ getIconNormal WRITE setIconNormal)

			Q_PROPERTY(QColor normalBgColor READ getNormalBgColor WRITE setNormalBgColor)
			Q_PROPERTY(QColor normalTextColor READ getNormalTextColor WRITE setNormalTextColor)
			

public:
		enum TextAlign 
		{
		TextAlign_Left = 0x0001,			//左侧对齐
		TextAlign_Right = 0x0002,		//右侧对齐
		TextAlign_Top = 0x0020,			//顶部对齐
		TextAlign_Bottom = 0x0040,		//底部对齐
		TextAlign_Center = 0x0004		//居中对齐
	};


		enum IconPosition 
		{
			IconPosition_Left = 0,			//左侧
			IconPosition_Right = 1,		//右侧
			IconPosition_Top = 2,			//顶部
			IconPosition_Bottom = 3	//底部
		};

protected:
 	void paintEvent(QPaintEvent *);
	void drawBg(QPainter *painter);
	void drawText(QPainter *painter);
	void drawIcon(QPainter *painter);
 

public:
	int getPaddingLeft()	const;
	int getPaddingRight()	const;
	int getPaddingTop()	const;
	int getPaddingBottom()	const;
	TextAlign getTextAlign()	const;

	bool getShowIcon()	const;

	int getIconLeftSpace()	const;
	int getIconTopSpace()	const;

	void setIconLeftSpace(int iconSpace);
	void setIconTopSpace(int iconSpace);
	
	
	QSize getIconSize()	const;


	QPixmap getIconNormal()	const;
	//设置显示图标
	void setShowIcon(bool showIcon);
	//设置图标间隔
	 

	//设置图标尺寸
	void setIconSize(const QSize &iconSize);

	//设置正常图标
	void setIconNormal(const QPixmap &iconNormal);

	QColor getNormalBgColor()	const;
	void setNormalTextColor(const QColor &normalTextColor);
	QColor getNormalTextColor()         const;
	//设置文字对齐
	void setTextAlign(const TextAlign &textAlign);
	//设置正常背景颜色
	void setNormalBgColor(const QColor &normalBgColor);

public Q_SLOTS:
	//设置文字间隔
	void setPaddingLeft(int paddingLeft);
	void setPaddingRight(int paddingRight);
	void setPaddingTop(int paddingTop);
	void setPaddingBottom(int paddingBottom);
	void setPadding(int padding);
	void setPadding(int paddingLeft, int paddingRight, int paddingTop, int paddingBottom);


public:
	explicit NavLabelEx(QWidget *parent = nullptr);
 
private:
	int		m_iPaddingLeft;                    //文字左侧间隔
	int		m_iPaddingRight;                   //文字右侧间隔
	int		m_iPaddingTop;                     //文字顶部间隔
	int		m_iPaddingBottom;                  //文字底部间隔

	TextAlign		m_iTextAlign;                //文字对齐

	int			m_iTextLeft;


	bool			m_bShowIcon;                      //显示图标

	int			m_iIconLeftSpace;			//图标左边间隔
	int			m_iIconTopSpace;			//图标上边间隔


	QSize		m_iIconSize;                     //图标尺寸

	QPixmap		m_iIconNormal;                 //正常图标
	QColor			m_iNormalTextColor;             //正常文字颜色
 	QBrush			m_iNormalBgBrush;               //正常背景画刷
	QColor			m_iNormalBgColor;               //正常背景颜色
	 
};


#endif//_NAV_LABEL_EX_H_
