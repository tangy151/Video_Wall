#include "runtimedata.h"

#include "Public/selectmediasourcewindow.h"
#include "BottomArea/mediasettingwindow.h"
#include "BottomArea/playerlistwindow.h"
#include "BottomArea/audiosettingwindow.h"

#include "EditorWindow/ipstreameditorwindow.h"
#include "EditorWindow/localstreameditorwindow.h"
#include "EditorWindow/pictureeditorwindow.h"
#include "EditorWindow/playlisteditorwindow.h"
#include "EditorWindow/videosourceeditrowindow.h"


RuntimeData	 g_iRuntimeData;

RuntimeData& OnGetRuntimeData()
{
	return g_iRuntimeData;
}

RuntimeData::RuntimeData( )
 {
}

RuntimeData::~RuntimeData()
{
}
SelectMediaSourceWindow*RuntimeData::OnGetSelectMediaSourceWindow()
{
	return m_pSelectMediaSourceWindow;
}
PlayerListWindow*RuntimeData::OnGetPlayerListWindow()
{
	return m_pPlayerListWindow;
}
MediaSettingWindow*RuntimeData::OnGetMediaSettingWindow()
{
	return m_pMediaSettingWindow;
}

AudioSettingWindow*RuntimeData::OnGetAudioSettingWindow()
{
	return m_pAudioSettingWindow;
}

void	RuntimeData::OnSetAudioSettingWindow(AudioSettingWindow* pWindow)
{
	m_pAudioSettingWindow = pWindow;
}

void RuntimeData::OnSetSelectMediaSourceWindow(SelectMediaSourceWindow* pWindow)
{
	m_pSelectMediaSourceWindow = pWindow;
}
void	RuntimeData::OnSetPlayerListWindow(PlayerListWindow* pWindow)
{
	m_pPlayerListWindow = pWindow;
}
void	RuntimeData::OnSetMediaSettingWindow(MediaSettingWindow* pWindow)
{
	m_pMediaSettingWindow = pWindow;
}


VideoSourceEditroWindow* RuntimeData::OnGetVideoSourceEditroWindow()
{
	return m_pVideoSourceEditroWindow;
}
 
PlayListEditorWindow*	RuntimeData::OnGetPlayListEditorWindow()
{
	return m_pPlayListEditorWindow;
}
 
PictureEditorWindow*		RuntimeData::OnGetPictureEditorWindow()
{
	return m_pPictureEditorWindow;
}
 
LocalStreamEditorWindow*	RuntimeData::OnGetLocalStreamEditorWindow()
{
	return m_pLocalStreamEditorWindow;
}
 
IPStreamEditorWindow*	 RuntimeData::OnGetIPStreamEditorWindow()
{
	return m_pIPStreamEditorWindow;
}
 
void	 RuntimeData::OnSetVideoSourceEditroWindow(VideoSourceEditroWindow* pWindow)
{
	m_pVideoSourceEditroWindow = pWindow;
}
 
void	RuntimeData::OnSetPlayListEditorWindow(PlayListEditorWindow* pWindow)
{
	m_pPlayListEditorWindow = pWindow;
}
 
void	RuntimeData::OnSetPictureEditorWindow(PictureEditorWindow* pWindow)
{
	m_pPictureEditorWindow = pWindow;
}
 
void	RuntimeData::OnSetLocalStreamEditorWindow(LocalStreamEditorWindow* pWindow)
{
	m_pLocalStreamEditorWindow = pWindow;
}
 
void	 RuntimeData::OnSetIPStreamEditorWindow(IPStreamEditorWindow* pWindow)
{
	m_pIPStreamEditorWindow = pWindow;
}

