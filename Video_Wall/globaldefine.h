#ifndef		_GLOBAL_DEFINE_H_
#define	    _GLOBAL_DEFINE_H_
 
#define   PIX_1080p		1


#if	PIX_1080p

#define		ROW	    3
#define		COL		4

#define		CHANNEL_COUNT	ROW*COL 
 #define	CHAN_GAP	6
 
#define		BUTTON_WIDTH		91
#define		LEFT_GAP	    	55

 #else

#define		ROW	    3
#define		COL		3

#define		CHANNEL_COUNT	ROW*COL 

#define		CHAN_GAP	6
 
#define		BUTTON_WIDTH		80
#define		LEFT_GAP	    	44

#endif
 
#define		BUTTON_HEIGHT	    50
#define		HEIGHT_GAP			55
 
enum  MEDIA_SELECT_TYPE
{
	MEDIA_TYPE_NULL = 0,
	VOIDE	= 1 ,		    //��Ƶ
	PICTURE = 2,			//ͼƬ
	IP_STREAM = 3,		    //������
	LOCAL_STREAM = 4,	    //ʵʱ��
	PLAY_LIST	= 5,		//�����б�
};


typedef enum _tagItemType
{
    ItemType_Group = 0,
    ItemType_Child = 1,

} ItemType;



#endif//_GLOBAL_DEFINE_H_
