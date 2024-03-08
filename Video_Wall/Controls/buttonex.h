#ifndef		_BUTTON_EX_H_
#define	_BUTTON_EX_H_


#include <QtWidgets/QPushButton>

class ButtonEx
	: public QPushButton
{
	Q_OBJECT
		Q_ENUMS(TextAlign)
		Q_ENUMS(TrianglePosition)
		Q_ENUMS(LinePosition)
		Q_ENUMS(IconPosition)

		Q_PROPERTY(int paddingLeft READ getPaddingLeft WRITE setPaddingLeft)
		Q_PROPERTY(int paddingRight READ getPaddingRight WRITE setPaddingRight)
		Q_PROPERTY(int paddingTop READ getPaddingTop WRITE setPaddingTop)
		Q_PROPERTY(int paddingBottom READ getPaddingBottom WRITE setPaddingBottom)
		Q_PROPERTY(TextAlign textAlign READ getTextAlign WRITE setTextAlign)

		Q_PROPERTY(bool showplayBttonState READ getShowPlayButtonState WRITE setShowPlayButtonState)
 		Q_PROPERTY(PlayBttonState playBttonState READ getPlayButtonState WRITE setShowPlayButtonState)

		Q_PROPERTY(QColor buttonStateColor READ getButtonStateColor WRITE setButtonStateColor)
		 

		Q_PROPERTY(bool showIcon READ getShowIcon WRITE setShowIcon)
		Q_PROPERTY(int iconSpace READ getIconSpace WRITE setIconSpace)
		Q_PROPERTY(QSize iconSize READ getIconSize WRITE setIconSize)
		Q_PROPERTY(QPixmap iconNormal READ getIconNormal WRITE setIconNormal)
		Q_PROPERTY(QPixmap iconHover READ getIconHover WRITE setIconHover)
		Q_PROPERTY(QPixmap iconCheck READ getIconCheck WRITE setIconCheck)

		Q_PROPERTY(bool showLine READ getShowLine WRITE setShowLine)
		Q_PROPERTY(int lineSpace READ getLineSpace WRITE setLineSpace)
		Q_PROPERTY(int lineWidth READ getLineWidth WRITE setLineWidth)
		Q_PROPERTY(LinePosition linePosition READ getLinePosition WRITE setLinePosition)
		Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)

		Q_PROPERTY(QColor normalBgColor READ getNormalBgColor WRITE setNormalBgColor)
		Q_PROPERTY(QColor hoverBgColor READ getHoverBgColor WRITE setHoverBgColor)
		Q_PROPERTY(QColor checkBgColor READ getCheckBgColor WRITE setCheckBgColor)
		Q_PROPERTY(QColor normalTextColor READ getNormalTextColor WRITE setNormalTextColor)
		Q_PROPERTY(QColor noverTextColor READ getHoverTextColor WRITE setHoverTextColor)
		Q_PROPERTY(QColor checkTextColor READ getCheckTextColor WRITE setCheckTextColor)


		Q_PROPERTY(bool bBigStyle READ getBigStyle WRITE setBigStyle)

 


public:
	enum TextAlign
	{
		TextAlign_Left				= 0x0001,				//左侧对齐
		TextAlign_Right			= 0x0002,			//右侧对齐
		TextAlign_Top				= 0x0020,				//顶部对齐
		TextAlign_Bottom		= 0x0040,		//底部对齐
		TextAlign_Center			= 0x0004			//居中对齐
	};
	 

	enum PlayBttonState
	{
		Button_Play		= 0,	// 播放
		Button_Pause	= 1,	//暂停
		Button_Stop		= 2,	//停止
 		Button_Prev		= 3,	//上一帧
		Button_Next	= 4,	//下一帧

		Button_Arrow_Down	= 5,
		Button_Arrow_Right	= 6,
 	};
	 

	enum IconPosition
	{
		IconPosition_Left				= 0,	//左侧
		IconPosition_Right			= 1,	//右侧
		IconPosition_Top				= 2,	//顶部
		IconPosition_Bottom		= 3	//底部
	};

	enum LinePosition
	{
		LinePosition_Left			= 0,	//左侧
		LinePosition_Right		= 1,	//右侧
		LinePosition_Top			= 2,	//顶部
		LinePosition_Bottom	= 3	//底部
	};

public:
	explicit	ButtonEx(QWidget *parent);


protected:
	void enterEvent(QEvent *);
	void leaveEvent(QEvent *);
	void mousePressEvent(QMouseEvent * pEvent);
	void mouseReleaseEvent(QMouseEvent *pEvent);

	void paintEvent(QPaintEvent *);
	void drawBg(QPainter *painter);
	void drawText(QPainter *painter);
	void drawIcon(QPainter *painter);
	void drawLine(QPainter *painter);
	void drawButtonState(QPainter *painter);
 

public:
	int getPaddingLeft() const;
	int getPaddingRight() const;
	int getPaddingTop() const;
	int getPaddingBottom() const;
	TextAlign getTextAlign() const;

	bool getShowPlayButtonState() const;
 	PlayBttonState	 getPlayButtonState()const;


	QColor getButtonStateColor() const;

	bool getShowIcon() const;
	int getIconSpace() const;
	QSize getIconSize() const;
	QPixmap getIconNormal() const;
	QPixmap getIconHover() const;
	QPixmap getIconCheck() const;


 
		bool getBigStyle() const;
		void setBigStyle(bool bBigStyle);

	bool getShowLine() const;
	int getLineSpace() const;
	int getLineWidth() const;
	LinePosition getLinePosition() const;
	QColor getLineColor() const;

	QColor getNormalBgColor() const;
	QColor getHoverBgColor() const;
	QColor getCheckBgColor() const;
	QColor getNormalTextColor() const;
	QColor getHoverTextColor() const;
	QColor getCheckTextColor() const;

	QSize sizeHint() const;
	QSize minimumSizeHint() const;


public Q_SLOTS:
	//设置文字间隔
	void setPaddingLeft(int iPaddingLeft);
	void setPaddingRight(int iPaddingRight);
	void setPaddingTop(int iPaddingTop);
	void setPaddingBottom(int iPaddingBottom);
	void setPadding(int iPadding);
	void setPadding(int iPaddingLeft, int iPaddingRight, int iPaddingTop, int iPaddingBottom);

	//设置文字对齐
	void setTextAlign(const TextAlign& iTextAlign);

	//显示播放按钮状态
	void setShowPlayButtonState(bool bShowTriangle);
 
	
	//设置播放按钮类型
	void setShowPlayButtonState(const PlayBttonState& iTrianglePosition);
	 
	//设置倒三角颜色
	void setButtonStateColor(const QColor& iTriangleColor);

	//设置显示图标
	void setShowIcon(bool bShowIcon);
	//设置图标间隔
	void setIconSpace(int iIconSpace);
	//设置图标尺寸
	void setIconSize(const QSize& iIconSize);
	//设置正常图标
	void setIconNormal(const QPixmap &iIconNormal);
	//设置悬停图标
	void setIconHover(const QPixmap &iIconHover);
	//设置按下图标
	void setIconCheck(const QPixmap &iIconCheck);

	//设置显示线条
	void setShowLine(bool bShowLine);
	//设置线条间隔
	void setLineSpace(int iLineSpace);
	//设置线条宽度
	void setLineWidth(int iLineWidth);
	//设置线条位置
	void setLinePosition(const LinePosition &iLinePosition);
	//设置线条颜色
	void setLineColor(const QColor &iLineColor);
	 
	//设置正常边框颜色
	void setNormalFrameColor(const QColor &iNormalFrameColor);

	//设置正常背景颜色
	void setNormalBgColor(const QColor &iNormalBgColor);


	//设置悬停背景颜色
	void setHoverBgColor(const QColor &iHoverBgColor);
	//设置选中背景颜色
	void setCheckBgColor(const QColor &iCheckBgColor);

	//设置正常文字颜色
	void setNormalTextColor(const QColor & iNormalTextColor);
	//设置悬停文字颜色
	void setHoverTextColor(const QColor &iHoverTextColor);
	//设置选中文字颜色
	void setCheckTextColor(const QColor &iCheckTextColor);

	//设置正常背景画刷
	void setNormalBgBrush(const QBrush &iNormalBgBrush);
	//设置悬停背景画刷
	void setHoverBgBrush(const QBrush &iHoverBgBrush);
	//设置选中背景画刷
	void setCheckBgBrush(const QBrush &iCheckBgBrush);

	//    Q_SIGNALS :
	// 	void	 clicked();
	// signals:
	// 	void LoadWidget(
private:
	int				m_iPaddingLeft;			//文字左侧间隔
	int				m_iPaddingRight;			//文字右侧间隔
	int				m_iPaddingTop;			//文字顶部间隔
	int				m_iPaddingBottom;		//文字底部间隔
	int				m_iIconSpace;				//图标间隔
	int				m_iLineSpace;				//线条间隔
	int				m_iLineWidth;				//线条宽度
 

	bool				m_bHover;					//悬停标志位
	bool				m_bShowLine;				//显示线条
	bool				m_bShowPlayState;		//显示播放状态
	bool				m_bShowIcon;				//显示图标

	bool				m_bBigStyle;

	TextAlign		m_iTextAlign;                //文字对齐


	PlayBttonState			m_iPlayButtonSate;  //播放窗口按钮状态

	QColor			m_iButtonSateColor;               //倒三角颜色

	QSize			m_iIconSize;                     //图标尺寸
	QPixmap		m_iIconNormal;                 //正常图标
	QPixmap		m_iIconHover;                  //悬停图标
	QPixmap		m_iIconCheck;                  //选中图标




	LinePosition m_iLinePosition;				 //线条位置
	QColor			m_iLineColor;                   //线条颜色

	QColor			m_iNormalFrameColor;               //边框颜色
	QColor			m_iNormalBkColor;						//背景颜色

	QColor			m_iHoverBgColor;                //悬停背景颜色
	QColor			m_iCheckBgColor;                //选中背景颜色
	QColor			m_iNormalTextColor;             //正常文字颜色
	QColor			m_iHoverTextColor;              //悬停文字颜色
	QColor			m_iCheckTextColor;              //选中文字颜色

	QBrush			m_iNormalBgBrush;               //正常背景画刷
	QBrush			m_iHoverBgBrush;                //悬停背景画刷
	QBrush			m_iCheckBgBrush;                //选中背景画刷


};


#endif//_BUTTON_EX_H_


