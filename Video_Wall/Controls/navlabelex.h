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
		TextAlign_Left = 0x0001,			//������
		TextAlign_Right = 0x0002,		//�Ҳ����
		TextAlign_Top = 0x0020,			//��������
		TextAlign_Bottom = 0x0040,		//�ײ�����
		TextAlign_Center = 0x0004		//���ж���
	};


		enum IconPosition 
		{
			IconPosition_Left = 0,			//���
			IconPosition_Right = 1,		//�Ҳ�
			IconPosition_Top = 2,			//����
			IconPosition_Bottom = 3	//�ײ�
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
	//������ʾͼ��
	void setShowIcon(bool showIcon);
	//����ͼ����
	 

	//����ͼ��ߴ�
	void setIconSize(const QSize &iconSize);

	//��������ͼ��
	void setIconNormal(const QPixmap &iconNormal);

	QColor getNormalBgColor()	const;
	void setNormalTextColor(const QColor &normalTextColor);
	QColor getNormalTextColor()         const;
	//�������ֶ���
	void setTextAlign(const TextAlign &textAlign);
	//��������������ɫ
	void setNormalBgColor(const QColor &normalBgColor);

public Q_SLOTS:
	//�������ּ��
	void setPaddingLeft(int paddingLeft);
	void setPaddingRight(int paddingRight);
	void setPaddingTop(int paddingTop);
	void setPaddingBottom(int paddingBottom);
	void setPadding(int padding);
	void setPadding(int paddingLeft, int paddingRight, int paddingTop, int paddingBottom);


public:
	explicit NavLabelEx(QWidget *parent = nullptr);
 
private:
	int		m_iPaddingLeft;                    //���������
	int		m_iPaddingRight;                   //�����Ҳ���
	int		m_iPaddingTop;                     //���ֶ������
	int		m_iPaddingBottom;                  //���ֵײ����

	TextAlign		m_iTextAlign;                //���ֶ���

	int			m_iTextLeft;


	bool			m_bShowIcon;                      //��ʾͼ��

	int			m_iIconLeftSpace;			//ͼ����߼��
	int			m_iIconTopSpace;			//ͼ���ϱ߼��


	QSize		m_iIconSize;                     //ͼ��ߴ�

	QPixmap		m_iIconNormal;                 //����ͼ��
	QColor			m_iNormalTextColor;             //����������ɫ
 	QBrush			m_iNormalBgBrush;               //����������ˢ
	QColor			m_iNormalBgColor;               //����������ɫ
	 
};


#endif//_NAV_LABEL_EX_H_
