#ifndef			_RUN_TIME_DATA_H_
#define		_RUN_TIME_DATA_H_
 
class SelectMediaSourceWindow;
class PlayerListWindow;
class MediaSettingWindow;
class AudioSettingWindow;


class VideoSourceEditroWindow;
class PlayListEditorWindow;
class PictureEditorWindow;
class LocalStreamEditorWindow;
class IPStreamEditorWindow;
 

class RuntimeData  
{ 
public:
	RuntimeData( );
	~RuntimeData();
 

public:
	SelectMediaSourceWindow*OnGetSelectMediaSourceWindow();
	PlayerListWindow*OnGetPlayerListWindow();
	MediaSettingWindow*OnGetMediaSettingWindow();
	AudioSettingWindow*OnGetAudioSettingWindow();
	
	void	OnSetAudioSettingWindow(AudioSettingWindow* pWindow);
	void OnSetSelectMediaSourceWindow(SelectMediaSourceWindow* pWindow);
	void	OnSetPlayerListWindow(PlayerListWindow* pWindow);
	void	OnSetMediaSettingWindow(MediaSettingWindow* pWindow);
	
	VideoSourceEditroWindow*OnGetVideoSourceEditroWindow();
	PlayListEditorWindow*OnGetPlayListEditorWindow();
	PictureEditorWindow*	OnGetPictureEditorWindow();
	LocalStreamEditorWindow*OnGetLocalStreamEditorWindow();
	IPStreamEditorWindow*	OnGetIPStreamEditorWindow();
	 
	void	OnSetVideoSourceEditroWindow(VideoSourceEditroWindow* pWindow);
	void	OnSetPlayListEditorWindow(PlayListEditorWindow* pWindow);
	void	OnSetPictureEditorWindow(PictureEditorWindow* pWindow);
	void	OnSetLocalStreamEditorWindow(LocalStreamEditorWindow* pWindow);
	void	OnSetIPStreamEditorWindow(IPStreamEditorWindow* pWindow);

private:
	  SelectMediaSourceWindow*		m_pSelectMediaSourceWindow;
	  PlayerListWindow*					m_pPlayerListWindow;
	  MediaSettingWindow*				m_pMediaSettingWindow;
	  AudioSettingWindow*				m_pAudioSettingWindow;
	   
	  VideoSourceEditroWindow*		m_pVideoSourceEditroWindow;
	  PlayListEditorWindow*				m_pPlayListEditorWindow;
	  PictureEditorWindow*				m_pPictureEditorWindow;
	  LocalStreamEditorWindow*		m_pLocalStreamEditorWindow;
	  IPStreamEditorWindow*			m_pIPStreamEditorWindow;

};

RuntimeData& OnGetRuntimeData();

#endif//_RUN_TIME_DATA_H_
