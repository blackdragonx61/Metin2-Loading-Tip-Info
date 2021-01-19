///Add
#if defined(__LOADING_TIP__)
#include "PythonBackground.h"
#endif

//Find
	m_dwSelectedCharacterIndex = iChrSlot;
	
///Add
#if defined(__LOADING_TIP__)
	CPythonBackground::Instance().SetWarpMapInfo(m_akSimplePlayerInfo[m_dwSelectedCharacterIndex].lMapIndex);
#endif

//Find
	Tracen("PythonNetworkMainStream Clear");
	
///Add
#if defined(__LOADING_TIP__)
	m_TipVnum.clear();
	m_TipList.clear();
#endif