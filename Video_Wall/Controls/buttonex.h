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
		TextAlign_Left				= 0x0001,				//������
		TextAlign_Right			= 0x0002,			//�Ҳ����
		TextAlign_Top				= 0x0020,				//��������
		TextAlign_Bottom		= 0x0040,		//�ײ�����
		TextAlign_Center			= 0x0004			//���ж���
	};
	 

	enum PlayBttonState
	{
		Button_Play		= 0,	// ����
		Button_Pause	= 1,	//��ͣ
		Button_Stop		= 2,	//ֹͣ
 		Button_Prev		= 3,	//��һ֡
		Button_Next	= 4,	//��һ֡

		Button_Arrow_Down	= 5,
		Button_Arrow_Right	= 6,
 	};
	 

	enum IconPosition
	{
		IconPosition_Left				= 0,	//���
		IconPosition_Right			= 1,	//�Ҳ�
		IconPosition_Top				= 2,	//����
		IconPosition_Bottom		= 3	//�ײ�
	};

	enum LinePosition
	{
		LinePosition_Left			= 0,	//���
		LinePosition_Right		= 1,	//�Ҳ�
		LinePosition_Top			= 2,	//����
		LinePosition_Bottom	= 3	//�ײ�
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
	//�������ּ��
	void setPaddingLeft(int iPaddingLeft);
	void setPaddingRight(int iPaddingRight);
	void setPaddingTop(int iPaddingTop);
	void setPaddingBottom(int iPaddingBottom);
	void setPadding(int iPadding);
	void setPadding(int iPaddingLeft, int iPaddingRight, int iPaddingTop, int iPaddingBottom);

	//�������ֶ���
	void setTextAlign(const TextAlign& iTextAlign);

	//��ʾ���Ű�ť״̬
	void setShowPlayButtonState(bool bShowTriangle);
 
	
	//���ò��Ű�ť����
	void setShowPlayButtonState(const PlayBttonState& iTrianglePosition);
	 
	//���õ�������ɫ
	void setButtonStateColor(const QColor& iTriangleColor);

	//������ʾͼ��
	void setShowIcon(bool bShowIcon);
	//����ͼ����
	void setIconSpace(int iIconSpace);
	//����ͼ��ߴ�
	void setIconSize(const QSize& iIconSize);
	//��������ͼ��
	void setIconNormal(const QPixmap &iIconNormal);
	//������ͣͼ��
	void setIconHover(const QPixmap &iIconHover);
	//���ð���ͼ��
	void setIconCheck(const QPixmap &iIconCheck);

	//������ʾ����
	void setShowLine(bool bShowLine);
	//�����������
	void setLineSpace(int iLineSpace);
	//�����������
	void setLineWidth(int iLineWidth);
	//��������λ��
	void setLinePosition(const LinePosition &iLinePosition);
	//����������ɫ
	void setLineColor(const QColor &iLineColor);
	 
	//���������߿���ɫ
	void setNormalFrameColor(const QColor &iNormalFrameColor);

	//��������������ɫ
	void setNormalBgColor(const QColor &iNormalBgColor);


	//������ͣ������ɫ
	void setHoverBgColor(const QColor &iHoverBgColor);
	//����ѡ�б�����ɫ
	void setCheckBgColor(const QColor &iCheckBgColor);

	//��������������ɫ
	void setNormalTextColor(const QColor & iNormalTextColor);
	//������ͣ������ɫ
	void setHoverTextColor(const QColor &iHoverTextColor);
	//����ѡ��������ɫ
	void setCheckTextColor(const QColor &iCheckTextColor);

	//��������������ˢ
	void setNormalBgBrush(const QBrush &iNormalBgBrush);
	//������ͣ������ˢ
	void setHoverBgBrush(const QBrush &iHoverBgBrush);
	//����ѡ�б�����ˢ
	void setCheckBgBrush(const QBrush &iCheckBgBrush);

	//    Q_SIGNALS :
	// 	void	 clicked();
	// signals:
	// 	void LoadWidget(
private:
	int				m_iPaddingLeft;			//���������
	int				m_iPaddingRight;			//�����Ҳ���
	int				m_iPaddingTop;			//���ֶ������
	int				m_iPaddingBottom;		//���ֵײ����
	int				m_iIconSpace;				//ͼ����
	int				m_iLineSpace;				//�������
	int				m_iLineWidth;				//�������
 

	bool				m_bHover;					//��ͣ��־λ
	bool				m_bShowLine;				//��ʾ����
	bool				m_bShowPlayState;		//��ʾ����״̬
	bool				m_bShowIcon;				//��ʾͼ��

	bool				m_bBigStyle;

	TextAlign		m_iTextAlign;                //���ֶ���


	PlayBttonState			m_iPlayButtonSate;  //���Ŵ��ڰ�ť״̬

	QColor			m_iButtonSateColor;               //��������ɫ

	QSize			m_iIconSize;                     //ͼ��ߴ�
	QPixmap		m_iIconNormal;                 //����ͼ��
	QPixmap		m_iIconHover;                  //��ͣͼ��
	QPixmap		m_iIconCheck;                  //ѡ��ͼ��




	LinePosition m_iLinePosition;				 //����λ��
	QColor			m_iLineColor;                   //������ɫ

	QColor			m_iNormalFrameColor;               //�߿���ɫ
	QColor			m_iNormalBkColor;						//������ɫ

	QColor			m_iHoverBgColor;                //��ͣ������ɫ
	QColor			m_iCheckBgColor;                //ѡ�б�����ɫ
	QColor			m_iNormalTextColor;             //����������ɫ
	QColor			m_iHoverTextColor;              //��ͣ������ɫ
	QColor			m_iCheckTextColor;              //ѡ��������ɫ

	QBrush			m_iNormalBgBrush;               //����������ˢ
	QBrush			m_iHoverBgBrush;                //��ͣ������ˢ
	QBrush			m_iCheckBgBrush;                //ѡ�б�����ˢ


};


#endif//_BUTTON_EX_H_


