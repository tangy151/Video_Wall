#ifndef		_NAVIGATION_BAR_H_
#define		_NAVIGATION_BAR_H_


#include <QWidget>

class NavigationBar
	: public QWidget
{
	Q_OBJECT
		Q_ENUMS(BarStyle)

		Q_PROPERTY(QColor bgColorStart READ getBgColorStart WRITE setBgColorStart)
		Q_PROPERTY(QColor bgColorEnd READ getBgColorEnd WRITE setBgColorEnd)

		Q_PROPERTY(QColor barColorStart READ getBarColorStart WRITE setBarColorStart)
		Q_PROPERTY(QColor barColorEnd READ getBarColorEnd WRITE setBarColorEnd)

		Q_PROPERTY(QColor textNormalColor READ getTextNormalColor WRITE setTextNormalColor)
		Q_PROPERTY(QColor textSelectColor READ getTextSelectColor WRITE setTextSelectColor)

		Q_PROPERTY(QString items READ getItems WRITE setItems)
		Q_PROPERTY(int currentIndex READ getCurrentIndex WRITE setCurrentIndex)
		Q_PROPERTY(QString currentItem READ getCurrentItem WRITE setCurrentItem)

		Q_PROPERTY(int bgRadius READ getBgRadius WRITE setBgRadius)
		Q_PROPERTY(int barRadius READ getBarRadius WRITE setBarRadius)
		Q_PROPERTY(int space READ getSpace WRITE setSpace)

		Q_PROPERTY(int lineWidth READ getLineWidth WRITE setLineWidth)
		Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)

		Q_PROPERTY(BarStyle barStyle READ getBarStyle WRITE setBarStyle)

		Q_PROPERTY(bool keyMove READ getKeyMove WRITE setKeyMove)
		Q_PROPERTY(bool horizontal READ getHorizontal WRITE setHorizontal)
		Q_PROPERTY(bool flat READ getFlat WRITE setFlat)

public:
	enum BarStyle {
		BarStyle_Rect = 0,              //Բ�Ǿ���
		BarStyle_Line_Top = 1,          //�ϱ�����
		BarStyle_Line_Right = 2,        //�ұ�����
		BarStyle_Line_Bottom = 3,       //�±�����
		BarStyle_Line_Left = 4          //�������
	};

	explicit NavigationBar(QWidget *parent = 0);
	~NavigationBar();

protected:
	void resizeEvent(QResizeEvent *);
	void mousePressEvent(QMouseEvent *);
	void keyPressEvent(QKeyEvent *);
	void paintEvent(QPaintEvent *);
	void drawBg(QPainter *painter);
	void drawBar(QPainter *painter);
	void drawText(QPainter *painter);

private:
	QColor bgColorStart;            //���������������俪ʼ��ɫ
	QColor bgColorEnd;              //���������������������ɫ

	QColor barColorStart;           //��������ǰ��Ŀ���俪ʼ��ɫ
	QColor barColorEnd;             //��������ǰ��Ŀ���������ɫ

	QColor textNormalColor;         //����������ɫ
	QColor textSelectColor;         //����ѡ����ɫ

	QColor old_bgColorEnd;          //���ڱ�ƽ���л�
	QColor old_barColorEnd;         //���ڱ�ƽ���л�

	QString items;                  //������Ŀ������Ϣ
	int currentIndex;               //��ǰѡ����Ŀ����
	QString currentItem;            //��ǰѡ����Ŀ����

	int bgRadius;                   //����Բ�ǰ뾶
	int barRadius;                  //ѡ����Ŀ����Բ�ǰ뾶
	int space;                      //��ĿԪ��֮��ļ��

	int lineWidth;                  //�������
	QColor lineColor;               //������ɫ

	BarStyle barStyle;              //ѡ��Ԫ����ʽ

	bool keyMove;                   //�Ƿ�֧�ְ����ƶ�
	bool horizontal;                //�Ƿ������ʾ
	bool flat;                      //�Ƿ��ƽ��

	//Ԫ�ؼ���,�ɶԳ���,Ԫ�ص�����,��������Χ
	QVector<QPair<QString, QRectF> > listItem;

	QRectF barRect, targetRect;     //ѡ�������Ŀ������ľ���
	double barLen, targetLen;       //ѡ�������Ŀ������ĳ���

	double initLen;                 //�������ĳ���
	int step;                       //ÿ���ƶ��Ĳ���
	int initStep(int distance);     //���㲽��

	bool isForward;                 //�Ƿ���ǰ�ƶ�
	bool isVirgin;                  //�Ƿ��״δ���
	QTimer *timer;                  //�������ƶ�ʱ��

private slots:
	void slide();

public:
	QColor getBgColorStart()	const;
	QColor getBgColorEnd()	const;

	QColor getBarColorStart()	const;
	QColor getBarColorEnd()         const;

	QColor getTextNormalColor()     const;
	QColor getTextSelectColor()     const;

	QString getItems()              const;
	int getCurrentIndex()           const;
	QString getCurrentItem()        const;

	int getBgRadius()               const;
	int getBarRadius()              const;
	int getSpace()                  const;

	int getLineWidth()              const;
	QColor getLineColor()           const;

	BarStyle getBarStyle()          const;

	bool getKeyMove()               const;
	bool getHorizontal()            const;
	bool getFlat()                  const;

	QSize sizeHint()                const;
	QSize minimumSizeHint()         const;

public Q_SLOTS:
	//ɾ��������Ŀ
	void clearItem();

	//���õ���������������ɫ
	void setBgColorStart(const QColor &bgColorStart);
	void setBgColorEnd(const QColor &bgColorEnd);

	//���õ�ǰ��Ŀѡ�б�������ɫ
	void setBarColorStart(const QColor &barColorStart);
	void setBarColorEnd(const QColor &barColorEnd);

	//����������ɫ
	void setTextNormalColor(const QColor &textNormalColor);
	void setTextSelectColor(const QColor &textSelectColor);

	//��������Ԫ�ؼ���ǰ������ֵ
	void setItems(const QString &items);
	void setCurrentIndex(int index);
	void setCurrentItem(const QString &item);

	//���ñ߿�Բ��
	void setBgRadius(int bgRadius);
	void setBarRadius(int barRadius);
	//������Ŀ���
	void setSpace(int space);

	//�����������
	void setLineWidth(int lineWidth);
	//����������ɫ
	void setLineColor(const QColor &lineColor);

	//����ѡ��Ԫ����ʽ
	void setBarStyle(const BarStyle &barStyle);

	//���ü��̰����Ƿ��ܹ��ƶ���Ŀ
	void setKeyMove(bool keyMove);
	//���ú�����ʾ,���Ϊ����������ʾ
	void setHorizontal(bool horizontal);
	//���ñ�ƽ,Ĭ�ϲ���ƽ
	void setFlat(bool flat);

	//�ƶ�����һ����Ŀ
	void moveFirst();
	//�ƶ������һ����Ŀ
	void moveLast();
	//��ǰ�ƶ���Ŀ
	void movePrevious();
	//�����ƶ���Ŀ
	void moveNext();
	//�ƶ���ָ��������Ŀ
	void moveTo(int index);
	//�ƶ���ָ��������Ŀ
	void moveTo(const QString &item);
	//�ƶ���ָ������λ����Ŀ
	void moveTo(const QPointF &point);

Q_SIGNALS:
	//��ǰ��Ŀ�ı��ź�,indexΪ��ǰ��Ŀ�������� itemΪ��ǰ��Ŀ����
	void currentItemChanged(int index, const QString &item);
};


#endif//_NAVIGATION_BAR_H_
