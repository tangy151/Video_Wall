#ifndef		_SLIDER_EX_H_
#define		_SLIDER_EX_H_

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>


//����������ĸ�����
enum State 
{
	MinHandle,	//�󻬿�
	MaxHandle,	//�һ���
	None,		//��
};

//�ؼ���ʽ
enum SliderStyle
{
	Single_HorizontalSlider,	//ˮƽ��ʽ������
	Single_VerticalSlider,		//��ֱ��ʽ������
	Double_HorizontalSlider,	//ˮƽ��ʽ˫����
	Double_VerticalSlider,		//��ֱ��ʽ˫����
};

//������ʽ
enum HandleStyle
{
	PolygonEx,	//����λ���
	RectangleEx,	//���λ���
	EllipseEx,	//Բ�λ���
};


class SliderEx 
	: public QWidget
{
	Q_OBJECT

public:
	SliderEx(QWidget *parent = nullptr);
	~SliderEx();


signals:
	void valueChanged(float min, float max);

protected:
	void resizeEvent(QResizeEvent *event);		//�ı䴰�ڴ�С�¼�
	void paintEvent(QPaintEvent *event);		//�����¼�
	void mousePressEvent(QMouseEvent *event);	//��갴���¼�
	void mouseMoveEvent(QMouseEvent *event);	//����ƶ��¼�
	void mouseReleaseEvent(QMouseEvent *event);	//��굯���¼�
	void keyPressEvent(QKeyEvent *event);		//���̰����¼�
	void keyReleaseEvent(QKeyEvent *event);		//���̵����¼�
	void enterEvent(QEvent *event);				//�����봰���¼�
	void leaveEvent(QEvent* event);				//����뿪�����¼�

protected:
	void paintPolygon(QPolygon polygon, QColor color, QPainter* painter);	//���ƶ����	
	void paintRectangle(QRect rect, QColor color, QPainter* painter);		//���ƾ���
	void paintEllipse(QRect rect, QColor color, QPainter* painter);			//����Բ��
	void paintSlider(QPainter* painter);									//���Ʋ�
	void paintText(QPainter* painter);										//�����ı�
	void paintHandle(QPainter* painter);									//���ƻ���
	void calculationPos(QPoint pot);										//���������
	 
public:
	//--- ���ýӿ� ---//
	float getMinRange() const;				//��ȡ��С��Χ
	float getMaxRange() const;				//��ȡ���Χ
	float getCurMinValue() const;			//��ȡ��ǰ��Сֵ
	float getCurMaxValue() const;			//��ȡ��ǰ���ֵ

	void setOverlap(bool bl);											//�����Ƿ��������ص�
	void setStyle(SliderStyle sliderStyle, HandleStyle handleStyle);	//���ÿؼ���ʽ��������ʽ
	void setSliderColor(QColor botColor, QColor selColor);				//���ò۵�ɫ��ѡ��ɫ
	void setHandleColor(QColor selColor, QColor unSelColor);			//���û���ѡ��ɫ��δѡ��ɫ
	
	void setRange(float min, float max);	//������Чֵ��Χ
	void setMinRange(float value);			//������С��Χ
	void setMaxRange(float value);			//�������Χ
	void setCurMinValue(float value);		//���õ�ǰ��Сֵ
	void setCurMaxRange(float value);		//���õ�ǰ���ֵ
	void setSingleStep(float step);			//���ð����ƶ�����

	void setDrawVolume(bool bDraw);
	 
	void setIconNormal(const QPixmap &iconNormal);//��������ͼ��

private:
	float m_MinRange;		//��С��Χ
	float m_MaxRange;		//���Χ
	float m_curMinValue;	//��ǰ��Сֵ
	float m_curMaxValue;	//��ǰ���ֵ
	float m_singleStep;		//������������

	QPolygon minHandlePolygon;	//�󻬿�(�����)
	QPolygon maxHandlePolygon;	//�һ���(�����)
	QRect minHandleRect;		//�󻬿�(����)
	QRect maxHandleRect;		//�һ���(����)

	SliderStyle m_SliderStyle;	//������ʽ��ˮƽ������ֱ��
	HandleStyle m_HandleStyle;	//������ʽ������Ρ����Ρ�Բ��
	State m_state;				//�������Ļ���
	State m_lastHandle;			//�ϴε���Ļ���

	QColor m_sliderColor;					//�۵�ɫ
	QColor m_sliderSelectionColor;	//��ѡ��ɫ
	QColor m_sliderHandleColor;		//����ѡ��ɫ
	QColor m_unSliderHandleColor;	//����δѡ��ɫ

	int m_minX, m_minY, m_maxX, m_maxY;	//���һ����x��y����

	bool m_isDrawText;		//�Ƿ�����ı�
	bool m_textBrush;		//�����ı�����
	bool m_isOverlap;		//�Ƿ��������ص�

	bool		m_bDrawVolume;
	QPixmap		m_iIconNormal;                 //����ͼ��

	int			m_overlapOffset;	//�ص�ƫ����
 };


#endif//_SLIDER_EX_H_
